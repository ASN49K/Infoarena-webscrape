#include<bits/stdc++.h>
using namespace std;
ifstream in("paths.in");
ofstream out("paths.out");
const int N = 200001;
int n,k,e,T[N],F[N],g[N],lf,u=1,a,b,getLeaf(int nod);
int64_t sol[N],cT[N],cD[N],costAll,*DU,*DA,*DB,U,A,B,costK,bestOfTheRest;
vector<pair<int,int64_t>> v[N];
queue<int> q;
vector<pair<int64_t,int>> P;
void readTree(),cazGeneral(),cazParticular(),dfs(int,int64_t*,int&,int64_t&);
int main()
{
    readTree();
    if(k==1)cazParticular();
    cazGeneral();
    return 0;
}
void readTree()
{
    ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in>>n>>k;
    for(int i=1; i<n; i++)
    {
        int x,y;
        int64_t c;
        in>>x>>y>>c;
        costAll+=c;
        v[x].push_back(make_pair(y,c));
        g[x]++;
        v[y].push_back(make_pair(x,c));
        g[y]++;
    }
}
void cazGeneral()
{
    /// imi creez o coada cu toate frunzele
    for(int i=1; i<=n; i++)if(g[i]==1)
        {
            q.push(i);
            lf++;
        }

    /// BEGIN : caz particular nr_frunze<k -> pentru orice nod X solutia este costul total al arborelui
    if(lf<=k)
    {
        for(int i=1; i<=n; i++) out<<costAll;
        exit(0);
    }
    /// END

    /// incep o parcurgere simultana din toate frunzele construind o descompunere a arborelui in drumuri
    e=n-1;
    int root;
    while(e) /// parcurgerea se va finaliza cand am utilizat toate muchiile
        /// cand parcurg o muchie scad gradele la capetele acesteia
    {
        int nod=q.front(); /// in coada voi avea la un moment dat orice nod care mai are un singur vein accesibil
        /// [initial aceste noduri sunt frunzele
        ///  dar pe masura ce fac parcurgerea adaug noduri care mai au exact un vein neparcurs]
        q.pop();
        g[nod]--; /// iau un nod care are grad "rezidual" 1 ii reduc gradu la 0 si astfel el nu va mai fi accesat
        for(auto it:v[nod])
        {
            int dad;/// acesta va fi nodul spre care prelungesc drumul curent
            /// pentru nodul curent acest nod va capata statut de "tata"
            int64_t cst;
            tie(dad,cst)=it;
            if(g[dad]) /// tatal va fi singurul nod care mai are grad rezidual
            {
                e--;/// parcurg muchia
                T[nod]=dad; /// am stabilit tatal in aceasta parcurgere
                root=dad; /// la final, radaina arborelui va fi capatul ultimei muchii parcurse
                cT[nod]=cst; /// memorez costul muchiei de la oricare nod spre tatal sau.
                /// Acest cost va face parte din costul total al drumului pe care se gaseste nodul curent


                /// pentru fiecare nod voi stabili un fiu favorit
                /// Fiecare nod face parte dintr-un drum
                /// Fiul favorit este sub nod pe drumul spre frunza

                if(!F[dad]) /// cazul in care in nodul tata nu a mai ajuns inca niciun drum
                    ///nodul curent este deocamdata singurul candidat la fiu favorit pentru tata
                {
                    F[dad]=nod;

                    cD[dad]=cD[nod]+cT[nod]; /// cD[dad] costul in jos(spre frunza) al nodului la care m-am legat
                }

                else if(cD[nod]+cT[nod]>cD[dad]) /// cazul cand nod are deja un frate si dad il are deocamdata ca fiu favorit
                    /// dar eu as crea un drum mai bun spre frunza mea decat fratele !!!
                {
                    int bro=F[dad];/// acesta este fratele pe care "il detronez" si devin eu ca fiu favorit

                    P.push_back(make_pair(cD[dad],bro));/// celalat drum este "eliminat" din arbore

                    cD[dad]=cD[nod]+cT[nod]; /// imi preiau rolul de fiu favorit
                    F[dad]=nod;
                }


                else P.push_back(make_pair(cD[nod]+cT[nod],nod));/// cazul cand fratele favorit isi pastreaza statutul
                /// drumul nodului curent este eliminat din arbore
                g[dad]--;/// anunt ca inca un fiu a adus un drum in dad


                if(g[dad]==1)q.push(dad);/// daca gradul rezidual in dad a ramas 1, atunci din dad pot prelungi drumul cel mai mare
                /// acest drum ajunge in tata prin "fiul favorit"
            }
        }
    }

    /// dupa ce am parcurs ultima muchie am prelungit cel mai lung drum corespunzator unei frunze
    /// acest drum nu a fost inca adaugat la descompunerea arborelui in drumuri
    /// il adaug acum
    /// Observatie importanta = acum avem capatul ultimului drum drept radaina a arborelui in care am stabilit deja>
    /// vectorul de tati T[] (fiecare nod cu exceptia radainii are tatal)
    /// vectorul de fii favoriti F[] (fiecare nod cu exceptia frunzelor are un fiu favorit)
    /// vectorul F[] recupereaza drumul din oricare nod spre frunza "proprie"
    P.push_back(make_pair(cD[root],root));

    /// imi sortez drumurile in ordine descrescatoare dupa lungime
    sort(P.begin(),P.end());
    reverse(P.begin(),P.end());

    /// Ce este special legat de aceasta descompunere???


    /// sa presupunem ca am strict mai mult de k+1 frunze
    /// se poate arata ca frunza A a ultimului(celui mai scurt drum) nu trebuie aleasa pentru solutia NICIUNUI NOD N !!!
    /// demonstratie prin reducere la absurd.
    /// Evident ca daca as alege A, obligatoriu as avea in solutie tot pathul corespunzator acelei frunze.
    /// Fie X nodul in care se agata drumul frunzei A la restul arborelui.
    /// acum am doua cazuri
    /// cazul 1: X are grad 2 in arborele solutie
    /// atunci este suficient sa aleg in locul lui A oricare alta frunza B nealeasa care ajunge in X prin vectorul de tati
    /// tot drumul  B-X se adauga la solutie si evident ca acesta este mai lung decat A-X
    /// daca nodul N este pe drumul A-X se pierde din solutie doar portiunea A-N a drumului A-X
    /// altfel se pierde intregul drum A-X
    /// dar tot se obtine o solutie mai buna
    /// cazul 2: X are grad strict mai mare ca 2 in arborele solutie
    /// atunci este suficient sa aleg in locul lui A oricare alta frunza B nealeasa
    /// Din B se ajunge prin vectorul de tati un nod Y al arborelui solutie
    /// Tot drumul B-Y se adauga la solutia modificata si acest drum sigur este mai lung decat A-X
    /// Prin eliminarea lui A se pierde drumul de la A pana la cel mai apropiat nod ales dintre N,Y si X deci se va pierde cel mult
    /// lungimea drumului A-X


    ///Acum putem elimina acest path din arbore si solutia finala pentru nodurile neeliminate va ramane aceeasi
    ///Sa presupunem ca am rezolvat problema in arborele ramas.
    ///Ar mai ramane sa rezolvam problema pentru path-ul eliminat
    ///MAGIC-> se poate demonstra ca solutia pentru toate nodurile N din path este egala cu solutia din X adunata cu lungimea drumului N-X


    ///Acum cu aceste idei
    /// - pot elimina pe rand toate drumurile pana raman K+1 drumuri(sau echivalent K+1 frunze)
    /// rezolv problema pentru arborele cu cele mai bune K+1 drumuri(frunze)
    /// adaug si rezolv in oridnea inversa eliminarii celelalte drumurile eliminate

    /// Mi-a mai ramas sa rezolv problema pentru un arbore cu exact K+1 frunze si stiu descompunerea acestui arbore in drumuri

    /// prima impresie ar fi ca optim ar fi sa aleg cele mai bune K frunze
    /// .... dar nu e chiar asa
    /// uneori e mai bine sa folosesc inlocuiesc o funza cu a k+1 frunza (numita in continuare "best of the rest"

    /// memorez cel mai slab drum din cele k+1
    bestOfTheRest=P[k].first;

    /// imi calculez costul arborelui AK cu cele mai bune k frunze
    for(int i=0; i<k; i++)costK+=P[i].first;

    /// rezolv arborele AK
    for(int i=0; i<k; i++) for(int nod=P[i].second; nod; nod=F[nod])
        {
            /// in mod normal as folosi exact cele K frunze
            sol[nod]=costK;

            /// singurul motiv pentru care nu as face asta?
            /// sunt prea aproape de o frunza( frunza de pe drumul meu)
            /// daca distanta pana la frunza mea este mai mica decat "best of the rest"
            /// prefer sa inlocuiesc acea frunza
            /// pierd distanta pana la acea frunza
            /// dar castig prin inlocuirea sa cu al k+1 drum
            if(bestOfTheRest>cD[nod])sol[nod]+=bestOfTheRest-cD[nod];
        }

    /// aici aplic ceea ce spuneam mai sus -> rezolv path-urile in ordinea inversa eliminarii
    /// acelasi principiu de rezolvare e valabil si pentru al K+1 lea path care va fi tratat
    /// ca ultimul eliminat ( deci primul care va fi readaugat si rezolvat)
    for(int i=k; i<lf; i++) for(int nod=P[i].second; nod; nod=F[nod])sol[nod]=sol[T[nod]]+cT[nod];
    for(int i=1; i<=n; i++) out<<sol[i]<<'\n';
}
void cazParticular()
{
    ///Cazul k=1
    /// se determina un diametru A-B
    /// pentru orice nod X solutia = max( dist(X,A) , dist(X,B) )
    DU=sol;
    DU[u]=1;
    dfs(u,DU,a,A);
    DA=cT;
    DA[a]=1;
    dfs(a,DA,b,B);
    DB=cD;
    DB[b]=1;
    dfs(b,DB,u,U);
    for(int i=1; i<=n; i++)out<<max(DA[i],DB[i])-1<<'\n';
    exit(0);
}
void dfs(int nod,int64_t *dst,int &bst,int64_t &Bst)
{
    if(dst[nod]>Bst)
    {
        Bst=dst[nod];
        bst=nod;
    }
    for(auto it:v[nod])if(!dst[it.first])
        {
            dst[it.first]=dst[nod]+it.second;
            dfs(it.first,dst,bst,Bst);
        }
}
