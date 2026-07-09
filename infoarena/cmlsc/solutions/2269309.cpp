#include <iostream>
#include <fstream>

using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

int main()
{
    int v[1025],vf[1025],i,j,t,it=0,poz=0,N,M;
    input >> M >> N;
    for(i=0;i<M;i++) {
        input >> v[i];
    }
    for(i=0;i<N;i++) {
        input >> t;
        for(j=poz;j<M;j++) {
            if(t==v[j]) {
                poz=j;
                vf[it]=v[j];
                it++;
                break;
            }
        }
    }
    output << it << "\n";
    for(i=0;i<it;i++) output << vf[i] << " ";
    return 0;
}
