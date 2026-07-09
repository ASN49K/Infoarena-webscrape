#include<iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
    if(!b) return a;
        else return euclid(b,a%b);
}


int main()
{
int n,i=0;
f>>n;

while(i<n)
{   int x,y;
    f>>x>>y;
    g<<euclid(x,y)<<endl;
    i++;
}
f.close();
g.close();
}
