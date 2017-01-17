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
* [Aho-Corasick](aho_corasick.cpp) (string searching)
* [Knuth-Morris-Pratt](knuth_morris_pratt.cpp) (string searching)
* [Manacher's algorithm](manacher.cpp) (finding palindromes)
* [Minimum lexicographic rotation](min_rotation.cpp)
* [Palindromic tree](palindromic_tree.cpp) (trie of all substring palindromes)
* [Suffix array and LCP](suffix_array.cpp)
* [Z algorithm](z_algorithm.cpp) (matching all suffixes with longest prefix)

Graphs:
* [Articulation points](articulation_points.cpp)
* [Circulation](circulation.cpp) (a variant of network flow)
* [Dinic's algorithm](dinic.cpp) (maximum flow)
* [Directed minimum spanning tree (arborescence)](directed_mst.cpp)
* [Heavy-light decomposition of a tree](heavy_light.cpp)
* [Min-cost max-flow using DFS](mcmf_dfs.cpp)
* [Min-cost max-flow using Dijkstra](mcmf_dijkstra.cpp)
* [Common tree algorithms](tree.cpp)

Math:
* [Convex hull of 2D points](convex_hull.cpp)
* [Counting primes up to N](count_primes.cpp)
* [Euclidean algorithm](euclid.cpp) (GCD, Diophantine equations)
* [Rounded integer division](div_round.cpp)
* [Gaussian elimination](gauss.cpp)
* [Modular Gaussian elimination](gauss_mod.cpp)
* [Fast Fourier transform](fft.cpp)
* [Matrix multiplication and exponentiation](matrix.cpp)
* [Sieve of Eratosthenes](prime.cpp)

Other:
* [Monotone queue](monotone_queue.cpp) (can tell maximum element in O(1))

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

All snippets were tested in solutions to multiple programming problems, and
used as a reference in two ACM-ICPC world finals.

### Can I use these snippets in my code?

Yes, I don't mind.

Just make sure you understand the rules of competitions you
participate in. Sometimes they require solutions to be fully written by
yourself.
