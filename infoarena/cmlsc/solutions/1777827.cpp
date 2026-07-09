 #include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <vector>
#define maxim(a,b) ((a>b)?a:b)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	ifstream fin;
	fin.open("cmlsc.in");
	ofstream fout;
	fout.open("cmlsc.out");
	int n,m,bst,k[1025];
	fin >> n >> m;
	int a[1025],b[1025];
	int D[1026][1025];
	for (int i=1;i<=m;i++)
	{
		fin >> a[i];
	//	cout << a[i] << endl;
	}

	for(int i=1;i<=n;i++)
	{
		fin >> b[i];
	}

	for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        if (a[i] == b[j])
            D[i][j] = 1+D[i-1][j-1];
        else
            D[i][j] = maxim(D[i-1][j],D[i][j-1]);

    int i,j;
    for (i=m,j=n;i;)
    if (a[i] == b[j])
        k[++bst] = a[i], --i,--j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

	fout << bst << "\n";
	for (int i=bst;i;--i)
	{
		fout << k[i] << " ";
		//cout << b[i] << " ";
	}

	//cout << n << m;
	fin.close();
	fout.close();
	return 0;
}
