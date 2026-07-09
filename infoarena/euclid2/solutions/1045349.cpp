#include <iostream>
#include <fstream>
using namespace std;
int a,b,t,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
   while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;

}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}