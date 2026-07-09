#include<fstream>
using namespace std;
#define INFINIT 1<<30
int T,v[100003],d[100004],t[100004];
struct nod{
	int info,cost;
	nod * next;
};
nod *g[50005];
int h[50005],nh,poz[50005],dd[50005];
void adaugaarc(int a,int b,int c);
void dijkstra(int sursa,int n);
void init(int sursa,int n); 
void cerne(int k);
void promoveaza(int k);
int main()
{
  int n,m,s;
  int i;
  ifstream fin("distante.in");
  ofstream fout("distante .out");
  fin>>T;
  int q;
  //fin>>n>>m>>s;
  
  for(int j=1;j<=T;j++)
   { 
    fin>>n>>m>>s;
    for(i=1;i<=n;i++)
       fin>>dd[i];
    for(;m;m--)
       {
         int a,b,c;
         fin>>a>>b>>c;
         adaugaarc(a,b,c);
         adaugaarc(b,a,c);
        }              
     dijkstra(s,n);
     for(int w=1;w<=n;w++)
       g[w]=NULL;
     int pp=1;
     for(q=1;q<=n && pp==1;q++)  
        if(d[q]!=dd[q])
           pp=0; 
     if(pp==1)
       fout<<"DA";
     else
        fout<<"NU";
     fout<<endl;
     }
  return 0;
}
void dijkstra(int sursa,int n)
{
  init(sursa,n);
  for(int kk=1;kk<n;kk++)
  {
    int pmin;
    pmin=h[1];
    v[pmin]=1;
    if(d[pmin]==INFINIT)
       break;
    h[1]=h[nh--];
    poz[h[1]]=1;
    cerne(1);
    for(nod *p=g[pmin];p;p=p->next)
      if(v[p->info]==0)
       if(d[p->info]>d[pmin]+p->cost)
         { 
           d[p->info]=d[pmin]+p->cost;
           t[p->info]=pmin;
           promoveaza(poz[p->info]);
           }
    }
}       
void init(int sursa,int n)
{
  for(int i=1;i<=n;i++)
    v[i]=0,d[i]=INFINIT,t[i]=-1,poz[i]=i,h[i]=i;
  v[sursa]=1;
  d[sursa]=0;
  t[sursa]=0;
  nh=n;
  h[sursa]=h[nh--];
  poz[h[1]]=sursa;
  cerne(sursa);
  for(nod *p=g[sursa];p;p=p->next)
   {
     t[p->info]=sursa;d[p->info]=p->cost;
     promoveaza(poz[p->info]);
   }
}
void cerne(int k)
{
  int esteheap=0,aux,i;
  while(esteheap==0 && 2*k<=nh)
  {
    i=2*k;
    if(i+1<=nh && d[h[i+1]]<d[h[i]])                            
         i=2*k+1;
    if(d[h[i]]>=d[h[k]])
      esteheap=1;
    else
     {
       aux=h[k];
       h[k]=h[i];
       h[i]=aux;
       poz[h[i]]=i;
       poz[h[k]]=k;
       k=i;
       }
    }
}
void promoveaza(int k)
{
  int aux,esteheap=0,i;
  while(esteheap==0 && k/2>0)
  {
    i=k/2;
    if(d[h[i]]<=d[h[k]])
      esteheap=1;
    else
    {
       aux=h[k],h[k]=h[i],h[i]=aux;
       poz[h[k]]=k,poz[h[i]]=i;
       k=i;
    }
}
}
void adaugaarc(int a,int b,int c)
{
  nod *p=new nod;
  p->info=b;
  p->cost=c;
  p->next=g[a];
   g[a]=p;
  }
              
