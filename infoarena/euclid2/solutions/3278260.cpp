#include <fstream>
int n; std::ifstream fin ("euclid2.in"); std::ofstream fout ("euclid2.out");
inline int euclid(int a,int b){int r=0;while(b!=0){r=a%b;a=b;b=r;}return a;}
int main(){ fin >> n;for(int i=1;i<=n;i++){int x,y;fin >> x >> y;fout <<euclid(x,y) << '\n';} return 0;}