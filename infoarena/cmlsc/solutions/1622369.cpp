#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int h=1,j,a[1025],b[1025],m,n,i,comun[1025],poz[1025];
void citire()
{fin>>m>>n;
for(i=1;i<=m;i++)fin>>a[i];
for(i=1;i<=n;i++)fin>>b[i];
}
void cautare()
{
for(i=1;i<=m;i++)
{for(j=1;j<=n;j++)
{if(a[i]==b[j]){if(poz[h-1]<j){comun[h]=a[i];poz[h]=j;h++;b[j]=257;break;}}
}
}
}
void scriere()
{fout<<--h<<"\n";
for(i=1;i<=h;i++)
    fout<<comun[i]<<" ";

}

int main()
{citire();
cautare();
scriere();


return 0;
}
