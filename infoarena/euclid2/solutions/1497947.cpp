#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b){
int t;
while(b!=0){
    t=b;
    b=a%b;
    a=t;

}
return a;}


int main()
{
int t,a,b,i;
fstream f,g;
f.open("euclid2.in",ios::in);
g.open("euclid2.out",ios::out);
f>>t;
for(i=1;i<=t;i++){
f>>a>>b;
g<<cmmdc(a,b)<<endl;
}}
