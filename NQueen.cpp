#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <math.h>
#include <time.h>
using namespace std;

long long int step=10000000;
long long int count=0;	//count total number of solutions
clock_t start, timefirst, end;
int *solutionVector=0;
void NQueen(int,int);
bool Place(int,int);
void PRINT_SOLUTION(int*,int,int);

void NQueen(int N,int col){

	//iterating through all rows of column 'col'
	for(int i=0;i<N;i++){
		if (Place(i,col)==true){
			solutionVector[col] = i;

			if(col==N-1){
				count++;
				if (count==1){
					//timefirst = clock();
					PRINT_SOLUTION(solutionVector,N,N);
				}

				if (count>step){
					cout<"One crore";
					step = step+step;
				}
				
			}
			else{
				//PRINT_SOLUTION(solutionVector,N,col+1);
				NQueen(N,col+1);

			}
		}
	}
	return;
}

int main(){

	int N;	//N x N chessboard
	

	cout<<"\nDimensions of chess board: ";
	cin>>N;

	solutionVector = new int[N]; //Solution 1D vector

	for(int i=0;i<N;i++)
		solutionVector[i]=-1;

	start = clock(); 

	NQueen(N,0);

	end = clock(); 

	cout<<"\nTotal number of soutions: "<<count<<endl;
	cout<<"\nExecution time : "<<double(end-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
	//cout<<"\nExecution time for first solution: "<<double(timefirst-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;

	step=10000000;
	count=0;
	start = clock(); 

	NQueen(N+1,0);

	end = clock(); 

	cout<<"\nTotal number of soutions: "<<count<<endl;
	cout<<"\nExecution time : "<<double(end-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
	//cout<<"\nExecution time for first solution: "<<double(timefirst-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;

	step=10000000;
	count=0;
	start = clock(); 

	NQueen(N+2,0);

	end = clock(); 

	cout<<"\nTotal number of soutions: "<<count<<endl;
	cout<<"\nExecution time : "<<double(end-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
	//cout<<"\nExecution time for first solution: "<<double(timefirst-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
	
	step=10000000;
	count=0;
	start = clock(); 

	NQueen(N+3,0);

	end = clock(); 

	cout<<"\nTotal number of soutions: "<<count<<endl;
	cout<<"\nExecution time : "<<double(end-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
	//cout<<"\nExecution time for first solution: "<<double(timefirst-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
	getchar();
	//getchar();

	return 0;
}

bool Place(int i,int j){
	for(int col=0;col<=j-1;col++){
		if(abs(solutionVector[col]-i) == abs(col-j) or solutionVector[col]==i){
			return false;
		}
	}
	return true;
}

void PRINT_SOLUTION(int solutionVector[],int N,int col){
	cout<<"\n\n[\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<col;j++){
			if(solutionVector[j]==i){
				cout<<"Q ";
			}
			else{
				cout<<"- ";
			}
		}
		cout<<"\n";
	}
	cout<<"]\n\n";
}