#include<fstream.h>
int main ()
{
   int t,a,b,d,i;
   ifstream fin("euclid.in");  
   ofstream fout("euclid.out"); 
    fin>>t;
    for(i=1;i<=t;i++){
   fin>>a>>b;
    while(a!=b){
       if(a>b)
           a=a-b;
       else
        b=b-a;   
        d=a;
    }
       fout<< d<<'\n';
    }
       return 0;
}
       
       