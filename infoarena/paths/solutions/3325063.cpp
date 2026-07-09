#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100000;
const long long INF = 1e18;
long long rez[MAXN + 1], maxr2[MAXN + 1], dist[MAXN + 1], sumr[MAXN + 1];
int best[MAXN + 1], best2[MAXN + 1], par[MAXN + 1], best2sub[MAXN + 1];//best2sub[i] este al doilea maxim din subarbore care provine dintr-un fiu diferit
//in best[i] este nodul cu costul maxim de la nod la i care se afla in subarborele lui i si in maxr este costul de pe drum(am scos maxr ca era inutil)
//si best2 si maxr2 sunt din afara subarborelui
vector<int> adj[MAXN + 1];
vector<int> cost[MAXN + 1];
map<long long, int> frk;
map<long long, int> fr;
map<long long, int>::iterator it;
long long rezp;
struct frunza {//cele care nu sunt frunze au contributia 0 deci nu conteaza, caz particular daca 1 este frunza
    long long contrib;
    int poz;
} v[MAXN + 1];
char cmp(frunza a, frunza b) {
    return a.contrib > b.contrib;
}
void dfs(int nod) {
    int x, nr, i;
    nr = adj[nod].size();
    best[nod] = nod;
    best2[nod] = best2sub[nod] = 0;
    for (i = 0; i < nr; i++) {
        x = adj[nod][i];
        if (par[x] < 0) {
            par[x] = nod;
            dist[x] = dist[nod] + cost[nod][i];
            dfs(x);
            if (dist[best[x]] > dist[best[nod]]) {//raspunsul va fi o frunza mereu
                best2sub[nod] = best[nod];
                best[nod] = best[x];
            } else if (dist[best[x]] > dist[best2sub[nod]]) {
                best2sub[nod] = best[x];
            }
        }
    }
}
void dfs2(int nod) {//ca sa calculez best2
    int x, nr, i, z;
    nr = adj[nod].size();
    if (nod == 1) {
        v[best[1]].contrib = dist[best[1]];//la radacina
    }
    for (i = 0; i < nr; i++) {
        x = adj[nod][i];
        if (par[x] == nod) {
            if (best[nod] == best[x]) {
                z = best2sub[nod];
            } else {
                z = best[nod];
            }
            //verific daca este din subarborele celorlati fii sau din afara subarborelui parintelui lui x
            if (dist[z] - dist[nod] > maxr2[nod]) {
                maxr2[x] = dist[z] - dist[nod] + cost[nod][i];
                best2[x] = z;
            } else {
                maxr2[x] = maxr2[nod] + cost[nod][i];
                best2[x] = best2[nod];
            }
            dfs2(x);
            if (best[x] != best[nod]) {
                v[best[x]].contrib = dist[best[x]] - dist[nod];
            }
        }
    }
}
void scadfk(long long val) {
    frk[val]--;
    if (frk[val] == 0) {
        frk.erase(val);
    }
}
void scadf(long long val) {
    fr[val]--;
    if (fr[val] == 0) {
        fr.erase(val);
    }
}
void scad(int nod, int val) {
    long long mink, max2;
    it = frk.begin();
    mink = it->first;
    it = fr.end();
    it--;
    max2 = it->first;
    if (sumr[nod] >= mink) {//daca sunt egale mink cu max2 nu cred ca conteaza
        scadfk(sumr[nod]);

        sumr[nod] -= val;
        if (sumr[nod] >= max2) {
            //ramane tot in primele k maxime
            frk[sumr[nod]]++;
            rezp -= val;
        } else {
            rezp -= (sumr[nod] + val - max2);
            fr[sumr[nod]]++;
            scadf(max2);
            frk[max2]++;
        }
    } else {
        scadf(sumr[nod]);
        sumr[nod] -= val;
        fr[sumr[nod]]++;
    }
}
void adun(int nod, int val) {
    long long mink;
    it = frk.begin();
    mink = it->first;
    if (sumr[nod] >= mink) {//daca sunt egale mink cu max2 nu cred ca conteaza
        scadfk(sumr[nod]);

        sumr[nod] += val;
        rezp += val;
        frk[sumr[nod]]++;
    } else {
        scadf(sumr[nod]);
        sumr[nod] += val;
        if (sumr[nod] <= mink) {//ramane tot in cele mici
            fr[sumr[nod]]++;
        } else {
            rezp += sumr[nod] - mink;
            frk[sumr[nod]]++;
            scadfk(mink);
            fr[mink]++;
        }
    }
}
void dfs3(int nod) {
    int x, nr, i;
    nr = adj[nod].size();
    for (i = 0; i < nr; i++) {
        x = adj[nod][i];
        if (par[x] == nod) {
            rezp = rez[nod];
            scad(best[x], cost[nod][i]);
            adun(best2[x], cost[nod][i]);
            rez[x] = rezp;
            dfs3(x);
            //le facla loc cum erau inainte sa schimb radacina din nod in x
            adun(best[x], cost[nod][i]);
            scad(best2[x], cost[nod][i]);
        }
    }
}
int main()
{
    //O(n * log)
    int n, k, i, x, y, c;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &x, &y, &c);
        adj[x].push_back(y);
        adj[y].push_back(x);
        cost[x].push_back(c);
        cost[y].push_back(c);
        par[i + 2] = -1;
    }
    //conteaza doar frunzele, dar la restul voi pune contributia 0 ca nu va strica rezultatul
    //greedy, la fiecare tin cu cat contribuie la rezultat
    //si rerooting cu 2 mapuri ca se schimba doar 2 valori cand schimb radacina(primul map e cu cele mai mari k sume) si al doilea cu restul
    par[1] = 0;
    dist[0] = -INF;
    dfs(1);
    maxr2[1] = -INF;
    dfs2(1);
    for (i = 1; i <= n; i++) {
        v[i].poz = i;
    }
    sort(v + 1, v + n + 1, cmp);
    for (i = 1; i <= k; i++) {
        sumr[v[i].poz] = v[i].contrib;
        frk[v[i].contrib]++;
        rez[1] += v[i].contrib;
    }
    for (; i <= n; i++) {
        sumr[v[i].poz] = v[i].contrib;
        fr[v[i].contrib]++;
    }
    dfs3(1);//rerooting
    for (i = 1; i <= n; i++) {
        printf("%lld\n", rez[i]);
    }
    return 0;
}
