/*
 * =====================================================================================
 *
 *       Filename:  test_list.c
 *
 *    Description:  Tests the linked list implementation by CUnit
 *
 *        Version:  1.0
 *        Created:  04/17/2016 08:39:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <stdint.h>
#include    <stdlib.h>
#include    <CUnit/CUnit.h>

#include    "test_list.h"
#include    "list.h"

int clean_list_suite
    (
    void
    )
{
return 0;
}

int init_list_suite
    (
    void
    )
{
return 0;
}

int setup_list_suite
    (
    void
    )
{
CU_pSuite pSuite = NULL;
pSuite = CU_add_suite(
            "Linked List Test Suite", 
            init_list_suite, 
            clean_list_suite);
if(NULL == pSuite)
    {
    return -1;
    }
/* Add more tests here as functions are developed */
if((NULL == CU_add_test(pSuite, "Testing add()", test_add)                      )
|| (NULL == CU_add_test(pSuite, "Testing get_head()", test_get_head)            )
|| (NULL == CU_add_test(pSuite, "Testing get_tail()", test_get_tail)            )
|| (NULL == CU_add_test(pSuite, "Testing make_new_list()", test_make_new_list)  )
|| (NULL == CU_add_test(pSuite, "Testing prepend()", test_prepend)              )
|| (NULL == CU_add_test(pSuite, "Testing remove_element()", test_remove_element)))
    {
    return -1;
    }
return 0;
}

void test_add
    (
    void
    )
{
uint32_t arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
uint32_t i;
list * new_list = make_new_list();
node * cur = NULL;
CU_ASSERT_PTR_NOT_NULL(new_list);
for(i = 0; i < 10; i++)
    {
    add(new_list, &(arr[i]));
    }
cur = get_head(new_list);
CU_ASSERT_PTR_NOT_NULL(cur);
i = 0;

while(cur != NULL)
    {
//    printf("%d\n", *(uint32_t *)cur->data);
    CU_ASSERT_EQUAL(*(uint32_t *)cur->data, arr[i]);
    cur = cur->next;
    i++;
    }
//printf("Now loop from the tail\n");
cur = NULL;
cur = get_tail(new_list);
CU_ASSERT_PTR_NOT_NULL(cur);
i = 9;
while(cur != NULL)
    {
//    printf("%d\n", *(uint32_t *)cur->data);
    CU_ASSERT_EQUAL(*(uint32_t *)cur->data, arr[i]);
    cur = cur->prev;
    i--;
    }
//printf("Done looping through the linked list!\n");
//printf("The list is %d elements long.\n", new_list->size);
CU_ASSERT_EQUAL(new_list->size, 10);
}

void test_get_head
    (
    void
    )
{
}

void test_get_tail
    (
    void
    )
{
}

void test_make_new_list
    (
    void
    )
{
}

void test_prepend
    (
    void
    )
{
uint32_t arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
uint32_t i;
list * new_list = make_new_list();
node * cur = NULL;
CU_ASSERT_PTR_NOT_NULL(new_list);
for(i = 0; i < 10; i++)
    {
    prepend(new_list, &(arr[i]));
    }
cur = get_head(new_list);
CU_ASSERT_PTR_NOT_NULL(cur);
i = 0;
while(cur != NULL)
    {
    CU_ASSERT_EQUAL(*(uint32_t *)cur->data, arr[i]);
//    printf("%d\n", *(uint32_t *)cur->data);
    cur = cur->next;
    i++;
    }
//printf("Now loop from the tail\n");
cur = NULL;
cur = get_tail(new_list);
CU_ASSERT_PTR_NOT_NULL(cur);
i = 9;
while(cur != NULL)
    {
    CU_ASSERT_EQUAL(*(uint32_t *)cur->data, arr[i]);
//    printf("%d\n", *(uint32_t *)cur->data);
    cur = cur->prev;
    i--;
    }
//printf("Done looping through the linked list!\n");
CU_ASSERT_EQUAL(new_list->size, 10);
//printf("The list is %d elements long.\n", new_list->size);
}

void test_remove_element
    (
    void
    )
{
uint32_t arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90}; uint32_t i;
list * new_list = make_new_list();
CU_ASSERT_PTR_NOT_NULL(new_list);
node * cur;
for(i = 0; i < 10; i++)
    {
    add(new_list, &(arr[i]));
    }
CU_ASSERT_EQUAL(new_list->size, 9);
//printf("The list is %d elements long.\n", new_list->size);
cur = remove_element(new_list, 3);
CU_ASSERT_EQUAL(*(uint32_t *)cur->data, arr[3]);
//printf("Removed the element containing %d.\n", *(uint32_t *)cur->data);
cur = get_head(new_list);
i = 0;

while(cur != NULL)
    {
    if(i == 3)
        {
        i++;
        }
    CU_ASSERT_EQUAL(*(uint32_t *)cur->data, arr[i]);
//    printf("%d\n", *(uint32_t *)cur->data);
    cur = cur->next;
    i++;
    }
CU_ASSERT_EQUAL(new_list->size, 9);
//printf("The list is now %d elements long.\n", new_list->size);
}

