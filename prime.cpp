// Compute primes up to MAX

//bitset<MAX> prime;
bool prime[MAX];
vector<int> P;

void init_prime() {
  prime[2] = true;
  for (int i = 3; i < MAX; i += 2) prime[i] = true;

  for (int i = 3; i*i < MAX; i += 2)
    if (prime[i])
      for (int j = i*i; j < MAX; j += i+i)
        prime[j] = false;

  REP(i, MAX) if (prime[i]) P.push_back(i);
}
