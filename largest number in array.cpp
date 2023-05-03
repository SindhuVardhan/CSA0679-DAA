#include <stdio.h>

int main(){
	int n,i;
	printf("enter the number of elements in array:");
	scanf("%d",&n);
	
	int arr[n];
	printf("enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	for(i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	printf("The largest element in the array is: %d\n", max);
    return 0;
}