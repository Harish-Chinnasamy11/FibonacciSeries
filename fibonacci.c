#include <stdio.h>
#include <stdlib.h>

int * generateFibonacciSeries (int size)
{
    int * arr = malloc(size * sizeof(int));
    if (size == 1) {
        arr[0] = 0;
    }
    else if (size == 2) {
        arr[0] = 0; 
        arr[1] = 1;
    }
    else {
        arr[0] = 0; 
        arr[1] = 1;
        for(int i=2; i<size; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }
    return arr;
}
int sumSeries (int a[],int size) 
{
	int sum = 0;
	for(int i=0;i<size-1;i++)
		sum+=a[i];
	return sum;
}	
	

int * getEvenNumbers(int * arr, int size, int count)
{
    int j=0;
    int * arr1 = malloc(count * sizeof(int));
    for(int i=0; i<size; i++)
    {
        if (arr[i]%2==0) {
              arr1[j++] = arr[i];
        }
    }
    return arr1;
}
int * getOddNumbers(int *arr, int size, int count)
{
	int j=0;
	int * odd = malloc(count * sizeof(int));
	for(int i=0;i<size;i++)
	{
		if(arr[i]%2!=0){
			odd[j++]=arr[i];
		}
	}
	return odd;
}

int nthElement(int * arr, int size)
{
    int n;
    scanf("%d", &n);
    if (n > size+1 || n < 1) {
        return -1;
    }
    
    return arr[n-1];
}

int main() {
    int size;
    scanf("%d", &size);
 
    int* arr = generateFibonacciSeries(size);
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    int EvenCount=0;
    for(int i=0; i<size; i++)
    {
        if (arr[i]%2==0) {
            EvenCount++;
        }
    }
    int* arr1 = getEvenNumbers(arr, size, EvenCount);
    printf("\neven Series :");
    for(int i=0; i<EvenCount; i++)
    {
        printf("%d ",arr1[i]);
    }
	printf("\nOdd Series : ");
	int OddCount = size-EvenCount;
    int* odd = getOddNumbers(arr, size, OddCount);
    for(int i=0; i<OddCount; i++)
    {
        printf("%d ",odd[i]);
    }
	printf("\nsum = %d",sumSeries(arr,size));

    printf("\nnth Element = %d", nthElement(arr, size));
    return 0;
}