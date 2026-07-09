#include<bits/stdc++.h>
using namespace std;
int euclid(int a,int b)
{
    while(b)
    {
       int r=a%b;
       a=b;
       b=r;
    }
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,a,b;
    f>>T;
    for(int i=1;i<=T;i++)
        {
            f>>a>>b;

            g<<euclid(a,b)<< " "<<'\n';

        }



}
