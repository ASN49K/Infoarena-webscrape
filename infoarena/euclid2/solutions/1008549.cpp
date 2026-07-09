#include<iostream>
#include<fstream>
using namespace std;

long int euc(long int a, long int b)
{
    if(!b) return a;
    return (euc(b, a%b));
}

int main()
{
    long int i, x, y;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>i;

    while(i!=0)
    {
         f>>x;
         f>>y;
         g<<euc(x, y)<<endl;
         i--;
    }


    f.close();
    g.close();

    return 0;
}
