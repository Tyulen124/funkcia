#include <iostream>
#include <Windows.h>

bool VisYear(int year)
{
	return   (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int daysinmonth(int year, int month)
{
	
	int arrday[12]{ 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	if (month == 2 && VisYear(year))
	{
		 return 29;
	}
	return arrday[month - 1];
	
}
void printdifferencedate(int d1, int m1, int y1, int d2, int m2, int y2)
{
	while (true)
	{
		int maxDay1 = daysinmonth(y1, m1);
		if (d1 < 1 || d1 > maxDay1)
		{
			std::cout << "Неверная дата!";
			Sleep(1500);
			system("cls");
			break;
		}
		if (m1 > 12 || m1 < 1)
		{
			std::cout << "Неверная дата!";
			Sleep(1500);
			system("cls");
			break;

		}
		int maxDay2 = daysinmonth(y2, m2);
		if (d2 < 1 || d2 > maxDay2)
		{
			std::cout << "Неверная дата!";
			Sleep(1500);
			system("cls");
			break;
		}
		if (m2 > 12 || m2 < 1)
		{
			std::cout << "Неверная дата!";
			Sleep(1500);
			system("cls");
			break;

		}
		long long sum1 = 0;
		long long sum2 = 0;
		long long diff = 0;
		for (int yr = 1; yr < y1; yr++)
		{
			if (VisYear(yr))
			{
				sum1 += 366;
			}
			else
			{
				sum1 += 365;
			}
		}
		for (int m = 1; m < m1; m++)
		{
			sum1 += daysinmonth(y1, m);
		}
		sum1 += d1;

		for (int yr = 1; yr < y2; yr++)
		{
			if (VisYear(yr))
			{
				sum2 += 366;
			}
			else
			{
				sum2 += 365;
			}
		}
		for (int m = 1; m < m2; m++)
		{
			sum2 += daysinmonth(y2, m);
		}
		sum2 += d2;


		if (sum1 > sum2)
		{
			diff = sum1 - sum2;
		}
		else
		{
			diff = sum2 - sum1;
		}
		std::cout << "Разница между датами: " << diff << " дней";
		break;
	}
	
}
void printArithmeticMean(int name[], int size)
{
	double arithMean = 0;
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += name[i];
	}
	arithMean = sum / size;
	std::cout << "Среднее арифмитическое массива: " << arithMean;
}
void printquatity(int name[], int size)
{
	int sumPlus = 0;
	int sumMinus = 0;
	int sumNull = 0;
	for (int i = 0; i < size; i++)
	{
		if (name[i] == 0)
		{
			sumNull++;
		}
		if (name[i] > 0)
		{
			sumPlus++;
		}
		if (name[i] < 0)
		{
			sumMinus++;
		}
	}

	std::cout << "Количество положительных элементов: " << sumPlus << "\n" << "Количество отрицательных элементов: " << sumMinus << "\n" << "Количество нулевых элементов: " << sumNull;
}

int main() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8); //1251 CP_UTF8
	srand(time(NULL));
	const int size = 5;
	int arr[size]{};
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 11 - 5;
	}
	
	std::cout << "\n";
	printdifferencedate(1, 3, 2025, 1, 3, 2026);
	std::cout << "\n";
	printdifferencedate(1, 1, 2026, 31, 12, 2026);  
	std::cout << "\n";
	printdifferencedate(1, 1, 2020, 1, 1, 2021);
	
	std::cout << "\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	printArithmeticMean(arr, size);
	std::cout << "\n";
	printquatity(arr, size);







}