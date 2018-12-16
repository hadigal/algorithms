/*******************************************************************************
* File: bubble_sort.c
* Author: Hrishikesh Adigal
* email: hadigal@sdsu.edu
* Date: 06/03/2018
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int *bubble_sort(int *,int);
void print_array(int *,int);
struct timeval st,sp;

int main()
{
  int *arr,i,size, *pass;
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
  bubble_sort(arr,size);
  printf("\nBubble Sorted Array:\n");
  print_array(arr,size);
  printf("\nNumber of passes made to sort the array:%d",*pass);
  printf("\n********************************\n");
  printf("\n------------------------------------------------\n");
  free(arr);
  return 0;
}

int * bubble_sort(int * arr, int size)
{
  gettimeofday(&st,NULL);
  int i,j,flag,temp;
  for(i = 0; i < size - 1; i++)
  {
    flag = 0;
    for(j = 0; j < size - 1 - i; j++)
    {
      if(arr[j+1] < arr[j])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        flag++;
      }
    }
    if(flag == 0)
    {
      break;
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
