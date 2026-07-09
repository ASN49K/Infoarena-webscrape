#include<iostream>

using namespace std;

#define min(a,b) (a>b?b:a)
#define max(a,b) (a<b?b:a)

int div(int a, int b){
int c;
while(a%b!=0){
a=a%b;
a=b;
b=c;
}
return b;
}


int main(){
int t,a,b,i;
cin>>t;
for(int i=1;i<=t;++i){
cin>>a>>b;
cout<<div(max(a,b),min(a,b))<<"\n";
}
return 0;
}