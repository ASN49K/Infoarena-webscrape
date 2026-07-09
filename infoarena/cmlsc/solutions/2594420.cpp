#include <iostream>
#include <fstream>
#include <vector>

#define max(a, b) ((a>b) ? a : b)
#define min(a, b) ((a<b) ? a : b)

using namespace std;

    ifstream fin("C:\\Users\\Eduard\\Documents\\CLionProjects\\subsiruri\\cmlsc.in");
    ofstream fout("C:\\Users\\Eduard\\Documents\\CLionProjects\\subsiruri\\cmlsc.out");

int main() {
    int N, M;
    fin >> N >> M;

    vector <int> A(N);
    vector <int> B(M);
    vector <int> subsir;

    for(int i = 0; i<N; i++){
        fin >> A[i];
    };
    for(int i = 0; i<M; i++){
        fin >> B[i];
    };

    for(int i = 0; i<max(N, M); i++){
        for(int j = 0; j<min(N, M); j++){
                if(A[i] == B[j]) subsir.push_back(A[i]);
        };
    };

    fout << subsir.size() << endl;
    for(int i = 0; i<subsir.size(); i++){
            fout << subsir[i] << " ";
    }

    return 0;
}