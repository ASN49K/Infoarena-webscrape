#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b;
int euclid(int a,int b)
{
 if(b==0)
    return a;
 return euclid(b,a%b);
}
int main()
{
    int a,b,t;
    f>>t;
    for(int i=0;i<t;i++)
    {
    f>>a>>b;
    g<<euclid(a,b)<<endl;
    }
    return 0;
}
