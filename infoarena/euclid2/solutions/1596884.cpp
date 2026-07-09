#include<fstream.h>
#include<iostream.h>
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t,r;
f>>t;
while (t)
{
    r=0;
    f>>a>>b;
    r=a%b;
    a=b;
    b=r;
    g<<a<<endl;
    t--;

}
return 0;
}
