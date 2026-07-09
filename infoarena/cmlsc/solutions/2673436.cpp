#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int A[1025];
int B[1025];
int Aa[1025];
int Bb[1025];
int result[1025];

vector<int> hashtableM[257];
vector<int> hashtableN[257];

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    ios::sync_with_stdio(false);
    fout.tie(nullptr);

    int M, N, a = 0, b = 0, cnt = 0;
    fin >> M >> N;

    for (int i = 1; i <= M; ++i) {
        fin >> A[i];
        int key = A[i];
        hashtableM[key].push_back(A[i]);
    }
    for (int i = 1; i <= N; ++i) {
        fin >> B[i];
        int key = B[i];
        hashtableN[key].push_back(B[i]);
    }

    for (int i = 1; i <= M; ++i) {
        int key = A[i];
        if (hashtableN[key].size() != 0) {
            a += 1;
            Aa[a] = hashtableM[key][0];
            hashtableM[key].pop_back();
            hashtableN[key].pop_back();
        }
    }

    for (int i = 1; i <= M; ++i) {
        int key = A[i];
        hashtableM[key].push_back(A[i]);
    }
    for (int i = 1; i <= N; ++i) {
        int key = B[i];
        hashtableN[key].push_back(B[i]);
    }

    for (int i = 1; i <= N; ++i) {
        int key = B[i];
        if (hashtableM[key].size() != 0) {
            b += 1;
            Bb[b] = hashtableN[key][0];
            hashtableM[key].pop_back();
            hashtableN[key].pop_back();
        }
    }

    for (int i = 1; i <= a; ++i) {
        if (Aa[i] == Bb[i]) {
            cnt += 1;
            result[cnt] = Aa[i];
        }
    }
    fout << cnt << "\n";
    for (int i = 1; i <= cnt; ++i) {
        fout << result[i] << " ";
    }


    return 0;
}
