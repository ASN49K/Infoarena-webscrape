#include <fstream>

using namespace std;
int euclid(int a,int b){
    int r;
    if(a>b){
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    else if(b>a){
        while(a!=0){
            r=b%a;
            b=a;
            a=r;
        }
    }
    return b;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n,i,x,y;
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>x>>y;
        fout<<euclid(x,y)<<"\n";
    }
    return 0;
}
