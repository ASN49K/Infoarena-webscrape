#include <fstream>
using namespace std;ifstream f("nim.in");ofstream g("nim.out");int n,t,s,x;int main(){f>>t;while(t--){f>>n;s=0;while(n--)f>>x,s^=x;if(s)g<<"DA\n";else g<<"NU\n";}}
