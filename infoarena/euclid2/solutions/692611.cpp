#include<iostream>
#include<fstream>
using namespace std;
int main ()
{   long t, a, b, r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while (t!=0)
   {

    f>>a>>b;
    r=a%b;
    while(r!=0)
    {
    a=b;
    b=r;
    r=a%b;}
    g<<b<<endl;
    t--;}

    f.close();
    g.close();
    return 0;
}
