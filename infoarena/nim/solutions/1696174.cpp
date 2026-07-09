#include <fstream>
using namespace std;ifstream fin("nim.in");ofstream fout("nim.out");int n,t,s,x;int main(){fin>>t;while(t--){fin>>n;s=0;while(n--)fin>>x,s^=x;if(s)fout<<"DA\n";else fout<<"NU\n";}}
