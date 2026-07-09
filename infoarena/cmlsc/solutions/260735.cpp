#include <fstream>

using namespace std;

fstream f;
fstream g;
int m,n;
int a[1024];
int b[1024];
int i,j;
int vect[1024];
char l1[1024];
int lungime;
int x;

int main()
{
    f.open("cmlsc.in",fstream::in);
    f >> m >> n;
    for(i=0;i<m;i++)
       f >> a[i]; 
    for(i=0;i<n;i++)
      f>> b[i];       
    f.close();
    
    
    g.open("cmlsc.out",fstream::out);
    if(m<n)
    {
           for(i=0;i<m;i++)
             for(j=x;j<n;j++)
                if(a[i]==b[j]&&!l1[j])
                   {
                       vect[lungime++]=a[i];
                       l1[j]=1;
                       x=j;
                       break;                   
                   }
    }
    else
    {
          for(i=0;i<n;i++)
             for(j=x;j<m;j++)
                if(b[i]==a[j]&&!l1[j])
                   {
                       vect[lungime++]=b[i];
                       l1[j]=1;
                       x=j;
                       break;                   
                   }
    }
    g << lungime  << "\n";
    for(i=0;i<lungime;i++)
      g << vect[i] << " ";
    g.close();    
    return 0;
    
}
