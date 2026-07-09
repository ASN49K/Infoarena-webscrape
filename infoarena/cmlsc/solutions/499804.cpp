#include<fstream.h>

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int main()
{
int f[257]={0};
int n,m,i;
short x;
fin>>m>>n;
for(i=1;i<=m;i++) {fin>>x;
                   f[x]++;}
m=0;

for(i=1;i<=n;i++) {fin>>x;
                   f[x]++;
                   if(f[x]==2) m++; }
fout<<m<<'\n';
for(i=0;i<=256;i++) if (f[i]==2) fout<<i<<" ";

fin.close();
fout.close();
return 0;
}