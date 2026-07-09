#include <iostream>
#include<fstream>
using namespace std;
int n,a,v;
    int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int i,r;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>v;
        in>>a;
        while(a!=0)
        {
            r=v%a;
            v=a;
            a=r;
        }
        out<<v<<"\n";
    }
    in.close();
    out.close();
}
