#include "linkedlist.h"
#include "answer07.h"
#include <stdlib.h>
#include <stdio.h>

#define NUM_CASES (10)

/* Used for the test generator to create a loop
 * in a the linked list intentionally. The loop
 * will be created from index "from" to index "to".
 */
bool createLoop(node_t * head, int from, int to)
{
  if (from < to)
  {
    return false;
  }

  node_t * fromNode;
  node_t * toNode;
  node_t * cur = head;
  for (int i = 0; i <=from; i++)
  {
    // out of bounds
    if (cur == NULL)
    {
      return false;
    }

    // find the two nodes to create the circular link
    if (i == to)
    {
      toNode = cur;
    }
    if (i == from)
    {
      fromNode = cur;
    }
    
    cur = cur->next;
  }

  fromNode->next = toNode;

  // remove all nodes after the loop
  while(cur != NULL) {
    rem(&cur, 0);
  }
  return true;

}

int main(int argc, char * * argv)
{
#ifdef HINTS
  char *hints[] = {"empty linked list",
                   "one node linked list without loops",
                   "one node linked list with a single node loop",
                   "medium sized linked list without loops",
                   "medium sized linked list that loops in the middle",
                   "large sized linked list without loops",
                   "large sized linked list that loops from the end to the beginning",
                   "large sized linked list that loops from the end to the end",
                   "extra large sized linked list without loops",
                   "extra large sized linked list that loops from"};
#endif

  int testSizes[] =        {0    , 1    , 1   , 10   , 30  , 151  , 829 , 1510, 2472, 3199};
  bool expectedAnswers[] = {false, false, true, false, true, false, true, true, false, true};
  node_t * linkedLists[NUM_CASES] = {NULL};
  for (int i = 0; i < NUM_CASES; i++)
  {
    for (int j = 0; j < testSizes[i]; j++)
    {
      insert(&(linkedLists[i]), 0, j);
    }

  }
  // at the very start
  createLoop(linkedLists[2], 0, 0);

  // somewhere in the middle
  createLoop(linkedLists[4], 22, 5);

  // somewhere at the end to the beginning
  createLoop(linkedLists[6], 828, 0);

  // at the end to itself
  createLoop(linkedLists[7], 1509, 1509);

  // at the end to the middle
  createLoop(linkedLists[9], 3198, 1027);

  int incorrect = 0;
  for (int i = 0; i < NUM_CASES; i++) {
    bool actual = isCircular(linkedLists[i]);
    if (actual != expectedAnswers[i])
    {
      incorrect++;
    }

#ifdef HINTS
    printf("[*] Testing %s\n", hints[i]);
    printf("[%c] Your result: %s, Correct result: %s\n",
          (actual == expectedAnswers[i] ? '*' : '!'),
          (actual ? "true " : "false"),
          (expectedAnswers[i] ? "true" : "false"));
#endif
  }
  return incorrect;
}
