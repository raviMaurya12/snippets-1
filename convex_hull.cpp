// 2D convex hull

vector<Pt> convex_hull(vector<Pt> pts) {
  sort(pts.begin(), pts.end());
  vector<Pt> H;

  REP(step, 2) {
    auto start = H.size();
    for (Pt P : pts) {
      while (H.size() >= start+2 && ccw(H[H.size()-2], H[H.size()-1], P) < 0)
        H.pop_back();
      H.push_back(P);
    }
    
    H.pop_back();
    reverse(pts.begin(), pts.end());
  }
  return H;
}

