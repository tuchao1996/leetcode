#include "lcode20180817.h"
#include<algorithm>

lcode20180817::lcode20180817()
{
}


lcode20180817::~lcode20180817()
{
}


int maxProfit_problem::maxProfit(vector<int>& prices)
{
	if (prices.size() < 2) return 0;
	//int ans = 0, buy = -1;
	//for (int i = 0; i < prices.size() - 1; i++) {
	//	if (buy == -1) {
	//		if (prices[i] >= prices[i + 1]) continue;
	//		else buy = prices[i];
	//	}
	//	else {
	//		if (prices[i] <= prices[i + 1]) continue;
	//		else {
	//			ans += prices[i] - buy;
	//			buy = -1;
	//		}
	//	}
	//}
	//if (buy != -1 && prices.back() > buy) ans += prices.back() - buy;
	//return ans;

	int ans = 0;
	for (int i = 0; i < prices.size() - 1; i++) {
		if (prices[i + 1] > prices[i]) {
			ans += prices[i + 1] - prices[i];
		}
	}
	return ans;
}

int maxProfit1_problem::maxProfit(vector<int>& prices, int fee)
{
	if (prices.size() < 2) return 0;
	vector<int> buy(prices.size(), 0), sell(prices.size(), 0);
	buy[0] = -prices.front();
	sell[0] = 0;
	for (int i = 1; i < prices.size(); i++) {
		buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
		sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
	}
	return max(buy.back(), sell.back());
}
