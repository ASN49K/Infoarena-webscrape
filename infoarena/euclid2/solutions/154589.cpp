#include<fstream>
using namespace std;
int t,a,b;

int euclid(int x,int y){
if(y==0) return x;
return euclid(y,x%y);
}

int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(;t;t--){
  f>>a>>b;
  g<<euclid(a,b)<<endl;	
}	
f.close();
g.close();
return 0;
}