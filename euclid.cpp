// Euclidean algorithm
//
// Note: If a or b is negative, then g can be negative, too!
//
// a*x + b*y = g
// x' = x + k * b/g
// y' = y - k * a/g

void euclid(llint a, llint b, llint &x, llint &y, llint &g) {
  if (b == 0) {
    x = 1; y = 0; g = a;
  } else {
    euclid(b, a % b, y, x, g);
    y -= x * (a/b);
  }
}
