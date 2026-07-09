#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int i,t;
    int a,b,c;
    in>>t;
    for(i=0;i<t;i++)
    {
        in>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        out<<a<<"\n";
    }
    return 0;
}
