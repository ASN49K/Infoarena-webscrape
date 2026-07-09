#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");
int T,N,XOR,Cluster_Value;
int main(){
    fin>>T;
    while(T--){

        fin>>N;

        XOR=0;

        while(N--){

            fin>>Cluster_Value;

            XOR = XOR ^ Cluster_Value;

        }
        if( XOR )
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    fin.close();fout.close();
    return 0;
}
