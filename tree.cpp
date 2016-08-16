// A lot of useful snippets for trees

int N;
llint length[MAX];
vector<int> adj[MAX];

int jump[MAX][LG];
int depth[MAX];
llint dist[MAX];

int tick;
int discovery[MAX];
int finish[MAX];

void dfs(int x, int dad) {
  jump[x][0] = dad == -1 ? x : dad;
  FOR(i, 1, LG) jump[x][i] = jump[ jump[x][i-1] ][i-1];

  discovery[x] = tick++;
  for (int y : adj[x]) {
    if (y == dad) continue;

    depth[y] = depth[x] + 1;
    dist[y] = dist[x] + length[y];
    dfs(y, x);
  }
  finish[x] = tick++;
}

bool ancestor(int x, int y) {
  return discovery[x] <= discovery[y] && finish[y] <= finish[x];
}

int lca(int x, int y) {
  if (ancestor(x, y)) return x;
  for (int i = LG-1; i >= 0; --i)
    if (!ancestor(jump[x][i], y))
      x = jump[x][i];
  return jump[x][0];
}

llint distance(int x, int y) {
  return dist[x] + dist[y] - 2 * dist[lca(x, y)];
}

int num_edges(int x, int y) {
  return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int rel(int x, int y) {
  assert(x != y);
  if (!ancestor(x, y)) return jump[x][0];

  for (int i = LG-1; i >= 0; --i)
    if (depth[y] - (1<<i) > depth[x])
      y = jump[y][i];
  return y;
}

int kth(int x, int y, int k) {
  int p = lca(x, y);
  int d = num_edges(x, y);

  for (int i = LG-1; i >= 0; --i) {
    if (depth[x] - (1<<i) >= depth[p] && k - (1<<i) >= 0) {
      d -= 1<<i;
      k -= 1<<i;
      x = jump[x][i];
    }
    if (depth[y] - (1<<i) >= depth[p] && d - (1<<i) >= k) {
      d -= 1<<i;
      y = jump[y][i];
    }
  }
  return k == 0 ? x : y;
}
