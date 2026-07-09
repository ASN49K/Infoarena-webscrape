#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream in("euclid2.in");
ofstream out("euclid2.out");
 
int euclid(int a, int b)
{
    int c;
    while (b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
 
int main()
{
    int T, a, b;
    in>>T;
    for (int i=1;i<=T;i++)
    {
        in>>a>>b;
        out<<euclid(a, b)<<"\n";
    }
    return 0;
}