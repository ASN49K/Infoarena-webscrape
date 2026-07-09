#include <bits/stdc++.h>


using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        sum=0;
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
