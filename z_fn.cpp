// Z Algorithm
//
// Given string s, this algorithm produces an array z, where z[i] is the
// length of longest substring starting from s[i] which is also a prefix.
// More thorough explanation: http://codeforces.com/blog/entry/3107
//
// Time complexity: O(N)
//
// Arguments:
// - s is the string
// - N is the length of the string
// - z is the array where the result will be stored

void z_fn(char *s, int N, int *z) {
  z[0] = N;
  int L = -1, R = -1;

  FOR(i, 1, N) {
    z[i] = i >= R ? 0 : min(R-i, z[i-L]);
    while (i+z[i] < N && s[i+z[i]] == s[z[i]]) ++z[i];
    if (i+z[i] > R) L = i, R = i+z[i];
  }
}
