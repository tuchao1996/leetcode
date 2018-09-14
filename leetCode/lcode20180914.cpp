#include "lcode20180914.h"
#include<algorithm>


lcode20180914::lcode20180914()
{
}


lcode20180914::~lcode20180914()
{
}

int DFS(vector<vector<int>>& grid, int row, int col) {
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size() || grid[row][col] == 0) return 0;
	grid[row][col] = 0;
	return 1 + DFS(grid, row + 1, col) + DFS(grid, row - 1, col) + DFS(grid, row, col - 1) + DFS(grid, row, col + 1);
}

int maxAreaOfIsland_problem::maxAreaOfIsland(vector<vector<int>>& grid)
{
	// 18%
	if (grid.empty()) return 0;
	int ans = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 1) ans = max(ans, DFS(grid, i, j));
		}
	}
	return ans;
}

int islandPerimeter_problem::islandPerimeter(vector<vector<int>>& grid)
{
	// 75%
	int ans = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 1) {
				ans += 4;
				if (i - 1 >= 0) ans -= grid[i - 1][j];
				if (i + 1 < grid.size()) ans -= grid[i + 1][j];
				if (j - 1 >= 0) ans -= grid[i][j - 1];
				if (j + 1 < grid[i].size()) ans -= grid[i][j + 1];
			}
		}
	}
	return ans;
}

int DFS2(vector<vector<int>>& grid, vector<vector<int>>& map, int i, int j) {
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || map[i][j] == 0) return 0;
	map[i][j] = 0;
	int count = 4;
	if (i + 1 < grid.size()) count -= grid[i + 1][j];
	if (i - 1 >= 0) count -= grid[i - 1][j];
	if (j + 1 < grid[i].size()) count -= grid[i][j + 1];
	if (j - 1 >= 0) count -= grid[i][j - 1];
	return count + DFS2(grid, map, i + 1, j) + DFS2(grid, map, i - 1, j) + DFS2(grid, map, i, j - 1) + DFS2(grid, map, i, j + 1);
}

int islandPerimeter_problem::islandPerimeter2(vector<vector<int>>& grid)
{
	// %
	int ans = 0;
	vector<vector<int>> map(grid.begin(), grid.end());
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 1) { 
				ans = DFS2(grid, map, i, j);
				return ans;
			}
		}
	}
}

void DFS3(vector<vector<char>>& grid, int i, int j) {
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') return;
	grid[i][j] = '0';
	DFS3(grid, i - 1, j); DFS3(grid, i + 1, j); DFS3(grid, i, j - 1); DFS3(grid, i, j + 1);
	return;
}

int numIslands_problem::numIslands(vector<vector<char>>& grid)
{
	// 25%
	int ans = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == '1') { DFS3(grid, i, j); ans += 1; }
		}
	}
	return ans;
}
