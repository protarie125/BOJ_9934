#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll K;
ll b, t;
vl lst;
vl graph;

void Fill(ll x) {
  if (b < x * 2) {
    graph[x] = lst[t++];
    return;
  }

  Fill(x * 2);
  graph[x] = lst[t++];
  Fill(x * 2 + 1);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> K;
  b = 1;
  for (auto i = 0; i < K; ++i) {
    b *= 2;
  }
  --b;

  lst = vl(b);
  for (auto&& x : lst) cin >> x;

  graph = vl(b + 1);
  t = 0;
  Fill(1);

  ll n = 2;
  for (auto i = 1; i <= b; ++i) {
    cout << graph[i] << ' ';
    if (i + 1 == n) {
      cout << '\n';
      n *= 2;
    }
  }

  return 0;
}
