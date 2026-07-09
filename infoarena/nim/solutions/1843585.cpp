#include <bits/stdc++.h>


using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int t,n,x,sum;
    fin>>t;
    while(t--)
    {
        sum=0;
        fin>>n;
        for(int i=0;i<n;++i)
        {
            fin>>x;
            sum^=x;
        }
        if(sum==0)
            fout<<"Nu";
        else
            fout<<"Da";
    }
    return 0;
}
