#include "lcode20180831.h"
#include<algorithm>
#include<unordered_map>

lcode20180831::lcode20180831()
{
}


lcode20180831::~lcode20180831()
{
}

int findPairs_problem::findPairs(vector<int>& nums, int k)
{
	// 14%
	if (nums.size() < 2) return 0;
	sort(nums.begin(), nums.end());
	int count = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		while ( i > 0 && i < nums.size() - 1 && nums[i] == nums[i - 1]) i++;
		if (i >= nums.size() - 1) break;
		int another = k + nums[i];
		auto it = find(nums.begin() + i + 1, nums.end(), another);
		if (it != nums.end()) { count++; continue; }
	}
	return count;
}

int findPairs_problem::findPairs2(vector<int>& nums, int k)
{
	// %
	if (nums.size() < 2 || k < 0) return 0;
	int count = 0;
	unordered_map<int, int> map;
	for (int num : nums) map[num]++;
	for (auto it = map.begin(); it != map.end(); it++) {
		if (k == 0) { if (it->second > 1) count++; }
		else {
			if (map.find(it->first + k) != map.end()) count++;
		}
	}
	return count;
}

int getMinimumDifference_problem::getMinimumDifference(TreeNode * root)
{
	// 23% O(N) O(1)
	if (root == NULL) return minAns;
	getMinimumDifference(root->left);
	if (preValue > 0) minAns = min(minAns, abs(root->val - preValue));
	preValue = root->val;
	getMinimumDifference(root->right);
	return minAns;
}

vector<int> countSmaller_problem::countSmaller(vector<int>& nums)
{
		// 0%
		if (nums.size() == 0) return {};
		vector<int> ans;
		for (int i = 0; i < nums.size() - 1; i++) {
			int count = 0;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] < nums[i]) count++;
			}
			ans.push_back(count);
		}
		ans.push_back(0);
		return ans;
}
