#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main()
{
	char pat[500];
	string str;
	char npat[500];
	int n = 0, i = 0, j = 0;
	cout << "input 0 to quit" << endl;
	while (1)
	{
		memset(npat, '\0', sizeof(npat));
		cout << "please input a sentence:";
		cin.getline(pat, 500);
		i = 0, j = 0;
		str = pat;
		n = str.length();
		for (i = 0; i < n; i++)
		{
			if (pat[i] >= 'a' && pat[i] <= 'z')
			{
				pat[i] = pat[i] - 32; //英文統一成大寫
			}
			if ((pat[i] >= 'A' && pat[i] <= 'Z') || (pat[i] >= '0' && pat[i] <= '9')) //去除標點符號
			{
				npat[j] = pat[i];
				j++;
			}
		}
		str = npat;
		n = str.length();
		if (pat[0] == '0' && n == 1)
		{
			exit(0);
		}
		for (i = 0; i < n / 2; i++)
		{
			if (npat[i] != npat[n - i - 1])
			{
				cout << "It Is Not a Palindrome!" << endl;
				n = 0;
			}
		}
		if (n == 0)
		{
			continue;
		}
		cout << "It Is a Palindrome!" << endl;
	} //while
	return 0;
} //main
