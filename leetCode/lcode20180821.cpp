#include "lcode20180821.h"
#include<stack>


lcode20180821::lcode20180821()
{
}


lcode20180821::~lcode20180821()
{
}

bool canPlaceFlowers_problem::canPlaceFlowers(vector<int>& flowerbed, int n)
{

	//for (int i = 0; i < flowerbed.size(); i++) {
	//	while (i < flowerbed.size() && flowerbed[i] == 1) i++;
	//	if (i >= flowerbed.size() || !n) break;
	//	if (i == 0) {
	//		if (flowerbed[i + 1] == 0) {
	//			n--;
	//			i++;
	//		}
	//	}
	//	else if (i == flowerbed.size() - 1) {
	//		if (flowerbed[i - 1] == 0) {
	//			n--;
	//			i++;
	//		}
	//	}
	//	else {
	//		if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1]) {
	//			n--;
	//			i++;
	//		}
	//	}
	//	if (!n) break;
	//}
	//if (!n) return true;
	//else return false;

	for (int i = 0; i < flowerbed.size(); i++) {
		if (n == 0) return true;
		while (i < flowerbed.size() && flowerbed[i] == 1) i++;
		if (i >= flowerbed.size()) break;
		if ((i == 0 || !flowerbed[i - 1]) && (i == flowerbed.size() - 1 || !flowerbed[i + 1])) {
			flowerbed[i] = 1;
			n--;
			i++;
		}
	}
	return n == 0;
}

int findPoisonedDuration_problem::findPoisonedDuration(vector<int>& timeSeries, int duration)
{
	if (timeSeries.size() < 1) return 0;
	int ans = 0;
	for (int i = 0; i < timeSeries.size(); i++) {
		if (i < timeSeries.size() - 1) ans += timeSeries[i + 1] - timeSeries[i] >= duration ? duration : timeSeries[i + 1] - timeSeries[i];
		else ans += duration;
	}
	return ans;
}

vector<int> asteroidCollision_problem::asteroidCollision(vector<int>& asteroids)
{
	//int pos = -1, neg = -1;
	//do {
	//	pos = -1, neg = -1;
	//	for (int i = 0; i < asteroids.size() - 1; i++) {
	//		if (asteroids[i] > 0 && asteroids[i + 1] < 0) {
	//			pos = i;
	//			neg = i + 1;
	//		}
	//	}
	//	if (pos == -1) break;
	//	if (asteroids[pos] > -asteroids[neg]) {
	//		asteroids.erase(asteroids.begin() + neg);
	//	}
	//	else if (asteroids[pos] < -asteroids[neg]) {
	//		asteroids.erase(asteroids.begin() + pos);
	//	}
	//	else {
	//		asteroids.erase(asteroids.begin() + pos);
	//		asteroids.erase(asteroids.begin() + pos);
	//	}
	//} while (pos != -1 && neg != -1 && asteroids.size());
	//vector<int> ans;
	//for (int num : asteroids) {
	//	if (num) ans.push_back(num);
	//}
	//return ans;

	//stack<int> ans;
	//for (int a : asteroids) {
	//	if (ans.empty()) {
	//		ans.push(a);
	//	}
	//	else {
	//		if (ans.top() > 0 && a < 0) {
	//			bool flag;
	//			while (ans.top() > 0 && a < 0) {
	//				flag = false;
	//				if (abs(ans.top()) < abs(a)) {
	//					ans.pop();
	//					if (ans.empty()) {
	//						ans.push(a);
	//						break;
	//					}
	//				}
	//				else if (abs(ans.top()) == abs(a)) {
	//					ans.pop();
	//					break;
	//				}
	//				else break;
	//				flag = true;
	//			}
	//			if (flag) ans.push(a);
	//		}
	//		else ans.push(a);
	//	}
	//}
	//vector<int> answer(ans.size(), 0);
	//for (int i = answer.size() - 1; i >= 0; i--) {
	//	answer[i] = ans.top();
	//	ans.pop();
	//}
	//return answer;

	//class Solution(object) :
	//	def asteroidCollision(self, asteroids) :
	//	ans = []
	//	for new in asteroids :
	//while ans and new < 0 < ans[-1] :
	//	if ans[-1] < -new :
	//		ans.pop()
	//		continue
	//		elif ans[-1] == -new :
	//		ans.pop()
	//		break
	//	else:
	//ans.append(new)
	//	return ans

	//vector<int> s; // use vector to simulate stack.
	//for (int i = 0; i < asteroids.size(); i++) {
	//	if (asteroids[i] > 0 || s.empty() || s.back() < 0) // a[i] is positive star or a[i] is negative star and there is no positive on stack
	//		s.push_back(asteroids[i]);
	//	else if (s.back() <= -asteroids[i]) { // a[i] is negative star and stack top is positive star
	//		if (s.back() < -asteroids[i]) i--; // only positive star on stack top get destroyed, stay on i to check more on stack.
	//		s.pop_back(); // destroy positive star on the frontier;
	//	} // else : positive on stack bigger, negative star destroyed.
	//}
	//return s;

	stack<int> ans;
	for (int i = 0; i < asteroids.size(); i++) {
		if (asteroids[i] > 0 || ans.empty() || ans.top() < 0) ans.push(asteroids[i]);
		else if (-asteroids[i] >= ans.top()) {
			if (-asteroids[i] > ans.top()) i--;
			ans.top();
		}
	}
	vector<int> answer(ans.size(), 0);
	for (int i = answer.size() - 1; i >= 0; i--) {
		answer[i] = ans.top();
		ans.pop();
	}
	return answer;
}
