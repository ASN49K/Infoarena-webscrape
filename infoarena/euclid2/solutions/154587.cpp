#include<fstream>
using namespace std;

int euclid(int x,int y){
if(y==0) return x;
return euclid(y,x%y);
}

int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t;
f>>t;
for(int i=1;i<=t;i++){
  long a,b;
  f>>a>>b;
  g<<euclid(a,b)<<endl;	
}	
f.close();
g.close();
return 0;
}