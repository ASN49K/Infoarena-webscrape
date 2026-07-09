#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n;
int main()
{
    in>>n;
    for(int i=1;i<=n;i++)
    {
       long long a,b;
        in>>a>>b;
        while(b)
        {
            int r;
            r=a%b;
            a=b;b=r;
        }
        out<<a<<"\n";
    }
}
