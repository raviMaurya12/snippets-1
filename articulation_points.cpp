// Articulation points

int tick = 1;
int discovery[MAX];
bool articulation[MAX];

int dfs(int x, int dad) {
  discovery[x] = ++tick;
  int low = discovery[x];

  articulation[x] = false;
  int children = 0;

  for (int y : E[x]) {
    if (y == dad) continue;

    if (discovery[y] < 0) {
      ++children;
      int w = dfs(y, x);

      if (w >= discovery[x]) articulation[x] = true;
      low = min(low, w);
    } else {
      low = min(low, discovery[y]);
    }
  }
  if (dad == -1) articulation[x] = children > 1;

  return low;
}

void init() {
  REP(i, N) discovery[i] = -1;
  REP(i, N) if (discovery[i] == -1) dfs(i, -1);
}
