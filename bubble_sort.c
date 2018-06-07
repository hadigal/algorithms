/*******************************************************************************
* File: bubble_sort.c
* Author: Hrishikesh Adigal
* email: hadigal@sdsu.edu
* Date: 06/03/2018
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int *bubble_sort(int *,int, int *);
void print_array(int *,int);

int main()
{
  int *arr,i,size,*sarr, *pass;
  int p_var =1;
  pass = &p_var;
  setbuf(stdout,NULL);
  printf("\n----------------------------------------------\n");
  printf("Enter the array size:\n");
  scanf("%d",&size);
  arr = (int *)calloc(size,sizeof(int));
  printf("\nEnter the array elements:\n");
  for(i = 0; i < size; i++)
  {
    scanf("%d",arr+i);
  }
  printf("\n************ RESULT ************\n");
  printf("Given Array:\n");
  print_array(arr,size);
  sarr = bubble_sort(arr, size, pass);
  printf("\nSelection Sorted Array:\n");
  print_array(sarr,size);
  printf("\nNumber of passes made to sort the array:%d",*pass);
  printf("\n********************************\n");
  printf("\n------------------------------------------------\n");
  free(arr);
  return 0;
}

int * bubble_sort(int * arr, int size, int * pass)
{
  int i,temp,j,flag;
  while(1)
  {
    j = 1;
    flag = 0;
    for(i = 0; i < size && j < size; i++)
    {
      if(arr[j] < arr[i])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        flag = 1;
      }
      j++;
    }
    if(flag == 0)
    {
      break;
    }
    (*pass)++;
  }
  return arr;
}

void print_array(int * arr,int size)
{
  int i;
  for(i = 0; i< size; i++)
  {
    printf("arr[%d]:%d\n",i,arr[i]);
  }
}
