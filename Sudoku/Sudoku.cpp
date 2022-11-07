#include<iostream>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

//������ ��������� ��������� ���������
enum OptSwap
{
	OneOpt = 1,
	TwoOpt,
	TreeOpt
};

//������� ������
void PrintArr(int arr[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//������� ���������
void SwapSud(int arr[9][9], int optswap)
{
	int tmp;
	//OneOpt
	if (optswap == OneOpt)
	{
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j]; arr[i][j] = arr[i + 1][j]; arr[i + 1][j] = tmp;
			}
		}
		for (int i = 3; i < 4; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j]; arr[i][j] = arr[i + 1][j]; arr[i + 1][j] = tmp;
			}
		}
		for (int i = 6; i < 7; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j]; arr[i][j] = arr[i + 1][j]; arr[i + 1][j] = tmp;
			}
		}
	}
	//TwoOpt
	else if (optswap == TwoOpt)
	{
		for (int i = 1; i < 2; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j]; arr[i][j] = arr[i + 1][j]; arr[i + 1][j] = tmp;
			}
		}
		for (int i = 4; i < 5; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j]; arr[i][j] = arr[i + 1][j]; arr[i + 1][j] = tmp;
			}
		}
		for (int i = 7; i < 8; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j]; arr[i][j] = arr[i + 1][j]; arr[i + 1][j] = tmp;
			}
		}
	}
	//TreeOpt
	else if (optswap == TreeOpt)
	{
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[0][j]; arr[0][j] = arr[2][j]; arr[2][j] = tmp;
			}
		}
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[3][j]; arr[3][j] = arr[5][j]; arr[5][j] = tmp;
			}
		}
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[6][j]; arr[6][j] = arr[8][j]; arr[8][j] = tmp;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	string path = "Sudoku.txt";
	int optSwap = rand() % 3 + 1;
	int ArrSud[9][9];
	int firstnum = 1;
	int endnum;

	//���������� �������
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			ArrSud[i][j] = firstnum;
			firstnum++;
			endnum = firstnum;
			if (firstnum > 9)
			{
				firstnum = 1;
			}
		}
		//�������� �� ��������
		switch (endnum)
		{
		case 2: firstnum = 5;break;
		case 3: firstnum = 6;break;
		case 4: firstnum = 7;break;
		case 5: firstnum = 8;break;
		case 6: firstnum = 9;break;
		case 10: firstnum = 4;break;
		}

		switch (i)
		{
		case 2: firstnum = 2;break;
		case 5: firstnum = 3;break;
		}
	}

	PrintArr(ArrSud);

	SwapSud(ArrSud, optSwap);

	PrintArr(ArrSud);

	return 0;
}