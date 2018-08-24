#pragma once
#include<vector>
using namespace std;

class seach
{
public:
	seach(vector<int>& nums, int target);
	~seach();
	bool search();

private:
	vector<int> nums;
	int target;
};

