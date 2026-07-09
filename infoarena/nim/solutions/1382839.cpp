#include<fstream>
using namespace std;ifstream fin("nim.in");ofstream fout("nim.out");int main() {int t,n,s,x,sum;fin>>t;while(t--){fin>>n;sum=0;while(n--)fin>>x,sum^=x;fout<<((sum!=0)?"DA\n":"NU\n");}return 0;}
