#include "iostream"
#include <windows.h>
using namespace std;

void outputMass(float[], int);
void inputMass(float[], int);
int FindMaxElementIndex(float[], int);
int FindMinElementIndex(float[], int);
float GetSumElements(float[], int);
float GetMulElements(float[], int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;

	cout << "Введите размер массива: ";
	cin >> size;

	float* mass = new float[size];
	inputMass(mass, size);

	cout << "Массив: " << endl;
	outputMass(mass, size);

	int indexMax = FindMaxElementIndex(mass, size);
	int indexMin = FindMinElementIndex(mass, size);
	cout << "Наибольший элемент массива: mass[" << indexMax << "] = " << mass[indexMax] << endl;
	cout << "Наименьший элемент массива: mass[" << indexMin << "] = " << mass[indexMin] << endl;

	swap(mass[indexMax], mass[indexMin]);

	cout << "Массив после замены: " << endl;
	outputMass(mass, size);

	float sum = GetSumElements(mass, size);
	float mul = GetMulElements(mass, size);

	cout << "Сумма всех элементов массива: " << sum << endl;
	cout << "Произведение всех элементов массива: " << mul << endl;
}

void outputMass(float mass[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << mass[i] << "\t";
	}
	cout << endl;
}

void inputMass(float mass[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << "Mass[" << i << "] = ";
		cin >> mass[i];
	}
	cout << endl;
}

int FindMaxElementIndex(float mass[], int size)
{
	int indexMax = 0;
	for (int i = 0; i < size; i++) {
		if (mass[i] > mass[indexMax]) {
			indexMax = i;
		}
	}
	return indexMax;
}

int FindMinElementIndex(float mass[], int size)
{
	int indexMin = 0;
	for (int i = 0; i < size; i++) {
		if (mass[i] < mass[indexMin]) {
			indexMin = i;
		}
	}
	return indexMin;
}

float GetSumElements(float mass[], int size) {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += mass[i];
	}
	return sum;
}

float GetMulElements(float mass[], int size) {
	float mul = 1;
	for (int i = 0; i < size; i++) {
		mul *= mass[i];
	}
	return mul;
}
