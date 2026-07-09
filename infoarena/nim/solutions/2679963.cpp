#include <iostream>
#include <fstream>
using namespace std;

int main()
{ ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,i,x,rez;
fin>>t;
for(i=1;i<=t;i++)
{
    fin>>n;
    fin>>x;
    rez=x;
    for(int j=1;j<=n-1;j++)
    {
        fin>>x;
        rez=rez^x;
    }
    if(rez==0)
        fout<<"NU"<<endl;
    else
        fout<<"DA"<<endl;
}
    return 0;
}
