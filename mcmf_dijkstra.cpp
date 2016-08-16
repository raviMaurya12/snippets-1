// Min-cost max-flow (uses Dijkstra's algorithm)
//
// Configure: MAXV
// Configure: MAXE (at least 2*calls_to_edge)
// Configure: oo (max_capacity and max_distance)
//
// init(n): Resets and initializes with given number of nodes
// edge(x, y, c, w): Adds an edge x->y with capacity c and weight w
// run(src, sink): Starts the algorithm and returns {total_flow, total_cost}

namespace Mcmf {
  const int MAXV = 1000100;
  const int MAXE = 1000100;
  const llint oo = 1e18;

  int V, E;
  int last[MAXV], how[MAXV]; llint dist[MAXV];
  int next[MAXE], from[MAXE], adj[MAXE]; llint cap[MAXE], cost[MAXE];

  struct cmpf {
    bool operator () (int a, int b) {
      if (dist[a] != dist[b]) return dist[a] < dist[b];
      return a < b;
    }
  };
  set<int, cmpf> S;

  void init(int n) {
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
  }

  void edge(int x, int y, llint c, llint w) {
    from[E] = x; adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
    from[E] = y; adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
  }

  pair<llint, llint> run(int src, int sink) {
    llint total = 0;
    llint flow = 0;

    for (;;) {
      REP(i, V) dist[i] = oo;
      dist[src] = 0;

      for (;;) {
        bool done = true;
        REP(x, V) for (int e = last[x]; e != -1; e = next[e]) {
          if (cap[e] == 0) continue;

          int y = adj[e];
          llint val = dist[x] + cost[e];

          if (val < dist[y]) {
            dist[y] = val;
            how[y] = e;
            done = false;
          }
        }
        if (done) break;
      }

      if (dist[sink] >= oo / 2) break;

      llint aug = cap[how[sink]];
      for (int i = sink; i != src; i = from[how[i]])
        aug = min(aug, cap[how[i]]);

      for (int i = sink; i != src; i = from[how[i]]) {
        cap[how[i]] -= aug;
        cap[how[i]^1] += aug;
        total += cost[how[i]] * aug;
      }
      flow += aug;
    }
    return {total, flow};
  }
}
