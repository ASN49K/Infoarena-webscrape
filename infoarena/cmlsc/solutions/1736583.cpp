#include <iostream>
#include <stack>
#include <iostream>
#include <fstream>
#define max(a, b) ( (a) > (b) ? (a) : (b) )
using namespace std;

unsigned short dyn[1025][1025];
unsigned short str1[1024], str2[1024];
unsigned short len1, len2, max = 0;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
	fin >> len1 >> len2;

	for (int i = 0; i < len1; i++)
		fin >> str1[i];

	for (int j = 0; j < len2; j++)
		fin >> str2[j];

	for (int i = 0; i < len1; i++)
		for (int j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
				dyn[i+1][j+1] = dyn[i][j] + 1;
			else
				dyn[i+1][j+1] = max(dyn[i+1][j], dyn[i][j+1]);
		}

	fout << dyn[len1][len2] << '\n';

	int i = len1, j = len2;

	stack<short> solution;
	while (i != 0 && j != 0)
	{
		int next = max(max(dyn[i - 1][j - 1], dyn[i][j - 1]), max(dyn[i - 1][j - 1], dyn[i - 1][j]));
		if (next == dyn[i - 1][j - 1])
		{
			if(next != dyn[i][j])
				solution.push(str1[i - 1]);
			i--;
			j--;
		}
		else if(next == dyn[i-1][j])
		{
			i--;
		}
		else if(next == dyn[i][j-1])
		{
			j--;
		}
	}
/*
	cout << "X   ";
	for (int i = 0; i < len2; i++)
		cout << str2[i] << ' ';
	cout << endl;
	for (int i = 0; i <= len1; i++)
	{
		if (i >= 1)
			cout << str1[i - 1] << " ";
		else
			cout << "  ";
		for (int j = 0; j <= len2; j++)
			cout << dyn[i][j] << ' ';
		cout << endl;
	}
	*/
	while(!solution.empty())
	{
		fout << solution.top() << ' ';
		solution.pop();
	}
}