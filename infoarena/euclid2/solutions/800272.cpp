#include<iostream>
#include<fstream>
using namespace std;
int gcd(int a, int b)
   {
       if (a==0)
       return b;
    while (b)
        {
        if (a > b)
           a-=b;
        else
           b-=a;
        }
    return a;
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
