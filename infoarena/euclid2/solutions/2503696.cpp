#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("joben.in");
ofstream fout("joben.out");
int n;
char a[100005], b[100005];

int main()
{
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		int x[30] = { 0 }, y[30] = { 0 };
		fin >> a >> b;
		if (strlen(a) != strlen(b))
			fout << "NU\n";
		else {
			for (int j = 0; a[j]; j++)
			{
				x[a[j] - 'a']++;
				y[b[j] - 'a']++;
			}
			bool bun = true;
			sort(x, x + 27);
			sort(y, y + 27);
			for(int j = 0; j <= 27; j++)
				if(x[j] != y[j])
				{ 
					bun = false;
					break;
				}
			if (bun) fout << "DA\n";
			else fout << "NU\n";
		}
	}
	fin.close();
	fout.close();
	return 0;
}
