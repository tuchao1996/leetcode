#include "lcode20180913.h"
#include<unordered_map>
#include<algorithm>

lcode20180913::lcode20180913()
{
}


lcode20180913::~lcode20180913()
{
}

int majorityElement_problem::majorityElement(vector<int>& nums)
{
	// 57%
	if (nums.empty()) return 0;
	unordered_map<int, int> map;
	for (int num : nums) {
		map[num]++;
		if (map[num] > nums.size() / 2) return num;
	}
}

int dp(vector<int> nums, int low, int high) {
	if (low == high) return nums[low];
	int mid = low + (high - low) / 2;
	int left = dp(nums, low, mid);
	int right = dp(nums, mid + 1, high);
	if (low == high) return left;
	int left_majority = count(nums.begin() + low, nums.begin() + high, left);
	int right_majority = count(nums.begin() + low, nums.begin() + high, right);
	return max(left_majority, right_majority);
}

int majorityElement_problem::majorityElement2(vector<int>& nums)
{
	return dp(nums, 0, nums.size());
}

vector<int> majorityElement2_problem::majorityElement(vector<int>& nums)
{
	// 80.73%
	if (nums.empty()) return {};
	unordered_map<int, int> map;
	vector<int> ans;
	//for (int num : nums) map[num]++;
	//for (auto it = map.begin(); it != map.end(); it++) if (it->second > nums.size() / 3) ans.push_back(it->first);
	for (int num : nums) if (map[num] <= nums.size() / 3 && ++map[num] > 3) ans.push_back(num);
	return ans;
}

vector<vector<int>> generateMatrix_problem::generateMatrix(int n)
{
	// 100%
	vector<vector<int>> ans(n, vector<int>(n, 0));
	int count = 2;
	int row = 0, col = 0;
	ans[0][0] = 1;
	while (count <= n * n) {
		while (col + 1 < n && ans[row][col + 1] == 0) ans[row][++col] = count++;
		while (row + 1 < n && ans[row + 1][col] == 0) ans[++row][col] = count++;
		while (col - 1 >= 0 && ans[row][col - 1] == 0) ans[row][--col] = count++;
		while (row - 1 >= 0 && ans[row - 1][col] == 0) ans[--row][col] = count++;
	}
	return ans;
}
