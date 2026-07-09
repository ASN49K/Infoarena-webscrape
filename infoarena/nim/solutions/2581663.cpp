#include <bits/stdc++.h>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int t,n;

int main()
{
    in>>t;

    while(t--)
    {
        in>>n;
        int xsum=0;

        for(int i=1,val;i<=n;i++)
        {
            in>>val;
            xsum^=val;
        }

        if(xsum!=0)
            out<<"DA\n";
        else
            out<<"NU\n";
    }

    return 0;
}
