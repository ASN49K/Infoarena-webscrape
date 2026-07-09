#include <iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,t;

int euclid(int x,int y)
{
    if(y==0)return x;
     else return euclid(y, x%y);

}
int main()
{ f>>t;
while(f>>a>>b)
{
g<<euclid(a,b)<<endl;
}
f.close();
g.close();
}
