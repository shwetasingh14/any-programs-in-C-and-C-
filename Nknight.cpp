#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include <time.h>
using namespace std;

clock_t start, end;
int count=0;
int chessboard[100][100];
int *solution = 0;
void NKnight(int,int,int x = 0,int y = 0,int z = 0);
bool isOkay(int,int,int,int);
bool isInside(int,int,int);
void PRINT_SOLUTION(int chessboard[][100],int);

int main(int argc, char const *argv[])
{
	/* code */

	// Dimensions of chessboard
	int N=6;
	int knights=8;

	cin>>N;
	cin>>knights;

	solution = new int[knights];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			chessboard[i][j] = -1;	

	start = clock(); 
	NKnight(N,knights);
	end = clock();

	cout<<"Total number of solutions: "<<count<<endl;
	cout<<"\nExecution time : "<<double(end-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
	return 0;
}

void NKnight(int N,int knights,int col,int row,int knightNumber){
	
	if(knightNumber == knights){
		count = count + 1;
		
		if(count==1){	
		PRINT_SOLUTION(chessboard,N);
		}
	
	}

	if(row == N)
		return;

	for(int j=col;j<N;j++){
		if(isOkay(row,j,N,knightNumber)){
			chessboard[row][j] = 1;
			knightNumber +=1;
			solution[knightNumber-1] = N * (row) + (j + 1);
			
			if(j == N-1)
				NKnight(N,knights,(j+1)%N,row+1,knightNumber);
			else
				NKnight(N,knights,(j+1)%N,row,knightNumber);
			
			chessboard[row][j] = -1;
			knightNumber -=1;
		}
	}

	for(int i=row+1;i<N;i++){
		for(int j=0;j<N;j++){
			if(isOkay(i,j,N,knightNumber)){
			chessboard[i][j] = 1;
			knightNumber +=1;
			solution[knightNumber-1] = N * (i) + (j + 1);

			if(j == N-1)
				NKnight(N,knights,(j+1)%N,i+1,knightNumber);
			
			else	
				NKnight(N,knights,(j+1)%N,i,knightNumber);
			
			chessboard[i][j] = -1;
			knightNumber -=1;
			}
		}
	}
}

bool isOkay(int row,int col,int N,int knightNumber){

int i,j;

for(int k = 0;k<knightNumber;k++){
	
	i = (solution[k]-1)/N;
	j = (solution[k]-1)%N;

	if(isInside(i-1,j+2,N))
	if(i-1==row and j+2 == col)
		return false;

	if(isInside(i+1,j+2,N))
	if(i+1==row and j+2 == col)
		return false;

	if(isInside(i-2,j+1,N))
	if(i-2==row and j+1 == col)
		return false;

	if(isInside(i-2,j-1,N))
	if(i-2==row and j-1 == col)
		return false;

	if(isInside(i-1,j-2,N))
	if(i-1==row and j-2 == col)
		return false;

	if(isInside(i+1,j-2,N))
	if(i+1==row and j-2 == col)
		return false;

	if(isInside(i+2,j-1,N))
	if(i+2==row and j-1 == col)
		return false;

	if(isInside(i+2,j+1,N))
	if(i+2==row and j+1 == col)
		return false;
}
return true;

}

bool isInside(int row,int col,int N){
	if(row<0 or row>N-1 or col<0 or col>N-1)
		return false;
	return true;
}

void PRINT_SOLUTION(int chessboard[][100],int N){
	cout<<"\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<setw(5)<<chessboard[i][j]<<"   ";
		cout<<"\n";
	}

}