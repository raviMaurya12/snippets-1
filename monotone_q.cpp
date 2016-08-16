// Monotone queue

// template<class T> struct MinQ {
// template<class T> struct MaxQ {
  deque<T> D, Q;
  T top() { return D.front(); }

  void push(T x) {
    // while (!D.empty() && x < D.back()) D.pop_back(); // MinQ
    // while (!D.empty() && x > D.back()) D.pop_back(); // MaxQ
    D.push_back(x);
    Q.push_back(x);
  }

  void pop() {
    if (D.front() == Q.front()) D.pop_front();
    Q.pop_front();
  }

  T front() { return Q.front(); }
  T empty() { return Q.empty(); }
  T size()  { return Q.size();  }
};
