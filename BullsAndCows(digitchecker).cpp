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

class Solution {
public:
    string getHint(string secret, string guess) {
        int ssz= secret.length();
        int A = 0,B = 0,digits[10];
        memset(digits,0,sizeof(digits));
        for (int i=0;i<ssz;i++)
        {    if(secret[i]==guess[i])
            {   A++;secret[i]=guess[i]='-';}
            else
                digits[secret[i]-'0']++;
        }
        for(int i=0;i<ssz;i++)
        {
            if(guess[i]=='-')
                continue;
            else if(digits[guess[i]-'0'])
            {    
                digits[guess[i]-'0']--;B++;
            }
        }
        return to_string(A)+'A'+to_string(B)+'B';
    }
};


int main()
{

    int t=1;scanf("%d\n",&t);
    for(int i=0;i<t;i++) {
        string secret,guess;
        getline(cin,secret);
        getline(cin,guess);
        Solution test;
        cout<<test.getHint(secret,guess);
    }

}