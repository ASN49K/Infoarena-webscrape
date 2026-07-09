#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,x,y;
int euclid(int a,int b){
    int r;
    if(a<b)
        swap(a,b);
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>x>>y;
        fout<<euclid(x,y)<<'\n';
    }

    return 0;
}
