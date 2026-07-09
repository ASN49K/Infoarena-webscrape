#include<fstream>
#include<iostream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");



int main(){
long long n,a,b,r;
in>> n;
for(int i=1;i<=n;i++){
    in>>a>>b;
    if(a<b){r=a;a=b;b=r;}
    int t;
    t=a%b;
     while(t!=0){
        a=b;b=t;
        t=a%b;
    }
    out<<b<<'\n';
}

return 0;
}
