#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
using vll = vector<ll>;
using LD = long double;

#define ALL(v) v.begin(), v.end()
#define t_start auto start = chrono::high_resolution_clock::now();
#define t_stop auto stop = chrono::high_resolution_clock::now();LD duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();duration*=1e-6;cerr<<fixed<<duration<<setprecision(9)<<"\n";
#define SYNC ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define REP(i , n) for(int i =0 ; i < n ;i++)
#define REPN(i , n) for(int i = 1; i <= n ; i++)
#define deb(x) cerr << #x << " " << x << " ";
#define debl(x) cerr << #x << " " << x << "\n";
#define her 	cerr << " here \n"; 
#define pb push_back
#define fi first 
#define se second
#define un(x) x.erase(unique(ALL(x)), x.end())

ll ModMulti(ll a, ll b, ll & m) { 
    ll prod = (ll)(((ll)a*(ll)b) / (ll)m);
    ll rem = a*b - prod*m; if (rem>m)rem %= m;
    return rem>0?rem:rem+m; 
}



ll ModExp(ll a,ll b,ll m){
    if(b==0) return 1;
    if(b&1) return ModMulti(a,ModExp(a,b-1,m),m);
    long long ans = ModExp(a,b/2,m);
    return (ll) ModMulti(ans,ans,m);
}

ll dig(ll n){
	return (ll) to_string(n).length();
}

ll Solve(ll d,ll n,ll m){
    if(n==0) return 0;
    if(n&1){
        ll ans = Solve(d,n-1,m); 
        return (1 + ModMulti(ModExp(10,d,m),ans,m))%m;
    }
    ll ans = Solve(d*2,n/2,m);
    return (ans+ModMulti(ModExp(10,d,m),ans,m))%m;
}

int main(){ 
    t_start
    int t=1;cin >> t;
    while(t--){
        ll a,n,m;
        cin>>a>>n>>m;
        ll d = dig(a);
        a = a%m; 
        cout<< (a*Solve(d,n,m))%m <<"\n";
    }
    t_stop
}