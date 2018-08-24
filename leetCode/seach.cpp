#include "seach.h"


seach::seach(vector<int>& nums, int target)
{
	for (int i = 0; i < nums.size(); i++) this->nums.push_back(nums[i]);
	this->target = target;
}

seach::~seach()
{
}

bool seach::search()
{
	if (nums.size() < 1) return false;
	int low = 0, high = nums.size() - 1;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (nums[mid] == target) return true;
		if (nums[mid] > nums[high]) {
			if (nums[mid] > target && nums[low] <= target) high = mid - 1;
			else low = mid + 1;
		}
		else if (nums[mid] < nums[high]) {
			if (nums[mid] < target && nums[high] >= target) low = mid + 1;
			else high = mid - 1;
		}
		else {
			high--;
		}
	}
	return nums[low] == target ? true : false;
}
