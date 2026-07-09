#include <fstream>
std::ifstream f("nim.in");std::ofstream g("nim.out");
main(){int n,t,s,x;f>>t;while(t--){f>>n;s=0;while(n--)f>>x,s^=x;g<<(s?"DA\n":"NU\n");}}
