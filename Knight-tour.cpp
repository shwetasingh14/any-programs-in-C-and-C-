#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int chessboard[100][100];

void Knight_tour(int,int,int,int);
bool isOkay(int,int,int);
void PRINT_SOLUTION(int chessboard[][100],int N);

void Knight_tour(int N,int i,int j,int count){

	if(count== N*N -1){
		//cout<<"Hello";
		PRINT_SOLUTION(chessboard,N);
		exit(0);
	}

	if(isOkay(i+2,j+1,N)){
		chessboard[i+2][j+1] = count+1;
		Knight_tour(N,i+2,j+1,count+1);
		chessboard[i+2][j+1] = -1;		
	}

	if(isOkay(i+1,j+2,N)){
		chessboard[i+1][j+2] = count+1;
		Knight_tour(N,i+1,j+2,count+1);
		chessboard[i+1][j+2] = -1;
	}

	if(isOkay(i-1,j+2,N)){
		chessboard[i-1][j+2] = count+1;
		Knight_tour(N,i-1,j+2,count+1);
		chessboard[i-1][j+2] = -1;
	}


	if(isOkay(i-2,j+1,N)){
		chessboard[i-2][j+1] = count+1;
		Knight_tour(N,i-2,j+1,count+1);
		chessboard[i-2][j+1] = -1;	
	}

	if(isOkay(i-2,j-1,N)){
		chessboard[i-2][j-1] = count+1;
		Knight_tour(N,i-2,j-1,count+1);
		chessboard[i-2][j-1] = -1;	
	}

	if(isOkay(i-1,j-2,N)){
		chessboard[i-1][j-2] = count+1;
		Knight_tour(N,i-1,j-2,count+1);
		chessboard[i-1][j-2] = -1;		
	}

	if(isOkay(i+1,j-2,N)){
		chessboard[i+1][j-2] = count+1;
		Knight_tour(N,i+1,j-2,count+1);
		chessboard[i+1][j-2] = -1;		
	}

	if(isOkay(i+2,j-1,N)){
		chessboard[i+2][j-1] = count+1;
		Knight_tour(N,i+2,j-1,count+1);
		chessboard[i+2][j-1] = -1;		
	}


	//cout<<"END";
	return;
}

int main(){

	int count=0;
	int x,y;
	int N; //N x N chessboard

	cout<<"Dimensions of chessboard: ";
	cin>>N;
	cout<<"initial position of Knight: ";
	cin>>x;	//initial x co-ordinate
	cin>>y; //initial y co-ordinate


	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			chessboard[i][j] = -1;
	}

	//initializing position of Knight
	chessboard[x][y] = count;

	Knight_tour(N,x,y,count);

	cout<<"Solution not found!!"<<endl;
	return 0; 
}

bool isOkay(int i,int j,int N){

	if(i<0 or i>N-1 or j<0 or j>N-1)
		return false;
	if(chessboard[i][j] != -1)
		return false;
	return true;

	//return (i >= 0 && i < N && j >= 0 && j < N && chessboard[i][j] == -1); 
}

void PRINT_SOLUTION(int chessboard[][100],int N){
	cout<<"\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<setw(5)<<chessboard[i][j]<<"   ";
		cout<<"\n";
	}

}
