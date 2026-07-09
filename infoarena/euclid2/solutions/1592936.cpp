#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");

    int a,b,t,i,l,aux;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;
        f>>b;
       while (b>0)
       {
           aux=b;
           b=a%b;
           a=aux;
       }
       g<<aux<<"\n";
    }
    return 0;
}
