#pragma once
class floodfill
{
public:
	floodfill();
	~floodfill();
	void DFS(int r, int c, int id);
	void act();
private:
	int m, n;
	int idx[1000][1000];
	char pix[1000][1000];
};

