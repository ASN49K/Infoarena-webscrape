#include<iostream>  
#include<fstream>  
using namespace std;  
int x[1024], y[1024],c[1024][1024],s[1024];  
    int max(int a, int b)  
    {  
        if (a>b)  
          return a;  
      else return b;  
   }  
     
   int main()  
   {int m, n, i, j,a=0;  
       ifstream f("cmlsc.in");  
         f>>m>>n;  
       for(i=1;i<=m;i++)  
       f>>x[i];  
       for(i=1;i<=n;i++)  
       f>>y[i];  
       f.close();  
         
       for(i=1;i<=m;i++)  
       for(j=1;j<=n;j++)  
       if(x[i]==y[j])  
             c[i][j]=c[i-1][j-1]+1;  
         else  
             c[i][j]=max(c[i][j-1],c[i-1][j]);  
             
        ofstream g("cmlsc.out");  
          g<<c[m][n]<<endl;  
       i=m;j=n;  
     while(i)    
      {     if(x[i]==y[j])  
            {    
                s[++a]=x[i];    
                i--;    
                j--;    
            }    
            else    
                if(c[i][j-1]>c[i-1][j])    
                    j=j-1;    
            else    
               i=i-1;    
   }  
      for(i=c[m][n];i>=1;i--)  
       g<<s[i]<<" ";      
          
        g.close(); 
        system("pause"); 
        return 0;  
        }     
