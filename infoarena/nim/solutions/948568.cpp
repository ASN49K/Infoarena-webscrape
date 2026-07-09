#include<fstream>
using namespace std;ifstream f("nim.in");ofstream g("nim.out");int x,n,X;int main(){f>>n;while(n--){f>>x;X^=x;}if(X)g<<"DA";else g<<"NU";return 0;}