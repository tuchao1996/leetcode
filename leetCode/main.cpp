#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<numeric>
#include<unordered_set>
#include<queue>
#include<map>
#include<stack>
#include "floodfill.h"
#include "lcode20180825.h"

using namespace std;
#define test 0

#ifdef test

void stopTimer(double sec) {
	Sleep(sec * 1000);
}

#endif

//
//class SolutiontwoSum {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		int vecSize = nums.size(), i, j;
//		bool flag = false;
//		vector<int> ans;
//		for (i = 0; i < vecSize; i++) {
//			for (j = i + 1; j < vecSize; j++) {
//				if (nums[i] + nums[j] == target) {
//					flag = true;
//					break;
//				}
//			}
//			if (flag == true) {
//				break;
//			}
//		}
//		ans.push_back(i);
//		ans.push_back(j);
//		return ans;
//	}
//};
//
///*
//class Solution {
//public:
//vector<vector<int>> threeSum(vector<int>& nums) {
//
//}
//};
//*/
//class Solution1 {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		vector<vector<int>> ans;
//		vector<int> pair;
//		set<int> condidate;
//		int i, j, index1, index2, index3, eleSize=0;
//		bool flag = false;
//		if (nums.size() == 3) {
//			if (nums[0] + nums[1] + nums[2] == 0) {
//				for (i = 0; i < 3; i++) {
//					pair.push_back(nums[i]);
//				}
//				ans.push_back(pair);
//			}
//			return ans;
//		}
//		else
//		{
//			for(index1 = 0; index1 < nums.size() - 2; index1++) {
//				for (index2 = index1+1; index2 < nums.size() - 1; index2++) {
//					for (index3 = index2 + 1; index3 < nums.size(); index3++) {
//						if (nums[index1] + nums[index2] + nums[index3] == 0) {
//							pair.clear();
//							pair.push_back(nums[index1]);
//							pair.push_back(nums[index2]);
//							pair.push_back(nums[index3]);
//							for (j=0; j < ans.size(); j++) {
//								condidate.clear();
//								condidate.insert(pair.begin(), pair.end());
//								condidate.insert(ans[j].begin(), ans[j].end());
//								if (condidate.size() == 3) {
//									break;
//								}
//							}
//							if (j == ans.size()) {
//								ans.push_back(pair);
//							}
//						}
//					}
//				}
//			}
//			return ans;
//		}
//	}
//};
//
//class Solution2 {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		vector<vector<int>> ans;
//		vector<int> ans_pair;
//		if (nums.size() < 3) {
//			return ans;
//		}
//		sort(nums.begin(), nums.end());
//		int i=0, j=0, k=0;
//		for (i = 0; i < nums.size() - 2; i++) {
//			if (i > 0 && nums[i] == nums[i-1]) {
//				continue;
//			}
//			j = i + 1;
//			k = nums.size() - 1;
//			while (j < k) {
//				if (nums[i] + nums[k] + nums[j] < 0) {
//					++j;
//					while (j < k && nums[j] == nums[j - 1]) {
//						j++;
//					}
//				}
//				else if (nums[i] + nums[k] + nums[j] > 0) {
//					--k;
//					while (j < k && nums[k] == nums[k + 1]) {
//						k--;
//					}
//				}
//				else {
//					ans_pair.clear();
//					ans_pair.push_back(nums[i]);
//					ans_pair.push_back(nums[j]);
//					ans_pair.push_back(nums[k]);
//					ans.push_back(ans_pair);
//					++j;
//					while (j < k && nums[j] == nums[j - 1]) {
//						j++;
//					}
//					--k;
//					while (j < k && nums[k] == nums[k + 1]) {
//						k--;
//					}
//				}
//			}
//		}
//		return ans;
//	}
//};
//
//int func(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	else if (n < 1) {
//		return 0;
//	}
//	else {
//		return func(n - 1) + 3 * (n - 1) ;
//	}
//}
//
//class Solution3 {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (nums.size() == 1) {
//			return nums.size();
//		}
//		else if (nums.size() < 1) {
//			return 0;
//		}
//		else {
//			for (vector<int>::iterator it = nums.begin()+1; it != nums.end(); it++) {
//				if (*it == *(it - 1)) {
//					nums.erase(it);
//					it--;
//				}
//			}
//			return nums.size();
//		}
//
//	}
//};
//
//class Solution4 {
//public:
//	int removeElement(vector<int>& nums, int val) {
//		if (nums.size() == 0)
//			return 0;
//		for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
//			if (*it == val) {
//				nums.erase(it);
//			}
//			else {
//				it++;
//			}
//		}
//		return nums.size();
//	}
//};
//
//class Solution5 {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		if (nums.size() == 0) {
//			return 0;
//		}
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i] == target) {
//				return i;
//			}
//			else if (nums[i] < target) {
//				if (i == nums.size() - 1)
//					return i+1;
//			}
//			else {
//				return i;
//			}
//		}
//	}
//};
//
//// Forward declaration of isBadVersion API.
//bool isBadVersion(int version);
//
//class Solution6 {
//public:
//	int firstBadVersion(int n) {
//		int low, mid, high;
//		low = 1;
//		high = n;
//		while (low < high) {
//			mid = low + (high - low) / 2;
//			if (isBadVersion(mid) == false) {
//				low = mid+1;
//			}
//			else {
//				high = mid;
//			}
//		}
//		return high;
//	}
//};
//
//class Solution7 {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		vector<int> ans;
//		if (nums.size() == 0) {
//			ans.push_back(-1);
//			ans.push_back(-1);
//			return ans;
//		}
//		int low = 0, high = nums.size() - 1, mid = low + (high - low) / 2;
//		while (low < high && nums[mid] != target) {
//			if (nums[mid] == target) {
//				continue;
//			}
//			else if (nums[mid] < target) {
//				low = mid + 1;
//			}
//			else {
//				high = mid - 1;
//			}
//			mid = low + (high - low) / 2;
//		}
//		if (nums[mid] != target) {
//			ans.push_back(-1);
//			ans.push_back(-1);
//			return ans;
//		}
//		else {
//			low = mid;
//			high = mid;
//			if (low != 0) {
//				while (low > 0 && nums[low - 1] == target) {
//					low--;
//				}
//			}
//			if (high != nums.size()-1) {
//				while (high < nums.size()-1 && nums[high + 1] == target) {
//					high++;
//				}
//			}
//		}
//		ans.push_back(low);
//		ans.push_back(high);
//		return ans;
//	}
//};
//
//class Solution0 {
//public:
//	int mySqrt(int x) {
//		if (x < 1) {
//			return 0;
//		}
//		int low = 1, high = x, mid;
//		while (low < high) {
//			mid = low + (high - low) / 2;
//			if (double(mid) * mid < x) {
//				low = mid;
//				if (high - low == 1) {
//					return double(low + 1) * (low + 1) <= x ? low + 1 : low;
//				}
//			}
//			else if (double(mid)*mid > x) {
//				high = mid - 1;
//			}
//			else {
//				return mid;
//			}
//		}
//		if (low == high) {
//			return low;
//		}
//	}
//};
//
//class Solution8 {
//public:
//	int mySqrt(int x) {
//		if (x == 0) return 0;
//		if (x == 1) return 1;
//
//		long temp = x;
//		for (int i = 0; i<32; i++) {
//			temp = (temp >> 1);
//			if (temp*temp <= x)
//				break;
//		}
//
//		while (temp * temp < x) {
//			temp++;
//		}
//
//		int result = (int)(temp * temp == x ? temp : temp - 1);
//		return result;
//	}
//};
//
//class Human
//{
//public:
//	Human():age(10), height(165){}
//	Human(int age, int hight): age(age), height(height){}
//	~Human();
//	int getAge() { return this->age; }
//
//private:
//	const int age;
//	const int height;
//};
//
//Human::~Human() {
//	cout << "Age is " << this->age << endl;
//}
//
//class man : public Human
//{
//public:
//	man() { ; }
//	void setHair(char *x) { strcpy_s(hairColor, x); }
//	char* getHair() { return hairColor; }
//
//private:
//	char hairColor[100];
//};
//
//class Solution9 {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int i, j, sum=0, maxI = 0, maxJ = 0, maxSum=0;
//		if (nums.size() < 1) {
//			return 0;
//		}
//		else if (nums.size() == 1) {
//			return nums[0];
//		}
//		else {
//			maxSum = nums[maxI];
//			for (i = 0; i < nums.size(); i++) {
//				sum = 0;
//				for (j = i; j < nums.size(); j++) {
//					sum += nums[j];
//					if (sum > maxSum) {
//						maxSum = sum;
//						maxI = i;
//						maxJ = j;
//					}
//				}
//			}
//			return maxSum;
//		}
//	}
//};
//
//class Solution10 {
//public:
//
//	int myMax(int x, int y) {
//		return x > y ? x : y;
//	}
//
//	int maxSubArray(vector<int>& nums) {
//		int i, maxSum = 0;
//		int ans = 0;
//		if (nums.size() < 1) {
//			return 0;
//		}
//		maxSum = nums[0];
//		ans = nums[0];
//		for (i = 1; i < nums.size(); i++) {
//			maxSum = myMax(nums[i], nums[i] + maxSum);
//			ans = maxSum > ans ? maxSum : ans;
//		}
//		return ans;
//	}
//};
//
//class Solution11 {
//public:
//	vector<int> plusOne(vector<int>& digits) {
//		int i;
//		for (i = digits.size()-1; i >= 0; i--) {
//			if (digits[i] == 9) {
//				digits[i] = 0;
//			}
//			else {
//				digits[i] += 1;
//				return digits;
//			}
//		}
//		digits.insert(digits.begin(), 1);
//		return digits;
//	}
//};
//
////����ѭ��
//int myMax(int x, int y) {
//	return x > y ? x : y;
//}
//
//int dp(int *weights, int *values, int &maxWeight, int num) {
//	int i, j;
//	vector<vector<int>> f;
//	vector<int> x;
//	for (i = 0; i < num; i++) {
//		f.push_back(x);
//		for (j = 0; j < maxWeight+1; j++) {
//			f[i].push_back(0);
//		}
//	}
//	for (i = 1; i < num; i++) {
//		for (j = maxWeight; j > 0; j--) {
//			if (j >= weights[i]) {
//				f[i][j] = myMax(f[i - 1][j], f[i - 1][j - weights[i]] + values[i]);
//			}
//			else {
//				f[i][j] = f[i - 1][j];
//			}
//		}
//	}
//	return f[num-1][maxWeight];
//}
//
////�ݹ�д��
//
//void dp(vector<vector<int>> &f, int i, int num, int maxWeight, int *weights, int *values) {
//	if (i > num-1) {
//		return;
//	}
//	int j;
//	for (j = maxWeight; j >= 0; j--) {
//		if (j >= weights[i]) {
//			f[i][j] = myMax(f[i - 1][j], f[i - 1][j - weights[i]] + values[i]);
//		}
//		else {
//			f[i][j] = f[i - 1][j];
//		}
//	}
//}
//
//void dp(int m ,int n, int **a, int **d, int **next) {
//	int ans = INFINITE, first = 0;
//	for (int j = n - 1; j >= 0; j++) { // ����
//		for (int i = 0; i < m; i++) {
//			if (j == n - 1) {
//				d[i][j] = a[i][j];
//			}
//			else {
//				int rows[3] = { i, i - 1, i + 1 };
//				if (i == 0) {
//					rows[1] = m - 1;
//				}
//				else if (i == m - 1) {
//					rows[2] = 0;
//				}
//				sort(rows, rows + 3);
//				d[i][j] = INFINITE;
//				for (int k = 0; k < 3; k++) {
//					int v = a[i][j] + d[rows[k]][j + 1];
//					if (v > d[i][j]) {
//						d[i][j] = v;
//						next[i][j] = rows[k];
//					}
//				}
//			}
//			if (j == 0 && d[i][j] < ans) {
//				ans = d[i][j];
//				first = i;
//			}
//		}
//	}
//	printf("%d\n", first + 1);
//	for (int i = next[first][0], j = 1; j < n; j++, i = next[i][j]) {
//		printf("%d\n", i + 1);
//	}
//}
//
//int* subarray(int arr[], int len) {
//	int *dp = new int[len];
//	dp[0] = arr[0];
//	for (int i = 1; i < len; i++) {
//		dp[i] = max(arr[i], arr[i] + dp[i - 1]);
//	}
//	return dp;
//}
//
//void recursive(int arr[], int *dp, int n) {
//	if (n == -1) return;
//	recursive(arr, dp, n - 1);
//	if (n == 0) dp[n] = arr[n];
//	else dp[n] = max(arr[n], arr[n]+dp[n-1]);
//}
//
////��̬�滮˼�� �� �ݹ� �� �ֶ���֮
//
//void package_recursive(int *w, int *v, int dp[][11], int n, int maxW) {
//	if (n == 0) return;
//	package_recursive(w, v, dp, n - 1, maxW);
//	for (int j = 0; j <= maxW; j++) {
//		if (j >= w[n]) {
//			dp[n][j] = max(dp[n - 1][j], dp[n - 1][j - w[n]] + v[n]);
//		}
//		else {
//			dp[n][j] = dp[n][j - 1];
//		}
//	}
//}
//
////�ⷨ1
//class Solution12 {
//public:
//	int maxArea(vector<int>& height) {
//		int max = 0;
//		for (int i = 0, j = height.size() - 1; i < j;) {
//			int heightContainer = height[i] < height[j] ? height[i] : height[j];
//			int volume = (j - i) * heightContainer;
//			max = max > volume ? max : volume ;
//			while (i < j && height[i] <= heightContainer ) i++;
//			while (i < j && height[j] <= heightContainer ) j--;
//		}
//		return max;
//	}
//};
//
////�ⷨ2
//class Solution13 {
//public:
//	int maxArea(vector<int>& height) {
//		int max = 0;
//		for (int i = 0, j = height.size() - 1; i < j;) {
//			int heightContainer = height[i] < height[j] ? height[i] : height[j];
//			int volume = (j - i) * heightContainer;
//			max = max > volume ? max : volume;
//			if (height[i] <= height[j]) {
//				i++;
//			}
//			else {
//				j--;
//			}
//		}
//		return max;
//	}
//};
//
////Trapping rain water 14
//class Solution14 {
//public:
//	int trap(vector<int>& height) {
//		if (height.size() < 2) return 0;
//		int water = 0;
//		vector<int>::iterator maxEleIt = max_element(height.begin(), height.end());
//		for (int i = *maxEleIt; i > 0; i--) {
//			vector<int> h = height;
//			for (int k = 0; k < height.size(); k++) {
//				h[k] = max(height[k]-i+1, 0);
//			}
//			int left = 0;
//			int right = left + 1;
//			while(right < height.size()){
//				for (; left < height.size() && h[left] == 0; left++);
//				for (right = left+1; right < height.size() && h[right] == 0; right++);
//				if (right < height.size()) {
//					water += right - left - 1;
//				}
//				left++;
//			}
//		}
//		return water;
//	}
//};
//
////Trapping rain water suggestion
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		if (height.size() < 2) return 0;
//		int water = 0;
//		int left = 0, right = height.size() - 1;
//		int maxLeft = 0, maxRight = 0;
//		while (left < right){
//			if (height[left] <= height[right]) {
//				if (height[left] >= maxLeft) {
//					maxLeft = height[left];
//				}
//				else {
//					water += maxLeft - height[left];
//				}
//				left++;
//			}
//			else {
//				if (height[right] >= maxRight) {
//					maxRight = height[right];
//				}
//				else {
//					water += maxRight - height[right];
//				}
//				right--;
//			}
//		}
//		return water;
//	}
//};
//
//void snakeArr() {
//	const int N = 100;
//	int arr[N][N];
//	int n, value;
//	int x, y;
//	while (scanf("%d", &n) == 1) {
//		memset(arr, 0, sizeof(arr));
//		value = arr[0][n - 1] = 1;
//		x = 0; y = n - 1;
//		while (value < pow(n, 2)) {
//			while (x + 1 < n && arr[x + 1][y] == 0) arr[++x][y] = ++value;
//			while (y - 1 >= 0 && arr[x][y - 1] == 0) arr[x][--y] = ++value;
//			while (x - 1 >= 0 && arr[x - 1][y] == 0) arr[--x][y] = ++value;
//			while (y + 1 < n && arr[x][y + 1] == 0) arr[x][++y] = ++value;
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << arr[i][j] << "   ";
//			}
//			cout << endl;
//		}
//	}
//}
//
//int myless(char s[], int i, int ans) {
//	int len = strlen(s);
//	for (int j = 0; j < len; j++) {
//		if (s[(i + j) % len] != s[(ans + j) % len]) {
//			return s[(i + j) % len] < s[(ans + j) % len];
//		}
//	}
//	return 0;
//}
//
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& numbers, int target) {
//		vector<int> ans;
//		int left = 0, right = numbers.size() - 1;
//		while (left < right) {
//			int curSum = numbers[left] + numbers[right];
//			if (curSum < target) {
//				left++;
//			}
//			else if (curSum > target) {
//				right--;
//			}
//			else{
//				ans.push_back(left + 1);
//				ans.push_back(right + 1);
//				return ans;
//			}
//		}
//		ans.push_back(0);
//		ans.push_back(0);
//		return ans;
//	}
//};
//
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& numbers, int target) {
//		vector<int> ans;
//		for (int i = 0; i < numbers.size() - 1; i++) {
//			int left = i + 1, right = numbers.size() - 1;
//			while (left <= right) {
//				int mid = left + (right - left) / 2;
//				int curSum = numbers[i] + numbers[mid];
//				if (curSum < target) {
//					left = mid + 1;
//				}
//				else if (curSum > target) {
//					right = mid - 1;
//				}
//				else {
//					ans.push_back(i + 1);
//					ans.push_back(mid + 1);
//					return ans;
//				}
//			}
//		}
//		for (int i = 0; i < 2; i++) {
//			ans.push_back(0);
//		}
//		return ans;
//	}
//};
//
//class Solution {
//public:
//	int threeSumClosest(vector<int>& nums, int target) {
//		if (nums.size() < 3) return NULL;
//		int ans = nums[0] + nums[1] + nums[2];
//		if (ans == target) {
//			return ans;
//		}
//		for (int i = 0; i < nums.size() - 2; i++) {
//			for (int j = i + 1; j < nums.size() - 1; j++) {
//				for (int k = j + 1; k < nums.size(); k++) {
//					int curSum = nums[i] + nums[j] + nums[k];
//					if (abs(curSum - target) < abs(ans - target)) {
//						ans = curSum;
//						if (ans == target) {
//							return ans;
//						}
//					}
//				}
//			}
//		}
//		return ans;
//	}
//};
//
//class Solution {
//public:
//	int threeSumClosest(vector<int>& nums, int target) {
//		if (nums.size() < 3) return accumulate(nums.begin(), nums.end(), 0);
//		sort(nums.begin(), nums.end());
//		int ans = nums[0] + nums[1] + nums[2];
//		if (ans == target) return ans;
//		for (int i = 0; i < nums.size()-2; i++) {
//			if (i > 0 && nums[i] == nums[i - 1]) continue;
//			int j = i + 1;
//			int k = nums.size() - 1;
//			while (j < k) {
//				if (j > i + 1 && nums[j] == nums[j - 1]) { j++; continue; }
//				if (k < nums.size()-1 && nums[k] == nums[k + 1]) { k--; continue; }
//				int curSum = nums[i] + nums[j] + nums[k];
//				if (curSum == target) return curSum;
//				if (abs(curSum - target) < abs(ans - target)) {
//					ans = curSum;
//				}
//				curSum - target > 0 ? k-- : j++;
//			} 
//		}
//		return ans;
//	}
//};

//class Solution {
//public:
//	int threeSumClosest(vector<int>& nums, int target) {
//		vector< vector<int> > vecTriplets;
//		vector<int> triplet(3, 0);
//
//		std::sort(nums.begin(), nums.end());
//
//		int nearest_sum = INT_MAX;
//		int nearest_diff = INT_MAX;
//		size_t lastIndex = nums.size() - 2;
//		size_t j = 0, k = lastIndex + 1;
//		for (int i = 0; i < lastIndex; ++i) {
//			if (i > 0 && nums[i] == nums[i - 1])
//				continue;
//			triplet[0] = nums[i];
//			j = i + 1;
//			k = lastIndex + 1;
//			while (j < k) {
//				if (j > i + 1 && nums[j] == nums[j - 1]) {
//					++j;
//					continue;
//				}
//
//				// Get the current abs closest and update it if needed
//				int sum = nums[j] + nums[k] + nums[i];
//				int diff = std::abs(target - sum);
//				if (sum == target) {
//					return sum;
//				}
//				else {
//					// Check if we have to update the nearest_dif and nearest_sum
//					if (diff < nearest_diff) {
//						nearest_diff = diff;
//						nearest_sum = sum;
//					}
//
//					// Forward pointers
//					if (nums[j] + nums[k] + nums[i] > target) {
//						--k;
//					}
//					else {
//						++j;
//					}
//				}
//			} // while (i < k)
//		} // for (int i)
//		return nearest_sum;
//	}
//};

//class Solution {
//public:

	/*vector<int> cmpString(string str1, string str2) {
		vector<int> ans;
		int count = 0;
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] != str2[i]) {
				count++;
				ans.push_back(i);
			}
		}
		ans.push_back(count);
		return ans;
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> ans;
		vector<string> pair;
		int i;
		for (i = 0; i < wordList.size(); i++) {
			if (memcmp(endWord.data(), wordList[i].data(), endWord.size()) == 0) break;
		}
		if (i == wordList.size()) {
			return ans;
		}
		vector<int> indices(wordList.size(), 1), charUsed(beginWord.size(), 1);
		string tmp(beginWord);
		pair.push_back(tmp);
		for (int j = 0; j < wordList.size(); j++){
			for (i = 0; i < wordList.size(); i++) {
				if (indices[i] == 0) continue;
				vector<int> cmpResult = cmpString(tmp, wordList[i]);
				if (cmpResult.back() == 1) {
					tmp = wordList[i];
					pair.push_back(tmp);
					indices[i] = 0;
					if (tmp == endWord) {
						ans.push_back(pair);
						break;
					}
				}
			}
		}
		return ans;
	}*/

//	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList1) {
//		//very interesting problem
//		//It can be solved with standard BFS. The tricky idea is doing BFS of paths instead of words!
//		//Then the queue becomes a queue of paths.
//		unordered_set<string> wordList;
//		vector<vector<string>> ans;
//		queue<vector<string>> paths;
//		for (int i = 0; i < wordList1.size(); i++) {
//			wordList.insert(wordList1[i]);
//		}
//		paths.push( {beginWord} );
//		int level = 1;
//		int minLevel = INT_MAX;
//
//		//"visited" records all the visited nodes on this level
//		//these words will never be visited again after this level 
//		//and should be removed from wordList. This is guaranteed
//		// by the shortest path.
//		unordered_set<string> visited;
//
//		while (!paths.empty()) { 
//			vector<string> path = paths.front(); // FIFO
//			paths.pop();
//			if (path.size() > level) {
//				//reach a new level
//				for (string w : visited) wordList.erase(w);
//				visited.clear();
//				if (path.size() > minLevel)
//					break; 
//				else
//					level = path.size();
//			}
//			string last = path.back();
//			//find next words in wordList by changing
//			//each element from 'a' to 'z'
//			for (int i = 0; i < last.size(); ++i) {
//				string news = last;
//				for (char c = 'a'; c <= 'z'; ++c) {
//					news[i] = c;
//					if (wordList.find(news) != wordList.end()) {
//						//next word is in wordList
//						//append this word to path
//						//path will be reused in the loop
//						//so copy a new path
//						vector<string> newpath = path;
//						newpath.push_back(news);
//						visited.insert(news);
//						if (news == endWord) {
//							minLevel = level;
//							ans.push_back(newpath);
//						}
//						else
//							paths.push(newpath);
//					}
//				}
//			}
//		}
//		return ans;
//	}
//
//};
//
//class Solution {
//public:
//	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList1) {
//		unordered_set<string> wordList;
//		for (int i = 0; i < wordList1.size(); i++) {
//			wordList.insert(wordList1[i]);
//		}
//		vector<vector<string>> ans;
//		queue<vector<string>> paths;
//		paths.push({ beginWord });
//		int level;
//		int minLevel = INT_MAX;
//		unordered_set<string> visited;
//		while (!paths.empty()) {
//			vector<string> path = paths.front();
//			paths.pop();
//			// �жϵ�ǰ�Ƿ�����Ž�С
//			if (path.size() > level) {
//				for (string w : visited) wordList.erase(w);
//				visited.clear();
//				if (path.size() > minLevel) {
//					break;
//				}
//				else {
//					level = path.size();
//				}
//			}
//			// Ѱ�����Ž�
//			string last = path.back();
//			for (int i = 0; i < last.size(); i++) {
//				string news = last;
//				for (char c = 'a'; c <= 'z'; c++) {
//					news[i] = c;
//					if (wordList.find(news) != wordList.end()) {
//						vector<string> newPath = path;
//						newPath.push_back(news);
//						visited.insert(news);
//						if (news == endWord) {
//							minLevel = level;
//							ans.push_back(newPath);
//						}
//						else {
//							paths.push(newPath);
//						}
//					}
//				}
//			}
//		}
//	}
//};
//
//struct node {
//	int data;
//	node *left;
//	node *right;
//};
//
//void testBFS(){
//	queue<node*> visited, unvisited;
//	node nodes[9];
//	node *current;
//	unvisited.push(&nodes[0]);
//	while (!unvisited.empty()) {
//		current = unvisited.front();
//		if (current->left != NULL) unvisited.push(current->left);
//		if (current->right != NULL) unvisited.push(current->right);
//		visited.push(current);
//
//		cout << current->data << endl; // ���ݴ���
//
//		unvisited.pop();
//	}
//}

//class Solution {
//public:
//	vector<vector<int>> transpose(vector<vector<int>>& A) {
//		//vector<vector<int>> B;
//		//vector<int> oneDB;
//		//for (int j = 0; j < A[0].size(); j++) {
//		//	oneDB.clear();
//		//	for (int i = 0; i < A.size(); i++) {
//		//		oneDB.push_back(A[i][j]);
//		//	}
//		//	B.push_back(oneDB);
//		//}
//		//return B;
//
//		const int ROW = A.size(), COL = A[0].size();
//		int **ans;
//		ans = new int *[COL];
//		for (int i = 0; i < COL; i++) {
//			ans[i] = new int[ROW];
//			memset(ans[i], 0, ROW * sizeof(int));
//		}
//		for (int i = 0; i < ROW; i++) {
//			for (int j = 0; j < COL; j++) {
//				ans[j][i] = A[i][j];
//			}
//		}
//		vector<vector<int>> B;
//		for (int i = 0; i < COL; i++) {
//			vector<int> part;
//			for (int j = 0; j < ROW; j++) {
//				part.push_back(ans[i][j]);
//			}
//			B.push_back(part);
//		}
//		return B;
//	}
//};

// class Solution {
// public:
// 	bool exist(vector<vector<char>>& board, string word) {
// 		bool isPath(vector<vector<char>> board, int i, int j, string word);
// 		if (board.empty()) return false;
// 		for (int i = 0; i < board.size(); i++) {
// 			for (int j = 0; j < board[0].size(); j++) {
// 				if (this->isPath(board, i, j, word)) {
// 					return true;
// 				}
// 			}
// 		}
// 		return false;
// 	}
// 	bool isPath(vector<vector<char>> board, int i, int j, string word) {
// 		if (word.empty()) return true;
// 		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[0] != board[i][j]) return false;
// 		char tmp = board[i][j];
// 		board[i][j] = '#';
// 		word.erase(word.begin());
// 		bool res = isPath(board, i + 1, j, word) || isPath(board, i - 1, j, word) || isPath(board, i, j + 1, word) || isPath(board, i, j - 1, word);
// 		board[i][j] = tmp;
// 		return res;
// 	}
// };

int main() {
	//vector<int> nums = { 4,3,2,7,8,2,3,1 };
	//lcode20180825 *s = new lcode20180825();
	//vector<int> ans = s->findDuplicates(nums);
	//for (int a : ans) cout << a << ' ';
	bool flag = int(float(42) / -6) == float(42) / -6;
	cout << flag << endl;

	system("pause");
	return 0;
}