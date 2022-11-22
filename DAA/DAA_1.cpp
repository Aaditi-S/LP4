#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
	if( n <= 1){
		return n;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}
int i_fibbo(int n)
{
	int sl = 0 ;
	int l =1;
	for(int i=0 ; i < n-1 ; i++)
	{
		int curr = sl + l;
		sl = l;
		l = curr;
	}
	return l;
}
int main()
{
	int n = 5;
	cout<<fibonacci(n)<<"\n";
	cout<<i_fibbo(n);
	return 0;
}
