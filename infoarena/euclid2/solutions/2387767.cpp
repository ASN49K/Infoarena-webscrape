#include<fstream>
using namespace std;
int euclid(int a,int b){
    if(b==9)
        return a;
    else
        return(a,a%b);
}
int main(){
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
fin>>n;
    for(int i=1;i<=n;++i){
        fin>>a>>b;
            if(a<b){
        int temp=a;
        a=b;
        b=temp;
    }
       fout<<euclid(a,b);
    }

}
