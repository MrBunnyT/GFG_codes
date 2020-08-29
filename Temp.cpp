// #include<bits/stdc++.h>
// using namespace std;

// struct node
// {
//     int data;
//     node *next;
// }*first = NULL;

// void Create(int arr[],int n)
// {
//     int i;
//     struct node *t,*last;
//     first =  new node();
//     first->next=NULL;
//     last = first;
//     for(i=0;i<n;i++)
//     {
//         t = new node();
//         t->data=arr[i];
//         t->next=NULL;
//         last->next=t;
//         last=t;
//     }
// }

// void display(node *p)
// {
//     p=p->next;
//     while(p!=NULL)
//     {
//         p=p->next;
//         cout<<p->data;
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// 	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     int sz;cin>>sz;
//     int A[] = {1,2,3,4};
//     Create(A,sz);
//     display(first);
// }

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


int uniquePath(int M, int N)
{
    int dp[M+1][N+1];
    
    for(int i = 1; i <= M; i++)
    {
        dp[i][1] = 1;
    }
    
    for(int j = 1; j <= N; j++)
    {
        dp[1][j] = 1;
    }
    
    for(int i = 2; i <= M; i++)
    {
        for(int j = 2; j <= N; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    for (int i = 1; i < M+1; i++)
    {
        for (int j = 1; j < N+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
    return dp[M][N];
}
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
        
        cout << uniquePath(M, N) << endl;
    }
	return 0;
}