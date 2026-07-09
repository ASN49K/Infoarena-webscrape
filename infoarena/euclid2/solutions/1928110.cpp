#include <fstream>
using namespace std;int e(int a, int b){if(!b) return a;e(b,a%b);}int main(){ ifstream i("euclid2.in"); ofstream o("euclid2.out");int t,a,b,i;in>>t;for (i=0;i<t;i++){i>>a>>b;o<<e(a,b)<<'\n';}in.close();out.close();return 0;}
