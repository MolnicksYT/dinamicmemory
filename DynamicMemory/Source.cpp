#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
#define DYNAMIC_MEMORY_1

#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������ ������ ������� : ";cin >> n;
	int* arr = new int[n];
	cout << arr << endl;
	FillRand(arr, n);
	Print(arr, n);
	int brr[5];
	cout << brr << endl;
	FillRand(arr, 5);
	Print(arr, 5);
	cout << endl;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100; //* - �������� �������������� � ���������� �������� �� ������
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t"; //[] - �������� �������������� ���������� �������� �� �������
	}
}