#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(a<b)
        swap(a, b);
    int r;
    while(a%b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return b;
}

int rcmmdc(int a, int b)
{
    if(a<b)
        swap(a, b);
    if(b == 0)
        return a;
    else
        return rcmmdc(b, a%b);
}

int main()
{
    int t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        int a, b;
        fin>>a>>b;
        fout<<rcmmdc(a, b)<<endl;
    }
    return 0;
}
