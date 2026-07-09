#include<fstream.h>
int cmmdc(int x, int y){
while(x!=y){
if(x>y) x=x-y;
	else y=y-x;
}
return x;
}
void main (){
int a,b,d;
ifstream f("euclid2.in");
f>>a;f>>b;
d=cmmdc(a,b);
ofstream g("euclid2.out");
g<<d;
}


