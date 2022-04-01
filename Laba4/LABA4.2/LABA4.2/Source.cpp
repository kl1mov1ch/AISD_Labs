#include "Header.h"

using namespace std;
void random_array(int *const array, int N)
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 100;
	}
}
void print_array(int* const array, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << " ";	
	}
}
void sort_array(int* const array, int N)
{
		int i, j, step, tmp;
		for (step = N / 2; step > 0; step /= 2)
			for (i = step; i < N; i++)
			{
				tmp = array[i];
				for (j = i; j >= step; j -= step)
				{
					if (tmp < array[j - step])
						array[j] = array[j - step];
					else
						break;
				}
				array[j] = tmp;
			}
}

void laur_number(int* const array, int N , int won, int num)
{
	for (int i = N -1; i >= 0; i--)
	{
		if (num ==3 )
		{
			break;
		}
		if (array[i] == array[i - 1])
		{
			won++;
		}
		if (array[i] > array[i -1])
		{
			num++;
			won++;
		}
	}
	cout << endl;
	cout << "Победителей: " << won << endl;
}


void main()
{
	int won = 0;
	int num = 0;
	setlocale(LC_ALL, "ru");
	int N;
	cout << "Введите число учасников: "; cin >> N;
	int* array = new int[N];
	random_array(array, N);
	sort_array(array, N);
	print_array(array, N);
	laur_number(array, N, won, num);
}