#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("file.in");
ofstream fout("file.out");

int n,i,a,b,r;

void cmmdc(int a, int b)
{
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<"\n";
}

int main()
{
    fin>>n;
    while(i<n)
    {
        fin>>a>>b;
        cmmdc(a,b);
        i++;
    }
    return 0;
}
