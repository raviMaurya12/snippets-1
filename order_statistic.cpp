// Example usage of the order-statistic tree

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using ost =
  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void run() {
  ost<int> T;
  REP(i, 5) T.insert(10 * i);

  assert(*T.find_by_order(0) == 0);
  assert(*T.find_by_order(2) == 20);
  assert(T.find_by_order(999) == T.end());

  assert(T.order_of_key(-5) == 0);
  assert(T.order_of_key(0) == 0);
  assert(T.order_of_key(17) == 2);
  assert(T.order_of_key(20) == 2);
  assert(T.order_of_key(999) == T.size());
}
