#include <iostream>
#include <fstream>
using namespace std;


ifstream in("euclid2.in");
ofstream out("euclid2.out");



void euclid(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    out<<a<<"\n";
}

int main()
{
    int n;
    in>>n;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        euclid(a,b);
    }



    return 0;
}
