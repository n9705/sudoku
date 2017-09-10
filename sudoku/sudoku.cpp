#include<iostream>
using namespace std;
int board[9][9];
int N;
void init()//��ʼ�� 
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
void print()//��� 
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
int check(int row, int col, int num)//�ж��Ƿ��ܷ� 
{
	for (int i = 0; i<9; i++)//�ж�����û��ͬ�� 
	{
		if (board[i][col] == num)return 0;
	}
	for (int j = 0; j<9; j++)//�ж�����û��ͬ�� 
	{
		if (board[row][j] == num)return 0;
	}
	int x = row / 3, y = col / 3;
	x = 3 * x;
	y = 3 * y;
	for (int i = 0; i<3; i++)//���С�Ź��� 
	{
		for (int j = 0; j<3; j++)
		{
			if (board[x + i][y + j] == num)return 0;
		}
	}
	return 1;
}
int t = 0;//ͳ������˶������� 
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
int main()
{
	freopen("sudoku.txt", "w", stdout);
	init();
	cin >> N;
	sudoku(0, 1);
	return 0;
}