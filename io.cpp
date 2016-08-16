// Fast input

namespace IO {
  const int N = 10000;
  int pos = N;
  char buf[N];

  char read_char() {
    if (pos == N) fread(buf, 1, N, stdin), pos = 0;
    return buf[pos++];
  }

  int read_int() {
    char c;
    while (!isdigit(c = read_char()));
    int x = c - '0';
    while (isdigit(c = read_char())) x = 10*x + c-'0';
    return x;
  }
}
