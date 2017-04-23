#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

/*
 * typedef of a huffman tree struct: huffTree_t
 * ----------------------------
 */
typedef struct _huffTree huffTree_t;

/*
 * Function: createNode
 * ----------------------------
 *   byte: unsigned char of the char (byte) to create a node
 *   frequency: long long integer with how many times the char (byte) occurred in the file
 *
 *   returns: huffTree_t* of the created node.
 */
huffTree_t* createNode(unsigned char byte, long long int frequency);

/*
 * Function: createTree
 * ----------------------------
 *   byte: unsigned char of the char (byte) to create a tree
 *   frequency: long long integer with how many times the char (byte) occurred in the file
 *   left: huffTree_t* left node of the tree to create
 *   right: huffTree_t* right node of the tree to create
 *
 *   returns: huffTree_t* of the created tree.
 */
huffTree_t* createTree(unsigned char byte, long long int frequency, huffTree_t *left, huffTree_t *right);

/*
 * Function: createTreeFromPreFix
 * ----------------------------
 *   Creates a tree by heading a prefixed print of a tree
 *
 *   pFile: FILE* of the file to get the header
 *   newTree: huffTree_t** of a tree where the tree will be created from a pre fix print of a tree
 *   end: integer of how many nodes the tree will have
 *   i: integer* to keep track of how many nodes where read
 *
 *   returns: nothing
 */
void createTreeFromPreFix(FILE *pFile, huffTree_t **newTree, int end, int *i);
huffTree_t* createTreeFromFile(char pathFile[]);

/*
 * Function: isHuffTreeEmpty
 * ----------------------------
 *   hm: huffTree_t* huffman tree
 *
 *   returns: boolean wheter the tree is empty or not
 */
bool isHuffTreeEmpty(huffTree_t *hm);

/*
 * Function: height
 * ----------------------------
 *   hm: huffTree_t* huffman tree
 *
 *   returns: integer of tree's height
 */
int height(huffTree_t *hm);

/*
 * Function: isMoreFrequent
 * ----------------------------
 *   a: huffTree_t* huffman tree to compare with tree b
 *   b: huffTree_t* huffman tree to compare with tree a
 *
 *   returns: boolean wheter the tree a's char (byte) occurs more frequently then tree b's char
 */
bool isMoreFrequent(huffTree_t *a, huffTree_t *b);

/*
 * Function: swap
 * ----------------------------
 *   Swaps the content of tree a with tree b
 *
 *   a: huffTree_t* huffman tree to swap with tree b
 *   b: huffTree_t* huffman tree to swap with tree a
 *
 *   returns: nothing
 */
void swap(huffTree_t *a, huffTree_t *b);

/*
 * Function: getNext
 * ----------------------------
 *   atual: huffTree_t* huffman tree to get the it's next tree
 *
 *   returns: huffTree_t* of the next tree
 */
huffTree_t* getNext(huffTree_t *atual);

/*
 * Function: setNext
 * ----------------------------
 *   Sets the atual tree's next tree to be the given next
 *
 *   atual: huffTree_t* huffman tree to set the it's next tree
 *   next: huffTree_t* huffman tree to be the next tree of the given atual
 *
 *   returns: nothing
 */
void setNext(huffTree_t *atual, huffTree_t *next);

/*
 * Function: getFrequency
 * ----------------------------
 *   atual: huffTree_t* huffman tree to get the it's char (byte) frequency
 *
 *   returns: long long int of the tree's char (byte) frequency
 */
long long int getFrequency(huffTree_t *atual);

/*
 * Function: printNode
 * ----------------------------
 *   Prints a tree's char (byte) and it's frequency
 *
 *   atual: huffTree_t* a huffman tree/node to print
 *
 *   returns: nothing
 */
void printNode(huffTree_t *atual);

/*
 * Function: printTreeInFile
 * ----------------------------
 *   Prints a tree with pre order in a file
 *
 *   newFile: FILE* the file to be printed in
 *   tree: huffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreeInFile(FILE *newFile, huffTree_t *tree);

/*
 * Function: printTreePreOrder
 * ----------------------------
 *   Prints a tree with pre order
 *
 *   tree: huffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreePreOrder(huffTree_t *tree);

/*
 * Function: printTreeInOrder
 * ----------------------------
 *   Prints a tree with in order
 *
 *   tree: huffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreeInOrder(huffTree_t *tree);

/*
 * Function: printTreePosOrder
 * ----------------------------
 *   Prints a tree with pos order
 *
 *   tree: huffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreePosOrder(huffTree_t *tree);

/*
 * Function: createDictionary
 * ----------------------------
 *   Creates a dictionary with a huffman tree
 *
 *   tree: huffTree_t* huffman tree to create a dictionary with
 *   dictionary: boolean bidimensional array to be filled with the representation of a char (byte)
 *   bitsQuantity: integer array to be filled with how many bits are needed to represent a char (byte)
 *   frequency: long long integer array to be fille with how many times a char (byte) occurred in the file to compress
 *   bits: boolean array to store the new representation of the char (byte)
 *   depth: integer with the the actual height in which the recursion is
 *
 *   returns: nothing
 */
void createDictionary(huffTree_t *tree, bool dictionary[][256], int bitsQuantity[], long long int frequency[], bool bits[], int depth);

/*
 * Function: countTrashSize
 * ----------------------------
 *   bitsQuantity: integer array with how many bits are needed to represent a char (byte)
 *   frequency: long long integer array with how many times a char (byte) occurred
 *
 *   returns: integer of the trash size
 */
int countTrashSize(int bitsQuantity[], long long int frequency[]);

/*
 * Function: countTreeSize
 * ----------------------------
 *   tree: huffTree_t* huffman tree to count it's size
 *
 *   returns: integer of the amount of chars needed to print the tree
 */
int countTreeSize(huffTree_t *tree);

/*
 * Function: decompressBytes
 * ----------------------------
 *   Descompresses the chars (bytes) of a compressed file to form a new file
 *
 *   pFile: FILE* to be read and extracted the compressed chars (bytes)
 *   newFile: FILE* to print in the decompressed bytes
 *   tree: huffTree_t* huffman tree to know find correspondent char (byte)
 *   trashSize: integer of the trash size
 *   progressBar: long long integer of the progress bar
 *
 *   returns: nothing
 */
void decompressBytes(FILE *pFile, FILE *newFile, huffTree_t *tree, int trashSize, long long int progressBar[]);

/*
 * Function: destroyHuffTree
 * ----------------------------
 *   Destroys a huffman tree
 *
 *   tree: huffTree_t* huffman tree to destroy
 *
 *   returns: nothing
 */
void destroyHuffTree(huffTree_t *tree);

#endif //HUFFTREE_H
