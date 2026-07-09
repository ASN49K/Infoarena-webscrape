#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int A[20],B[20],n,m;


void citire()
{
   ifstream in ("cmls.in.txt");

    
    in>>n;
    in>>m;

    for(int i = 1; i<=n; i++)
        {
            in>>A[i];
        
      
        };

    
    for(int i = 1; i<=m; i++)
        {
            in>>B[i];
     
        };

}


void lungime(int n, int m)
{
     ofstream out ("cmls.out.txt");
    int a[20][20];
    int v[20],k=0;

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
                        v[k] = A[i];
                        k++;

                            
                    }
                if(A[i]!=B[j])
                    {
                        a[i][j] = max(a[i-1][j],a[i][j-1]);


                    }

                
            }
    
    out<<a[n][m]<<" "<<endl;

    for(int i = 0 ; i<k;i++ )
        out<<v[i]<<" ";

    
}

void afisare(int n, int m)
{
    lungime(n,m);

}
int main()
{
  ifstream in ("cmls.in.txt");

      in>>n;
    in>>m;


    citire();
    afisare(n,m);


}