#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int rcmmdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return rcmmdc(b, a%b);
}

int main()
{
    int t;
    fin>>t;
    int a, b;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        if(a<b)
            swap(a, b);
        fout<<rcmmdc(a, b)<<endl;
    }
    return 0;
}
