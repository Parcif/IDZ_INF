//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//#include<iostream>
//#include<math.h>
//
//int main() {
//
//    vector<char> n;
//    vector <vector<char>> h;
//    //VARIABLES
//    char chars[] = { '0', '1', '2', '3' };
//    int password[4]{ 0 };
//
//    //SIZES OF VERIABLES
//    int chars_length = sizeof(chars) / sizeof(char);
//    int password_length = sizeof(password) / sizeof(int);
//
//    //CYCKLE TROUGH ALL OF THE COMBINATIONS
//    for (int i = 0; i < pow(chars_length, password_length); i++) {
//
//        //CYCKLE TROUGH ALL OF THE VERIABLES IN ARRAY
//        for (int i2 = 0; i2 < password_length; i2++) {
//            //IF VERIABLE IN "PASSWORD" ARRAY IS THE LAST VERIABLE IN CHAR "CHARS" ARRRAY
//            if (password[i2] == chars_length) {
//                //THEN INCREMENT THE NEXT VERIABLE IN "PASSWORD" ARRAY
//                password[i2 + 1]++;
//                //AND RESET THE VERIABLE BACK TO ZERO
//                password[i2] = 0;
//            }
//        }
//
//        //PRINT OUT FIRST COMBINATION
//        std::cout << i << ": ";
//        for (int i2 = 0; i2 < password_length; i2++) {
//            cout << chars[password[i2]] << " ";
//            n.push_back(chars[password[i2]]);
//        }
//        h.push_back(n);
//        n.clear();
//        std::cout << "\n";
//
//        //INCREMENT THE FIRST VERIABLE IN ARRAY
//        password[0]++;
//    }
//
//    cout << "\n_______________________________________________________________________\n" << endl;
//
//    for (int i = 0; i < h.size(); i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            cout << h[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//    char x1;
//    char x2;
//    char x3;
//    char x4;
//
//
//    for (int i = 0; i < h.size(); i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            for (int k = 0; k < 4; k++)
//            {
//                for (int p = 0; p < 4; p++)
//                {
//                    for (int x = 0; x < 4; x++)
//                    {
//                        if ((h[i][j] * 1 + h[i][k] * 2 + h[i][p] * 4 + h[i][x] * 8) % 5 == 4)
//                        {
//                            x1 = h[i][j];
//                            x2 = h[i][k];
//                            x3 = h[i][p];
//                            x4 = h[i][x];
//
//                        }
//                    }
//                }
//            }
//        }
//        
//    }
//
//    cout << "\n" << x1 << x2 << x3 << x4 << endl;
//    
//}

#include<iostream>
#include<string>
using namespace std;
string nxt(string s)
{
	string t = s; int i;
	i = s.size() - 1;
	while (i >= 0 && s[i] == '9') { s[i] = '0'; --i; }
	if (i >= 0)t[i]++;
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
int main() {
	int m, x, L, v, i; string s = "", t;
	cin >> x >> m >> L >> v;
	for (i = 0; i < L; ++i)s += '0';
	t = s;
	while (p(t, x, m) != v)
	{
		t = nxt(t);
		if (t == s) { cout << "NO SOLUTION"; return 0; }
	}
	cout << t;
	return 0;
}