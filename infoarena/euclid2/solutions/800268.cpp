#include<iostream>
#include<fstream>
using namespace std;
int gcd(int a, int b)
    {
        if (b==0)
         return a;
        else
         return gcd(b,a%b);
    }
int main ()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a , b , n;
    f>>n;
    for (int i=1;i<=n;i++)
    {f>>a>>b;
    g<<gcd(a,b)<<endl;
    }

    f.close();
    g.close();
}
