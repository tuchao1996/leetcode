#include "lcode20180828.h"
#include<algorithm>


lcode20180828::lcode20180828()
{
}


lcode20180828::~lcode20180828()
{
}

vector<vector<int>> flipAndInvertImage_problem::flipAndInvertImage(vector<vector<int>>& A)
{
	// 11%
	for (int i = 0; i < A.size(); i++) {
		reverse(A[i].begin(), A[i].end());
		for (int j = 0; j < A[i].size(); j++) A[i][j] = A[i][j] == 1 ? 0 : 1;
 	}
	return A;
}

void gameOfLife_problem::gameOfLife(vector<vector<int>>& board)
{
	// 100%
	// 0,-1 ==> 0; 1,2 ==> 1
	if (board.size() < 1) return;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			int sum_num = 0;
			for (int I = max(0, i - 1); I < max(int(board.size()), i + 2); I++)
				for (int J = max(0, j - 1); J < max(int(board[I].size()), j + 2); J++)
					if (I != i || J!= j) sum_num += board[I][J] == -1 || board[I][J] == 1 ? 1 : 0;
			if (board[i][j] == 0 && sum_num == 3) board[i][j] = 2;
			else if (board[i][j] == 1 && (sum_num < 2 || sum_num > 3)) board[i][j] = -1;
		}
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			board[i][j] = board[i][j] < 1 ? 0 : 1;
		}
	}
}

void gameOfLife_problem::gameOfLife2(vector<vector<int>>& board)
{
	// 100%
	int m = board.size(), n = m ? board[0].size() : 0;
	for (int i = 0; i<m; ++i) {
		for (int j = 0; j<n; ++j) {
			int count = 0;
			for (int I = max(i - 1, 0); I<min(i + 2, m); ++I)
				for (int J = max(j - 1, 0); J<min(j + 2, n); ++J)
					count += board[I][J] & 1;
			if (count == 3 || count - board[i][j] == 3)
				board[i][j] |= 2;
		}
	}
	for (int i = 0; i<m; ++i)
		for (int j = 0; j<n; ++j)
			board[i][j] >>= 1;
}

void setZeroes_problem::setZeroes(vector<vector<int>>& matrix)
{
	// 4%
	int col0 = 1;
	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
		}
	}
	for (int i = matrix.size() - 1; i >= 0; i--) {
		for (int j = matrix[i].size() - 1; j > 0; j--) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
		}
		if (!col0) matrix[i][0] = 0;
	}
}
