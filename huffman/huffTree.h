#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

/*
 * typedef of a huffman tree struct: HuffTree_t
 * ----------------------------
 */
typedef struct _HuffTree HuffTree_t;

/*
 * Function: createNode
 * ----------------------------
 *   byte: unsigned char of the char (byte) to create a node
 *   frequency: long long integer with how many times the char (byte) occurred in the file
 *
 *   returns: HuffTree_t* of the created node.
 */
HuffTree_t* createNode(unsigned char byte, long long int frequency);

/*
 * Function: createTree
 * ----------------------------
 *   byte: unsigned char of the char (byte) to create a tree
 *   frequency: long long integer with how many times the char (byte) occurred in the file
 *   left: HuffTree_t* left node of the tree to create
 *   right: HuffTree_t* right node of the tree to create
 *
 *   returns: HuffTree_t* of the created tree.
 */
HuffTree_t* createTree(unsigned char byte, long long int frequency, HuffTree_t *left, HuffTree_t *right);

/*
 * Function: createTreeFromPreFix
 * ----------------------------
 *   Creates a tree by heading a prefixed print of a tree
 *
 *   pFile: FILE* of the file to get the header
 *   newTree: HuffTree_t** of a tree where the tree will be created from a pre fix print of a tree
 *   end: integer of how many nodes the tree will have
 *   i: integer* to keep track of how many nodes where read
 *
 *   returns: nothing
 */
void createTreeFromPreFix(FILE *pFile, HuffTree_t **newTree, int end, int *i);
HuffTree_t* createTreeFromFile(char pathFile[]);

/*
 * Function: isHuffTreeEmpty
 * ----------------------------
 *   hm: HuffTree_t* huffman tree
 *
 *   returns: boolean wheter the tree is empty or not
 */
bool isHuffTreeEmpty(HuffTree_t *hm);

/*
 * Function: height
 * ----------------------------
 *   hm: HuffTree_t* huffman tree
 *
 *   returns: integer of tree's height
 */
int height(HuffTree_t *hm);

/*
 * Function: isMoreFrequent
 * ----------------------------
 *   a: HuffTree_t* huffman tree to compare with tree b
 *   b: HuffTree_t* huffman tree to compare with tree a
 *
 *   returns: boolean wheter the tree a's char (byte) occurs more frequently then tree b's char
 */
bool isMoreFrequent(HuffTree_t *a, HuffTree_t *b);

/*
 * Function: swap
 * ----------------------------
 *   Swaps the content of tree a with tree b
 *
 *   a: HuffTree_t* huffman tree to swap with tree b
 *   b: HuffTree_t* huffman tree to swap with tree a
 *
 *   returns: nothing
 */
void swap(HuffTree_t *a, HuffTree_t *b);

/*
 * Function: getNext
 * ----------------------------
 *   atual: HuffTree_t* huffman tree to get the it's next tree
 *
 *   returns: HuffTree_t* of the next tree
 */
HuffTree_t* getNext(HuffTree_t *atual);

/*
 * Function: setNext
 * ----------------------------
 *   Sets the atual tree's next tree to be the given next
 *
 *   atual: HuffTree_t* huffman tree to set the it's next tree
 *   next: HuffTree_t* huffman tree to be the next tree of the given atual
 *
 *   returns: nothing
 */
void setNext(HuffTree_t *atual, HuffTree_t *next);

/*
 * Function: getFrequency
 * ----------------------------
 *   atual: HuffTree_t* huffman tree to get the it's char (byte) frequency
 *
 *   returns: long long int of the tree's char (byte) frequency
 */
long long int getFrequency(HuffTree_t *atual);

/*
 * Function: printNode
 * ----------------------------
 *   Prints a tree's char (byte) and it's frequency
 *
 *   atual: HuffTree_t* a huffman tree/node to print
 *
 *   returns: nothing
 */
void printNode(HuffTree_t *atual);

/*
 * Function: printTreeInFile
 * ----------------------------
 *   Prints a tree with pre order in a file
 *
 *   newFile: FILE* the file to be printed in
 *   tree: HuffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreeInFile(FILE *newFile, HuffTree_t *tree);

/*
 * Function: printTreePreOrder
 * ----------------------------
 *   Prints a tree with pre order
 *
 *   tree: HuffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreePreOrder(HuffTree_t *tree);

/*
 * Function: printTreeInOrder
 * ----------------------------
 *   Prints a tree with in order
 *
 *   tree: HuffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreeInOrder(HuffTree_t *tree);

/*
 * Function: printTreePosOrder
 * ----------------------------
 *   Prints a tree with pos order
 *
 *   tree: HuffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreePosOrder(HuffTree_t *tree);

/*
 * Function: createDictionary
 * ----------------------------
 *   Creates a dictionary with a huffman tree
 *
 *   tree: HuffTree_t* huffman tree to create a dictionary with
 *   dictionary: boolean bidimensional array to be filled with the representation of a char (byte)
 *   bitsQuantity: integer array to be filled with how many bits are needed to represent a char (byte)
 *   frequency: long long integer array to be fille with how many times a char (byte) occurred in the file to compress
 *   bits: boolean array to store the new representation of the char (byte)
 *   depth: integer with the the actual height in which the recursion is
 *
 *   returns: nothing
 */
void createDictionary(HuffTree_t *tree, bool dictionary[][256], int bitsQuantity[], long long int frequency[], bool bits[], int depth);

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
 *   tree: HuffTree_t* huffman tree to count it's size
 *
 *   returns: integer of the amount of chars needed to print the tree
 */
int countTreeSize(HuffTree_t *tree);

/*
 * Function: decompressBytes
 * ----------------------------
 *   Descompresses the chars (bytes) of a compressed file to form a new file
 *
 *   pFile: FILE* to be read and extracted the compressed chars (bytes)
 *   newFile: FILE* to print in the decompressed bytes
 *   tree: HuffTree_t* huffman tree to know find correspondent char (byte)
 *   trashSize: integer of the trash size
 *   progressBar: long long integer of the progress bar
 *
 *   returns: nothing
 */
void decompressBytes(FILE *pFile, FILE *newFile, HuffTree_t *tree, int trashSize, long long int progressBar[]);

/*
 * Function: destroyHuffTree
 * ----------------------------
 *   Destroys a huffman tree
 *
 *   tree: HuffTree_t* huffman tree to destroy
 *
 *   returns: nothing
 */
void destroyHuffTree(HuffTree_t *tree);

#endif //HUFFTREE_H
