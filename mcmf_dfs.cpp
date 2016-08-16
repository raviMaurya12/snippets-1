// Min-cost max-flow (uses DFS)
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
  int last[MAXV], curr[MAXV], bio[MAXV]; llint pi[MAXV];
  int next[MAXE], adj[MAXE]; llint cap[MAXE], cost[MAXE];

  void init(int n) {
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
    REP(i, V) pi[i] = 0;
  }

  void edge(int x, int y, llint c, llint w) {
    adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
  }

  llint push(int x, int sink, llint flow) {
    if (x == sink) return flow;
    if (bio[x]) return 0;
    bio[x] = true;

    for (int &e = curr[x]; e != -1; e = next[e]) {
      int y = adj[e];

      if (cap[e] && pi[x] == pi[y] + cost[e])
        if (llint f = push(y, sink, min(flow, cap[e])))
          return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }

  pair<llint, llint> run(int src, int sink) {
    llint total = 0;
    llint flow = 0;

    for (;;) {
      REP(i, V) bio[i] = false;
      REP(i, V) curr[i] = last[i];

      while (llint f = push(src, sink, oo)) {
        total += pi[src] * f;
        flow += f;
        REP(i, V) bio[i] = false;
      }

      llint inc = oo;
      REP(x, V) if (bio[x]) {
        for (int e = last[x]; e != -1; e = next[e]) {
          int y = adj[e];
          if (cap[e] && !bio[y]) inc = min(inc, pi[y] + cost[e] - pi[x]);
        }
      }
      if (inc == oo) break;

      REP(i, V) if (bio[i]) pi[i] += inc;
    }
    return {total, flow};
  }
}
