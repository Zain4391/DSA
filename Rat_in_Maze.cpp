#include <iostream>
using namespace std;

bool isSafe(int **arr,int x,int y,int Board_size)
{
    if(x<Board_size && y<Board_size && arr[x][y]==1) //check to see if moving to the next block in the grid is possible
    {
        return true;
    }

    return false;
}

bool RatinMaze(int **arr,int x,int y,int Board_size,int **sol)
{
    if(x == Board_size-1 && y == Board_size-1) //base case
    {
        sol[x][y]=1;
        return true;
    }

    if(isSafe(arr,x,y,Board_size))
    {
        sol[x][y]=1;

        if(RatinMaze(arr,x+1,y,Board_size,sol)) //recursive call to check the row
        {
            return true;
        }
        if(RatinMaze(arr,x,y+1,Board_size,sol)) //recursive call to check the column
        {
            return true;
        }
       sol[x][y]=0; //backtracking
       return false;
    }

    return false;
}

void print(int **arr,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<arr[i][j]<<" ";
        }

        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter board size: "<<endl;
    cin>>n;

    int **arr = new int *[n];

    for(int i=0;i<n;i++)
    {
        arr[i] = new int [n];
    }

    cout<<"Enter values in the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter 0 and 1s for row "<<i+1<<endl;
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    cout<<endl;

    print(arr,n);

    cout<<endl;

    int **sol= new int *[n];

    for(int i=0;i<n;i++)
    {
        sol[i]=new int [n];
        for(int j=0;j<n;j++)
        {
            sol[i][j]=0;
        }
    }

    if(RatinMaze(arr,0,0,n,sol))
    {
        cout<<"A possible solution: "<<endl;
        print(sol,n);
    }
    else
    {
        cout<<"No possible solution."<<endl;
    }

    return 0;
}