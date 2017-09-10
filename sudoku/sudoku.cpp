#include<iostream>
using namespace std;
int board[9][9];
int N;
void init()//初始化 
{
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			board[i][j] = 0;
		}
	}
	board[0][0]=3;//(2+9)%9+1=3
}
void print()//输出 
{
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int check(int row, int col, int num)//判断是否能放 
{
	for (int i = 0; i<9; i++)//判断列有没相同的 
	{
		if (board[i][col] == num)return 0;
	}
	for (int j = 0; j<9; j++)//判断行有没相同的 
	{
		if (board[row][j] == num)return 0;
	}
	int x = row / 3, y = col / 3;
	x = 3 * x;
	y = 3 * y;
	for (int i = 0; i<3; i++)//检查小九宫格 
	{
		for (int j = 0; j<3; j++)
		{
			if (board[x + i][y + j] == num)return 0;
		}
	}
	return 1;
}
int t = 0;//统计输出了多少数独 
void sudoku(int i, int j)
{
	for (int x = 1; x <= 9; x++)
	{
		if (check(i, j, x) == 1)
		{
			board[i][j] = x;
			if (i == 8 && j == 8)
			{
				print();
				t++;
				if (t >= N) exit(-1);
				return;
			}
			if (j == 8)
			{
				sudoku(i + 1, 0);
			}
			else
			{
				sudoku(i, j + 1);
			}
		}
	}
	board[i][j] = 0;
	return;
}
int main(int argc, char *argv[])
{
	init();
	if (sscanf(argv[2],"%d", &N) == 0)
	{
		cout << "请输入一个数字" << endl;
		return 0;
	}
	else freopen("sudoku.txt", "w", stdout); 
	sudoku(0, 1);
	return 0;
}
