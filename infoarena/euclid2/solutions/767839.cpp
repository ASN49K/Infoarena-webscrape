#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
int r=1;
while(r != 0)
{
r=a%b;
a=b;
b=r;
}
return a;
}

int main()
{
int t,a,b;
in>>t;
for(int i=1;i<=t;i++){
in>>a>>b;
out<<euclid(a,b)<<"\n";
}
return 0;
}