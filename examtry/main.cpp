// Author: r3gz3n
// 3b 13 12 9 56 4e
// 6 56 a a 5f f
// 6 56 47 18 56 d
// 13 46 14 1f 13 27
// 52 52 a 5a 47 1
// 1d 13 b 1b 49 17

// Template Begin
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define le length()
#define sz size()

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds

#define eps 1e-6
#define pi 3.141592653589793

using namespace std;

template<class T> inline T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<class T> inline T mod(T x) { if(x < 0) return -x; else return x; }

typedef vector<int> VII;
typedef pair<int, int> PII;
typedef pair<int, PII > PPII;
typedef vector< PPII > VPPII;
typedef vector< PII > VPII;

const int MOD = 1e9 + 7;
const int INF = 1e9;

// Template End
const int MAX = 10;
VPPII adj[MAX];
bool vis[MAX];
int dist[MAX];
int distt[MAX];
int parent[MAX];

int dijkstra(int s, int d, int k) {
    priority_queue <PII, VPII, greater<PII> > pq;
    pq.push({0, s});
    dist[s] = 0;
    distt[s] = 0;
    parent[s] = -1;
    while(!pq.empty()) {
        PII p = pq.top();
        pq.pop();
        if (p.se == d) return distt[d];
        int x = p.se;
        for (int i = 0; i < adj[x].sz; i++) {
            int y = adj[x][i].fi;
            int t = adj[x][i].se.fi;
            int c = adj[x][i].se.se;
            if (y == d) {
                if (dist[y] > dist[x] + k*t + c) {
                    dist[y] = dist[x] + k*t + c;
                    distt[y] = distt[x] + t;
                    parent[y] = x;
                    pq.push({dist[y], y});
                }
            }
            else {
                if (dist[y] > dist[x] + k*(t+1) + c) {
                    dist[y] = dist[x] + k*(t+1) + c;
                    distt[y] = distt[x] + t + 1;
                    parent[y] = x;
                    pq.push({dist[y], y});
                }
            }
        }
    }
    return -1;
}


void display(int s, int d) {
    int x = d;
    VII v;
    while (x != s) {
        v.pb(x);
        x = parent[x];
    }
    v.pb(s);
    reverse(v.be, v.en);
    for (int i = 0; i < v.sz; i++) {
        cout << v[i];
        if (i < v.sz-1) cout << "->";
        else cout <<  ' ';
    }
}

int main(int argc, char* argv[]) {
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    int n, k, m, y, x, c, s, d;
    float t;
    cin >> k >> n >> m;
    if (!(1 <= k and k <= 1600)) {
        cout << "Error" << endl;
        return 0;
    }
    if (!(1 <= m and m <= (n*(n-1))/2)) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t >> c;
        if (!(1 <= x and x <= n)) {
            cout << "Error" << endl;
            return 0;
        }
        if (!(1 <= y and y <= n)) {
            cout << "Error" << endl;
            return 0;
        }
        adj[x].pb({y, {t, c}});
        adj[y].pb({x, {t, c}});
    }

    cin >> s >> d;
    if (!(1 <= d and d <= n)) {
        cout << "Error" << endl;
        return 0;
    }
    if (!(1 <= s and s <= n)) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        distt[i] = INF;
    }
    int anst = dijkstra(s, d, k);
    if (anst == -1) cout << "Error" << endl;
    else {
        display(s, d);
        cout << anst << ' ' << dist[d] << endl;
    }
    return 0;
}
