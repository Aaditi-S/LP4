2/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr , int l , int h)
{
    int pivot = arr[h];
    int i=l;
    for(int j=l ; j<h ; j++)
    {
        if(arr[j] < pivot){
            swap(arr[i] , arr[j]);
            i++;
        }
    }
    swap(arr[i] , arr[h]);
    return i;
}
void qsort(vector<int>&arr , int l , int h)
{
    if(l < h)
    {
        int p = partition(arr , l , h);
        cout<<p<<"\n";
        qsort(arr , l , p-1);
        qsort(arr , p+1 , h);
    }
}
int r_partition(vector<int>&arr , int l , int h){
    int idx = l + rand() %(h - l +1);
    swap(arr[idx] , arr[h]);
    return partition(arr , l , h);
}
void r_qsort(vector<int>&arr , int l , int h)
{
    if(l < h)
    {
        int p = r_partition(arr , l ,h);
        r_qsort(arr , l , p-1);
        r_qsort(arr , p+1 , h);
    }
}
int main()
{
    vector<int>arr ={6,5,4,3,2,1};
    r_qsort(arr , 0 , 5);
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    
    return 0;
}

