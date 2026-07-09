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
    int x, y;

    ifstream f("adunare.in");
    ofstream g("adunare.out");

    f>>x;
    f>>y;

    g<<euc(x, y);

    f.close();
    g.close();

    return 0;
}
