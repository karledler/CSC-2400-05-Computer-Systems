
#include <stdio.h>
#include "stingarray.h"

#define MAX 10
char * myarray[MAX];

int main()
{
  InitArray(myarray, MAX);

  Insert(myarray, NULL, 0);   /* program should not crash */

  Insert(myarray, "zero", 0);
  Insert(myarray, "one", 1);
  Insert(myarray, "two", 2);
  Insert(myarray, "three", 3);
  Insert(myarray, "four", 4);
  Insert(myarray, "five", 5);

  Print(myarray, 6);         /* program should not crash */
  Print(myarray, 3);

  PrintAll(myarray, MAX);

  Remove(myarray, 2);
  Print(myarray, 2);         /* program should not crash */
  Remove(myarray, 4);
  PrintAll(myarray, MAX);

  RemoveAll(myarray, MAX);
  printf("Array emptied ... \n");
  PrintAll(myarray, MAX);

  return (0);
}
