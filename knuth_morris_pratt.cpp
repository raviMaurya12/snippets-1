// Knuth-Morris-Pratt
//
// Given a string s of length N, computes the array fn, where fn[x] is the
// length of the longest prefix of s equal to a suffix of s[0..x).
//
// This algorithm is simply a special case of Aho-Corasick: a trie containing
// just one string is built. For a node x, fn[x] points to it's "failure" node.
//
// Time complexity: O(N)
//
// Configure: konstanta MAX

char s[MAX];
int fn[MAX];

void kmp() {
  fn[1] = 0;

  FOR(t, 1, N) {
    int x = t+1;
    fn[x] = fn[t];
    
    while (fn[x] && s[fn[x]] != s[t]) fn[x] = fn[fn[x]];
    if (s[fn[x]] == s[t]) ++fn[x];
  }
}
