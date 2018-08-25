#include "lcode20180816.h"
#include<algorithm>


lcode20180816::lcode20180816()
{
}


lcode20180816::~lcode20180816()
{
}

void maxProfit_problem::dp_fun(vector<int>& prices, int i, vector<int>& dp)
{
	if (i < 1) { dp[0] = 0; return; }
	dp_fun(prices, i - 1, dp);
	int maxPrefix = 0;
	for (int j = i - 1; j >= 0; j--)
		maxPrefix = max(maxPrefix, prices[i] - prices[j]);
	dp[i] = max(maxPrefix, dp[i - 1]);
}

int maxProfit_problem::dp_fun2(vector<int>& prices, int i)
{
	if (i < 1) { return 0; }
	int maxPrefix = 0;
	for (int j = i - 1; j >= 0; j--)
		maxPrefix = max(maxPrefix, prices[i] - prices[j]);
	return max(maxPrefix, dp_fun2(prices, i - 1));
}

int maxProfit_problem::maxProfit1(vector<int>& prices)
{

	if (prices.size() < 2) return 0;
	// method 3
	//int ans = INT_MIN;
	//for (int i = 0; i < prices.size() - 1; i++) {
	//	for (int j = i + 1; j < prices.size(); j++) {
	//		if (prices[j] - prices[i] > ans) {
	//			ans = prices[j] - prices[i];
	//		}
	//	}
	//}

	// method 4
	//int lowestPrice = INT_MAX, maxProfit = 0;
	//for (int i = 0; i < prices.size(); i++) {
	//	if (prices[i] < lowestPrice) lowestPrice = prices[i];
	//	else if (prices[i] - lowestPrice > maxProfit) maxProfit = prices[i] - lowestPrice;
	//}
	//return maxProfit;

	//int maxProfit = 0;
	//vector<int> dp(prices.size(), 0);
	//this->dp_fun(prices, prices.size() - 1, dp);
	//auto it_max = max_element(dp.begin(), dp.end());
	//return *it_max;

	return this->dp_fun2(prices, prices.size() - 1);
}

int maxProfit1_problem::maxProfit(vector<int>& prices)
{
	if (prices.size() < 2) return 0;
	vector<int> s0(prices.size(), 0), s1(prices.size(), 0), s2(prices.size(), 0);
	s0[0] = 0, s1[0] = -prices[0], s2[0] = INT_MIN;
	for (int i = 1; i < prices.size(); i++) {
		s0[i] = max(s0[i - 1], s2[i - 1]);
		s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
		s2[i] = s1[i - 1] + prices[i];
	}
	return max(s0.back(), s2.back());
}
