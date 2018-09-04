#include "lcode20180904.h"
#include<algorithm>


lcode20180904::lcode20180904()
{
}


lcode20180904::~lcode20180904()
{
}

int findLengthOfLCIS_problem::findLengthOfLCIS(vector<int>& nums)
{
	// 50%
	if (nums.size() < 1) return 0;
	if (nums.size() < 2) return 1;
	int ans = INT_MIN, count = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > nums[i - 1]) count += 1;
		else { ans = max(ans, count); count = 1; }
	}
	ans = max(ans, count);
	return ans;
}

int findNumberOfLIS_problem::findNumberOfLIS(vector<int>& nums)
{
		// %
		// Dynamic Programming
		// lengths[i] 0 ==> longest ending in nums[i]
		// counts[i] 1 ==> number of longest ending in nums[i]
		if (nums.size() < 2) return nums.size();
		vector<int> lengths(nums.size(), 0);
		vector<int> counts(nums.size(), 1);
		for (int j = 0; j < nums.size(); j++) {
			for (int i = 0; i < j; i++) {
				if (nums[i] < nums[j]) {  // 满足条件
					if (lengths[i] >= lengths[j]) { // 出现断层 || 刚刚扫描
						lengths[j] = 1 + lengths[i];
						counts[j] = counts[i];
					}
					else if (lengths[i] + 1 == lengths[j]) // 重复长度
						counts[j] += counts[i];
				}
			}
		}
		int ans = 0;
		auto it = max_element(lengths.begin(), lengths.end());
		for (int i = 0; i < lengths.size(); i++) if (lengths[i] == *it) ans += counts[i];
		return ans;
}

int findNumberOfLIS_problem::findNumberOfLIS2(vector<int>& nums)
{
	// %
	// DP思想，是否增加最后的nums[i]为最大的subsequence.
	int n = nums.size(), res = 0, max_len = 0;
	vector<pair<int, int>> dp(n, { 1,1 });            //dp[i]: {length, number of LIS which ends with nums[i]}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j <i; j++) {
			if (nums[i] > nums[j]) {
				if (dp[i].first == dp[j].first + 1) dp[i].second += dp[j].second;
				if (dp[i].first < dp[j].first + 1)dp[i] = { dp[j].first + 1, dp[j].second };
			}
		}
		if (max_len == dp[i].first)res += dp[i].second;
		if (max_len < dp[i].first) {
			max_len = dp[i].first;
			res = dp[i].second;
		}
	}
	return res;
}

int lengthOfLIS_problem::lengthOfLIS(vector<int>& nums)
{
		// %
		if (nums.size() < 2) return nums.size();
		vector<int> dp(nums.size(), 0);
		int ans = INT_MIN;
		dp[0] = 1;
		for (int i = 1; i < nums.size(); i++) {
			int maxVal = 0;
			for (int j = 0; j < nums.size(); j++) {
				if (nums[i] > nums[j]) maxVal = max(maxVal, dp[j]);
			}
			dp[i] += maxVal + 1;
			ans = max(ans, dp[i]);
		}
		return ans;
}