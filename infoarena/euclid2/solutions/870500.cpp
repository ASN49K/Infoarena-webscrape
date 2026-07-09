#include <iostream>
#include<fstream>
using namespace std;
int t,a,b,i;
int euclid(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }
    return 0;
    fout.close();
}
