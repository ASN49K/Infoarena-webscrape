#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a,int b){
if(a==b)
    return a;
else if(a>b)
    return euclid(a-b,b);
else return euclid(a,b-a);
}
int main()
{   int n,i=0,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
f>>n;
for(i=0;i<n;i++)
{
    f>>a>>b;
    g<<euclid(a,b)<<endl;
}
f.close();
g.close();
}
