#include<fstream.h>
long T,aux, a, b, i;
long divizor(int a, int b){
		    if(b==0) return a;
		    return divizor(b, a%b);}
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main(){
f>>T;
for(i=1;i<=T;i++){f>>a>>b;
		 g<<divizor(a, b)<<'\n';
		 }
f.close();
g.close();
return 0;}
