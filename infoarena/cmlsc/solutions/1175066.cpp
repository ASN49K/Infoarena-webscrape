#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
ifstream f;
ofstream g;

int i,j,a[1024],b[1024],n1,n2,m,c[1024],q;


int cmlsc(int i,int j,int m)
        {
        if(i==0||j==0) return m;
        else
        if(a[i]==b[j])
                {
                 c[m]=a[i];
                 m++;
                 return cmlsc(i-1,j-1,m);
                 m--;
                }
        else {  int qq=cmlsc(i-1,j,m),pp=cmlsc(i,j-1,m);
                if(qq>pp)return qq;
                else return pp; }

        }
int main()
{
f.open("cmlsc.in");
g.open("cmlsc.out");
f>>n1>>n2;


for(i=1;i<=n1;i++)f>>a[i];
for(i=1;i<=n2;i++)f>>b[i];


q=cmlsc(n1,n2,1);


g<<--q<<'\n';

while(q>0)
        {
        g<<c[q]<<' ';
        q--;
        }

f.close();
g.close();
return 0;
}
