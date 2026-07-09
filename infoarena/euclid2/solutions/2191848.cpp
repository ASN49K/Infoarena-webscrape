#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b;
void cetire()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        while(a!=b)
        {
            if(a<b)
                b-=a;
            else
                a-=b;
        }
        fout<<a<<"\n";
    }
}
int main()
{
    cetire();
    return 0;
}
