#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
void euclid(int a , int b)
{
    if(b==0) cout<<a<<"\n";
    else euclid(b , a % b );
}
int main()
{
    fin>>n;
    while (n)
        {
            fin>>a>>b;
            euclid(a,b);
            n--;
        }
    return 0;
}
