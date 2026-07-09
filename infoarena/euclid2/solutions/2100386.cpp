#include <fstream>


using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int divizor(int a,int b){
    int r,aux;

    r=a%b;
while(r!=0){
  a=b;
  b=r;
  r=a%b;
}
return b;
}
int main()
{ int i,n,a,b;
f>>n;
for(i=1;i<=n;i++){
    f>>a>>b;
    g<<divizor(a,b)<<endl;

}

    return 0;
}
