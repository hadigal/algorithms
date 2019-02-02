#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// temp array to hold the split array
int *temp;

// function to print array
void printArray(int *arr, int size)
{
  for(int itr = 0; itr < size; ++itr)
  {
    printf("arr[%d]:%d\n",itr,arr[itr]);
  }
}

// copy elements of sorted halves to main array till given halves indices
void copyArr(int *arr, int *temp, int lIdx, int rIdx)
{
  int itr;
  for(itr = 0; itr <= rIdx; ++itr)
  {
    arr[itr] = temp[itr];
  }
}

// merge to split halves of the array to be sorted
void merge(int *arr, int *temp, int lIdx1,int rIdx1, int lIdx2, int rIdx2)
{
  // local vars
  int itr1 = lIdx1;
  int itr2 = lIdx2;
  int itr3 = lIdx1;

  // store the elements by sorting in both the halves
  while((itr1 <= rIdx1) && (itr2 <= rIdx2))
  {
    if(arr[itr1] <= arr[itr2])
    {
      temp[itr3++] = arr[itr1++];
    }
    else
    {
      temp[itr3++] = arr[itr2++];
    }
  }
  // store the remaining elements of the array
  while(itr1 <= rIdx1)
  {
    temp[itr3++] = arr[itr1++];
  }
  while(itr2 <= rIdx2)
  {
    temp[itr3++] = arr[itr2++];
  }
  return;
}

// recursively sort the array by top down merge approach
void mergeSort(int *arr, int lIdx, int rIdx)
{
  int mid;
  if(lIdx < rIdx)
  {
    mid = (lIdx+rIdx)/2;
    mergeSort(arr,lIdx,mid);
    mergeSort(arr,mid+1,rIdx);
    merge(arr,temp,lIdx,mid,mid+1,rIdx);
    copyArr(arr,temp,lIdx,rIdx);
    return;
  }
}

// copy array in reverse order.
void copyReverse(int *arr, int *temp, int size)
{
  int itr;
  int itr2 = size-1;
  for(itr = 0; itr < size; ++itr)
  {
    arr[itr2--] = temp[itr];
  }
}

int main(void)
{
  int *arr, size, itr;
  struct timeval start, stop;

  printf("Enter the size of array:\n");
  scanf("%d",&size);
  arr = (int *)calloc(size, sizeof(*arr));
  temp = (int *)calloc(size, sizeof(*temp));
  printf("\nEnter the elements in the array:\n");
  for(itr = 0; itr < size; ++itr)
  {
    scanf("%d",arr+itr);
  }

  // record start time for sorting
  gettimeofday(&start,NULL);
  mergeSort(arr,0,size-1);
  // record stop time for sorting
  gettimeofday(&stop,NULL);

  // print the sorted array in ascending order
  printf("\nSorted Array:\n");
  printArray(arr,size);

  printf("\nSort time:%lf usec\n",(double)(stop.tv_usec - start.tv_usec));

  // print sorted array in descending order
  printf("\nReversed Sorted Array\n");
  copyReverse(arr,temp,size);
  printArray(arr,size);

  //free the allocated memory
  free(arr);
  free(temp);
  return EXIT_SUCCESS;
}
