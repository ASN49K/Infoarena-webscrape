#include <iostream>
#include <fstream>

using namespace std;

void citire(int a,int b)
{
    ifstream f("euclid2.in");
    f>>a>>b;
    f.close();
}

int euclid(int a,int b)
{
    if(!b)return a;
    euclid(b,a%b);
}

void afisare(int a, int b)
{

}

int main()
{
    int a,b,n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>n;

    for(int i=0;i<n;i++)
    {
        f>>a>>b;
        if(a<b)swap(a,b);
        g<<euclid(a,b);

    }

      g.close();
      f.close();
    return 0;
}
