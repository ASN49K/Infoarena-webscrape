#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
struct nod{
   int info;
   nod *next;
};
nod *g[260],*gt[260],*gn[260];
int vizitat[260],vizitatt[260],timp,ordine[260],nrc,nouviz;
vector<int> CTC[260];
void kosaraju();
void adaugat(int a,int b);
void adauga(int a,int b);
ofstream fout("plan.out");
void add(int a,int b);
void nougraf();
void add(int a,int b);
int grade[260],gradi[260];
void rezolva();
int p,
int main()
{
	ifstream fin("plan.in");
	fin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++)
	{
		int a,b;
		fin>>a>>b;
		adauga(a,b);
		adaugat(a,b);
	}
	kosaraju();
	nougraf();
	rezolva();
	return 0;
}
void dfs(int x)
{
  	vizitat[x]=1;
	for(nod *p=g[x];p;p=p->next)
		if(vizitat[p->info]==0)
			dfs(p->info);
	ordine[++timp]=x;	
}
void dfst(int x,int ctc)
{
   vizitatt[x]=1;
   CTC[ctc].push_back(x);
   for(nod *p=gt[x];p;p=p->next)
	   if(vizitatt[p->info]==0)
		   dfst(p->info,ctc);
}
void kosaraju()
{
	int i;
	for(i=1;i<=n;i++)
		if(vizitat[i]==0)
			dfs(i);
	for(i=timp;i>1;i--)
        if(vizitatt[ordine[i]]==0)
			dfst(ordine[i],++nrc);
}
void adauga(int a,int b)
{
	nod *p=new nod;
	p->info=b;
	p->next=g[a];
	g[a]=p;
}
void adaugat(int a,int b)
{
	nod *p=new nod;
	p->info=a;
	p->next=gt[b];
	gt[b]=p;
}
	
void nougraf()
{
  int i;
  for(i=1;i<nrc;i++)
   {
	  add(CTC[i][CTC[i].size()-1],CTC[i+1][CTC[i+1].size()-1]);
	  grade[CTC[i][CTC[i].size()-1]]++;
	  gradi[CTC[i+1][CTC[i+1].size()-1]];
    }
}
void add(int a,int b)
{
	nod *p=new nod;
	p->info=b;
	p->next=gn[a];
	gn[a]=p;
}
void rezolva()
{
	for(i=1;i<=n;i++)
	{ 
        if(gradi[i]==0)
            x[++nri]=i;
        if(grade[i]==0)
            y[++nre]=i;
        if(gradi[i]!=0 && grade[i]!=0)   
            normal[++nrnormal]=i;
	}
    if(nre>nri)
       fout<<nre<<endl;
    else
       fout<<nri<<endl;
    int pa;
    if(nre>nri)
	{ 
        for(i=1;i<=nri;i++)
           fout<<y[i]<<" "<<x[i]<<endl;
        for(i=nri+1;i<nre+1;i++)
            if(normal[1]!=0)
                fout<<y[i]<<" "<<normal[1]<<endl;
            else
               fout<<y[i]<<" "<<x[1];
	}
  else
    {
        if(nre==0 && nri==0)
            fout<<"0";
        if(nri>nre)
        { 
            for(i=1;i<=nre;i++)
				fout<<y[i]<<" "<<x[i]<<endl;
            for(i=nre+1;i<nri+1;i++)
                if(normal[1]!=0) 
					fout<<normal[1]<<" "<<x[i]<<endl;
                else
                    fout<<x[1]<<" "<<x[i];
		}   
	}
