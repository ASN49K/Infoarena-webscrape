#include <iostream>
#include <fstream>
using namespace std;
int a,b;
int c(int x,int y){
if(x==y)return x;
if(x>y)return c(x-y,y);
return c(x,y-x);
}
int main()
{
    ifstream f("euclid2.in");ofstream g("euclid2.out");
int i;
f>>i;
for(i;i>0;i--){f>>a>>b;g<<c(a,b)<<"\n";}
}
