#include <fstream>
using namespace std;ifstream f("nim.in");ofstream g("nim.out");int main(){int t,n,s,x,i;f>>t;while(t--){s=0;f>>n;for(i=1;i<=n;i++){f>>x;s^=x;}(s)?g<<"DA":g<<"NU";g<<'\n';}return 0;}