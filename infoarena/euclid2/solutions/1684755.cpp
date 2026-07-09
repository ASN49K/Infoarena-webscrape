#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n,a,b;
int cmmdc(int a,int b){
    while(a!=b){if(a>b)a=a-b;
                else b=b-a;
               }
    return a;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
           cin>>a>>b;
           cout<<cmmdc(a,b)<<"\n";
           }
}
