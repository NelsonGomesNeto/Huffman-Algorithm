#include "heap.h"
#include "priorityQueue.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
* Opens the temporary file used by the tests.
* Returns zero on success, non-zero otherwise.
*/
int init_suite1(void)
{
  if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
    return -1;
  }
  else {
    return 0;
  }
}

/* The suite cleanup function.
* Closes the temporary file used by the tests.
* Returns zero on success, non-zero otherwise.
*/
int clean_suite1(void)
{
  if (0 != fclose(temp_file)) {
    return -1;
  }
  else {
    temp_file = NULL;
    return 0;
  }
}

void test_enqueueHeap(void)
{
  int i;
  int nums[4][10] = {7, 3, 2, 1, 5, 6, 9, 4, 8, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int expected[4][10] = {7, 7, 7, 7, 7, 7, 9, 9, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  heap_t *heap = createHeap(10, '+');
  for (i = 0; i < 10; i ++)
  {
    enqueueHeap(heap, nums[0][i]);
    CU_ASSERT(frontHeap(heap) == expected[0][i]);
  }
  destroyHeap(heap);

  heap = createHeap(10, '+');
  for (i = 0; i < 10; i ++)
  {
    enqueueHeap(heap, nums[1][i]);
    CU_ASSERT(frontHeap(heap) == expected[1][i]);
  }
  destroyHeap(heap);

  heap = createHeap(10, '+');
  for (i = 0; i < 10; i ++)
  {
    enqueueHeap(heap, nums[2][i]);
    CU_ASSERT(frontHeap(heap) == expected[2][i]);
  }
  destroyHeap(heap);

  heap = createHeap(10, '+');
  for (i = 0; i < 10; i ++)
  {
    enqueueHeap(heap, nums[3][i]);
    CU_ASSERT(frontHeap(heap) == expected[3][i]);
  }
  destroyHeap(heap);
}

void test_enqueuePriorityQueue(void)
{
  int i;
  int nums[4][10] = {7, 3, 2, 1, 5, 6, 9, 4, 8, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int expected[4][10] = {7, 7, 7, 7, 7, 7, 9, 9, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  priorityQueue_t *pq = newPriorityQueue();
  for (i = 0; i < 10; i ++)
  {
    enqueuePriorityQueue(pq, nums[0][i], nums[0][i]);
    CU_ASSERT(maximum(pq) == expected[0][i]);
  }
  destroyPriorityQueue(pq);

  pq = newPriorityQueue();
  for (i = 0; i < 10; i ++)
  {
    enqueuePriorityQueue(pq, nums[1][i], nums[1][i]);
    CU_ASSERT(maximum(pq) == expected[1][i]);
  }
  destroyPriorityQueue(pq);

  pq = newPriorityQueue();
  for (i = 0; i < 10; i ++)
  {
    enqueuePriorityQueue(pq, nums[2][i], nums[2][i]);
    CU_ASSERT(maximum(pq) == expected[2][i]);
  }
  destroyPriorityQueue(pq);

  pq = newPriorityQueue();
  for (i = 0; i < 10; i ++)
  {
    enqueuePriorityQueue(pq, nums[3][i], nums[3][i]);
    CU_ASSERT(maximum(pq) == expected[3][i]);
  }
  destroyPriorityQueue(pq);
}

void test_dequeueHeap(void)
{
  int i;
  int nums[4][10] = {7, 3, 2, 1, 5, 6, 9, 4, 8, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int expected[4][10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  heap_t *heap = createHeap(10, '+');
  for (i = 0; i < 10; i ++)
    enqueueHeap(heap, nums[0][i]);
  for (i = 0; i < 10; i ++)
  {
    CU_ASSERT(frontHeap(heap) == expected[0][i]);
    dequeueHeap(heap);
  }
  destroyHeap(heap);

  heap = createHeap(10, '+');
  for (i = 0; i < 10; i ++)
    enqueueHeap(heap, nums[1][i]);
  for (i = 0; i < 10; i ++)
  {
    CU_ASSERT(frontHeap(heap) == expected[1][i]);
    dequeueHeap(heap);
  }
  destroyHeap(heap);

  heap = createHeap(10, '+');
  for (i = 0; i < 10; i ++)
    enqueueHeap(heap, nums[2][i]);
  for (i = 0; i < 10; i ++)
  {
    CU_ASSERT(frontHeap(heap) == expected[2][i]);
    dequeueHeap(heap);
  }
  destroyHeap(heap);

  heap = createHeap(10, '+');
  for (i = 0; i < 10; i ++)
    enqueueHeap(heap, nums[3][i]);
  for (i = 0; i < 10; i ++)
  {
    CU_ASSERT(frontHeap(heap) == expected[3][i]);
    dequeueHeap(heap);
  }
  destroyHeap(heap);
}

void test_dequeuePriorityQueue(void)
{
  int i;
  int nums[4][10] = {7, 3, 2, 1, 5, 6, 9, 4, 8, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int expected[4][10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  priorityQueue_t *pq = newPriorityQueue();
  for (i = 0; i < 10; i ++)
    enqueuePriorityQueue(pq, nums[0][i], nums[0][i]);
  for (i = 0; i < 10; i ++)
  {
    CU_ASSERT(maximum(pq) == expected[0][i]);
    dequeuePriorityQueue(pq);
  }
  destroyPriorityQueue(pq);

  pq = newPriorityQueue();
  for (i = 0; i < 10; i ++)
    enqueuePriorityQueue(pq, nums[1][i], nums[1][i]);
  for (i = 0; i < 10; i ++)
  {
    CU_ASSERT(maximum(pq) == expected[1][i]);
    dequeuePriorityQueue(pq);
  }
  destroyPriorityQueue(pq);

  pq = newPriorityQueue();
  for (i = 0; i < 10; i ++)
    enqueuePriorityQueue(pq, nums[2][i], nums[2][i]);
  for (i = 0; i < 10; i ++)
  {
    CU_ASSERT(maximum(pq) == expected[2][i]);
    dequeuePriorityQueue(pq);
  }
  destroyPriorityQueue(pq);

  pq = newPriorityQueue();
  for (i = 0; i < 10; i ++)
    enqueuePriorityQueue(pq, nums[3][i], nums[3][i]);
  for (i = 0; i < 10; i ++)
  {
    CU_ASSERT(maximum(pq) == expected[3][i]);
    dequeuePriorityQueue(pq);
  }
  destroyPriorityQueue(pq);
}

int main()
{
  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
  return CU_get_error();

  /* add a suite to the registry */
  pSuite = CU_add_suite("Enqueue Test", init_suite1, clean_suite1);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  if ((NULL == CU_add_test(pSuite, "test of enqueueHeap()", test_enqueueHeap))
  || (NULL == CU_add_test(pSuite, "test of enqueuePriorityQueue()", test_enqueuePriorityQueue)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }


  pSuite = CU_add_suite("Dequeue Test", init_suite1, clean_suite1);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(pSuite, "test of dequeueHeap()", test_dequeueHeap))
  || (NULL == CU_add_test(pSuite, "test of dequeuePriorityQueue()", test_dequeuePriorityQueue)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
