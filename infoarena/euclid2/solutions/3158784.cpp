#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define nmax 16
#define MOD 9901 
#define INF 2123456789
//#define fin cin 
//#define fout cout 

ifstream fin("fisier.in");
ofstream fout("fisier.out");

double A[nmax][nmax], B[nmax][nmax];

int main()
{
	A[1][1] = 1.0 * (sqrt(2) / 2);
	A[1][2] = 1.0 * (sqrt(2) / 2);
	A[2][2] = 1.0 * (sqrt(2) / 2);
	A[2][1] = -1.0 * (sqrt(2) / 2);
	fout << P(A, n);
	fin.close();
	fout.close();
	return 0;
}