// Finds all palindromes in a string
//
// Configure: konstanta MAX
// Note: The elements are of char type
// Note: Special elements are -1
// Note: rad must be of length 2*MAX
//
// manacher(s, N, rad): Computes a sequence of radii
// rad[2*i]:   Radius of the palindrome centered in s[i]
// rad[2*i+1]: Radius of hte palindrome centered in s[i..i+1]
//
// Example: s   = b a n a n a a
//          rad = 0000102010010

int rad[2*MAX];

void manacher(char *s, int N, int *rad) {
  static char t[2*MAX];
  int m = 2*N - 1;

  REP(i, m) t[i] = -1;
  REP(i, N) t[2*i] = s[i];

  int x = 0;
  FOR(i, 1, m) {
    int &r = rad[i] = 0;
    if (i <= x+rad[x]) r = min(rad[x+x-i], x+rad[x]-i);
    while (i-r-1 >= 0 && i+r+1 < m && t[i-r-1] == t[i+r+1]) ++r;
    if (i+r >= x+rad[x]) x = i;
  }

  REP(i, m) if (i-rad[i] == 0 || i+rad[i] == m-1) ++rad[i];
  REP(i, m) rad[i] /= 2;
}
