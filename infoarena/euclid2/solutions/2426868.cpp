#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmd(int a,int b)
{
    if (b==0) return a;
    return cmd(b,a%b);
}

int main()
{
    int n,a,b;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmd(a,b)<<endl;
    }
    return 0;
}
