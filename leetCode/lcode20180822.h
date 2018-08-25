#pragma once
#include<vector>
using namespace std;

class lcode20180822
{
public:
	lcode20180822();
	~lcode20180822();
};

class containsDuplicate_problem {
	bool containsDuplicate(vector<int>& nums);
};

class containsNearbyAlmostDuplicate_problem {
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
};

class containsNearbyDuplicate_problem {
	bool containsNearbyDuplicate(vector<int>& nums, int k);
};