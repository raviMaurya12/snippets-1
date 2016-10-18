### What is this?

This is a collection of algorithms and data structures I use in programming
contests.

The goal of every snippet is to be short, simple, performant, and easy to
copy-paste into other programs whenever needed.

Note that the code is not necessarily pedantic nor easy to understand.
Common good programming practices are intentionally violated.
Global variables, misuse of namespaces, inconsistent variable names, weird
hacks, etc. are all over the place, and that's OK.

### What is included?

Strings:
* Aho-Corasick (string searching)
* Knuth-Morris-Pratt (string searching)
* Manacher's algorithm (finding palindromes)
* Minimum rotation
* Palindromic tree (trie of palindromes in a string)
* Suffix array
* Z algorithm (matching a string with its suffixes)

Graphs:
* Articulation points
* Circulation (a variant of network flow)
* Dinic's algorithm (maximum flow)
* Directed minimum spanning tree (arborescence)
* Heavy-light decomposition
* Min-cost max-flow using DFS
* Min-cost max-flow using Dijkstra
* Tree algorithms

Math:
* Convex hull of 2D points
* Counting primes up to N
* Euclidean algorithm (GCD, Diophantine equations)
* Rounded integer division
* Gaussian elimination
* Modular Gaussian elimination
* Fast Fourier transform
* Matrix multiplication and exponentiation
* Sieve of Eratosthenes

Other:
* Monotone queue (can tell maximum element in O(1))

### How to use?

All snippets assume that you have the following predefined:
```cpp
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long llint;
```

Just copy-paste any snippet in your code and follow instructions in comments.

### Are these implementations correct?

Yes, they're very likely to be.

All snippets were tested in solutions for multiple programming problems, and
used as a reference in two ACM-ICPC world finals.

### Can I use these snippets in my code?

Yes, I don't care.

Just make sure you understand the rules of competitions you
participate in. Sometimes they require solutions to be fully written by
yourself.
