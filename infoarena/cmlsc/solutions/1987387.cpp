#include <iostream>
#include <fstream>
#include <vector>
#define MAX 1025

using namespace std;

int lsmax,a[MAX],b[MAX],lmax,n,m;
vector <int> s,rez;

void ver(int l1,int l2,int lung){
  if(lung>lmax){
    lmax=lung;
    rez=s;
  }
  if(l1==n||l2==m) return;
  else{
    //cout<<l1<<" "<<l2<<" "<<lung<<'\n';
    for(int i=l1+1;i<=n;i++)
      for(int j=l2+1;j<=m;j++){
        if(a[i]==b[j]){
          s.push_back(a[i]);
          ver(i,j,lung+1);
          s.pop_back();
        }
      }
  }
}

int main()
{
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];
    ver(0,0,0);
    g<<lmax<<'\n';
    for(int i=0;i<rez.size();i++)g<<rez[i]<<" ";
    f.close ();
    g.close ();
    return 0;
}
