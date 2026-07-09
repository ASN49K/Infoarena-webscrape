#include<iostream>
#include<fstream>
using namespace std;
inline int cmmdc(int a,int b)
{
    int c;
    while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b,i;
    f>>n;
    for(i=1;i<=n;++i)
       {
           f>>a>>b;
           g<<cmmdc(a,b)<<endl;
       }
       f.close();
       g.close();
       return 0;
}
