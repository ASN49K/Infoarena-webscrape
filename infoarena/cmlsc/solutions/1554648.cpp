#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m;
    int x1[1030], x2[1030];
    vector<int> solutie;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x1[i]);
    }

    for(int j = 0; j < m; j++)
    {
        scanf("%d", &x2[j]);
    }

    int l = 0;

    int nrx = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = nrx; j < m; j++)
        {
            if(x1[i] == x2[j])
            {
                solutie.push_back(x1[i]);
                nrx = j;
            }
        }
    }

    int lungime = solutie.size();

    printf("%d\n", solutie.size());

    for(int i = 0; i < lungime; i++)
    {
        printf("%d ", solutie[i]);
    }


//    int y1[1030];
//    int y2[1030];
//    int nr = 0;
//
//    for(int i = 0; i < 1030; i++)
//    {
//        y1[i] = y2[i] = 0;
//    }
//
//    int lung = 0;
//
//    for(int i = 0; i < lungime; i++)
//    {
//        for(int j = 0; j < 1030; j++)
//        {
//            if(y2[j] == 0 || y2[j] >= solutie[i])
//            {
//                if(y2[j] == 0)
//                {
//                    lung++;
//                }
//
//                y2[j] = solutie[i];
//                y1[i] = j;
//                break;
//            }
//        }
//    }
//
//    vector<int> solutieFinala;
//
//    lung--;
//
//    for(int i = lungime - 1; i >= 0; i--)
//    {
//        if(y1[i] == lung)
//        {
//            solutieFinala.push_back(solutie[i]);
//            lung--;
//        }
//    }
//
//    printf("%d\n", solutieFinala.size());
//
//    for(int i = solutieFinala.size() - 1; i >= 0; i--)
//    {
//        printf("%d ", solutieFinala[i]);
//    }

    return 0;
}
