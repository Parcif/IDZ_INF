#include<iostream>
#include<string>
using namespace std;

string next(string s)
{
	string t = s; 
	int i;

	i = s.size() - 1;
	while (i >= 0 && s[i] == '9') 
	{ 
		s[i] = '0';
		--i; 
	}

	if (i >= 0)
		t[i]++;

	return t;
}

int p(string s, int x, int m)
{
	int h = 0, i, r = 1, l = s.size();

	for (i = 0; i < l; ++i)
	{
		h = (h + (s[i] - '0') * r) % m;
		r = (r * x) % m;
	}
	return h;
}

int main() 
{
	int m, x, L, v, i; 	
	string s = "";
	string t;

	cin >> x >> m >> L >> v;

	for (i = 0; i < L; i++)
	{
		s += '0';
	}
	t = s;

	while (p(t, x, m) != v)
	{
		t = next(t);
		if (t == s) 
		{ 
			cout << "NO SOLUTION"; 
			return 0; 
		}
	}
	cout << t;
}