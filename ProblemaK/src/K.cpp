#include <iostream>
#include <vector>
#include <deque>
using namespace std;

using cola_monotona = deque<pair<long long, int>>;


namespace ColaMonotona{
    void insertar(cola_monotona & cm, int k, long long x, int i){
        while(!cm.empty() && x <= cm.front().first)
            cm.pop_front();
        cm.push_front({x,i});
        while(!cm.empty() && cm.back().second >= i+k)
            cm.pop_back();
    }

    inline long long minimo(cola_monotona & cm){
        return cm.back().first;
    }
};

void resuelveCaso(){
    int n, k; cin >> n >> k;

    vector<long long> v(n);
    long long sum = 0;
    for(auto&e:v) {
        cin >> e;
        sum += e;
    }

    vector<long long> dp(n+1, 0);
    cola_monotona cm;

    for(int i = n-1; i >= n-k; --i){
        ColaMonotona::insertar(cm, k+1, v[i], i);
    }
    for(int i = n-k-1; i >= 0; --i){
        long long x = v[i] + dp[i+1];
        ColaMonotona::insertar(cm, k+1, x, i);
        dp[i] = ColaMonotona::minimo(cm);
    }

    cout << sum - dp[0] << endl;
}


int main(){
    int t; cin >> t;
    for(int i = 0; i < t; ++i){
        resuelveCaso();
    }
}
