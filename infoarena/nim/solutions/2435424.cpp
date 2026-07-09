#include <fstream>
std::ifstream f("nim.in");std::ofstream g("nim.out");int t,n,s,k;main(){f>>t;while(t--){f>>n>>s;while(--n)f>>k,s^=k;g<<(s?"DA\n":"NU\n");}}
