#include<fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n,i,t,x,sol,w;

int main(){

    fin>>t;
    for(w=1;w<=t;w++){
        fin>>n;
        for(i=1;i<=n;i++){
            fin>>x;
            if(i!=1)
                sol=sol^x;
            else
                sol=x;
        }
        if(sol==0){
            fout<<"NU"<<"\n";
        }
        else{
            fout<<"DA"<<"\n";
        }
    }
    return 0;
}
