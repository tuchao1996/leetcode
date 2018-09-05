#include "lcode20180905.h"
#include<unordered_set>
#include<numeric>
#include<algorithm>

lcode20180905::lcode20180905()
{
}


lcode20180905::~lcode20180905()
{
}

int numMagicSquaresInside_problem::numMagicSquaresInside(vector<vector<int>>& grid)
{
		// 2%
		if (grid.size() < 3 || grid[0].size() < 3) return 0;
		int ans = 0;
		for (int i = 0; i < grid.size() - 3 + 1; i++) {
			for (int j = 0; j < grid[i].size() - 3 + 1; j++) {
				vector<vector<int>> subSquare;
				for (int row = 0; row < 3; row++) { vector<int> x; for (int col = 0; col < 3; col++) x.push_back(grid[i + row][j + col]); subSquare.push_back(x); }
				if (isMagicSquare(subSquare)) ans += 1;
			}
		}
		return ans;
}

bool numMagicSquaresInside_problem::isMagicSquare(vector<vector<int>> subSquare)
{
	//
	unordered_set<int> setArr;
	for (int i = 0; i < subSquare.size(); i++) {
		for (int j = 0; j < subSquare[i].size(); j++) {
			if (1 <= subSquare[i][j] && subSquare[i][j] <= 9) {
				setArr.insert(subSquare[i][j]);
				if (setArr.size() < i * 3 + j + 1) return false;
			}
			else return false;
		}
	}
	int total = accumulate(subSquare[0].begin(), subSquare[0].end(), 0);
	for (int i = 1; i < subSquare.size(); i++) {
		if (total != accumulate(subSquare[i].begin(), subSquare[i].end(), 0)) return false;
	}
	for (int i = 0; i < subSquare.size(); i++) {
		int sumCol = 0;
		for (int j = 0; j < subSquare[i].size(); j++) {
			sumCol += subSquare[j][i];
		}
		if (sumCol != total) return false;
	}
	if (subSquare[0][0] + subSquare[1][1] + subSquare[2][2] != total || subSquare[0][2] + subSquare[1][1] + subSquare[2][0] != total) return false;
	return true;
}

void rotate_problem::rotate(vector<vector<int>>& matrix)
{
	// 100%
	if (matrix.size() == 0) return;
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < i; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}
