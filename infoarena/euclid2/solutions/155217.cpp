#include<fstream>
using namespace std;
int a,b,t;
int euclid(int x,int y){
if(!y) return x;
return euclid(y,x%y);
}

int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(int i=0;i<t;i++){
 f>>a>>b;
 g<<euclid(a,b)<<endl;
}
f.close();
g.close();
return 0;
}  