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

void solveBalancing(string &inp,int sz)
{
    stack<char> data;
    data.push('-');
    int i = 1;
    for(int streamed=0;streamed<sz;streamed++)
    {
        if(inp[streamed]==')'&& data.top()=='(')
            data.pop();
        else if(inp[streamed]=='}'&& data.top()=='{')   
            data.pop();
        else if(inp[streamed]==']'&& data.top()=='[') 
            data.pop();
        else
            data.push(inp[streamed]);
    }
    if(data.size()>1)
        printf("not balanced\n");
    else
        printf("balanced\n");
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    // #endif
    int t;scanf("%d",&t);
    while(t--)
    {
        string inp;
        cin>>inp;
        solveBalancing(inp,inp.length());
    }

}