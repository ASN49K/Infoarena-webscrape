#include <fstream>

using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");
int n,i,a[100001],l[100001],maxx,start,refer,poz[100001],j;
void citire()
{fin>>n;
for(i=1;i<=n;i++)
    fin>>a[i];
fin.close();
}
void cautare()
{l[n]=1;poz[n]=-1;
for(i=n-1;i>0;i--)
{
    for(l[i]=1,poz[i]=-1,j=i+1;j<=n;j++)
    {if(a[i]<a[j] && l[i]<1+l[j])
    {
        l[i]=1+l[j];poz[i]=j;
    }

    }
}
}
void maxim()
{maxx=l[1];start=1;
for(i=2;i<=n;i++){
        if(l[i]>maxx)
        {maxx=l[i];
start=i;}
}

}
void scriere()
{
    fout<<maxx<<"\n";
   for(i=start;i!=-1;i=poz[i])
   {

        fout<<a[i]<<" ";
   }
}
int main()
{
    citire();
    cautare();
    maxim();
    scriere();
    return 0;
}
