#include <iostream>
using namespace std;

void swap(int &x,int &y){
	int temp = x;
	x = y;
	y = temp; 
}

int _partition(int arr[],int i,int j){
	int l=i-1;
	int m=i;

	while(m<j){
		if(arr[m]<arr[j]){
			swap(arr[l+1],arr[m]);
			l++;
		}
		m++;
	}
	swap(arr[l+1],arr[j]);
	return l+1;
}

void quicksort(int arr[],int i,int j){
	if(i<j){
		int k = _partition(arr,i,j);
		quicksort(arr,i,k-1);
		quicksort(arr,k+1,j);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {1,5,5,12,2,5,4,1,3,65};
	int n = sizeof(arr)/sizeof(int);
	quicksort(arr,0,n-1);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}