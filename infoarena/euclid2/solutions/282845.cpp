 #include<fstream.h>  
 int main()  
 {long int i,n,a,b;  
 ifstream f("euclid2.in");  
ofstream g("euclid2.out");  
f>>n;
for(i=1;i<=n;i++)
{ f>>a>>b;   
 while(a!=b)  
    if(a>b) a-=b;  
     else b-=a;  
 
 if(a==1) g<<0<<'\n';  
 else g<<a<<'\n';} 
f.close(); 
 g.close();  
 return 0;} 