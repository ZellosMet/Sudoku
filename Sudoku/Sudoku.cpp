#include<iostream>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

//Список выбранных вариантов перемешки
enum OptSwap
{
	OneOpt = 1,
	TwoOpt,
	TreeOpt
};

//Функция вывода
void WriteSud(int arr[9][9])
{
	ofstream Sudoku("Sudoku.txt");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (!(arr[i][j]==0))
			{
				Sudoku << "|" << arr[i][j] << "|";
			}	
			else
			{
				Sudoku << "|  |";
			}
		}
		Sudoku << endl << "------------------------" << endl;
	} 
}

//Функция перемешки
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

		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][0];arr[i][0] = arr[i][2];arr[i][2] = tmp;
			}

		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][3];arr[i][3] = arr[i][5];arr[i][5] = tmp;
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][6];arr[i][6] = arr[i][8];arr[i][8] = tmp;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j];
				arr[i][j] = arr[i + 3][j];
				arr[i + 3][j] = tmp;
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
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][0];arr[i][0] = arr[i][1];arr[i][1] = tmp;
			}

		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][3];arr[i][3] = arr[i][4];arr[i][4] = tmp;
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][6];arr[i][6] = arr[i][7];arr[i][7] = tmp;
			}
		}
	
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j];
				arr[i][j] = arr[i + 6][j];
				arr[i + 6][j] = tmp;
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
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][1];arr[i][1] = arr[i][2];arr[i][2] = tmp;
			}

		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][4];arr[i][4] = arr[i][5];arr[i][5] = tmp;
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 1; j++)
			{
				tmp = arr[i][7];arr[i][7] = arr[i][8];arr[i][8] = tmp;
			}
		}
		
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				tmp = arr[i][j];
				arr[i][j] = arr[i + 3][j];
				arr[i + 3][j] = tmp;
			}
		}
	}
}

//Функция шифрования
void PazzSud(int arr[9][9])
{
	int cntPazz = 0;
	int cntZer = 0;
	int i, j;
	i = j = 0;

	while (!(cntPazz==40))
	{
		i = rand() % 9;
		j = rand() % 9;
		if (!(arr[i][j] == 0))
		{
			arr[i][j] = 0;
			cntPazz++;
		}
	}	
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int optSwap = rand() % 3 + 1;
	int ArrSud[9][9];
	int firstnum = 1;
	int endnum;

	//Заполнение матрици
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
		//Проверка на смещение
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
	
	SwapSud(ArrSud, optSwap);

	PazzSud(ArrSud);

	WriteSud(ArrSud);

	return 0;
}