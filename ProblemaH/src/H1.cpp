#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

int inversos[11] = {
    0,
    1,
    500000004,
    333333336,
    250000002,
    400000003,
    166666668,
    142857144,
    125000001,
    111111112,
    700000005
};

ll total_cabezas(int r, int h, int p) {
    ll total = h;
    if(r==1) total*=p;
    else {
        for (int i = 0; i < p; i++) {
            total*=r;
            total%=MOD;
        }
        total-=h;
        total%=MOD;
        total*=inversos[r-1];
    }
    total%=MOD;
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