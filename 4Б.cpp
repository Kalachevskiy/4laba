#include <iostream>
#include <locale>
using namespace std;
//Найти номер первого вхождения максимального значения в
//последовательность натуральных чисел длины n.
//Последовательность не хранить.


//Входные данные - целое число (элемент последовательности)
//Назначение - определить  индекс первого вхождения максимального элемента последовательности с помощью рекурсии
//Выходные данные - индекс первого вхождения максимального элемента последовательности
int rec(int& totalNumbers, int currIndex = 0, int maxIndex = 0, int maxNumber = 0)
{
	//Возврат максимального индекса если последовательность закончилась
	if (currIndex == totalNumbers)
		return maxIndex + 1;
	int number;
	cout << "Введите число # " << currIndex + 1 << ": ";
	cin >> number;
	//если индекс максимального элемента равен нулю и последовательность  не закончилась, то индекс макс = 1,  и макс число = текущему 
	if (maxIndex == 0)
	{
		maxNumber = number;
	}
	// если текущий элемент больше максимального, текущий присваивается максимальному 
	else if (number > maxNumber)
	{
		maxIndex = currIndex;
		maxNumber = number;
	}
	return rec(totalNumbers, currIndex + 1, maxIndex, maxNumber);
}

//Входные данные - целое число (элемент последовательности)
//Назначение - определить  индекс первого вхождения максимального элемента последовательности с помощью рекурсии
//Выходные данные - индекс первого вхождения максимального элемента последовательности (счет с нуля)
int iter(int n)
{
	int maxNumber;
	int number;
	int index = 0;
	cout << "Введите число # " << 1 << ": ";
	cin >> number;
	maxNumber = number;
	for (int i = 1; i < n; i++)
	{
		cout << "Введите число # " << i + 1 << ": ";
		cin >> number;
		if (number > maxNumber)
		{
			maxNumber = number;
			index = i;
		}
	}
	return index + 1;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите длину последовательности: ";
	cin >> n;
	cout << "Индекс макс числа - " << iter(n) << endl;
	cout << "Индекс макс числа - " << rec(n) << endl;
}