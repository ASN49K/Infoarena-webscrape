#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
struct edge{
  int x, c;
};
int n;
vector<edge> gr[N];
long long dst[N];
edge dd[N];
int inord[N], outord[N];
int ord[N];
void dfs_max_dist(int nod, int dad, long long cdist, long long &mdist, int &nmdist){
  if(cdist > mdist){
    mdist = cdist;
    nmdist = nod;
  }
  for(auto x:gr[nod]){
    if(x.x == dad)
      continue;
    dfs_max_dist(x.x, nod, cdist + x.c, mdist, nmdist);
  }
}
void dfs_ord(int nod, int dad, int &cnt){
  ord[++cnt] = nod;
  inord[nod] = cnt;
  for(auto x:gr[nod]){
    if(x.x == dad){
      dd[nod] = x;
      continue;
    }
    dst[x.x] = dst[nod] + 1LL * x.c;
    dfs_ord(x.x, nod, cnt);
  }
  outord[nod] = cnt;
}
struct ainthelper{
  long long mxv;
  int idm;
};
ainthelper join(ainthelper a, ainthelper b){
  if(a.mxv >= b.mxv)
    return a;
  return b;
}
ainthelper aint[4*N];
long long lazy[4*N];
void build(int nod, int l, int r){
  if(l == r){
    aint[nod] = {dst[ord[l]], ord[l]};
    return;
  }
  int mid = (l + r)/2;
  build(2*nod, l, mid);
  build(2*nod + 1, mid + 1, r);
  aint[nod] = join(aint[2*nod], aint[2*nod + 1]);
}
void propag(int nod, int l, int r){
  aint[nod].mxv += lazy[nod];
  if(l != r){
    lazy[2*nod] += lazy[nod];
    lazy[2*nod + 1] += lazy[nod];
  }
  lazy[nod] = 0;
}
void update(int nod, int l, int r, int ul, int ur, long long val){
  propag(nod, l, r);
  if(r < ul || l > ur)
    return;
  if(ul <= l && r <=ur){
    lazy[nod] += val;
    propag(nod, l, r);
    return;
  }
  int mid = (l + r)/2;
  update(2*nod, l, mid, ul, ur, val);
  update(2*nod + 1, mid + 1, r, ul, ur, val);
  aint[nod] = join(aint[2*nod], aint[2*nod + 1]);
}
bool marked_tree[N];
long long mindist[N];
long long dsttotree[N];
void dfs_totree(int nod, int dad, long long dst){
  dsttotree[nod] = dst;
  for(auto x:gr[nod]){
    if(x.x == dad || marked_tree[x.x])
      continue;
    dfs_totree(x.x, nod, dst+ x.c);
  }
}
int main()
{
  int k;
  cin>>n>>k;
  for(int i =1 ; i<n; i++){
    int x, y, c;
    cin>>x>>y>>c;
    gr[x].push_back({y, c});
    gr[y].push_back({x, c});
  }
  long long mdst = -1;
  int root = 1;
  dfs_max_dist(1, 0, 0, mdst, root);
  int cnt = 0;
  dfs_ord(root, 0, cnt);
  build(1, 1, n);
  long long cost = 0;
  long long costk = 0;
  vector<int> leaves;
  leaves.push_back(root);
  marked_tree[root] = 1;
  for(int nri = 1; nri <= k; nri++){
    propag(1, 1, n);
    ainthelper ovr = aint[1];

    if(ovr.mxv == 0){
      break;
    }
    cost += ovr.mxv;
    int nod = ovr.idm;
    leaves.push_back(nod);
    while(marked_tree[nod] == false){
      marked_tree[nod] = true;
      update(1, 1, n, inord[nod], outord[nod], -dd[nod].c);
      nod = dd[nod].x;
    }
    if(nri + 1 <= k)
      costk = cost;
  }
  for(int i =1 ;i <=n; i++){
    mindist[i] = LLONG_MAX;
  }
  priority_queue<pair<long long, int>> pq;
  for(auto x:leaves){
    mindist[x] = 0;
    pq.push({0, x});
  }
  while(pq.size()){
    int nod = pq.top().second;
    long long val = pq.top().first;
    pq.pop();
    if(val > mindist[nod])
      continue;
    for(auto x:gr[nod]){
      if(mindist[x.x] > val + x.c){
        mindist[x.x] = val + x.c;
        pq.push({mindist[x.x], x.x});
      }
    }
  }
  for(int i = 1; i<=n; i++){
    if(marked_tree[i])
      dfs_totree(i, 0, 0);
  }
  for(int i =1 ; i<=n; i++){
    cout<<dsttotree[i] + max(costk, cost - mindist[i])<<"\n";
  }
  return 0;
}
