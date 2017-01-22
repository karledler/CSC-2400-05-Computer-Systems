
/*
 *    Library of functions for manipulating arrays of strings in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stingarray.h"

void InitArray(char *array[], int n)
/* Input:  @param array is an array of uninitialized pointers 
 *         @param n is the number of entries in the array 
 * Action: Initialize all entries in the array to NULL 
 */ 
{
  int i;

  for(i = 0; i < n; i++)
    array[i] = NULL;
}

void Insert(char *array[], char * s, int pos)
/* Input:  @param array is an array of strings
 *         @param s is a string to be inserted in the array 
 *         @param pos is a valid array index
 * Action: Insert s in position pos in the array 
 */
{
 if(s!=NULL)
{
 array[pos] = malloc(strlen(s)+1);
 strcpy(array[pos], s);
}
}

void Remove(char *array[], int pos)
/* Input:  @param array is an array of strings
 *         @param pos is a valid array index 
 * Action: Remove the string from position pos in the array (if any) 
 */ 
{
	if(array[pos]!=NULL)
	{
	free(array[pos]);
	array[pos]= NULL;
	}
}

void RemoveAll(char *array[], int n)
/* Input:  @param array is an array of strings
 *         @param n is number of entries in the array
 * Action: Remove all existing strings from the array 
 */
{
	int j;

	for(j = 0; j < n; j++)
	{
	Remove(array, j);
	}
}

void Print(char *array[], int pos)
/* Input:  @param array is an array of strings
 *         @param pos is a valid array index
 * Action: Print out the string from position pos (if any) in the array 
 */
{
	if(array[pos]!=NULL)
	{
	printf("%s\n", array[pos]);
	}
}

void PrintAll(char *array[], int n)
/* Input:  @param array is an array of strings
 *         @param n is the number of entries in the array
 * Action: Print out all array entries 
 */
{
	int k;
	for(k=0; k<n; k++)
	{
		if(array[k]!=NULL)
		{
		printf("%s\n", array[k]);
		}
	}
}
