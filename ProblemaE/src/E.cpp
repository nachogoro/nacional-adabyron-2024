#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef vector<int> vi;

const int INF = INT_MAX;

struct FenwickTree{
    vector<int> ft;
    FenwickTree(int m){
        ft.assign(m+1, 0);
    }
    int rsq(int j){
        int sum = 0;
        for(; j; j -= LSOne(j))
            sum += ft[ j ];
        return sum;
    }
    int rsq(int i, int j){
        return rsq( j ) - rsq( i - 1 );
    }
    void update(int i, int v){
        for(; i < ft.size(); i += LSOne(i))
            ft[ i ] += v;
    }
};
int N;
int nth(FenwickTree& ft, int start, int n){ // O(logn) donde n pertenece [0, N-start-1]
    int l = start, r = N;
    while(l<=r){
        int m = (l+r)/2, c = ft.rsq(start,m)-1; // c >= 0 siempre
        if(n < c) r = m-1;
        else if(c < n) l = m+1;
        else if(ft.rsq(m,m)) return m;
        else r = m-1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N && N){
        vi arr(N); FenwickTree ft(N); set<int> s;s.insert(INF);for(int i = 0; i < N; i++){cin >> arr[i]; s.insert(arr[i]);} int Q; cin >> Q;
        int i = 0;
        ll l = 0, r = 0, q; // [l, r]
        while(Q-- && cin >> q){
            while(q > r && i < N){
                s.erase(arr[i]);
                l = ++r; r += ft.rsq(arr[i], N);
                ft.update(arr[i],1);
                i++;
            }
            int a = (q-l==0?arr[i-1]:nth(ft, arr[i-1], q-l));
            cout << (a < *s.begin() ? "Es la " : "Fue la ") << a << "\n";
        }
        cout << "---\n";
    }
}