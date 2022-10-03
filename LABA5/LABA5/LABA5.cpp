#include <iostream>
#include<stack>
#include <string> 
using namespace std;

int main() {
	string s;
	getline(cin, s);
	stack <char> st;

	for (int i = 0; i < s.length(); ++i) {

		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			st.push(s[i]);
		}

		else if (s[i] == ')' && st.top() == '(')
		{
			st.pop();
		}
		else if (s[i] == ')' && st.top() != '(')
		{
			cout << "No";
			return 0;
		}

		else if (s[i] == ']' && st.top() == '[')
		{
			st.pop();
		}
		else if (s[i] == ']' && st.top() != '[') 
		{
			cout << "No";
			return 0;
		}

		else if (s[i] == '}' && st.top() == '{')
		{
			st.pop();
		}
		else if (s[i] == '}' && st.top() != '{') 
		{
			cout << "No";
			return 0;
		}

	}
	if (st.empty())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "no";
	}
		return 0;
}