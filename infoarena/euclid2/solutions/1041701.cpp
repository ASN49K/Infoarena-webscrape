#include<fstream>


int cmmdc(int a,int b)
{ int r;
r=a%b;
while(r)
{ b=r;
a=b;
r=a%b;
}
return b;
}
int main ()
{ int a,b,n,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=0;i<n;i++)
{ f>>a;
f>>b;
g<<cmmdc(a,b);
g<<'\n';
}
f.close();
g.close();
return 0;
}
