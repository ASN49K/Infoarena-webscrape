#include<fstream.h>
using namespace std;

int euclid(int a,int b){
if(!b) return a;
return euclid(b,a%b);
}
void main(){
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,x,y;
fin>>T;
for(int i=0;i<T;i++) {fin>>x>>y; fout<<euclid(x,y)<<endl;}
return 0;
}