#include <Windows.h>
#include "Hash_Twin_Chain.h"
#include <iostream>
using namespace std;
struct AAA
{
	int key;
	const char* mas;
	const char* number;
	AAA(int k, char* z, char* n)
	{
		key = k;
		mas = z;
		number = n;
	}
	AAA()
	{
		key = 0;
		mas = "";
		number = "";
	}
};
//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->number << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int current_size = 7;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >>current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "Сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {
			AAA* a = new AAA;
			char* str = new char[400];
			char* str1 = new char[400];
			cout << "Введите ключ" << endl;
			cin >> k;
			cin.ignore(32767, '\n');
			a->key = k;
			cout << "Введите номер телефона" << endl;
			cin.getline(str1, 400);
			cout << "Введите ФИО" << endl;
			cin.getline(str, 400);
			a->number = str1;
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "Введите ключ" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "Введите ключ" << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else
			{
				cout << "Первый элемент с данным ключом" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
