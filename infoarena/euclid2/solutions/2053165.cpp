#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b);
int main()
{
    int T,a,b,cmdivizor;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>T;
    for(int i=1; i<=T; i++)
    {
        in>>a;
        in>>b;
        cmdivizor=cmmdc(a,b);
        out<<cmdivizor<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
int cmmdc(int a, int b)
{
    if(b==0){return a;}
    else return cmmdc(b, a%b);
}
