#include "lcode20180824.h"
#include<unordered_set>
#include<numeric>

lcode20180824::lcode20180824()
{
}


lcode20180824::~lcode20180824()
{
}

int fairCandySwap_problem::vecSum(vector<int> arr)
{
	int ans = 0;
	for (int num : arr) ans += num;
	return ans;
}

vector<int> fairCandySwap_problem::fairCandySwap(vector<int>& A, vector<int>& B)
{
	//if (A.size() < 1 || B.size() < 1) return { 0,0 };
	//vector<int> ans;
	//sort(A.begin(), A.end()); sort(B.begin(), B.end());
	//int diff = vecSum(A) - vecSum(B);
	//if (diff < 0) {
	//	for (int i = 0; i < A.size(); i++) {
	//		auto it = upper_bound(B.begin(), B.end(), A[i]);
	//		while (it != B.end()) {
	//			if (A[i] - *it == diff / 2) return { A[i], *it };
	//			else it++;
	//		}
	//	}
	//}
	//else {
	//	for (int i = 0; i < B.size(); i++) {
	//		auto it = upper_bound(A.begin(), A.end(), B[i]);
	//		while (it != A.end()) {
	//			if (*it - B[i] == diff / 2) return { *it, B[i] };
	//			else it++;
	//		}
	//	}
	//}

	int sA = vecSum(A), sB = vecSum(B);
	for (int a : A) {
		for (int b : B) {
			if (b == a + (sB - sA) / 2) return { a,b };
		}
	}
	int diff = accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0);
	diff /= 2;
	unordered_set<int> st(A.begin(), A.end());
	for (auto x : B)
	{
		if (st.count(x + diff))
		{
			return { x + diff, x };
		}
	}
	return {};
}

int search_problem::search(vector<int>& nums, int target)
{
	// 96%
	if (nums.size() < 1) return -1;
	else if (nums.size() == 1) return nums.back() == target ? 0 : -1;
	int low = 0, high = nums.size() - 1, mid = low + (high - low) / 2;
	while (low < high) {
		mid = low + (high - low) / 2;
		if (nums[mid] < nums[high]) high = mid;
		else if (nums[mid] > nums[high]) low = mid + 1;
	}
	//mid = low;
	//int low0 = 0, high0 = mid - 1;
	//int low1 = mid, high1 = nums.size() - 1;
	//while (low0 <= high0) {
	//	mid = low0 + (high0 - low0) / 2;
	//	if (nums[mid] > target) { high0 = mid - 1; }
	//	else if (nums[mid] < target) { low0 = mid + 1; }
	//	else return mid;
	//}
	//while (low1 <= high1) {
	//	mid = low1 + (high1 - low1) / 2;
	//	if (nums[mid] > target) { high1 = mid - 1; }
	//	else if (nums[mid] < target) { low1 = mid + 1; }
	//	else return mid;
	//}
	//return -1;

	//((rot + (hi + rot)) / 2) % n ==> (rot + hi/2) % n ==> (rot + mid) % n;
	int rot = low;
	low = 0, high = nums.size() - 1;
	while (low <= high) {
		mid = low + (high - low) / 2;
		int realmid = (rot + mid) % nums.size();
		if (nums[realmid] < target) low = mid + 1;
		else if (nums[realmid] > target) high = mid - 1;
		else return realmid;
	}
	return -1;
}

bool search2_problem::search(vector<int>& nums, int target)
{
	if (nums.size() < 1) return false;
	int low = 0, high = nums.size() - 1;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (nums[mid] == target) return true;
		if (nums[mid] > nums[high]) {
			if (nums[mid] > target && nums[low] <= target) high = mid - 1;
			else low = mid + 1;
		}
		else if (nums[mid] < nums[high]) {
			if (nums[mid] < target && nums[high] >= target) low = mid + 1;
			else high = mid - 1;
		}
		else {
			high--;
		}
	}
	return nums[low] == target ? true : false;
}
