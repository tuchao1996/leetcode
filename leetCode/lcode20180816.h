#pragma once
#include<vector>
using namespace std;

class lcode20180816
{
public:
	lcode20180816();
	~lcode20180816();
};

class maxProfit_problem {
	void dp_fun(vector<int>& prices, int i, vector<int>& dp);
	int dp_fun2(vector<int>& prices, int i);
	int maxProfit1(vector<int>& prices);
};

class maxProfit1_problem {
	int maxProfit(vector<int>& prices);
};
