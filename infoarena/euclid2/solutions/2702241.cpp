#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,r;
        in>>a>>b;
        if(a<b)
        {
        a=a+b;
        b=a-b;
        a=a-b;
        }
        r=a%b;
        while(r!=0)
        {   a=b;
            b=r;
            r=a%b;
        }
        out<<b<<endl;
    }
    return 0;
}
