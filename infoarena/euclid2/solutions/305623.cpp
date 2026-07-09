#include<fstream.h>
long int imp,ap,deimp,rest,a,b,nr,t;
int main()
{
ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>t;
ap=0;
do
{
in>>a;
in>>b;
deimp=a;
imp=b;
while(imp!=0)
{ rest=deimp%imp;
deimp=imp;
imp=rest;
}
out<<deimp<<"\n";
ap=ap+1;
}while(ap!=t);
in.close();
out.close();
return 0;
}