#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
ifstream f;
ofstream g;

int i,j,a[1024],b[1024],n1,n2,m,c[1024][1024],q;



void matrice(int n,int t[],int mm,int tt[])
        {
        int nn=n;
        while(n>0)
                {
                int m=mm;
                while(m>0)
                        {
                         if(t[n]==tt[m])c[m][n]=1;
                         m--;
                        }
                n--;
                }

        m=mm;
        n=nn;
        i=1;
        int z=1;
        int rq=1;
         while(i<=m)
                {
                 j=z;

                 while(j<=n&&!c[j][i])j++;
                 if(j<=n&&c[j][i]){a[rq]=t[i];
                 rq++;
                 z=j+1;}
                 i++;
                }
         g<<--rq<<'\n';
         for(i=1;i<=rq;i++)g<<a[i]<<' ';

        }





int main()
{
f.open("cmlsc.in");
g.open("cmlsc.out");
f>>n1>>n2;


for(i=1;i<=n1;i++)f>>a[i];
for(i=1;i<=n2;i++)f>>b[i];

matrice(n1,a,n2,b);





f.close();
g.close();
return 0;
}
