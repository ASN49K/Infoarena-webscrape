#include <fstream>
using namespace std;ifstream f("clasic.in");ofstream g("clasic.out");int T,N,S,s;int main(){f>>T;for(;T--;){f>>N>>S;for(;--N;)f>>s,S^=s;g<<S<<'\n';}return 0;}
