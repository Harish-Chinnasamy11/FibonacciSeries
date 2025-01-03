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
	int sum =-1;
	for(int i=0;i<size;i++)
		sum+=a[i];
	return sum;
}	
	

int main() {
    int size;
    scanf("%d", &size);
    
    int* arr = generateFibonacciSeries(size);
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
	printf("\nsum = %d",sumSeries(arr,size));
    return 0;
}