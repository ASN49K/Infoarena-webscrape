#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
using namespace std;
ifstream si("nim.in");
//FILE*si=fopen("dominant.in","r");
ofstream so("nim.out");
int main()
{
    int t;
    si>>t;
    int n,s,i,x;
    while(t--)
    {
        s=0;
        si>>n;
        for(i=0;i<n;i++)
        {
            si>>x;
            s=s^x;
        }
        if(s==0)
            so<<"NU\n";
        else
            so<<"DA\n";
    }

    return 0;
}
