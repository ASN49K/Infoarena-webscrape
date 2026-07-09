#include<fstream>
using namespace std;

long euclid(long x;long y){
if(y==0) return x;
return euclid(y,x%y);
}

int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long t;
f>>t;
for(long i=1;i<=t;i++){
  long a,b;
  f>>a>>b;
  g<<euclid(a,b);	
}	
f.close();
g.close();
return 0;
}