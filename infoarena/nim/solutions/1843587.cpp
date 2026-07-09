#include <bits/stdc++.h>


using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int t,n,x,sum;
    fin>>t;
    for(int j=1;j<=t;j++)
    {

        fin>>n;
        fin>>sum;
        for(int i=1;i<n;++i)
        {
            fin>>x;
            sum^=x;
        }
        if(sum==0)
            fout<<"Nu"<<endl;
        else
            fout<<"Da"<<endl;
    }
    return 0;
}
