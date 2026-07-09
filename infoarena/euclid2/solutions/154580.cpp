#include<fstream>
using namespace std;

long euclid(long x,long y){
if(y==0) return x;
if(x==0) return y;
while(y!=0){
 long r=x%y;
  x=y;
  y=r;
}
return x;
}

int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long t;
f>>t;
for(long i=1;i<=t;i++){
  long a,b;
  f>>a>>b;
  g<<euclid(a,b)<<endl;	
}	
f.close();
g.close();
return 0;
}