#include <fstream>
#include <inttypes.h>

using namespace std;

struct Arrow {
    uint8_t sense:3;

    Arrow() {
        sense = 0;
    }

    void addUp() {
        sense |= 1;
    }

    void addUpperLeft() {
        sense |= 2;
    }

    void addLeft() {
        sense |= 4;
    }


    bool hasUp() const {
        return (sense & 1) != 0;
    }

    bool hasUpperLeft() const {
        return (sense & 2) != 0;
    }

    bool hasLeft() const {
        return (sense & 4) != 0;
    }

};

struct Array {
    int *list;
    int size;

    Array() {
        list = nullptr;
        size = 0;
    }

    Array(int initialCapacity) {
        list = new int[initialCapacity];
        size = 0;
    }
};

Array findLCS(const int *s1, const int &M, const int *s2, const int &N) {
    int lcs[M + 1][N + 1];
    int i, j;

    Arrow road[M + 1][N + 1];

    for (i = 0; i <= M; i++)
        lcs[i][0] = 0;

    for (j = 0; j <= N; j++)
        lcs[0][j] = 0;

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                road[i][j].addUpperLeft();
            } else {
                if (lcs[i - 1][j] > lcs[i][j - 1]) {
                    lcs[i][j] = lcs[i - 1][j];
                    road[i][j].addUp();
                } else if (lcs[i - 1][j] < lcs[i][j - 1]) {
                    lcs[i][j] = lcs[i][j - 1];
                    road[i][j].addLeft();
                } else {
                    lcs[i][j] = lcs[i][j - 1];
                    road[i][j].addLeft();
                    road[i][j].addUp();
                }
            }
        }
    }

    if (lcs[M][N] == 0)
        return Array{};

    int k = lcs[M][N];
    int *result = new int[k];
    int m = M, n = N;

    while (k > 0) {
        if (road[m][n].hasUpperLeft()) {
            result[--k] = s1[m - 1];
            --m;
            --n;
        } else if (road[m][n].hasLeft()) {
            --n;
        } else {
            --m;
        }
    }

    Array wrapper;
    wrapper.list = result;
    wrapper.size = lcs[M][N];
    return wrapper;
}

int main(void) {
    const string INPUT_FILENAME = "cmlsc.in";
    const string OUTPUT_FILENAME = "cmlsc.out";

    ifstream input(INPUT_FILENAME);
    ofstream output(OUTPUT_FILENAME);

    int M, N, i;
    input >> M >> N;

    int s1[M], s2[N];
    for (i = 0; i < M; i++)
        input >> s1[i];
    for (i = 0; i < N; i++)
        input >> s2[i];

    Array lcs = findLCS((int *) s1, M, (int *) s2, N);

    output << lcs.size << "\n";

    for (i = 0; i < lcs.size; i++)
        output << lcs.list[i] << " ";

    delete[] lcs.list;

    input.close();
    output.close();
    return 0;
}
