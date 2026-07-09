#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (int a, int b)
{
    int r;
    while (b) {
        r=a%b;
        a=b;
        b=r;
            }
            return a;
}
int n, a, b;
int main()
{
	fin >> n;
	for (int i=1; i<=n; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a , b) << "\n";
    }
}
