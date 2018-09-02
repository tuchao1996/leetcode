#pragma once
#include<vector>
using namespace std;

class lcode20180831
{
public:
	lcode20180831();
	~lcode20180831();
};

class findPairs_problem {
public:
	int findPairs(vector<int>& nums, int k);
	int findPairs2(vector<int>& nums, int k);
};


//*
//* Definition for a binary tree node.
//* struct TreeNode {
//*     int val;
//*     TreeNode *left;
//*     TreeNode *right;
//*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//* };
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class getMinimumDifference_problem {
public:
	int getMinimumDifference(TreeNode* root);
	getMinimumDifference_problem(): minAns(INT_MAX), preValue(-1) {}
private:
	int minAns;
	int preValue;
};

class countSmaller_problem {
public:
	vector<int> countSmaller(vector<int>& nums);
};

