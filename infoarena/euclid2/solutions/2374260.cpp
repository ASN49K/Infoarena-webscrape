#include <iostream>
#include <fstream>
#define "euclid2.in" in
#define "euclid2.out" out
using namespace std;
int a,b;
int euclid(int x, int y){
while(x!=y){
if(x<y)y-=x;
else x-=y;
}
return euclid;
}
int main()
{
    ifstream f(in);
int t;
f>>t;
    for(int i=t;i<=t;i++){
    f>>a>>b;
    cout<<euclid(a,b)<<endl;
    }
    return 0;
}
