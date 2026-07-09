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
                         if(t[n]==tt[m])c[n][m]=1;
                         m--;
                        }
                n--;
                }
        n=nn;
        m=mm;

        int z=1,rq=1;
        j=1;
        i=1;
        while(i<=n&&j<=m)
                {
                while(c[i][j]==0&&j<=m)j++;
                if(j<=m){a[rq]=t[i];rq++;z=j+1;}
                i++;
                j=z;
                }
        z=1; int qr=1;
        j=1;
        i=1;
        while(i<=m&&j<=n)
                {
                while(c[j][i]==0&&j<=n)j++;
                if(j<=n){b[qr]=t[j];qr++;z=j+1;}
                i++;
                j=z;
                }




        if(qr>rq){
        g<<--qr<<'\n';
        for(i=1;i<=qr;i++)g<<b[i]<<' ';}
        else
        {
        g<<--rq<<'\n';
        for(i=1;i<=rq;i++)g<<a[i]<<' ';
        }


        }





int main()
{
f.open("cmlsc.in");
g.open("cmlsc.out");
f>>n1>>n2;


for(i=1;i<=n1;i++)f>>a[i];
for(i=1;i<=n2;i++)f>>b[i];

matrice(n2,b,n1,a);





f.close();
g.close();
return 0;
}
