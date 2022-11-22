/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>>&board , int r , int c){
    int i , j;
    for(i=0 , j=c ; i<r ; i++)
    {
        if(board[i][j] == 1){
            return false;
        }
    }
    for(i=r-1 , j=c-1 ; i>=0 && j>=0 ; i-- , j--)
    {
        if(board[i][j] == 1){
            return false;
        }
    }
    for(i=r-1 , j=c+1 ; i>=0 && j<board.size() ; i-- , j++)
    {
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}
bool util(vector<vector<int>>&board , int r)
{
    if(r >= board.size()){
        return true;
    }
    for(int c=0 ; c<board.size() ; c++)
    {
        if(issafe(board ,r , c)){
            board[r][c] = 1;
            if(util(board , r+1)){
                return true;
            }
            board[r][c] = 0;
        }
        
    }
    return false;
}
void display(vector<vector<int>>&board)
{
    for(int i=0 ; i<board.size() ; i++)
    {
        for(int j=0 ; j<board.size() ; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void solve(int n , int c)
{
    vector<vector<int>>board(n , vector<int>(n , 0));
    board[0][c] = 1;
    if(util(board , 1) == true)
    {
        display(board);
    }else{
        cout<<"No solution exist";
    }
    
}
int main()
{
    int n = 5;
    solve(n , 3);
    return 0;
}

