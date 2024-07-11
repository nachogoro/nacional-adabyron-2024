#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)x.size())
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
const int mod = 1e9 + 7;
bool solve() {
    int n;
    cin >> n;
    if (n == 0) {
        return false;
    }
    vll disp(n + 1), ans(n + 1);
    vi btlncks = {0};
    ll aans = 0;
    disp[0] = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> disp[i];
        while (disp[btlncks[sz(btlncks) - 1]] >= disp[i]) {
            btlncks.pop_back();
        }
        btlncks.push_back(i);
        if (disp[i] < 2) continue;
        ans[i] = ((disp[i] - 1) * (i - btlncks[sz(btlncks) - 2] - 1))%mod;
        ans[i] = (ans[i] + ans[btlncks[sz(btlncks) - 2]])%mod;
        if (disp[btlncks[sz(btlncks) - 2]] > 0) ans[i] = (ans[i] + disp[btlncks[sz(btlncks) - 2]] - 1)%mod;
        aans = (aans + ans[i])%mod;
    }
    cout << aans << "\n";
    return true;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (solve());

    cout.flush();
    return EXIT_SUCCESS;
}
