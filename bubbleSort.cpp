#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
	for(int i=n-2;i>=1;i--){
		for(int j=0;j<=i;j++){
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {52,6,1,4,6,45,2,12,94,45,1};
	int n = sizeof(arr)/sizeof(int);

	bubbleSort(arr,n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
