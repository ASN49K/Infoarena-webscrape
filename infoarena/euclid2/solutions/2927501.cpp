#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");


int euclid(int a,int b)
{
    while(b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    return a;
}
void readsolve()
{
    int t;
   f>>t;
  cin>>t;
    while(t)
    {
        int a,b;
       f>>a>>b;
       g<<euclid(a,b)<<'\n';

        t--;
    }
}

int main()
{
    readsolve();
}
