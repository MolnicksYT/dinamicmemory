﻿#include<iostream>
using namespace std;
int** Allocate(const int m, const int n);
void Clear(int** arr, const int m);
void FillRand(int* arr[], const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);
//добавление эл-тов
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
//удаление эл-тов
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* insert(int*& arr, int& n, int index, int value);
/////////////////////////////////////////////////////////////////
///////////////// добавление элементов в конец массива //////////
/////////////////////////////////////////////////////////////////
int** push_row_back(int** arr, int& m, const int n);
int** push_row_front(int** arr, int& m, const int n);

void push_col_back(int** arr, const int m, int& n);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Ввести размер массива : ";cin >> n;
	//Объявление динамического массива:
	int* arr = new int[n];
	/*int s_arr[5];
	cout << sizeof(arr) << endl;//sizeof -возвращает элементы
	cout << sizeof(s_arr) << endl;*/
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << endl;
	cout << "\nВвести добавляемое в конце значения(add): \n"; cin >> value; //значение в конец массива
	arr = push_back(arr, n, value); 
	Print(arr, n);
	cout << "\nВвести добавляемое в начале значения(add): \n"; cin >> value; // значение в начало массива
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "\nудаление с конца значение массива(delete): \n"; // удаление значения с конца массива
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "\nудаление с начала значение массива(delete): \n"; // удаление значения с начала массива
	arr = pop_front(arr, n);
	Print(arr, n);
	delete[] arr;
#endif //DYNAMIC_MEMORY_1
	int m; //строки
	int n; // столбцы3
	cout << "Ввести кол-во строк: "; cin >> m;
	cout << "Ввести кол-во столбцов: "; cin >> n; 
	int** arr = Allocate(m, n);
	//обращение к эл-там массива:
	//FillRand(arr, m, n);
	//Print(arr, m, n);
	/*for (int i = 0;i < m;i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j]<<"\t";
		}
		cout << endl;
	}*/
	///////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////   ИСПОЛЬЗОВАНИЕ МАССИВА /////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	//обращение к элементам

	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << "==" << endl;
	cout << "добавление строки в конец массива: " << endl;
	arr = push_row_back(arr, m, n);
	cout << "Строка добавлена" << endl;
	Print(arr, m, n);
	cout << "Добавление строки в начало массива" << endl;
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "Добавление столбца в конец массива: " << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
	cout << "Вставка элемонтов в опред место массива: " << endl;
	insert;
	Print(arr, m, n);
	
		
	///////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////   УДАЛЕНИЕ МАССИВА /////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	//1) удаление строки двумерного массива:
	for (int i = 0;i < m;i++)
	{
		delete[] arr[i];
	}
	//2) Удаление массива указателей:
	delete[] arr;
	cout << "It's Okey!" << endl;
} 
int** Allocate(const int m, const int n)
{
	// 1) создание массива указателей
	int** arr = new int* [m];
	//2) выделение памяти под строки
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
}
void Clear(int** arr, const int m)
{
	//1) удаление строки двумерного массива:
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100; //* - оператор разыменовывает и возвращает значение по адресу
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t"; //[] - оператор индексирования возвращает значение по индексу
	}
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
{
	//ДОБАВЛЕНИЕ ЗНАЧЕНИЯ В КОНЕЦ МАССИВА
	// 1) создание буферного массива нужного массива (на 1 элемент больше):
	int* buffer = new int[n + 1];
	//2) КОПИРОВАНИЕ ЗНАЧЕНИЯ ИЗ ИСХОДНОГО МАССИВА В БУФЕРНЫЙ:
	for (int i = 0;i < n;i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаление исходного массива
	delete[] arr;
	//4) Подменение адреса старого массива адресом нового массива:
	arr = buffer;
	//после этого в массиве arr появляется элемент, в который можно положить ещё 1 значение
	//5) Вставка добавляемого элемента в конец массива:
	arr[n] = value;
	//6) после того как в массив добавился элемент, кол-во его элементов увеличелось на 1:
	n++;
	//7) MISSION COMPLITE - значение добавлено :-)
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0;i < n;i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0;i < n;i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0;i < n;i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	return buffer;
}
int* insert(int*& arr, int& n, int index, int value)
{
	if (index >= 0 && index <= n)
	{
		int* array = new int[n + 1];
		array[index] = value;
		for (int i = 0; i < index;i++)
		{
			array[i] = arr[i];
		}
		for (int i = index; i < n; i++)
		{
			array[i + 1] = arr[i];
		}
	}
		delete[] arr;
		return arr;
}
int** push_row_back(int** arr, int& m, const int n)
{
	
	//1) создание буферного массива
	int** buffer = new int* [m + 1];
	for (int i = 0;i < m + 1;i++)
	{
		buffer[i] = new int [n] {};
	}
	
	//2) копирование адреса сущеструющих строк в новый массив
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];

		/*for (int i = 0; i < m;i++)
		{
		buffer[i] = new int[n] {}; 
		}
		
		//2) копирование значения в буферный массив
		for (int i = 0; i < m; i++)
		{
		for (int j = 0;j < n;j++)
		{
		buffer[i][j] = arr[i][j];
		}
		}*/
		
		//3) удаление исходного массива указателей
		delete[] arr;
		
		//4) создание последней строки массива:
		buffer[m] = new int [n] {};

		//5) Увеличивание кол-во строк:
		m++;
		
		//6) Возвращаем адрес нового массива на массива
		return buffer;
}
int** push_row_front(int** arr, int& m, const int n)
{
	//1) создание буфферного массива указательей нужного размера
	int** buffer = new int*[m + 1];
	//2) коприрование адресов строк в новый массив:
	for (int i = 0;i < m;i++)
		buffer[i+1] = arr[i];
		//3) удаление исходного массива указателей
		delete[] arr;
	//4) создание нулевой строки массива
	buffer[0] = new int[n] {};
	//5) увеличение кол-ва строк
	m++;
	//6) возвращение нового массива
	return buffer;
}
void push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		//1) создание буферной строки
		int* buffer = new int[n + 1]{};
		//2) копирование исход строки массива в буферную
		for (int j = 0;j < n;j++)buffer[j] = arr[i][j];
		//3) удаление исходной строки
		delete[] arr[i];
		//4) Подминение адреса в масиве указателей на адрес новой строки
		arr[i] = buffer;
	}
	n++;
}