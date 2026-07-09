#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int main()
{
    int t, a, b, j, c, i;
    fi>>t;
    for (i=1; i<=t; i++)
    {
        fi>>a;
        fi>>b;
        if (a<b)
        {
            c=a;
            a=b;
            b=c;
        }
        j=2;
        c=1;
        while (j<=a/2 && j<=b)
        {
            if (a%j==0 && b%j==0)
                c=j;
            j++;
        }
        fo<<c<<endl;
    }
}
