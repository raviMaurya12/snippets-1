// Heavy-light decomposition

int parent[MAX], depth[MAX], size[MAX];
int chain[MAX], home[MAX];

void dfs(int x, int dad) {
  size[x] = 1;
  parent[x] = dad;

  for (Edge e : adj[x]) {
    if (e.y == dad) continue;

    depth[e.y] = depth[x] + 1;
    dfs(e.y, x);
    size[x] += size[e.y];
  }
}

void heli(int x, int dad, int c, int h) {
  chain[x] = c;
  home[x] = h++;

  int maks = -1;
  for (Edge e : adj[x]) {
    if (e.y == dad) continue;
    if (maks == -1 || size[e.y] > size[maks]) maks = e.y;
  }
  if (maks == -1) return;
  
  heli(maks, x, c, h);
  h += size[maks];
  
  for (Edge e : adj[x]) {
    if (e.y == dad || e.y == maks) continue;
    heli(e.y, x, e.y, h);
    h += size[e.y];
  }
}

int lca(int a, int b) {
  while (chain[a] != chain[b]) {
    if (depth[chain[a]] < depth[chain[b]]) swap(a, b);
    a = parent[chain[a]];
  }
  return depth[a] < depth[b] ? a : b;
}

void run() {
  dfs(0, -1);
  heli(0, -1, 0, 0);
}
