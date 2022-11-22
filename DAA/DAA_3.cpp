#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int , int>&a , pair<int ,int>&b)
{
	double r1 = (double)a.second / (double)a.first;
	double r2 = (double)b.second / (double)b.first;
	
	return r1 > r2;
}
double fractional_knapsack(vector<int>&wt , vector<int>&val , int w)
{
	vector<pair<int , int>>vtow;
	for(int i=0 ; i<wt.size() ; i++)
	{
		vtow.push_back({wt[i] , val[i]});
	}
	sort(vtow.begin() , vtow.end() , cmp);
	double f_val = 0.0;
	int cur_weight = 0; 
	for(int i=0 ; i<vtow.size() ; i++)
	{
		if(cur_weight + vtow[i].first <= w){
			cur_weight += vtow[i].first;
			f_val += vtow[i].second;
		}else{
			int remain = w - cur_weight;
			f_val += (vtow[i].second / (double)vtow[i].first)*remain;
			break;
		}
	}
	return f_val;
}

int main()
{
	vector<int>wt = {20 , 10 , 30};
	vector<int>val = {100 , 60 , 120};
	cout<<" "<<fractional_knapsack(wt , val , 50);
	return 0;
}
