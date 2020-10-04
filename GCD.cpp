#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define QUICK ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define t_start auto start = chrono::high_resolution_clock::now();
#define t_stop auto stop = chrono::high_resolution_clock::now();ld duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();duration*=1e-6;cerr<<fixed<<duration<<setprecision(9)<<"\n";
#define ll long long
#define ld long double
#define deb(x) cerr << #x << "=" << x << endl;
#define deb2(x, y) cerr << #x << "=" << x << " , " << #y << "=" << y << endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))

vector<long long> ans(2,0);
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> ans(2,0);
        if(A==0||B==0) {ans[1]=max(A,B);return ans;}
        ans ={A,B};
        for( ;A%B!=0;swap(A,B)) A=A%B;
        ans[1]=(ans[0]/min(A,B))*ans[1];ans[0]=min(A,B);
        return ans;
    }

    ll SteinGcd(ll a,ll b)
    {
        if(a==0&&b==0)return 0;
        if(a==0||b==0) return max(a,b);
        ll bits=0;
        for( ;(~a&1)&&(~b&1);a>>=1,b>>=1,bits++)deb2(a,b)
        if(a&1) swap(a,b);
        for( ;a!=0;a=a-b){
            deb2(a,b)
            while(~a&1)a>>=1;
            if(b>a)swap(a,b);
        }
        return b<<bits;
    }
};

int main()
{
    QUICK t_start
    int t=1;cin >> t;
    fo(tc,t){
        ll a,b;cin>>a>>b;
        Solution ok;
        vector<ll> ans(2);
        ans = ok.lcmAndGcd(a,b);
        for(int i:ans)
            cout<<i<<" ";
        cout<<"\n"<<ok.SteinGcd(a,b);
    }
}