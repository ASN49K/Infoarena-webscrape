#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#define MAXN 351
#define MAXM 12502
#define INFI 1000000000
#define MINI 1000
using namespace std;

struct NOD{
  int node,neigh,cap,cost,pozInv,org;
};

struct DIN{
  int fath,flow,cost,distFalsa;
};

struct PRQ{
  int nod,flow,cost;
};

bool operator<(PRQ a,PRQ b){
  return a.cost>b.cost;
}

FILE *fin,*fout;
int n,m,start,desti;
int rasp;

DIN dina[MAXN];
vector <NOD> graf[MAXN];
vector <NOD> bell;
priority_queue <PRQ> q;
map <pair<int,int>,int> hart;

void InitRead(){
  fin=fopen("fmcm.in","r");
  fout=fopen("fmcm.out","w");
}

void InitDinamica(){
  int i;

  for(i=1;i<=n;i++){
    dina[i].cost=INFI;
    dina[i].flow=INFI;
    dina[i].fath=-1;
  }

  dina[start].cost=0;
  dina[start].flow=INFI;
  dina[start].fath=-1;
}

void AddEdge(int x,int y,int cap,int cost){
  int pDus,pIntors;

  pDus=graf[x].size();
  pIntors=graf[y].size();

  graf[x].push_back({x,y,cap, cost,pIntors,1});
  bell.push_back({x,y,cap, cost,pIntors,1});
  graf[y].push_back({y,x,0  ,-cost,pDus   ,0});
  bell.push_back({y,x,0  ,-cost,pDus   ,0});
  hart[{x,y}]=pDus;
  hart[{y,x}]=pIntors;
}

void Dijkstra(){
  PRQ node;

  while(!q.empty()){
    q.pop();
  }

  q.push({start,INFI,0});

  while(!q.empty()){
    node=q.top();
    q.pop();

    if(node.cost==dina[node.nod].cost){
      for(NOD neigh : graf[node.nod]){
        if(neigh.cap>0){
          int costNou=node.cost-dina[neigh.neigh].distFalsa+dina[node.nod].distFalsa+neigh.cost;
          if(costNou<dina[neigh.neigh].cost){
            dina[neigh.neigh].cost=costNou;
            dina[neigh.neigh].fath=node.nod;
            dina[neigh.neigh].flow=min(node.flow,neigh.cap);
            q.push({neigh.neigh,min(node.flow,neigh.cap),costNou});
          }
        }
      }
    }
  }
}

void BackTrack(DIN scos){
  int x,fiu;

  x=desti;
  fiu=-1;

  while(x!=start){
    if(fiu!=-1){
      graf[x][hart[{x,fiu}]].cap-=scos.flow;
      graf[fiu][hart[{fiu,x}]].cap+=scos.flow;
    }

    fiu=x;
    x=dina[x].fath;
  }

  graf[x][hart[{x,fiu}]].cap-=scos.flow;
  graf[fiu][hart[{fiu,x}]].cap+=scos.flow;
}

void Bellman(){
  int i;

  for(i=1;i<=n;i++){
    dina[i].distFalsa=INFI;
  }

  dina[start].distFalsa=0;

  for(i=1;i<=n;i++){
    for(NOD neigh : bell){
      if(neigh.cap>0){
        if(dina[neigh.neigh].distFalsa>dina[neigh.node].distFalsa+neigh.cost){
          dina[neigh.neigh].distFalsa=dina[neigh.node].distFalsa+neigh.cost;
        }
      }
    }
  }
}

void PushFlux(){
  DIN aux;

  Bellman();
  rasp=0;
  aux={0,0,0,0};

  do{
    InitDinamica();
    Dijkstra();
    aux=dina[desti];
    if(aux.cost!=INFI){
      BackTrack(aux);
    }
  }while(aux.cost!=INFI);
}

void CalculateRasp(){
  int i;

  for(i=1;i<=n;i++){
    for(NOD nod : graf[i]){
      if(nod.org==0){
        rasp+=-nod.cost*nod.cap;
      }
    }
  }
}

void Read(){
  int i,a,b,c,z;

  fscanf(fin,"%d%d%d%d",&n,&m,&start,&desti);
  for(i=0;i<m;i++){
    fscanf(fin,"%d%d%d%d",&a,&b,&c,&z);
    AddEdge(a,b,c,z);
  }
}

void CloseRead(){
  fclose(fin);
  fclose(fout);
}

int main(){

  InitRead();
  Read();
  PushFlux();
  CalculateRasp();

  fprintf(fout,"%d\n",rasp);

  CloseRead();
  return 0;
}
