#include <iostream>

int condition(int X)
{
	using namespace std;
	int x, a;
	cout << "�������� ���� �� ��������� �������:\n";
	cout << "1 - ����\n";
	cout << "2 - �����\n";
	cout << "3 - ������\n";
	cout << "4 - �����\n";
	cout << endl;
	cin >> x;

	switch (x)
	{
	case 1:
		a = 1;
		break;
	case 2:
		a = 2;
		break;
	case 3:
		a = 3;
		break;
	case 4:
	default:cout << "���..." << endl;
		a = 4;
		break;
	}
	return a;
}
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	int num = 0;
	int n;
	cout << "������� ����� ����� ������: ";	cin >> n;
	int start = 1;
	int end = n;
	int middle = 0;
	while (start <= end)
	{
		int a = 0;
		middle = (start + end) / 2;
		cout << endl;
		cout << "x = " << middle << endl;
		a = condition(middle);
		if (a == 1)
		{
			start = middle;
			num++;
		}
		if (a == 2)
		{
			end = middle;
			num++;
		}
		if (a == 3)
		{
			cout << "���� ����� " << middle << endl;
			break;
		}
		if (a == 4)
			break;
	}
	cout << "���-�� �����: " << num << endl;
}
