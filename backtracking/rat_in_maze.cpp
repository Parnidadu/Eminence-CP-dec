#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int result[20][20];
void mazeH(int maze[][20],int result[][20],int n,int row,int col){
  if(row==n-1 && col== n-1){
    result[row][col]=1;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<result[i][j]<<" ";
      }
    }
    cout<<endl;
    return;
  }
  if(row>=n || row<0 || col>=n || col<0 || maze[row][col]== 0 || result[row][col]== 1){
    return;
  }
  result[row][col]=1;
  mazeH(maze,result,n,row-1,col);
  mazeH(maze,result,n,row+1,col);
  mazeH(maze,result,n,row,col-1);
  mazeH(maze,result,n,row,col+1);
  result[row][col]=0;      
}


void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
 	//int result[20][20]
  	memset(result,0,20*20*sizeof(int));
  //	result[0][0]=1;
  	mazeH(maze,result,n,0,0);
  

}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}


