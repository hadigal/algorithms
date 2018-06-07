/*******************************************************************************
* File: insertion_sort.c
* Author: Hrishikesh Adigal
* email: hadigal@sdsu.edu
* Date: 06/03/2018
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int *insertion_sort(int *, int);
void print_array(int *, int);

int main()
{
  int i,*sarr, *arr, size;
  setbuf(stdout,NULL);
  printf("\n------------------------------------------------\n");
  printf("\nEnter array size:\n");
  scanf("%d",&size);
  printf("Enter the array elements:\n");
  arr = (int *)calloc(size,sizeof(int));
  for(i = 0; i < size; i++)
  {
    scanf("%d",arr+i);
  }
  printf("\n************ RESULT ************\n");
  printf("Given Array:\n");
  print_array(arr,size);
  sarr = insertion_sort(arr,size);
  printf("\nSelection Sorted Array:\n");
  print_array(sarr,size);
  printf("\n********************************\n");
  printf("\n------------------------------------------------\n");
  free(arr);
  return 0;
}

int *insertion_sort(int * arr, int size)
{
  int i,j,temp;
  for(i = 1; i < size; i++)
  {
    temp = arr[i];
    for(j = i - 1; j >= 0; j--)
    {
      if(temp < arr[j])
      {
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
  return arr;
}

void print_array(int *arr, int size)
{
  for(int i = 0; i< size; i++)
  {
    printf("%d\n",*(arr+i));
  }
}
