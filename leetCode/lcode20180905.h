#pragma once
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class lcode20180905
{
public:
	lcode20180905();
	~lcode20180905();
};

class numMagicSquaresInside_problem
{
public:
	int numMagicSquaresInside(vector<vector<int>>& grid);
	bool isMagicSquare(vector<vector<int>> subSquare);
};

class rotate_problem
{
public:
	void rotate(vector<vector<int>>& matrix);
};

class RangeModule_problem
{
	// 97%
public:
	void addRange(int left, int right) {
		auto l = mapRange.upper_bound(left), r = mapRange.upper_bound(right);
		if (l != mapRange.begin()) {
			l--;
			if (l->second < left) l++;
		}
		if (l != r) {
			left = min(left, l->first);
			right = max(right, (--r)->second);
			mapRange.erase(l, ++r);
		}
		mapRange[left] = right;
	}

	bool queryRange(int left, int right) {
		auto it = mapRange.upper_bound(left);
		if (it == mapRange.begin() || (--it)->second < right) return false;
		return true;
	}

	void removeRange(int left, int right) {
		auto l = mapRange.upper_bound(left), r = mapRange.upper_bound(right);
		if (l != mapRange.begin()) {
			l--;
			if (l->second < left) l++;
		}
		if (l == r) return;
		int l1 = min(left, l->first), r1 = max(right, (--r)->second);
		mapRange.erase(l, ++r);
		if (l1 < left) mapRange[l1] = left;
		if (r1 > right) mapRange[right] = r1;
	}
private:
	map<int, int> mapRange;
};
