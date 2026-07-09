#include <iostream>
#include <fstream>

using namespace std;

int vf[1025],M,N;

int cmlsc(int v1[], int v2[]) {
    int MAX=0;
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(v1[i] == v2[j]) {
                vf[MAX]=v1[i];
                MAX++;
            }
        }
    }
    return MAX;
}

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

int main()
{
    int a[1025],b[1025];
    input >> M >> N;
    for(int i=0;i<M;i++) {
        input >> a[i];
    }
    for(int i=0;i<N;i++) {
        input >> b[i];
    }
    int ind=cmlsc(a,b);
    output << ind << "\n";
    for(int i=0;i<ind;i++) {
        output << vf[i] << " ";
    }
    return 0;
}
