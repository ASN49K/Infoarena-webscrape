#include<fstream>

using namespace std;

#define min(a,b) (a>b?b:a)
#define max(a,b) (a<b?b:a)


ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b){
int c;
while(a%b!=0){
c=a%b;
a=b;
b=c;
}
return b;
}


int main(){
int t,a,b,i;
fin>>t;
for(i=1;i<=t;++i){
cin>>a>>b;
fout<<cmmdc(max(a,b),min(a,b))<<"\n";
}
return 0;
}