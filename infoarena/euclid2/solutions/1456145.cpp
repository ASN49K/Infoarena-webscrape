#include<iostream>
#include<fstream>
using namespace std;
int t,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){
int r;
while(b)
{r=a%b;
a=b;b=r;}
return a;
}

int main(){


f>>t;
while(t){
    f>>a>>b;
    t--;
g<<cmmdc(a,b)<<"\n";
//cout<<cmmdc(a,b)<<"\n";

}
f.close();g.close();
return 0;}
