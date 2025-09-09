#include <iostream>
using namespace std;

const int MAXN = 10000;
const int MAXM = 20000;

int adj[MAXM];
int nxt[MAXM];
int first[MAXN];
bool vis[MAXN];

int edgeNo = 0;

void add(int u, int v) {
    adj[edgeNo] = v;
    nxt[edgeNo] = first[u];
    first[u] = edgeNo++;
}

bool dfs(int u, int p) {
    vis[u] = true;
    for (int e = first[u]; e != -1; e = nxt[e]) {
        int v = adj[e];
        if (!vis[v]) 
        {
            if (dfs(v, u)) return true;
        } else if (v != p)
        {
            return true;
        }
    }
    return false;
}

bool hasCycle(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        if (!vis[i]) 
        {
            if (dfs(i, -1)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Vertices : ";
    cin >> n;
    cout << "No of Edges: ";
    cin >> m;
    if(m == 0){
        cout << "false";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        first[i] = -1;
        vis[i] = false;
    }

    cout << "enter edges ( like value1 value2 ) :\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u;
        cin >> v;

        for (int e = first[u]; e != -1; e = nxt[e])
        {
            if (adj[e] == v) 
            {
                cout << "true\n";
                return 0;
            }
        }

        add(u, v);
        add(v, u);
    }

    if (hasCycle(n)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
