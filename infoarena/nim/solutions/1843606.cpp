#include <bits/stdc++.h>


using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int sum,t,n,x,j,i;
    fin>>t;
    for( j=1;j<=t;j++)
    {

        fin>>n;
       sum=0;
        for( i=1;i<=n;i++)
        {
            fin>>x;
            sum=sum^x;
        }
        if(sum==0)
            fout<<"Nu\n";
        else
            fout<<"Da\n";
    }
    return 0;
}
