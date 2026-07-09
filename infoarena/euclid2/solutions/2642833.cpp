#include <fstream>
std::ifstream in("euclid2.in");std::ofstream out("euclid2.out");
int e(int a,int b){return b?e(b,a%b):a;}
int main(){int t,a,b;for(in>>t;t--;){in>>a>>b;out<<e(a,b)<<'\n';}}