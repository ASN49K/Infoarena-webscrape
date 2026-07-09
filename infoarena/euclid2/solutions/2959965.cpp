#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Result{
  T x,y,z;
  void euclid(T a, T b){
    if(b==0){
      x=1;
      y=0;
      z=a;
    }else{
      euclid(b,a%b);
    }
  }
};
typedef long long ll;
/*
#ifdef ONPC
const int N=10000;
#else
const int N=31623776;
#endif // ONPC
bool isprime[N];
vector<int> p;
*/
int main(){
#ifdef ONPC
  freopen("input.txt","r",stdin);
  ///freopen("output.txt","w",stdout);
#else
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif // ONPC

  Result<ll> it;
  int t;
  cin>>t;
  while(t--){
    ll a, b;
    cin>>a>>b;
    it.euclid(a,b);
    cout<<it.z<<"\n";
  }

  exit(0);

  /*isprime[2]=1;
  for(int i=3;i<N;i+=2)isprime[i]=1;
  for(int i=3;i*i<N;i+=2)if(isprime[i]){
    for(int j=i*i;j<N;j+=2*i){
      isprime[j]=0;
    }
  }
  for(int i=0;i<N;i++){
    if(isprime[i]){
      p.push_back(i);
    }
  }
  map<ll,vector<ll>> mpdivis;
  int q;
  cin>>q;
  while(q--){
    ll number,sc;
    cin>>number>>sc;
    if(!mpdivis.count(sc)){
      ll ini=sc;
      for(auto&dv:p){
        if(sc%dv==0){
          while(sc%dv==0)sc/=dv;
          mpdivis[ini].push_back(dv);
        }
      }
      if(sc>1)mpdivis[ini].push_back(sc);
      sc=ini;
    }
    vector<ll> divis=mpdivis[sc];
    int k=(int)divis.size();

    if(1){
      cout<<" ---> ";
      for(auto&x:divis){
        cout<<x<<" ";
      }
      cout<<"\n";
    }
  }
*/
}
/**

**/
