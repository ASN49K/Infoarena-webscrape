/*
                `-/oo+/-   ``
              .oyhhhhhhyo.`od
             +hhhhyyoooos. h/
            +hhyso++oosy- /s
           .yoooossyyo:``-y`
            ..----.` ``.-/+:.`
                   `````..-::/.
                  `..```.-::///`
                 `-.....--::::/:
                `.......--::////:
               `...`....---:::://:
             `......``..--:::::///:`
            `---.......--:::::////+/`
            ----------::::::/::///++:
            ----:---:::::///////////:`
            .----::::::////////////:-`
            `----::::::::::/::::::::-
             `.-----:::::::::::::::-
               ...----:::::::::/:-`
                 `.---::/+osss+:`
                   ``.:://///-.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <cmath>
#define INF 0x3f3f3f3f
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int n, q, nr, xorr;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        xorr = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &nr);
            xorr = xorr ^ nr;
        }
        if(xorr == 0) printf("NU\n");
        else printf("DA\n");
    }
    return 0;
}
