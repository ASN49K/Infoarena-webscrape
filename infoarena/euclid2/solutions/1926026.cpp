#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a,b,r,n;
int main()
{
    fin>>n;
    while (n--)
    {
    fin>>a>>b;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<endl;
    }
}
