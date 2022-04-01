#include "stdafx.h"

using namespace std;

void random_price_produit(int *const produit_number, int N)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		produit_number[i] = rand() % 100;
	}
}

void sort_price(int *produit_number, int N)
{
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (i % 2 == 0)
				{
					if (produit_number[i] < produit_number[j])
					{
						swap(produit_number[i], produit_number[j]);
					}
				}
				else
				{
					if (produit_number[i] > produit_number[j])
					{
						swap(produit_number[i], produit_number[j]);
					}
				}
			}
		}
}

void print_price_produit(int* const produit_number, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << produit_number[i] << " ";
	}
}

void sum_price(int* const produit_number, int N, int sum)
{
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			sum += produit_number[i];
		}
	}
	cout <<"—умма: " << sum << endl;
}

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int N;
	int sum = 0;
	cout << "¬ведите количество товаров: "; cin >> N;
	int* produit_number = new int[N];
	random_price_produit(produit_number, N);
	sort_price(produit_number, N);
	print_price_produit(produit_number, N);
	cout << endl;
	sum_price(produit_number, N, sum);
}