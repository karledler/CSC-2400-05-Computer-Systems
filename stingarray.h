/* Library of functions for manipulating arrays of strings */

#ifndef __STRING_ARRAY
#define __STRING_ARRAY

      void InitArray(char *array[], int n);  
      /* Input:  @param array is an array of uninitialized pointers 
       *         @param n is the number of entries in the array 
       * Action: Initialize all entries in the array to NULL */

      void Insert(char *array[], char * s, int pos); 
      /* Input:  @param array is an array of strings
       *         @param s is a string to be inserted in the array 
       *         @param pos is a valid array index
       * Action: Insert s in position pos in the array */

      void Remove(char *array[], int pos); 
      /* Input:  @param array is an array of strings
       *         @param pos is a valid array index 
       * Action: Remove the string from position pos in the array (if any) */
 
      void RemoveAll(char *array[], int n); 
      /* Input:  @param array is an array of strings
       *         @param n is number of entries in the array
       * Action: Remove all existing strings from the array */

	void Print(char *array[], int pos); 
      /* Input:  @param array is an array of strings
       *         @param pos is a valid array index
       * Action: Print out the string at position pos (if any) in the array */

	void PrintAll(char *array[], int n); 
      /* Input:  @param array is an array of strings
       *         @param n is the number of entries in the array
       * Action: Print out all strings in the array (i.e., all non-NULL array entries) */

#endif
