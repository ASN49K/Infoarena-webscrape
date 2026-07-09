#include <fstream>

using namespace std;

ifstream fin("algsort.in");
ofstream fout("algsort.out");

int N;
int V[500005];

void quickSort(int l, int r)
{
    int i = l, j = r;
    int pivot = V[(l + r) / 2];

    while (i <= j)
    {
        while (V[i] < pivot)
            ++i;
        while (V[j] > pivot)
            --j;

        if (i <= j)
        {
            int aux = V[i];
            V[i] = V[j];
            V[j] = aux;
            ++i;
            --j;
        }
    }

    if (l < j)
        quickSort(l, j);
    if (i < r)
        quickSort(i, r);
}

int main()
{
    fin >> N;
    for (int i = 1; i <= N; ++i)
        fin >> V[i];

    quickSort(1, N);

    for (int i = 1; i <= N; ++i)
        fout << V[i] << ' ';
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
