#include <iostream>
#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    while(b)
    {
        int r = b%a;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int t;
    f >> t;
    for(int i = 0; i<t; ++i)
    {
        int a, b;
        f >> a >> b;
        fout << cmmdc(a, b) << endl;
    }
    return 0;
}
