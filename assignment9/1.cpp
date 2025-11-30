#include <iostream>
using namespace std;

int n, m;
int adj[100][100];

int q[1000], frontt, rearr;

void bfs(int start) {
    int visited[100];
    for(int i=0;i<n;i++) visited[i]=0;
    frontt = 0; rearr = 0;
    q[rearr++] = start;
    visited[start] = 1;
    while(frontt != rearr) {
        int u = q[frontt++];
        cout << u << " ";
        for(int v=0; v<n; v++) {
            if(adj[u][v] != 0 && visited[v]==0) {
                visited[v] = 1;
                q[rearr++] = v;
            }
        }
    }
    cout << endl;
}

int stackk[100], top=-1;

void dfs_rec(int u, int visited[]) {
    visited[u] = 1;
    cout << u << " ";
    for(int v=0; v<n; v++) {
        if(adj[u][v] != 0 && visited[v]==0) dfs_rec(v, visited);
    }
}

void dfs(int start) {
    int visited[100];
    for(int i=0;i<n;i++) visited[i]=0;
    dfs_rec(start, visited);
    cout << endl;
}

int parent[100];

int findp(int x) {
    if(parent[x]==x) return x;
    return parent[x] = findp(parent[x]);
}

void unite(int a, int b) {
    a = findp(a);
    b = findp(b);
    parent[a] = b;
}

void kruskal() {
    int edges[10000][3];
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(adj[i][j] != 0){
                edges[k][0] = i;
                edges[k][1] = j;
                edges[k][2] = adj[i][j];
                k++;
            }
        }
    }
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(edges[j][2] < edges[i][2]) {
                int t0 = edges[i][0], t1 = edges[i][1], t2 = edges[i][2];
                edges[i][0]=edges[j][0]; edges[i][1]=edges[j][1]; edges[i][2]=edges[j][2];
                edges[j][0]=t0; edges[j][1]=t1; edges[j][2]=t2;
            }
        }
    }

    for(int i=0;i<n;i++) parent[i]=i;

    int total = 0;
    for(int i=0;i<k;i++){
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        if(findp(u) != findp(v)) {
            unite(u,v);
            total += w;
            cout << u << " - " << v << " : " << w << endl;
        }
    }
    cout << "Total = " << total << endl;
}

void prim(int start) {
    int visited[100];
    int key[100];
    int par[100];
    for(int i=0;i<n;i++){
        visited[i]=0;
        key[i]=999999;
    }
    key[start] = 0;
    par[start] = -1;

    for(int c=0;c<n;c++){
        int u=-1;
        for(int i=0;i<n;i++){
            if(!visited[i] && (u==-1 || key[i] < key[u])) u=i;
        }
        visited[u] = 1;
        for(int v=0;v<n;v++){
            if(adj[u][v] && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                par[v] = u;
            }
        }
    }

    int total=0;
    for(int i=0;i<n;i++){
        if(par[i]!=-1){
            cout << par[i] << " - " << i << " : " << adj[par[i]][i] << endl;
            total += adj[par[i]][i];
        }
    }
    cout << "Total = " << total << endl;
}

void dijkstra(int src) {
    int dist[100], visited[100];
    for(int i=0;i<n;i++){
        dist[i] = 999999;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(int c=0;c<n;c++){
        int u = -1;
        for(int i=0;i<n;i++){
            if(!visited[i] && (u==-1 || dist[i] < dist[u])) u=i;
        }
        visited[u] = 1;
        for(int v=0; v<n; v++){
            if(adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << "dist[" << i << "]=" << dist[i] << endl;
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    bfs(0);
    dfs(0);
    prim(0);
    kruskal();
    dijkstra(0);
}
