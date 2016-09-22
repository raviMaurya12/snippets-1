// Integer division with rounding down/up

llint divd(llint a, llint b) {
  if (b < 0) a = -a, b = -b;
  return a/b - (a%b < 0);
}

llint divu(llint a, llint b) { 
  if (b < 0) a = -a, b = -b;
  return a/b + (a%b > 0);
}
