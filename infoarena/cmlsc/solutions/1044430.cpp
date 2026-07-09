#include <iostream>
#include <cstdio>
#define max(a,b) (a>b)?a:b
using namespace std;

int table[1025][1025];
int a[1025],b[1025];
int n,m;
void scan(){

  scanf("%d %d",&n,&m);

  for(int i = 1; i <= n; i++)
      scanf("%d",&a[i]);

  for(int i = 1; i <= m; i++)
    scanf("%d",&b[i]);

}

void subseq(int i,int j){


  if( i == 0)
    return;
  if (j == 0)
    return;
  if(a[i] == b[j])
  {
    subseq(i-1,j-1);
    cout << a[i] << " ";
    return;
  }
  if(table[i][j-1] > table[i-1][j])
    subseq(i,j-1);
  else
    subseq(i-1,j);

}

void solve(){


  for(int i =1 ; i <= n; i++){
    for(int j = 1 ; j <= m; j++){
      if(b[j] == a[i])
	table[i][j] = table[i-1][j-1]+1;
      else
	table[i][j] = max(table[i-1][j],table[i][j-1]);
    }

  }

  cout << table[n][m] << endl;

}

int main(){

  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
scan();
solve();
subseq(n,m);
}