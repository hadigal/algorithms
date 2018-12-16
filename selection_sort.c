/*******************************************************************************
* File: selection_sort.c
* Author: Hrishikesh Adigal
* email: hadigal@sdsu.edu
* Date: 06/03/2018
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval st, sp;
int * selection_sort(int *,int);
void print_array(int *,int);

int main()
{
  int size,i;
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
  sarr = selection_sort(arr,size);
  printf("\nSelection Sorted Array:\n");
  print_array(sarr,size);
  printf("\n********************************\n");
  printf("\n------------------------------------------------\n");
  free(arr);
  return 0;
}

int *selection_sort(int *arr,int size)
{
  int temp,i,j,min;
  gettimeofday(&st,NULL);
  for(i = 0; i < size - 1; i++)
  {
    min = i;
    for(j = i+1; j < size;j++)
    {
      if(arr[j] < arr[min])
      {
        min = j;
      }
    }
    if(i != min)
    {
      temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
  gettimeofday(&sp,NULL);
  printf("\n*****************************\n");
  printf("Sorting time:%lf usec\n",(double)(sp.tv_usec - st.tv_usec));
  printf("\n*****************************\n");
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
