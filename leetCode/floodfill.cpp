#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "floodfill.h"
#include "cstdio"
#include<cstring>
#include<iostream>
using namespace std;

floodfill::floodfill() {

}


floodfill::~floodfill()
{
}

void floodfill::DFS(int r, int c, int id) {
	if (r < 0 || r >= m || c < 0 || c >= n) return;
	if (idx[r][c] > 0 || pix[r][c] != '@') return;
	idx[r][c] = id;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i != 0 || j != 0) DFS(r + i, c + j, id);
		}
	}
}

void floodfill::act() {
	while (scanf("%d%d", &m, &n) == 2 && m && n) {
		for (int i = 0; i < m; i++) scanf("%s", pix[i]);
		memset(idx, 0, sizeof(idx));
		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (idx[i][j] == 0 && pix[i][j] == '@') DFS(i, j, ++count);
			}
		}
		cout << count << endl;
	}
}