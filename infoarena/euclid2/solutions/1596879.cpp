#include<fstream>
#include<iostream>
using namespace std;
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t,i=1,r;
f>>t;
while (i<=t)
{
    r=0;
    f>>a>>b;
    r=a%b;
    a=b;
    b=r;
    g<<a<<endl;
    i++;

}
f.close();
g.close();
cin.get();
return 0;
}
