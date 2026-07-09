#include <iostream>
#include <fstream>
using namespace std;

int cmmdc (int a, int b)
{
    if(b==0)return a;
    else return cmmdc(b,a%b);
}
int n,a,b,i;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
