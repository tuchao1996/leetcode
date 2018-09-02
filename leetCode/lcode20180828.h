#pragma once
#include<vector>
using namespace std;

class lcode20180828
{
public:
	lcode20180828();
	~lcode20180828();
};

class flipAndInvertImage_problem {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A);
};

class gameOfLife_problem {
public:
	void gameOfLife(vector<vector<int>>& board);
	void gameOfLife2(vector<vector<int>>& board);
};

class setZeroes_problem {
public:
	void setZeroes(vector<vector<int>>& matrix);
};
