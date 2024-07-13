#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

ll total_cabezas(int r, int h, int p) {
  ll total, sumando;
  total = 0;
  sumando = h;
  for (int i = 0; i < p; i++) {
    total += sumando;
    sumando *= r;
    total %= MOD;
    sumando %= MOD;
  }
  return total;
}

int main() {
  int r; // Replicación
  int h; // Ramificación
  ll total; // Suma total
  stack<int> cuellos; // Cuellos

  scanf("%d", &r);
  while (r != 0) {
    total = 0;
    do {
      scanf("%d", & h);
      if (h != 0) {
        cuellos.push(h);
        total += total_cabezas(r, h, cuellos.size());
        total %= MOD;
      } else {
        cuellos.top()--;
        while (cuellos.top() == 0) {
          cuellos.pop();
          if (cuellos.empty()) break; 
          else cuellos.top()--;
        }
      }
    } while (!cuellos.empty());
    printf("%lld\n", total);
    scanf("%d", &r);
  }
}