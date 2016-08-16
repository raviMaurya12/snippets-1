// A trie of palindromes
//
// Configure: MAX
// Configure: ALPHA
// Note: s[i] - 'A'
//
// Root of even palindromes: 0
// Root of odd palindromes: 1

int N;
char s[MAX];

int V;
int trie[MAX][ALPHA];
int fn[MAX], len[MAX];

int node() {
  REP(i, ALPHA) trie[V][i] = 0;
  fn[V] = len[V] = 0;
  return V++;
}

int suffix(int t, int i) {
  while (i-len[t]-1 < 0 || s[i-len[t]-1] != s[i]) t = fn[t];
  return t;
}

void paltree() {
  V = 0; node(); node();
  len[0] =  0; fn[0] = 1;
  len[1] = -1; fn[1] = 0;

  int t = 0;
  REP(i, N) {
    int c = s[i] - 'A';
    t = suffix(t, i);

    int &x = trie[t][c];
    if (!x) {
      x = node();
      len[x] = len[t] + 2;
      fn[x] = t == 1 ? 0 : trie[suffix(fn[t], i)][c];
    }
    t = x;
  }
}
