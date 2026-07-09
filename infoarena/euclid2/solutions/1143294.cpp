#include<fstream>
using namespace std;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
int cmmdc(int a, int b)
{
    if(a==b)
    return a;
    else
    if(a>b)
    return cmmdc(a-b,b);
    else
    return cmmdc(a,b-a);}
int main()
{
    int i,T,a,b;
    f>>T;
    for(i=0;i<T;i++)
    {
                    f>>a;
                    f>>b;
                    g<<cmmdc(a,b);}
    return 0;}
