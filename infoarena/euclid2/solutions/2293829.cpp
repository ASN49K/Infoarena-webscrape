#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int a,b,T;
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a;
        fin>>b;
        fout<<euclid(a,b)<<endl;
    }

    return 0;
}
