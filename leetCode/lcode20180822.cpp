#include "lcode20180822.h"
#include<set>


lcode20180822::lcode20180822()
{
}


lcode20180822::~lcode20180822()
{
}

bool containsDuplicate_problem::containsDuplicate(vector<int>& nums)
{
	//map<int, int> countMap;
	//for (int num : nums) {
	//	auto it = countMap.find(num);
	//	if (it == countMap.end()) countMap[num] = 0;
	//	else return true;
	//}
	//return false;
	set<int> setNums;
	for (int num : nums) {
		if (setNums.count(num) == 0) setNums.insert(num);
		else return true;
	}
	return false;
}

bool containsNearbyAlmostDuplicate_problem::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	// |x - nums[i]| <= t ==> x - nums[i] <=t && x - nums[i] >= -t
	set<long> window; // set is ordered automatically 
	for (int i = 0; i < nums.size(); i++) {
		if (i > k) window.erase(nums[i - k - 1]); // keep the set contains nums i j at most k
												  // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
		auto pos = window.lower_bound((long)nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
														  // x - nums[i] <= t ==> |x - nums[i]| <= t    
		if (pos != window.end() && *pos - nums[i] <= t) return true;
		window.insert((long)nums[i]);
	}
	return false;

	//vector<long> window;
	//for (int i = 0; i < nums.size(); i++) {
	//	if (i > k) window.erase(window.begin());
	//	for (long num0 : window) {
	//		if (abs((long)num0 - nums[i]) <= t) return true;
	//	}
	//	window.push_back((long)nums[i]);
	//}
	//return false;
}

bool containsNearbyDuplicate_problem::containsNearbyDuplicate(vector<int>& nums, int k)
{
	set<int> window;
	for (int i = 0; i < nums.size(); i++) {
		if (i > k) window.erase(nums[i - k - 1]);
		if (window.find(nums[i]) != window.end()) return true;
		window.insert(nums[i]);
	}
	return false;
}
