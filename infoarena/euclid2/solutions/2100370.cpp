#include <fstream>


using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int divizor(int a,int b){
while(a!=b){
    if(a>b) a=a-b;
    else b=b-a;
}
return a;
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
