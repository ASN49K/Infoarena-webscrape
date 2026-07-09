#include <iostream>
#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int main()
{
    int n;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        in>>a>>b;
        while(b>0)
        {
            int c=a%b;
            a=b;
            b=c;
        }
        out<<a<<'\n';
    }
    return 0;
}
