#include "lcode20180814.h"
#include<algorithm>


lcode20180814::lcode20180814()
{
}


lcode20180814::~lcode20180814()
{
}

int arrayPairSum_problem::arrayPairSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int ans = 0;
	for (int i = 0; i < nums.size(); i += 2) {
		ans += min(nums[i], nums[i + 1]);
	}
	return ans;
}

vector<int> constructArray_problem::constructArray(int n, int k)
{
	vector<int> ans;
	for (int i = 0; i < n; i++) ans.push_back(i + 1);
	while (k > 1) {
		int tmp = ans[0];
		ans.erase(ans.begin());
		int i = 0;
		while (i < ans.size() && ans[i] != tmp + k) i++;
		ans.insert(ans.begin() + i, tmp);
		k -= 2;
	}
	return ans;
}

int findMin_problem::findMin(vector<int>& nums)
{
	int low = 0, high = nums.size() - 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (nums[mid] > nums[high]) low = mid + 1;
		else if (nums[mid] < nums[high]) high = mid;
		else high--;
	}
	return nums[low];
}
