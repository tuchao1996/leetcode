#pragma once
#include<vector>
using namespace std;

class lcode20180829
{
public:
	lcode20180829();
	~lcode20180829();
};

class imageSmoother_problem {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M);
};

class subsets_problem {
public:
	vector<vector<int>> subsets(vector<int>& nums);
};

class subsetsWithDup_problem {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums);
	vector<vector<int>> subsetsWithDup2(vector<int>& nums);
private:
	void dfs(vector<int>& nums, vector<int>& sub, int start);
	vector<vector<int>> res;
};

