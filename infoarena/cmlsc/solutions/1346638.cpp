///CMLSC
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

int main() {
    ifstream inStr("cmlsc.in");
    ofstream outStr("cmlsc.out");

    int N, M;
    inStr >> N >> M;

    vector<vector<int> > best(N+1, vector<int>(M+1, 0));
    vector<int> A(N);
    vector<int> B(M);

    for(int i=0; i<N; ++i)
        inStr >> A[i];
    for(int i=0; i<M; ++i)
        inStr >> B[i];

    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            if(A[i - 1] == B[j - 1])
                best[i][j] = best[i-1][j-1] + 1;
            else
                best[i][j] = max(best[i][j-1], best[i-1][j]);

    outStr << best[N][M] << '\n';

    int i = N, j = M;
    list<int> answ;

    while(best[i][j] != 0)
        if(best[i][j-1] + 1 == best[i][j]) {
            answ.push_back(B[j-1]);
            --j;
            --i;
        } else
            if(best[i-1][j] + 1 == best[i][j]) {
                answ.push_back(A[i-1]);
                --j;
                --i;
            } else --j;

    for(list<int>::reverse_iterator it = answ.rbegin(); it != answ.rend(); ++it)
        outStr << *it << ' ';
    outStr << '\n';

    return 0;
}
