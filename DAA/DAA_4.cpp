#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int>&wt, vector<int>&val , int w , int idx ,vector<vector<int>>&dp)
{
	if(idx == 0){
		if(wt[idx] <= w){
			return val[idx];
		}
		return 0;
	}
	if(dp[idx][w] != -1){
		return dp[idx][w];
	}
	int nonpick = 0 + knapsack(wt , val , w , idx-1 , dp);
	int pick = INT_MIN;
	if(wt[idx] <= w){
		pick = val[idx] + knapsack(wt , val , w-wt[idx] , idx-1 , dp);
	}
	return dp[idx][w] = max(pick , nonpick);
}
int main()
{
	vector<int> wt = {2 , 3 , 5};
	vector<int> val = {30 , 40 , 60};
	int w = 6;
	vector<vector<int>>dp(3 , vector<int>(7 , -1));
	cout<<knapsack(wt , val , w , 2 , dp);
	return 0;
}
