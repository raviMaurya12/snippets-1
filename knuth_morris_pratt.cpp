// Knuth-Morris-Pratt
//
// Configure: konstanta MAX
// Initialize: fn[1] = 0
//
// fn[x] = length of the prefix equal to suffix of s[0..x)

char s[MAX];
int fn[MAX];

void kmp() {
  FOR(t, 1, N) {
    int x = t+1;
    fn[x] = fn[t];
    
    while (fn[x] && s[fn[x]] != s[t]) fn[x] = fn[fn[x]];
    if (s[fn[x]] == s[t]) ++fn[x];
  }
}
