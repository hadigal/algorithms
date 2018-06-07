/*******************************************************************************
* File: selection_sort.c
* Author: Hrishikesh Adigal
* email: hadigal@sdsu.edu
* Date: 06/03/2018
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int * selection_sort(int *,int, int);
void print_array(int *,int);

int main()
{
  int size,i,flag = 0;
  int *arr;
  int *sarr;
  setbuf(stdout, NULL);
  printf("\n------------------------------------------------\n");
  printf("\nEnter the array size:\n");
  scanf("%d",&size);
  arr = (int *)calloc(size,sizeof(int));
  printf("Enter the array element:\n");
  for(i = 0; i<size;i++)
  {
    scanf("%d",arr+i);
  }
  printf("\n************ RESULT ************\n");
  printf("Given Array:\n");
  print_array(arr,size);
  sarr = selection_sort(arr,size,flag);
  printf("\nSelection Sorted Array:\n");
  print_array(sarr,size);
  printf("\n********************************\n");
  printf("\n------------------------------------------------\n");
  free(arr);
  return 0;
}

int *selection_sort(int *arr,int size, int flag)
{
  int temp,i,j,cur_ind,min;
  for(i = 0; i<size; i++)
  {
    cur_ind = i+1;
    min = arr[i];
    temp = i;
    for(j = cur_ind; j < size;j++)
    {
      if(arr[j] < min)
      {
        temp = j;
        min = arr[j];
      }
    }
    arr[temp] = arr[i];
    arr[i] = min;
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
