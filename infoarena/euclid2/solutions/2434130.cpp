#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    if(a==b)
        return a;
    else
        while(a!=b)
        if(a>b)
        a=a-b;
    else
        b=b-a;
        return a;
}
int main()
{
    int n,a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    f.close();
    return 0;
}
