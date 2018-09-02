#include "lcode20180902.h"
#include<algorithm>
#include<unordered_map>

lcode20180902::lcode20180902()
{
}


lcode20180902::~lcode20180902()
{
}

int dominantIndex_problem::dominantIndex(vector<int>& nums)
{
	// 10%
	if (nums.size() == 0) return -1;
	else if (nums.size() == 1) return 0;
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) if (map.find(nums[i]) == map.end()) map[nums[i]] = i;
	sort(nums.begin(), nums.end(), [](int a, int b){ return a > b; });
	if (nums.front() >= nums[1] * 2) return map[nums.front()];
	return -1;
}

int maximumSwap_problem::maximumSwap(int num)
{
		// %
		vector<int> nums;
		do {
			nums.push_back(num % 10);
			num /= 10;
		} while (num);
		reverse(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++) {
			auto it = max_element(nums.begin() + i, nums.end());
			if (distance(nums.begin(), it) != i) {
				auto it2 = nums.end() - 1;
				for (; *it2 != *it; it2--);
				swap(*it2, nums[i]);
				break;
			}
		}
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ans *= 10;
			ans += nums[i];
		}
		return ans;
}
