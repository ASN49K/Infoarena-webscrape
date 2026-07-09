#include<fstream>
#include<iostream>
using namespace std;
ifstream in("t.in");
ofstream out("t.out");
int y(int a,int b){
    int t;
    t=a%b;
    while(t!=0){
        a=b;b=t;
        t=a%b;
    }
return b;
}


int main(){
long long n,a,b,r;
in>> n;
for(int i=1;i<=n;i++){
    in>>a>>b;
    if(a<b){r=a;a=b;b=r;}
    out<<y(a,b)<<'\n';
}

return 0;
}
