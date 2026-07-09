#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int nr;
int main()
{
    fin>>nr;
    long long int a,b,r;
    for(int i=1;i<=nr;i++)
    {
            fin>>a>>b;
            while(b!=0)
            {
                       r=a%b;
                       a=b;
                       b=r;
            }
            fout<<a<<"\n";    
    }
    return 0;
}
