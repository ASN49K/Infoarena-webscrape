#include <iostream>
#include <fstream>
using namespace std;
int n,i,a,b;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=1;i<=n;i++){
f>>a>>b;
while(a!=b){
if(a>b) a=a-b;
if(b>a) b=b-a;
}g<<a<<endl;

}

}
