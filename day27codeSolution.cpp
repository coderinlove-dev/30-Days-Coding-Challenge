#include <iostream>
#include <queue>
#include <list>
using namespace std;

int bfsShortest(int n, int edge[][2], int m, int start, int end) 
{
    list<int> adj[n];

    for (int i = 0; i < m; i++) 
    {
        int a = edge[i][0];
        int b = edge[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int dis[n];
    for (int i = 0; i < n; i++) 
    {
        dis[i] = -1;
    }

    queue<int> q;
    dis[start] = 0;
    q.push(start);

    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) 
        {
            if (dis[nxt] == -1) 
            {
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
                if (nxt == end) 
                {
                    return dis[nxt];
                }
            }
        }
    }

    return dis[end];
}

int main() {
    int n, m;
    cout << "Enter vertices: ";
    cin >> n;
    cout << "Enter Number Of Edges: ";
    cin >> m;

    int edge[m][2];
    cout << "Enter edge pairs (u v) : ";
    for (int i = 0; i < m; i++) {
        cin >> edge[i][0] >> edge[i][1];
    }

    int Start, End;
    cout << "Enter Start : ";
    cin >> Start ;
    cout << "Enter End : ";
    cin >> End;
    int ans = bfsShortest(n, edge, m, Start, End);
    cout << "Shortest path length = " << ans << endl;

    return 0;
}
