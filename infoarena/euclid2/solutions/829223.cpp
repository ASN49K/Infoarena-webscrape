#include<fstream>
using namespace std;
int main()
{ifstream i("euclid2.in");ofstream o("euclid2.out");int n,a,b;i>>n;for(int x=1;x<=n;x++){i>>a>>b;while(a!=b){if(a>b) a-=b;else b-=a;}o<<a<<" \n";}return 0;}