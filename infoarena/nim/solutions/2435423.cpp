#include <fstream>
std::ifstream f("nim.in");std::ofstream g("nim.out");int t,n,sum,k;int main(){f>>t;while(t--){f>>n>>sum;while(--n){f>>k;sum^=k;}g<<(sum?"DA\n":"NU\n");}}
