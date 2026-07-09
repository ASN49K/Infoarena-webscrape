#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void get(int a,int b)
{
    while(a!=b)
    {
        if(a>b)a=a-b;
        else b=b-a;
    }
    fout<<a<<endl;
}
int main()
{
    int n,a,b;
    fin>>n;
    for(int i=1;i<=n;++i)
    {
        fin>>a>>b;
        get(a,b);
    }
    return 0;
}
