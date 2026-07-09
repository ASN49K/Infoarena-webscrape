#include<iostream>
#include<fstream>
using namespace std;
int main ()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,a,b,r;
    while(f>>a>>b){
        if(a<b)
    {
            r=a;
            a=b;
            b=r;
    }
        while(a%b!=0)
            {
            r=a%b;
            a=b;
            b=r;
        }
        if(b!=1)
            g<<b;
        else
            g<<0;
            }
        return 0;}
