#include<fstream.h>
#include<conio.h>
 
ifstream f("cmmdc.in");  
 ofstream o("cmmdc.out");  
 void int(){unsigned n,v[10][2],i; 
 f>>n;  
for(i=1;i<=n;i++)f>>v[i][1]>>v[i][2];
 while(v[i][1]!=v[i][2]){if(v[i][1]>v[i][2])
v[i][1]=v[i][1]-v[i][2];if(v[i][1]<v[i][2])v[i][2]=v[i][2]-v[i][1];}  
 if(v[i][1]>1)o<<v[i][1];endl();  
 return 0;  
 }  