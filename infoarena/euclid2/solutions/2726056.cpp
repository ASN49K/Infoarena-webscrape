#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main(){
int t;
cin>>t;
while(t){
  int a,b;
  cin>>a>>b;
  while(b!=0){
    int r=a%b;
    a=b;
    b=r;
  }
  cout<<a<<'\n';
t--;
}


  return 0;
}
