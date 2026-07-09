#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b, c;
int main()
{
    int i;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        if(a<b)swap(a,b);
        while(b)
        {
            b=a%b;
            a=b;
            b=c;
        }
        fout<<a;
    }
   
    return 0;
}
