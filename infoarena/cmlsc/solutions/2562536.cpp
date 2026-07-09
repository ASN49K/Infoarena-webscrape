#include <iostream>
#include <fstream>
#include <algorithm>

#define x first
#define y second

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, k, pos1, pos2, cnt;
int a[1025], b[1025];
bool auxfr[260], fr[260];
pair < int, int > p[1025];

int main()
{
    in >> n >> m;
    for(int i = 1; i <= n; ++ i)
    {
        in >> a[i];
        auxfr[a[i]] = 1;
    }
    for(int i = 1; i <= m; ++ i)
    {
        in >> b[i];
        fr[b[i]] = auxfr[b[i]];
    }
    for(int i = 1; i <= 256; ++ i)
        if(fr[i])
        {
            ++ k;
            for(int j = 1; j <= n; ++ j)
                if(a[j] == i)
                {
                    p[k].x = j;
                    break;
                }
            for(int j = 1; j <= m; ++ j)
                if(b[j] == i)
                {
                    p[k].y = j;
                    break;
                }
        }
    sort(p + 1, p + k + 1);

    if(k)
        cnt = 1;

    pos1 = p[1].x;
    pos2 = p[1].y;

    for(int i = 2; i <= k; ++ i)
        if(p[i].x > pos1 && p[i].y > pos2)
        {
            ++ cnt;
            pos1 = p[i].x;
            pos2 = p[i].y;
        }

    out << cnt << '\n';

    pos1 = p[1].x;
    pos2 = p[1].y;

    out << a[pos1] << " ";

    for(int i = 2; i <= k; ++ i)
        if(p[i].x > pos1 && p[i].y > pos2)
        {
            ++ cnt;
            pos1 = p[i].x;
            pos2 = p[i].y;
            out << a[pos1] << " ";
        }

//    for(int i = 1; i <= k; ++ i)
//        cout << p[i].x << " " << p[i].y << '\n';
    return 0;
}
