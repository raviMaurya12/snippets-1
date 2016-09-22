// Useful modulo operations

inline int add(int a, int b) { return a+b < mod ? a+b : a+b-mod; }
inline int sub(int a, int b) { return a-b >=  0 ? a-b : a-b+mod; }
inline int mul(int a, int b) { return llint(a) * b % mod; }

inline void setadd(int &a, int b) { a = add(a, b); }
inline void setsub(int &a, int b) { a = sub(a, b); }
inline void setmul(int &a, int b) { a = mul(a, b); }

llint power(llint a, llint b, llint mod) {
  llint ret = 1;
  for (; b; b /= 2) {
    if (b%2) ret = ret*a % mod;
    a = a*a % mod;
  }
  return ret;
}
