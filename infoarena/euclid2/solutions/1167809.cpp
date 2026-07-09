#include<fstream>
using namespace std;
ifstream f("euclid2.in", ios::in);
ofstream g("euclid2.out", ios::out);
int cmmdc( int a, int b)
{
    if(b==0)
    return a;
    else
    return cmmdc(b,a%b);}
int main()
{
    int a,n,b,i;
    f>>n;
    while(n)
            {         f>>a;
                     f>>b;
                     g<<cmmdc(a,b);}
    return 0;}
    
