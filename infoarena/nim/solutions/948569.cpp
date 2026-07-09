#include<fstream>
using namespace std;ifstream f("nim.in");ofstream g("nim.out");int x,n,X,t;int main(){f>>n;while(n--){f>>t;X=0;while(t--){f>>x;X^=x;}if(X)g<<"DA\n";else g<<"NU\n";}return 0;}