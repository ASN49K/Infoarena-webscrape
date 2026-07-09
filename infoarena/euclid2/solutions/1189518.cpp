#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, x, y, aux, i;
int main(){
    fin>>n;
    for(i=1; i<=n; i++){
        fin>>x>>y;
        while(x>0 && y>0){
            if(x>y)
                x=x%y;
            else
                y=y%x;
        }
        if(x==0)
            fout<<y<<"\n";
        else
            fout<<x<<"\n";
    }


    return 0;
}
