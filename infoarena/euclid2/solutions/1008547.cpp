#include<iostream>
#include<fstream>
using namespace std;

int euc(int a, int b)
{
    if(!b) return a;
    return (euc(b, a%b));
}

int main()
{
    int i, x, y;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>i;

    for(int j=1; j<=i; j++)
    {
         f>>x;
         f>>y;
         g<<euc(x, y)<<endl;
    }


    f.close();
    g.close();

    return 0;
}
