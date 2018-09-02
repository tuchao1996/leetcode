#include "lcode20180902.h"
#include<algorithm>
#include<unordered_map>
#include<string>

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
		// 20%
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

int maximumSwap_problem::maximumSwap2(int num)
{
	// 20%
	string n = to_string(num);
	int len = n.length();
	vector<int> last(10, 0);
	for (int i = 0; i < len; i++) last[n[i] - '0'] = i;
	for (int i = 0; i < len; i++) {
		for (int j = 9; j > n[i] - '0'; j--) {
			if (last[j] > i) {
				swap(n[last[j]], n[i]);
				return stol(n, NULL, 10);
			}
		}
	}
	return num;
}

vector<int> maxNumber_problem::maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
	int n1 = nums1.size(), n2 = nums2.size();
	vector<int> best;
	for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1)
		best = max(best, maxNumber(maxNumber(nums1, k1),
			maxNumber(nums2, k - k1)));
	return best;
}

vector<int> maxNumber_problem::maxNumber(vector<int> nums, int k)
{
	int drop = nums.size() - k;
	vector<int> out;
	for (int num : nums) {
		while (drop && out.size() && out.back() < num) {
			out.pop_back();
			drop--;
		}
		out.push_back(num);
	}
	out.resize(k);
	return out;
}

vector<int> maxNumber_problem::maxNumber(vector<int> nums1, vector<int> nums2)
{
	vector<int> out;
	while (nums1.size() + nums2.size()) {
		vector<int>& now = nums1 > nums2 ? nums1 : nums2;
		out.push_back(now[0]);
		now.erase(now.begin());
	}
	return out;
}
