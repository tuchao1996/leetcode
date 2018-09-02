#include "lcode20180829.h"
#include<algorithm>
#include<set>


lcode20180829::lcode20180829()
{
}


lcode20180829::~lcode20180829()
{
}

vector<vector<int>> imageSmoother_problem::imageSmoother(vector<vector<int>>& M)
{
		// %
		if (M.size() < 1) return { {} };
		vector<vector<int>> ans;
		for (int i = 0; i < M.size(); i++) { vector<int> tmp(M[i].size(), 0); ans.push_back(tmp); }
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M[i].size(); j++) {
				float sum = 0, count = 0;
				for (int I = max(i - 1, 0); I < min(i + 2, int(M.size())); I++) {
					for (int J = max(j - 1, 0); J < min(j + 2, int(M[I].size())); J++) {
						count++;
						sum += M[I][J];
					}
				}
				ans[i][j] = int(sum / count);
			}
		}
		return ans;
}

vector<vector<int>> subsets_problem::subsets(vector<int>& nums)
{
	// %
	if (nums.size() < 1) return { {} };
	int sub_num = pow(2, nums.size());
	vector<vector<int>> ans(sub_num, vector<int>());
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < sub_num; j++) {
			if ((j >> i) & 1) ans[j].push_back(nums[i]);
		}
	}
	return ans;
}

vector<vector<int>> subsetsWithDup_problem::subsetsWithDup(vector<int>& nums)
{
		// 100%
		if (nums.size() < 1) return { {} };
		int sub_num = pow(2, nums.size());
		vector<vector<int>> ans(sub_num, vector<int>());
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < sub_num; j++) {
				if ((j >> i) & 1) ans[j].push_back(nums[i]);
			}
		}
		set<vector<int>> ans2;
		for (int i = 0; i < ans.size(); i++) ans2.insert(ans[i]);
		vector<vector<int>> ans3(ans2.begin(), ans2.end());
		return ans3;
}

vector<vector<int>> subsetsWithDup_problem::subsetsWithDup2(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<int> sub;
	dfs(nums, sub, 0);

	return res;
}

void subsetsWithDup_problem::dfs(vector<int>& nums, vector<int>& sub, int start)
{
	res.push_back(sub);
	for (int i = start; i <nums.size(); i++)
		if (i == start || nums[i] != nums[i - 1]) {
			sub.push_back(nums[i]);
			dfs(nums, sub, i + 1);
			sub.pop_back();
		}
}

