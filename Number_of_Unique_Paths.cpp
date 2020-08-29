#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
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

// ll factorials[100];
// void factorial()
// {
//     factorials[0]=factorials[1]=1;
//     for (int i = 2; i <= sizeof(factorials)/sizeof(0); i++)
//     {
//         factorials[i]=i*factorials[i-1];
//     }
// }

int uniquePath(int M, int N)
{
    int dp[M][N];
    
    for(int i = 0; i < M; i++)
    {
        dp[i][0] = 1;
    }
    
    for(int j = 0; j < N; j++)
    {
        dp[0][j] = 1;
    }
    
    for(int i = 1; i < M; i++)
    {
        for(int j = 1; j < N; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    
    return dp[M-1][N-1];
}

// int uniquePaththroughFactorial(int M,int N)
// {
    
//     factorial();
//     return factorials[M+N-2] / ( factorials[M-1] * factorials[N-1] );
// }

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    while(T--)
    {
        int M, N;
        cin >> M >> N;
        
        cout << uniquePath(M, N) << "\n";
    }
	return 0;
}