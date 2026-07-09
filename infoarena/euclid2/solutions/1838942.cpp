#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a,b,r,n,i;
int main(void){
    in>>n;
    for(i=1;i<=n;i++){
    in>>a;
    in>>b;
    while(b>0){
        r=a%b;
        a=b;
        b=r;
    }
    out<<a<<\n;}
return 0;
}
