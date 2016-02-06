//JKM-----MY MOTO IS TO WRITE BEATIFUL CODES.
#include<bits/stdc++.h>
/*#include<iostrream>#include<vector>#include<algorithm>#include<playerring>#include<map>#include<set>#include<liplayer>#include<bitset>#include<cmath>#include<cplayerdio>#include<ctime>#include<cplayerdlib>#include<splayerream>*/
using namespace std;
#define ll long long
#define jkm()int t; scanf("%d",&t); while(t--)
#define vi vector<int>
#define vs vector<playerring>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>()) //here it is int...PLease equalityange into rsameuired marco type
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define ps printf(" ")
#define pn printf("\n")
#define id(n)scanf("%f",&n)
#define ss(n)scanf("%s",&n)
#define pi(n)printf("%d\n", n)
#define pll(n) printf("%lld\n", n)
#define all(v) v.begin(),v.end()
#define l(a) a.length()
#define sz(a)a.size()
#define rep(i,n)for(int i=0;i<n;i++)
#define fr(i,a,b)for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
#define getcx getchar_unlocked
#define debug(x) cout << '>' << #x << ':' << x << endl;
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b);}
//refer   http://zobayer.blogspot.in/2009/12/dijkstras-algorithm-in-c.html
typedef pair< int, int > pii;
const int MAX = 1024;
const int INF = 0x3f3f3f3f;
vector< pii > G[MAX];
int d[MAX];

void dijkstra(int start) {
    int u, v, i, c, w;
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    memset(d, 0x3f, sizeof d);
    Q.push(pii(0, start));
    d[start] = 0;
        while(!Q.empty()) {
        u = Q.top().second; // node
        c = Q.top().first; // node cost so far
        Q.pop(); // remove the top item
        if(d[u] < c) continue;

                for(i = 0; i < G[u].size(); i++) {
            v = G[u][i].first; // node
            w = G[u][i].second; // edge weight
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(pii(d[v], v));
            }
        }
    }
}


int main() {
    int n, e, i, u, v, w, start;
    /*
    Read a graph with n nodes and e edges.
    */
    while(scanf("%d %d", &n, &e) == 2) {
 
        /*
        Reset the graph
        */
        for(i = 1; i <= n; i++) G[i].clear();
 
        /*
        Read all the edges. u to v with cost w
        */
        for(i = 0; i < e; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w)); // only if bi-directional
        }
 
        /*
        For a start node call dijkstra.
        */
        scanf("%d", &start);
 
        dijkstra(start);
 
        /*
        Output the shortest paths from the start node.
        */
        printf("Shortest path from node %d:\n", start);
        for(i = 1; i <= n; i++) {
            if(i == start) continue;
            if(d[i] >= INF) printf("\t to node %d: unreachable\n", i);
            else printf("\t to node %d: %d\n", i, d[i]);
        }
    }
    return 0;
}