#include <bits/stdc++.h>


using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int t,n,sum=0,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            sum^=x;
        }
        if(sum==0)
            fout<<"Nu";
            else
                fout<<"Da";
    }
    return 0;
}
