// Aho-Corasick
//
// Configure: MAX
// Configure: ALPHA
// Initialize: V = 0, node()
// Note: s[i] - 'A'

int V;
int trie[MAX][ALPHA];
int fn[MAX];

int node() {
  REP(i, ALPHA) trie[V][i] = 0;
  fn[V] = 0;
  return V++;
}

int insert(char *s) {
  int t = 0;
  for (; *s; ++s) {
    int c = *s - 'A';
    if (trie[t][c] == 0) trie[t][c] = node();
    t = trie[t][c];
  }
  return t;
}

void init_aho() {
  queue<int> Q;
  Q.push(0);

  while (!Q.empty()) {
    int t = Q.front(); Q.pop();
    
    REP(c, ALPHA) {
      int x = trie[t][c];
      if (x) {
        Q.push(x);

        if (t) {
          fn[x] = fn[t];
          while (fn[x] && trie[fn[x]][c] == 0) fn[x] = fn[fn[x]];
          if (trie[fn[x]][c]) fn[x] = trie[fn[x]][c];
        }
      }
    }
  }
}
