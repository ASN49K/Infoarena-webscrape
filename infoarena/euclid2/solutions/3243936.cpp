#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int euclid(int x , int y)
{
    if(y==0)
        return x;
    return euclid(y, x%y);
}
int main()
{
    fin>>n;
    while (n)
        {
            fin>>a>>b;
            fout<<euclid(a,b)<<endl;
            n--;
        }
    return 0;
}
