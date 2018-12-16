#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef unsigned int uint32;
static int *arr;

void quickSort(int *arr,int left,int rt)
{
  if(left >= rt)
  {
    return;
  }
  int l = left;
  int r = rt;
  int pIdx = (uint32)((rt + left)/2);

  while(left <= rt)
  {
    while(arr[left] < arr[pIdx])
    {
      ++left;
    }
    while(arr[rt] > arr[pIdx])
    {
      --rt;
    }
    if((arr[left] >= arr[rt]) && (left <= rt))
    {
      int temp = arr[left];
      arr[left] = arr[rt];
      arr[rt] = temp;
      ++left;
      --rt;
    }
  }
  quickSort(arr,l,left-1);
  quickSort(arr,left,r);
}

int main(void)
{
  int size;
  scanf("%u",&size);
  if( size <= 0)
  {
    printf("Invalid size\n");
    return EXIT_FAILURE;
  }
  arr = (int *)calloc(size,sizeof(*arr));
  for(uint32 itr = 0; itr < size; ++itr)
  {
    scanf("%d",arr+itr);
  }
  struct timeval start, stop;
  gettimeofday(&start,NULL);
  quickSort(arr,0,size-1);
  gettimeofday(&stop,NULL);
  printf("\n-------------------------- Sorted Array --------------------------\n");
  printf("\nSorting time:%lf usec\n\n",(double)(stop.tv_usec - start.tv_usec));
  for(uint32 itr = 0; itr < size; ++itr)
  {
    printf("%d\n",arr[itr]);
  }
  free(arr);
  return EXIT_SUCCESS;
}
