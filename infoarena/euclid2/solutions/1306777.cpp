#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int ecl(long long a,long long b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    ifstream si;
    si.open("euclid2.in");
    ofstream so;
    so.open("euclid2.out");
int t;
si>>t;
while(t--)
{
    int a,b;
    si>>a>>b;
    so<<ecl(a,b)<<'\n';
}
}
