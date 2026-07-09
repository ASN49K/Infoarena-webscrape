#include <fstream>
#include <cstring>

using namespace std;

ifstream in ("trie.in");
ofstream out ("trie.out");

struct trie
{
    int fii, ap;
    trie *nxt[26], *tata;
    trie()
    {
        fii = ap = 0;
        memset ( nxt, 0, sizeof (nxt) );
        tata = 0;
    }
} *tr;

char word[30];

int op;

void add ( trie *t, char *s )
{
    if ( *s == NULL )
    {
        t -> ap++;
        return;
    }

    if ( t -> nxt[*s - 'a'] == 0 )
    {
        t -> nxt[*s - 'a'] = new trie;
        t -> nxt[*s - 'a'] -> tata = t;
        t -> fii++;
    }

    add ( t -> nxt[*s - 'a'], s + 1 );
}

void del ( trie *t, char *s )
{
    if ( *s == NULL )
    {
        t -> ap--;

        if ( t -> fii == 0  &&  t -> ap == 0 )
        {
            t -> tata -> fii--;
            t -> tata -> nxt [*( s - 1 ) - 'a'] = 0;
            delete t;
        }

        return;
    }

    else
    {
        del ( t -> nxt[*s - 'a'], s + 1 );

        if ( t -> fii == 0  &&  t -> ap ==0  &&  t != tr )
        {
            t -> tata -> fii--;
            t -> tata -> nxt [*( s - 1 ) - 'a'] = 0;
            delete t;
        }

        return;
    }
}

int app ( trie *t, char *s )
{
    if ( *s == NULL )
        return ( t -> ap );
    else
    {
        if ( t -> nxt[*s - 'a'] )
            return app ( t -> nxt[*s - 'a'], s + 1);
        else
            return 0;
    }
}

int prefix ( trie *t, char *s )
{
    if ( *s == NULL)
        return 0;
    else
    {
        if ( t -> nxt[*s - 'a'] )
            return prefix ( t -> nxt[*s - 'a'], s + 1) + 1;
        else
            return 0;
    }
}

int main()
{
    tr = new trie;
    while ( in >> op )
    {
        in >> word;
        if ( op == 0 )
            add ( tr, word );
        else if ( op == 1 )
            del ( tr, word );
        else if ( op == 2 )
            out << app ( tr, word ) << '\n';
        else
            out << prefix ( tr, word ) << '\n';
    }
    return 0;
}
