#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int a,b,t,r;
 f>>t;
 while(t--)
 {
    f>>a>>b;
    while(b){r=a%b;a=b;b=r;}
  g<<a<<'\n';
 }
}
