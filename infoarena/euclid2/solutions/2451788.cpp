#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b){
if(b==0){
    return a;
}else
return cmmdc(b,a%b);

}
int main()
{
    int t,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(int i=t;i>=1;i--){
    f>>a>>b;
g<<cmmdc(a,b)<<"\n";
}
f.close();
g.close();
    return 0;
}
