#include <iostream>
#include<fstream>
using namespace std;ifstream f("euclid2.in");ofstream g("euclid2.out");
int c(int a,int b){int r;while(b){r=a%b;a=b;b=r;;}return a;}
int main()
{int n,a,b,i;f>>n;for(i=1;i<=n;i++){f>>a>>b;g<<c(a,b)<<endl;}}
