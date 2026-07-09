#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,i,a,b,c;

int main(){
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>a>>b;
        while(a!=0&&b!=0)
            if(a>b){
                c=a%b;
                a=c;
            }else{
                c=b%a;
                b=c;
            }
        fout<<a+b<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
