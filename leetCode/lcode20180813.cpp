#include "lcode20180813.h"
#include<algorithm>


lcode20180813::lcode20180813()
{
}


lcode20180813::~lcode20180813()
{
}

string addBinary_problem::addBinary(string a, string b)
{

	int maxLength = a.size() > b.size() ? a.size() : b.size();
	vector<int> aa(maxLength, 0), bb(maxLength, 0);
	string aTmp(a), bTmp(b);
	for (int i = maxLength - 1; i >= maxLength - int(a.size()); i--) {
		aa[i] = aTmp.back() == '1' ? 1 : 0;
		aTmp.pop_back();
	}
	for (int i = maxLength - 1; i >= maxLength - int(b.size()); i--) {
		bb[i] = bTmp.back() == '1' ? 1 : 0;
		bTmp.pop_back();
	}
	string ans;
	int tmp = 0;
	for (int i = maxLength - 1; i >= 0; i--) {
		int last = (aa[i] + bb[i] + tmp) % 2;
		ans.insert(ans.begin(), '0' + (last));
		tmp = aa[i] + bb[i] + tmp > 1 ? 1 : 0;
	}
	if (tmp == 1) {
		ans.insert(ans.begin(), '0' + (tmp));
	}
	return ans;
}

int arrayNesting_problem::arrayNesting(vector<int>& nums)
{

	vector<int> used(nums.size(), 0); // 若循环过程接触，则跳过，因为是同一个循环。
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (!used[i]) {
			int index = nums[i], count = 0;
			do {
				count++;
				used[index] = 1;
				index = nums[index];
			} while (index != nums[i]);
			ans = max(ans, count);
		}
	}
	return ans;
}

int smallestDistancePair_problem::smallestDistancePair(vector<int>& nums, int k)
{

	//vector<int> distances;
	//sort(nums.begin(), nums.end());
	//for (int i = 0; i < nums.size() - 1; i++) {
	//	for (int j = i + 1; j < nums.size(); j++) {
	//		distances.push_back(nums[j] - nums[i]);
	//	}
	//}
	//sort(distances.begin(), distances.end());
	//return distances[k - 1];

	sort(nums.begin(), nums.end());
	int low = 0;
	int high = nums.back() - nums[0];
	while (low < high) {
		int mid = low + (high - low) / 2;
		int count = 0;
		for (int right = 1, left = 0; left < nums.size() - 1; left++) {
			//while ( right < nums.size() && nums[right] - nums[left] <= mid) right++;
			//count += right - left -1;
			int i = left + 1, j = nums.size() - 1;
			while (i < j) {
				int midIJ = i + (j - i) / 2;
				if (nums[midIJ] - nums[left] <= mid) i = midIJ + 1;
				else j = midIJ;
			}
			count += i - left;
		}
		if (count >= k) high = mid;
		else low = mid + 1;
	}
	return low;
}
