#include <stdio.h>

int main()
{
    //int arr[] = {1,11,100,1,0,200,3,2,1,250};
    
    int size,i,x;
    printf("ENter array length : \n");
    scanf("%d",&size);
    
    int arr[size];
    
     printf("Enter array elements:\n");
     for(i = 0; i < size;  i++){
        scanf("%d", &arr[i]);
     }
     
     printf("Enter the sum : \n");
     scanf("%d",&x);
     
     
    int n= (int)( sizeof(arr) / sizeof(arr[0]));
	int currentSum=0, minimumLen=1+n, start=0, end=0;
	int low=0,high=0;
    
    while (end < n) {
        while (end < n && currentSum <= x)
        {
            currentSum = currentSum + arr[end];
            end++;
        }
        while (currentSum > x && start < n) {
            if (end - start < minimumLen)
            {
            minimumLen = end - start;
            high=end;
            low=start;
            }
            currentSum = currentSum - arr[start];
            start++;
        }
    }
    
    while(low<high)
    {
        printf("%d  ", arr[low]+minimumLen);
        low++;
    }
    printf("\n");
    return 0;
}
