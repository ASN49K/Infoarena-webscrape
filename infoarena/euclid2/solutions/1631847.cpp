#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("ciur.in");
ofstream fout("ciur.out");
int main()
{
    bool not_prim[2000003]={0};
    int i,n,contor=0;
    fin>>n;
    for(i=2;i<=n;i++)
        if(not_prim[i]==false)
    {
        for(int j=2*i;j<=n;j+=i)
        not_prim[j]=true;
        contor++;
    }
    fout<<contor;
    return 0;
}
