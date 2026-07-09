#include <fstream>
using namespace std;
fstream fin("euclid2.in",ios::in);
fstream fout("euclid2.out",ios::out);
int cmmdc(int a,int b){
    int x;
    if(a<b){x=a;}else{x=b;}
    while(x>=0){if((a%x==0)&&(b%x==0)){goto here;}else{x--;}}
    here:
    return x;}
int main(){
    int a[1001],b[1001];
    int t,i;
    fin>>t;
    for(i=1;i<=t;i++){fin>>a[i]>>b[i];}
    for(i=1;i<=t;i++){fout<<cmmdc(a[i],b[i])<<endl;}
    return 0;}

