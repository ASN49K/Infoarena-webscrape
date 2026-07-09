#include<iostream.h>
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
{ int a,b;
cin >>a>>b;
cout<<cmmdc(a,b);
return 0;
}
