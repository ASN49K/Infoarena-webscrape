#include <iostream>
#include <fstream>
using namespace std;
int cmmdc (int a,int b)
{
    int R;
    while (b!=0)
    {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long long i,T,a,b;
    fin >> T;
    for (i=1;i<=T;++i)
    {
        fin >> a >> b;
        fout << cmmdc(a,b) << '\n';
    }
    return 0;
}
