#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int A[1024],B[1024];
int n,m;
     int a[1024][1024];
    
   


void citire()
{
   ifstream in ("cmlsc.in");

    
    in>>n;
    in>>m;

    for(int i = 1; i<=n; i++)
            in>>A[i];

    
    for(int i = 1; i<=m; i++)
            in>>B[i];

}


void lungime(int n, int m)
{
    

     for(int i = 1; i<=n; i++)
        {
            a[i][0] = 0;
           
        }
      
        for(int i = 1; i<=m; i++)
            {
                a[0][i] = 0;  
            }
            
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            {  
                  
                if(A[i]==B[j])
                    {
                      
                        a[i][j] = a[i-1][j-1]+1;
                       
                      

                            
                    }
                if(A[i]!=B[j])
                    {
                       if(a[i-1][j]>= a[i][j-1])
                            {
                                a[i][j] = a[i-1][j];
                                
                            }
                        else
                        {
                            a[i][j] = a[i][j-1];
                          
                        }
                        


                    }

                
            }
    

    
}
void solutie(int i, int j)

{
    ofstream out ("cmlsc.out");
 int v[1024],k=0;
    while(i!=0 and j!=0)
    {    
            if(A[i] == B[j])
            {
               v[k] = A[i];
               i = i-1;
               j = j-1;
               k++;
               
                
            }
        else
        {   
            if(a[i-1][j]>= a[i][j-1])
                {
                    i--;

                }
                else
                {
                    j--;
                }
                
        }
    }
    out<<k<<endl;;
for(int i = k-1; i>=0;i--)
    out<<v[i]<<" ";

        

}





void afisare(int n, int m)
{
    lungime(n,m);
    solutie(n,m);
    


}
int main()
{
  ifstream in ("cmlsc.in");
 ofstream out ("cmlsc.out");
      in>>n;
    in>>m;


    citire();
    afisare(n,m);
return 0;

}