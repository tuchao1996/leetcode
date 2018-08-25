#include "lcode20180811.h"
#include<map>


lcode20180811::lcode20180811()
{
}


lcode20180811::~lcode20180811()
{
}

bool wordPattern_problem::wordPattern(string pattern, string str)
{

	if (pattern.empty()) return false;
	map<char, int> map_pattern;
	map<string, int> map_str;
	map<char, string> map;
	vector<string> s;
	string strPart;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			strPart.push_back(str[i]);
		}
		else {
			s.push_back(strPart);
			strPart.clear();
		}
	}
	s.push_back(strPart);
	if (pattern.size() != s.size()) return false;
	for (int i = 0; i < pattern.size(); i++) {
		if (map.find(pattern[i]) != map.end()) {
			if (map[pattern[i]] != s[i]) {
				return false;
			}
		}
		else
		{
			auto it0 = map.begin();
			for (; it0 != map.end(); it0++) {
				if (it0->second == s[i]) break;
			}
			if (it0 != map.end()) return false;
			else map[pattern[i]] = s[i];
		}
	}
	return true;
}

vector<vector<int>> fourSum_problem::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> ans;
	if (nums.size() < 4) return ans;
	sort(nums.begin(), nums.end());
	const int N = nums.size();
	for (int i = 0; i < nums.size() - 3; ) {
		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) { break; }
		if (nums[i] + nums[N - 1] + nums[N - 2] + nums[N - 3] < target) { i++; continue; }
		for (int j = i + 1; j < nums.size() - 2; ) {
			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) { break; }
			if (nums[i] + nums[j] + nums[N - 1] + nums[N - 2] < target) { j++; continue; }
			int left = j + 1, right = nums.size() - 1;
			while (left < right) {
				int ele_sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (ele_sum == target) {
					ans.push_back({ nums[i], nums[j], nums[left], nums[right] });
					right--;
					while (left < right && nums[right] == nums[right + 1])  right--;
					left++;
					while (left < right && nums[left] == nums[left - 1]) left++;
				}
				else if (ele_sum > target) {
					right--;
					while (left < right && nums[right] == nums[right + 1])  right--;
				}
				else {
					left++;
					while (left < right && nums[left] == nums[left - 1]) left++;
				}
			}
			// remove nums[j] duplicate
			j++;
			while (j < nums.size() - 2 && nums[j] == nums[j - 1]) j++;
		}
		// remove nums[i] duplicate
		i++;
		while (i < nums.size() - 3 && nums[i] == nums[i - 1]) i++;
	}
	return ans;
}
