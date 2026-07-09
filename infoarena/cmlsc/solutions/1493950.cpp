#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n,m,top1,top2,k;
int st1[1025],st2[1025];
int a[1025],b[1025];

ofstream fout("cmlsc.out");

void Citire()
{ ifstream fin("cmlsc.in");
  int i;
  fin>>n>>m;
  for (i=1;i<=n;i++)
  fin>>a[i];
  for (i=1;i<=m;i++)
  fin>>b[i];
 // sort (a+1, a+n+1);
 // sort (b+1, b+m+1);
  fin.close();
}

void Afisare2()
{
  int i,ok2=1;
  for (i=1;i<=k && ok2==1;i++)
     if (a[st1[i]]!=b[st2[i]])
         ok2=0;
  if (ok2==1)
     {
        fout<<k<<"\n";
        for (i=1;i<=k;i++)
           fout<<a[st1[i]]<<" ";
        fout<<"\n";
        fout.close();
        exit(0);
     }
}

void Back2(int top2,int k)
{
  int i;
  if (top2==k+1) Afisare2();
  else for (i=st2[top2-1]+1;i<=n-k+top2;i++)
       {
           st2[top2]=i;
           Back2(top2+1,k);
       }
}

void Afisare1()
{
   Back2(1,k);
}


void Back1(int top1,int k)
{
  int i;
  if (top1==k+1) Afisare1();
  else for (i=st1[top1-1]+1;i<=n-k+top1;i++)  /// i-urile cu care se completeaza stiva este de fapt indici, adica daca st[i]==j inseamna ca elementul a[j] din vector apare in combinare
       {                                   /// ca doua combinari de n luate cate k sa fie identice (subsir comun) inseamna clar ca au acelasi nr de elemente deci efectiv aceleasi el.
            st1[top1]=i;
            Back1(top1+1,k);
       }
}

int main ()
{
  Citire();
  int i;
  for (i=min(m,n);i>=1;i--)
  {  k=i;
     Back1(1,k);
  }
  return 0;
}
