#include "lcode20180812.h"
#include<algorithm>


lcode20180812::lcode20180812()
{
}


lcode20180812::~lcode20180812()
{
}

bool isOneBitCharacter_problem::isOneBitCharacter(vector<int>& bits)
{
	const int N = bits.size();
	if (N <= 2) return bits[0] == 0;
	for (int i = 0; i < N; i++) {
		if (bits[i] == 1) {
			i++;
			if (i == (N - 1)) return false;
		}
	}
	return true;
}

vector<int> advantageCount_problem::advantageCount(vector<int>& A, vector<int>& B)
{

	vector<int> ans(B.size(), -1);
	vector<int> vec(A);
	for (int i = 0; i < B.size(); i++) {
		sort(vec.begin(), vec.end());
		int j = 0;
		while (j < vec.size() && vec[j] <= B[i]) j++;
		if (j != vec.size()) {
			ans[i] = vec[j];
			vec.erase(vec.begin() + j);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == -1) {
			ans[i] = vec.back();
			vec.pop_back();
		}
	}
	return ans;
}

int maxProfit11_problem::maxProfit(vector<int>& prices)
{
	int oneLowestBuy = INT_MIN, oneMaxProfit = 0;
	int twoLowestBuy = INT_MIN, twoMaxProfit = 0;
	for (int price : prices) {
		twoMaxProfit = max(twoMaxProfit, price + twoLowestBuy);
		twoLowestBuy = max(twoLowestBuy, oneMaxProfit - price);
		oneMaxProfit = max(oneMaxProfit, price + oneLowestBuy);
		oneLowestBuy = max(oneLowestBuy, -price);
	}
	return twoMaxProfit;
}
