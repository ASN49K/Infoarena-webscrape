#include <iostream>
#include <fstream>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
using namespace std;
int a,b,i,t;
int cm(int a,int b)
{
    int c=a%b;
    while(c)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;

}
int main()
{
    f>>t;
    for(i=t;i>0;i--)
    {
       f>>a>>b;
        g<<cm(a,b);
    }

    return 0;
}
