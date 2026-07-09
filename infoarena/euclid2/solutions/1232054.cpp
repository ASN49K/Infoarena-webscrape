#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,t,a,b,aux;
int euclid (int a1, int b1)
{
    while (b1)
    {

    aux=b1;
    b1=a1%b1;
    a1=aux;
  //  cout<<a1<<" "<<b1<<"  ";
    }
  //  cout<<"\n";

    return a1;

}

int main()
{
f>>t;
for (i=1;i<=t;i++)
{
    f>>a>>b;

    g<<euclid(a, b)<<"\n";

}



    return 0;
}
