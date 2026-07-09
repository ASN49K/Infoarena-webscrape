#include <iostream>
#include<stdio.h>
using namespace std;FILE *f,*g;int main(){f=fopen("euclid2.in","r");g=fopen("euclid2.out","w");unsigned int t,a,b,i;a=1;b=3;swap(a,b);cout<<a<<b;fscanf(f,"%u",&t);for(i=1;i<=t;++i){fscanf(f,"%u%u",&a,&b);if (a<b) swap(a,b);while(!(b==0)){a=a%b;swap(a,b);}fprintf(g,"%d\n",a);}return 0;}
