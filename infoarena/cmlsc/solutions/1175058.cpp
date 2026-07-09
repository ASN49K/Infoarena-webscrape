#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f;
ofstream g;

int i,j,a[1024],b[1024],n1,n2,m,c[1024],q;

void cmlsc(int i,int j)
        {
        if(i>0&&j>0)
                {
                if(a[i]==b[j]){
                                c[m]=a[i];
                                m++;
                                cmlsc(i-1,j-1);
                                m--;
                                }
                                else
                if(a[i]!=b[j])
                        {
                        cmlsc(i-1,j);
                        cmlsc(i,j-1);
                        }
                }
                else if(m>q)q=m-1;
        }
int main()
{
f.open("cmlsc.in");
g.open("cmlsc.out");
f>>n1>>n2;

m=1;
for(i=1;i<=n1;i++)f>>a[i];
for(i=1;i<=n2;i++)f>>b[i];
q=0;
cmlsc(n1,n2);


g<<q<<'\n';

while(q>0)
        {
        g<<c[q]<<' ';
        q--;
        }

f.close();
g.close();
return 0;
}
