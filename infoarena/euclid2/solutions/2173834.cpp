#include <bits/stdc++.h>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n,a,b;
int euclid(int x,int y)
{
    if(!y) return x;
    else return euclid(y,y%x);
}

int main()
{
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }

}
