#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int a, b, r, t, i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1; i<=t; i++)
    {
        f>>a>>b;
        if(a==b)
            g<<a<<endl;
        else
        {
            do
            {
                r=a%b;
                a=b;
                b=r;
            }
            while(r!=0);
            g<<a<<endl;
        }
    }
    f.close();
    g.close();
}
