// Count prime numbers up to n
//
// Note: Prime numbers and precomputation go up to MAX
// Note: MAX > sqrt(n)
// A good value for MAX: around 50100100

int prec[MAX];

llint rec(llint n, int k) {
  if (n <= 1 || k < 0) return 0;
  if (n <= P[k]) return n-1;
  if (n < MAX && llint(P[k])*P[k] > n) return n-1 - prec[n] + prec[P[k]];

  const int LIM = 250;
  static int memo[LIM*LIM][LIM];

  bool ok = n < LIM*LIM;
  if (ok && memo[n][k]) return memo[n][k];

  llint ret = n/P[k] - rec(n/P[k], k-1) + rec(n, k-1);

  if (ok) memo[n][k] = ret;
  return ret;
}

llint prime_count(llint n) {
  if (n < MAX) return prec[n];
  int k = prec[(int)sqrt(n) + 1];
  return n-1 - rec(n, k) + prec[P[k]];
}

void init_prime_count() {
  FOR(i, 1, MAX) prec[i] = prec[i-1] + prime[i];
}
