#pragma once
#include<vector>
using namespace std;

class lcode20180902
{
public:
	lcode20180902();
	~lcode20180902();
};

class dominantIndex_problem {
public:
	int dominantIndex(vector<int>& nums);
};

class maximumSwap_problem {
public:
	int maximumSwap(int num);
	int maximumSwap2(int num);
};

class maxNumber_problem {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);
	vector<int> maxNumber(vector<int> nums, int k);
	vector<int> maxNumber(vector<int> nums1, vector<int> nums2);
};

