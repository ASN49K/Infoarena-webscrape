#include<fstream>
using namespace std;
int euclid(int a, int b)
{
    int c=a%b;
   while(c)
   {
       a=b;
       b=c;
       c=a%b;
    }
    return b;     
}    
int main()
{
    int T,a,b;
 FILE *f=fopen("euclid2.in","r");
 FILE *ff=fopen("euclid2.out","w");
 fscanf(f,"%d",T);
 while(T)
 {
     fscanf(f,"%d %d",a,b);
     fprintf(ff,"%d\n",euclid(a,b));
     T--;
 }    
}    
