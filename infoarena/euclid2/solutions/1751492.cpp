#include<iostream>
#include<fstream>
using namespace std;
int n,a,b,i,c;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;++i)
       {
           f>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<endl;
       }
       f.close();
       g.close();
       return 0;
}
