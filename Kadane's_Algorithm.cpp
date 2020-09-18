#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;


int kadaneSolve(int inp[],int sz)
{
    int gsum=INT_MIN,lsum=0;
    for(int i=0;i<sz;i++)
        {
            lsum = max(inp[i],lsum+inp[i]);
            gsum=max(lsum,gsum);
        }
    return gsum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++) {
        int sz;scanf("%d",&sz);
        int inp[sz];int ans = INT_MIN;
        fo(j,sz)
            scanf("%d",&inp[j]);
        printf("%d\n",kadaneSolve(inp,sz));
    }

}