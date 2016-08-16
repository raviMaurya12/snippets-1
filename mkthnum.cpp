// Solution to: http://www.spoj.com/problems/MKTHNUM/
// Uses persistent tournament tree

const int MAXN = 100100;
const int D = 31;
const int MAXMEM = (D+1) * MAXN;

struct Node {
  Node *l, *r;
  int cnt;
} mem[MAXMEM], *alloc = mem;
inline Node *clone(Node *n) { *alloc = *n; return alloc++; }

int N, Q;
int nums[MAXN];
Node *root[MAXN];

Node *construct(llint a = 0, llint b = 1LL<<D) {
  Node *n = alloc++;
  if (a+1 < b) {
    n->l = construct(a, (a+b)/2);
    n->r = n->l;
  }
  n->cnt = 0;
  return n;
}

Node *update(int x, Node *n, llint a = 0, llint b = 1LL<<D) {
  if (x < a || x >= b) return n;

  n = clone(n);
  n->cnt += 1;

  if (a+1 < b) {
    n->l = update(x, n->l, a, (a+b)/2);
    n->r = update(x, n->r, (a+b)/2, b);
  }
  return n;
}

int query(int k, Node *lo, Node *hi, llint a = 0, llint b = 1LL<<D) {
  if (a+1 == b) return a;

  int cnt = hi->l->cnt - lo->l->cnt;
  if (cnt >= k) return query(k, lo->l, hi->l, a, (a+b)/2);
  return query(k - cnt, lo->r, hi->r, (a+b)/2, b);
}

int main() {
  scanf("%d%d", &N, &Q);
  REP(i, N) scanf("%d", nums + i);

  root[0] = construct();
  REP(i, N) root[i+1] = update(nums[i] + (1<<30), root[i]);

  REP(i, Q) {
    int a, b, k; scanf("%d%d%d", &a, &b, &k); --a;
    printf("%d\n", query(k, root[a], root[b]) - (1<<30));
  }

  return 0;
}
