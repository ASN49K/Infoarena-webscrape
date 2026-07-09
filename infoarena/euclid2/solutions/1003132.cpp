#include <iostream>
#include <fstream>

using namespace std;


int main()
{
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int n,i,x,y,a,b,r;
f>>n;
for(i=1;i<=n;i++){
f>>a>>b;
x=a;
y=b;
r=x%y;
while(r!=0){
x=y;
y=r;
r=x%y;
}
g<<y<<endl;
}

}
