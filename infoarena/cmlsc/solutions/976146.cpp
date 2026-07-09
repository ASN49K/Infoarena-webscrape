#include <fstream>
using namespace std;

int m,n,a[1024],b[1024],matrix[1024][1024],raspuns[1024],dim;
int main()
{
    ifstream inFile("cmlsc.in");
    inFile>>m>>n;
    int i,j;
    for(i=1;i<=m;i++) inFile>>a[i];
    for(i=1;i<=n;i++) inFile>>b[i];

    ofstream outFile;
    outFile.open("cmlsc.out");


    for(j=1;j<=n;j++)
        for(i=1;i<=m;i++)
            if(a[i]==b[j]) matrix[j][i]=1;

  /*  for(j=1;j<=n;j++)
        {
        for(i=1;i<=m;i++) outFile<<matrix[j][i]<<" ";
        outFile<<endl;
        }                     */

    if(n<=m)
        {
          if(matrix[1][1]==1)
            {
              raspuns[1]=a[1];
              dim++;
            }
          for(i=2;i<=n;i++)
            {
               if((matrix[i][i]==1)||(matrix[i-1][i]==1))
                {
                  dim++;
                  raspuns[dim]=a[i];
                }
               else if(matrix[i][i-1]==1)
                      {
                         dim++;
                         raspuns[dim]=b[i];
                      }

            }
           if(matrix[n][n]!=1)
              {
                 int k=0;
                 for(j=n;j<=m;j++) if(matrix[n][j]==1) k=1;
                 if(k==1) {dim++; raspuns[dim]=b[n];}
              }
        }
        else
            {
          if(matrix[1][1]==1)
            {
              raspuns[1]=a[1];
              dim++;
            }
          for(i=2;i<=m;i++)
            {
               if((matrix[i][i]==1)||(matrix[i-1][i]==1))
                {
                  dim++;
                  raspuns[dim]=a[i];
                }
               else if(matrix[i][i-1]==1)
                      {
                         dim++;
                         raspuns[dim]=b[i];
                      }

            }
           if(matrix[m][m]!=1)
              {
                 int t=0;
                 for(j=m;j<=n;j++) if(matrix[j][m]==1) t=1;
                 if(t==1) {dim++; raspuns[dim]=a[m];}
              }


            }

   outFile<<dim<<endl;
   for(i=1;i<=dim;i++) outFile<<raspuns[i]<<" ";
  //  for(i=1;i<=m;i++) outFile<<a[i]<<" ";
  //  outFile<<endl;
  //  for(i=1;i<=n;i++) outFile<<b[i]<<" ";

    outFile.close();
    return 0;
}
