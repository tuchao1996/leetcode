#include "lcode20180825.h"
#include<algorithm>


lcode20180825::lcode20180825()
{
}


lcode20180825::~lcode20180825()
{
}

vector<int> findDisappearedNumbers_problem::findDisappearedNumbers(vector<int>& nums)
{
	if (nums.size() < 1) return {};
	// 0%
	//const int n = nums.size();
	//vector<int> ans;
	//for (int i = 0; i < n; i++) ans.push_back(i + 1);
	//sort(nums.begin(), nums.end());
	//for (int i = 0; i < n; i++) {
	//	while (i != 0 && i < n && nums[i] == nums[i - 1]) i++;
	//	ans[nums[i] - 1] = 0;
	//}
	//for (auto it = ans.begin(); it != ans.end(); ) {
	//	if (*it == 0) ans.erase(it);
	//	else it++;
	//}
	//	return ans;

	// 21%
	for (int i = 0; i < nums.size(); i++) {
		int m = abs(nums[i]) - 1;
		nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
	}
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++) if (nums[i] > 0) ans.push_back(i + 1);
	return ans;
}

vector<int> findDuplicates_problem::findDuplicates(vector<int>& nums)
{
	//// 45%
	//vector<int> vec = nums, vec1 = nums;
	//for (int i = 0; i < vec.size(); i++) {
	//	int m = abs(vec[i]) - 1;
	//	vec[m] = -vec[m];
	//}
	//for (int i = 0; i < vec1.size(); i++) {
	//	int m = abs(vec1[i]) - 1;
	//	if (vec1[m] > 0) vec1[m] = -vec1[m];
	//}
	//vector<int> ans;
	//for (int i = 0; i < vec.size(); i++) if (vec[i] > 0 && vec1[i] < 0) ans.push_back(i + 1);
	//return ans;

	// 
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++) {
		int index = abs(nums[i]) - 1;
		if (nums[index] < 0) ans.push_back(index + 1);
		nums[index] = -nums[index];
	}
	return ans;
}

int firstMissingPositive_problem::firstMissingPositive(vector<int>& nums)
{
	//
	for (int i = 0; i < nums.size(); i++) {
		while (0 < nums[i] && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
	}
	for (int i = 0; i < nums.size(); i++) if (nums[i] != i + 1) return i + 1;
	return nums.size() + 1;
}
