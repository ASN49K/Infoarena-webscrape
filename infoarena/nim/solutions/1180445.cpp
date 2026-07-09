#include<fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

int main() {

    int T,sol,N,i,x;
    in>>T;
    while(T--) {
        sol=0;
        in>>N;
        for(i=1;i<=N;i++){
            in>>x;
            sol^=x;
        }
        if(sol)
            out<<"DA"<<'\n';
        else
            out<<"NU"<<'\n';

    }

    in.close();
    out.close();
    return 0;

}
