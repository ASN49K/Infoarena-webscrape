#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,a,b;
int cmmdc(int a,int b)
{
    while(a!=b)
        if(a>b)a=a-b;
        else b=b-a;
        return a;
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
        {fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
        }

}
