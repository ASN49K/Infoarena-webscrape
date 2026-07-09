#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a[50][50],i,j;
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
        for(j=1;j<=2;j++)
        fin>>a[i][j];
    for(i=1;i<=n;i++)
        fout<<cmmdc(a[i][1],a[i][2])<<endl;

}
