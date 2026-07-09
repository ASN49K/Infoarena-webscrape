#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,n;
void cmmdc(int a,int b)
{
     while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    g<<a<<endl;
}

int main()
{
    f>>n;
    while( f>>x>>y  )
        cmmdc(x,y);

    return 0;
}
