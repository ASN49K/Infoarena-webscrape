#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int,int);
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,a,b;
    in>>n;
    for(int i=1;i<=n;i++)
        {
            in>>a>>b;
            out<<cmmdc(a,b)<<endl;
        }
    return 0;
}
int cmmdc(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
