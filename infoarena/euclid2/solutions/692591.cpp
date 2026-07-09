#include<iostream>
#include<fstream>
using namespace std;
int main ()
{   long i, t, a, b, r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
   {

    f>>a>>b;
    r=a%b;
    while(r!=0)
    {
    a=b;
    b=r;
    r=a%b;}
    g<<b<<endl;}

    f.close();
    g.close();
}
