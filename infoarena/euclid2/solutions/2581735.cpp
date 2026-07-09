#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>


using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd_smallest(int a, int b)
{
    int gcd =1;

    for(int i=2 ; i<= min(a,b); i++)
    {
        if(a%i==0 && b%i==0)
        {
            gcd = i;
        }
    }
    return gcd;
}
int gcd_difference(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            a -=b;
        else
            b-=a;
    }
    return a;

}

int gcd_division(int a, int b)
{
    while(b>0)
    {
        int c = a%b;
        a =b;
        b =c;

    }
    return a;
}

int gcd_div_rec(int a, int b)
{
    return( b==0)?a:gcd_div_rec(b,a%b);
}

int main ( )
{
    int t;
    in>>t;
    int a,b;
    for(int i=0; i<t; i++)
    {
        in>>a>>b;
        out<<gcd_smallest(a,b)<<'\n';
    }

    return 0;
}
