#include <iostream>
#include <fstream>
using namespace std;
ifstream f("fractii.in");
ofstream g("fractii.out");
int N,a,b,c,x,y;
int main()
{
    f>>N;
    a=1;
    b=1;
    c=0;
    while(a<=N)
    {
        x=a;
        y=b;
        while(x!=y)
            if(x>y)
            x=x-y;
        else
            if(x<y)
            y=y-x;
        if(x==1)
            c++;
        b++;
        if(b>N)
        {
            a++;
            b=1;
        }
    }
    g<<c;
    return 0;
}
