#include "answer07.h"
#include "linkedlist.h"

bool isCircular(const node_t * head)
{
	if (head == NULL || head->next == NULL){
    		return false; // an empty list is NOT a loop
  	}
	
	const node_t * slowptr = head;
	const node_t * fastptr = head;
	
	while ( (fastptr != NULL) && (fastptr->next != NULL) ){
          fastptr = fastptr->next->next;
          slowptr = slowptr->next;
	  if( fastptr == slowptr ) 
		return true; // same value/data, IS a loop	
	  }
	return false; 
}
