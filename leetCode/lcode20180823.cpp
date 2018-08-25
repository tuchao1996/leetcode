#include "lcode20180823.h"
#include<map>
#include<algorithm>


lcode20180823::lcode20180823()
{
}


lcode20180823::~lcode20180823()
{
}

int findShortestSubArray_problem::findShortestSubArray(vector<int>& nums)
{
		//3%
	//map<int, int> countMap;
	//for (int num : nums) if (countMap.find(num) != countMap.end()) countMap[num] += 1; else countMap[num] = 1;
	//auto it = countMap.begin();
	//int maxEle = it->first, maxNum = it->second;
	//for (it++; it != countMap.end(); it++) if (it->second >= maxNum) { maxEle = it->first; maxNum = it->second;}
	//vector<int> ele; 
	//for (it = countMap.begin(); it != countMap.end(); it++) if (it->second == maxNum) ele.push_back(it->first);
	//int ans = INT_MAX;
	//for (int element : ele) {
	//	int begin, end;
	//	for (int i = 0; i < nums.size(); i++) if (nums[i] == element) { begin = i; break; }
	//	for (int i = nums.size() - 1; i >= 0; i--) if (nums[i] == element) { end = i; break; }
	//	ans = min(ans, end - begin + 1);
	//}
	//return ans;
	
	int N = nums.size();
	map<int, vector<int> > mp;
	for (int i = 0; i < N; ++i)
		mp[nums[i]].push_back(i);
	int degree = 0;
	for (auto it = mp.begin(); it != mp.end(); it++)
		degree = max(degree, int(it->second.size()));
	int shortest = N;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second.size() == degree)
			shortest = min(shortest, it->second.back() - it->second.front() + 1);
	}
	return shortest;
}

int minimumTotal_problem::minimumTotal(vector<vector<int>>& triangle)
{
	//96%
	for (int row = triangle.size() - 2; row >= 0; row--) {
		for (int col = 0; col < triangle[row].size(); col++) {
			triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
		}
	}
	return triangle.front().front();
}

int strangePrinter_problem::strangePrinter(string s)
{
	if (s.empty()) return 0;
	vector<vector<int>> dp;
	for (int i = 0; i < s.size(); i++) { vector<int> tmp(s.size(), 0); dp.push_back(tmp); }
	for (int i = 0; i < s.size(); i++) {
		dp[i][i] = 1;
		if (i < s.size() - 1) dp[i][i + 1] = s[i] == s[i + 1] ? 1 : 2;
	}
	for (int len = 2; len < s.size(); len++) {
		for (int start = 0; start + len < s.size(); start++) {
			dp[start][start + len] = len + 1;
			for (int k = 0; k < len; k++) {
				int tmp = dp[start][start + k] + dp[start + k + 1][start + len];
				dp[start][start + len] = min(
					dp[start][start + len],
					s[start + k] == s[start + len] ? tmp - 1 : tmp
				);
			}
		}
	}
	return dp[0][s.size() - 1];
}
