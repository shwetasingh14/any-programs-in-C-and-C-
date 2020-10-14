#include<iostream>
using namespace std;

bool compare(const void *a,const void * b)
{
	return *(int*)a==*(int*)b;
}
int search(void *arr,int n,int sizeofdatatype,void *x,bool (*fun)(const void *,const void *))
{
	char *ptr = (char*)arr;
	for(int i=0;i<n;i++)
	{
		if(fun(ptr + i*sizeofdatatype,x))
			return i;
	}
	return -1;
}
int main()
{
	int arr[]={5,1,9,6,35,12,45,56,11};
	int n=9;
	int x=66;
	cout<<"Index: "<<search(arr,n,4,&x,compare); 
	return 0;
}
