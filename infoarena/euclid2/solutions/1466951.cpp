#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int a,b,x;
int aux;
int cauta(int c,int d)
{   x=d;

    if (c%d!=0) {x=c%d;

    cauta(d,c%d);}


    return x;

}

int main()
{   int t;
    f>>t;
    int c;
    for(int i=0;i<t;i++)
    {f>>a;
    f>>b;

    if(a>b) c= cauta(a,b);
    else c= cauta(b,a);
    g<<c<<" ";}
    f.close();
    g.close();
    return 0;
}
