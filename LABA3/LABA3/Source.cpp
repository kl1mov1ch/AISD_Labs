#include <iostream>
#include <ctime>
#include <stdio.h>
#include <thread>

using namespace std;
using namespace chrono;

void randArray(int *const arrayA, int const N)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		 arrayA[i] = rand() % 10;
	}
}

void copyarray(int* const arrayA, int* const arrayCopy, int const N)
{
	for (int i = 0; i < N; i++)
	{
		arrayCopy[i] = arrayA[i];
	}
}

void coutArray( int* const arrayA, int const N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arrayA[i] << " ";
	}
	cout << endl;
}

void bubble(int* const arrayA, int const N)
{

	bool flag = true;
	do
	{	
		flag = true;
		for (int j = 0; j < N - 1; j++) 
		{
			if (arrayA[j] > arrayA[j + 1]) 
			{
				flag = false;
				swap(arrayA[j], arrayA[j + 1]);
			}
		}
	} while (flag == false);

}
void coutbubble(int* const arrayB, int const N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arrayB[i] << " ";
	}
}
void ShellSort(int* const arrayC, int const N)
{
	int i, j, step, tmp;

	for (step = N / 2; step > 0; step /= 2)
		for (i = step; i < N; i++)
		{
			tmp = arrayC[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < arrayC[j - step])
					arrayC[j] = arrayC[j - step];
				else
					break;
			}
			arrayC[j] = tmp;
		}
}
void coutShellSort(int* const arrayC, int const N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arrayC[i] << " ";
	}
}
void selectionSort(int* const arrayD, int const N)
{
	int min, temp; 
	for (int i = 0; i < N - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)  
		{
			if (arrayD[j] < arrayD[min]) 
				min = j;      
		}
		swap(arrayD[i], arrayD[min]);
	}
}
void coutselectionSort(int* const arrayD, int const N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arrayD[i] << " ";
	}
}

void qsortRecursive(int* const arrayE, int const N)
{
	int i = 0;
	int j = N - 1;

	int mid = arrayE[N / 2];

	do 
	{
		while (arrayE[i] < mid)
		{
			i++;
		}

		while (arrayE[j] > mid)
		{
			j--;
		}

		if (i <= j) 
		{
			swap(arrayE[i], arrayE[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) 
	{
		qsortRecursive(arrayE, j + 1);
	}
	if (i < N) 
	{
		qsortRecursive(&arrayE[i], N - i);
	}
}

void coutqsortRecursive(int* const arrayE, int const N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arrayE[i] << " ";
	}
}

void main()
{
	int N;
	cout << "Enter array size: "; cin >> N; ;
	int	*arrayA = new int[N];
	int* arrayB = new int[N];
	int* arrayC = new int[N];
	int* arrayD = new int[N];
	int* arrayE = new int[N];
	randArray(arrayA, N);
	cout << "array A: "; coutArray(arrayA, N);
	cout << "---------------------------------------------------------------------------------" << endl;
	copyarray(arrayA, arrayB, N);
	cout << "array B: "; coutArray(arrayB, N); 
	cout << "---------------------------------------------------------------------------------" << endl;
	copyarray(arrayA, arrayC, N);
	cout << "array C: "; coutArray(arrayC, N);
	cout << "---------------------------------------------------------------------------------" << endl;
	copyarray(arrayA, arrayD, N);
	cout << "array D: "; coutArray(arrayD, N);
	cout << "---------------------------------------------------------------------------------" << endl;
	copyarray(arrayA, arrayE, N);
	cout << "array E: "; coutArray(arrayE, N);
	
	cout << "---------------------------------------------------------------------------------" << endl;
	
	auto bubble_start_time = high_resolution_clock::now();
	bubble(arrayB, N);
	cout << "bubble: "; coutbubble(arrayB, N);
	cout << endl;
	auto bubble_end_time = high_resolution_clock::now();
	duration<float> bubble_time= bubble_end_time - bubble_start_time;
	cout << "BubbleSort time: " << bubble_time.count() << " sec." << endl;
	
	cout << "---------------------------------------------------------------------------------" << endl;
	
	auto Shell_start_time = high_resolution_clock::now();
	ShellSort(arrayC, N);
	cout << "Shell: "; coutShellSort(arrayC, N);
	cout << endl;
	auto Shell_end_time = high_resolution_clock::now();
	duration<float> Shell_time = Shell_end_time - Shell_start_time;
	cout << "ShellSort time: " << Shell_time.count() << " sec." << endl;
	
	cout << "---------------------------------------------------------------------------------" << endl;
	
	auto selection_start_time = high_resolution_clock::now();
	selectionSort(arrayD, N);
	cout << "selectionSort: "; coutShellSort(arrayD, N);
	cout << endl;
	auto selection_end_time = high_resolution_clock::now();
	duration<float> selection_time = selection_end_time - selection_start_time;
	cout << "selectionSort time: " << selection_time.count() << " sec." << endl;
	
	cout << "---------------------------------------------------------------------------------" << endl;
	
	auto qsortRecursive_start_time = high_resolution_clock::now();
	qsortRecursive(arrayE, N);
	cout << "qsortRecursive: "; coutqsortRecursive(arrayE, N);
	cout << endl;
	auto  qsortRecursive_end_time = high_resolution_clock::now();
	duration<float>  qsortRecursive_time = qsortRecursive_end_time - qsortRecursive_start_time;
	cout << "qsortRecursive time: " << qsortRecursive_time.count() << " sec." << endl;
	
	cout << "---------------------------------------------------------------------------------" << endl;
	delete[] arrayA;
	delete[] arrayB;
	delete[] arrayC;
	delete[] arrayD;
	delete[] arrayE;
}
