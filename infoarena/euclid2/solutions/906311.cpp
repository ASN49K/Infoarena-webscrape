#include<fstream>
using namespace std;
int n,m[2][1024];

void ordonare(void)
{int i,j;
     for(i=0;i<n;i++)
     if(m[1][i]<m[2][i])
     {j=m[1][i];
     m[1][i]=m[2][i];
                m[2][i]=j;        }
     }
int euclid(int i,int m[2][1024])
{int t;
    while(m[2][i]!=0)
    {t=m[1][i]%m[2][i];
      m[1][i]=m[2][i];                       
       m[2][i]=t;}
    return m[1][i];
    }
int main()
{
    int i;
    ifstream fin("euclid2.in");
fin>>n;
for(i=0;i<n;i++)
fin>>m[1][i]>>m[2][i];
fin.close();
ordonare();
ofstream fout("euclid2.out");
for(i=0;i<n;i++)
fout<<euclid(i,m)<<"\n";
 fout.close();
    return 0;}
