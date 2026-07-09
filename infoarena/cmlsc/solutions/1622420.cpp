#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int h=1,j,a[1025],b[1025],m,n,i,comun[1025],poz[1025],k,maxx=-1,start;
void citire()
{fin>>m>>n;
for(i=1;i<=m;i++)fin>>a[i];
for(i=1;i<=n;i++)fin>>b[i];
}
void cautare()
{
for(i=1;i<=m;i++)
{for(j=1;j<=n;j++)
{if(a[i]==b[j])
{comun[h]=a[i];
poz[h]=j;
h++;b[j]=257;
break;}
}
}
}
void maxim()
{h--;j=0;
while(j!=h)
{j++;k=1;
    for(i=j+1;i<=h;i++){
        if(poz[i]>poz[i-1])
        k++;}
if(maxx<k){
maxx=k;
start=j;}
}}
void scriere()
{fout<<maxx<<"\n"<<comun[start]<<" ";
for(i=start+1;i<=h;i++)
    if(poz[i]>poz[i-1])
    fout<<comun[i]<<" ";

}

int main()
{citire();
cautare();
maxim();
scriere();


return 0;
}
