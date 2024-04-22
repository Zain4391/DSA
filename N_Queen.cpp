#include<bits/stdc++.h>
using namespace std;



bool isSafe(int **arr,int x,int y,int borad_size)
{
    for(int i=0;i<x;i++) //checks rows for Queens
    {
        if(arr[i][y]==1)
        {
            return false;
        }

    }

        int row=x;
        int col=y;

        while(row>=0 && col>= 0) //checks left diagonal
        {
            if(arr[row][col]==1)
            {
                return false;
            }

            row--;
            col--;
        }

        
        row=x;
        col=y;

        while(row>=0 && col<borad_size) //checks right diagonal
        { 
            if(arr[row][col]==1)
            {
                return false;
            }

            row--;
            col++ ;
        }

        return true;
}

bool NQueen(int **arr,int x,int board_size) //recursive function
{
    if(x == board_size)
    {
        return true;
    }

    for(int i=0;i<board_size;i++)
    {
        if(isSafe(arr,x,i,board_size))
        {
            arr[x][i]=1; //placing the Queens

            if(NQueen(arr,x+1,board_size))
            {
                return true;
            }

            arr[x][i]=0;//backtracking
        }
    }

    return false;
}

void print(int **arr,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }

        cout<<endl;
    }
}

int main()
{
    int size;
    cout<<"Enter the board size [N x N]: ";
    cin>>size;
    int **arr = new int *[size];
    for(int i=0;i<size;i++)
    {
        arr[i] = new int [size];

        for(int j=0;j<size;j++)
        {
            arr[i][j]=0; //new board set
        }
    }
    
     
    if(NQueen(arr,0,size))
    {
        cout<<"The possible solution: "<<endl;
        print(arr,size,size);
       
    }
    else
    {
        cout<<"No Possible solution."<<endl;
    }
    return 0;
}
