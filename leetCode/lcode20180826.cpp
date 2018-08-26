#include "lcode20180826.h"
#include<numeric>
#include<algorithm>
#include<unordered_map>

lcode20180826::lcode20180826()
{
}


lcode20180826::~lcode20180826()
{
}

int pivotIndex_problem::pivotIndex(vector<int>& nums)
{
	// 0%
	if (nums.size() < 3) return -1;
	for (int i = 0; i < nums.size(); i++) {
		if (i != 0 && i != nums.size() - 1) {
			int l_sum = accumulate(nums.begin(), nums.begin() + i, 0);
			int r_sum = accumulate(nums.begin() + i + 1, nums.end(), 0);
			if (l_sum == r_sum) return i;
		}
		else if (i == 0 && accumulate(nums.begin() + 1, nums.end(), 0) == 0) return 0;
		else if (i == nums.size() - 1 && accumulate(nums.begin(), nums.end() - 1, 0) == 0) return nums.size() - 1;
	}
	return -1;
}

int pivotIndex_problem::pivotIndex2(vector<int>& nums)
{
	// 25%
	if (nums.size() < 3) return -1;
	int l_sum = 0;
	int r_sum = accumulate(nums.begin(), nums.end(), 0);
	for (int i = 0; i < nums.size(); i++) { r_sum -= nums[i]; if (l_sum == r_sum) return i; l_sum += nums[i]; }
	return -1;
}

int subarraySum_problem::subarraySum(vector<int>& nums, int k)
{
	//// TIME LIMIT EXCEEDED
	//if (nums.size() < 1) return 0;
	//int ans = 0;
	//for (int win_size = 1; win_size <= nums.size(); win_size++) {
	//	for (int i = 0; i < nums.size() - win_size + 1; i++) {
	//		int cur_sum = accumulate(nums.begin() + i, nums.begin() + i + win_size, 0);
	//		if (cur_sum == k) ans += 1;
	//	}
	//}
	//return ans;

	// Using Cummulative sum
	// 1.56%
	if (nums.size() < 1) return 0;
	int ans = 0;
	vector<int> accmu;
	for (int i = 0, accmu_sum = 0; i < nums.size(); i++) { accmu_sum += nums[i]; accmu.push_back(accmu_sum); }
	for (int win_size = 1; win_size <= nums.size(); win_size++) {
		for (int i = 0; i < nums.size() - win_size + 1; i++) {
			int cur_sum;
			if (i == 0) cur_sum = accmu[i + win_size - 1];
			else cur_sum = accmu[i + win_size - 1] - accmu[i - 1];
			if (cur_sum == k) ans += 1;
		}
	}
	return ans;
}

int subarraySum_problem::subarraySum2(vector<int>& nums, int k) {
	// Using hashmap
	// 50%
	if (nums.size() < 1) return 0;
	int ans = 0, acc = 0;
	unordered_map<int, int> map;
	map[0]++;
	for (int num : nums) {
		acc += num;
		if (map.find(acc - k) != map.end()) ans += map[acc - k];
		map[acc]++;
	}
	return ans;
}

bool checkSubarraySum_problem::checkSubarraySum(vector<int>& nums, int k)
{
	// Using Cummulative sum
	// 32%
	if (nums.size() < 2) return false;
	vector<int> accmu;
	for (int i = 0, accmu_sum = 0; i < nums.size(); i++) { accmu_sum += nums[i]; accmu.push_back(accmu_sum); }
	for (int win_size = 2; win_size <= nums.size(); win_size++) {
		for (int i = 0; i < nums.size() - win_size + 1; i++) {
			int cur_sum;
			if (i == 0) cur_sum = accmu[i + win_size - 1];
			else cur_sum = accmu[i + win_size - 1] - accmu[i - 1];
			if (k != 0 && int(float(cur_sum) / k) == float(cur_sum) / k) return true;
			else if (k == 0 && cur_sum == k) return true;
		}
	}
	return false;
}
