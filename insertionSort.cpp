#include<iostream>
using namespace std;

void swap(int &x,int &y){
	int temp = x;
	x = y;
	y = temp;
}

void display(int arr[],int n){
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}	
}
void insertionSort(int arr[],int n){
	int j;
	for(int i = 1;i<n;i++){
		int current = arr[i];
		if(arr[i-1]>arr[i]){
			j = i - 1;
			while(arr[j]>current and j>=0){
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = current;
		}
		display(arr,n);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;        // size of array that we want to declare
	cin>>n;

	int arr[n];

	// input part
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	// calling function for insertion Sort
	insertionSort(arr,n);

	return 0;
}