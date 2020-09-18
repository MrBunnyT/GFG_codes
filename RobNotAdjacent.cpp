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
    // int rob(vector<int>& nums) {
    //     if(nums.size()==0)
    //         return 0;
    //     int excl = 0,new_excl;
    //     for(int i=1;i<nums.size();i++)
    //     {
    //         new_excl = max(excl,nums[i-1]);
    //         nums[i]+=excl;
    //         excl = new_excl;
    //     }
    //     return max(nums[nums.size()-1],excl);
    // }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int sz=nums.size();
        int dp[sz][2];
        dp[0][0]=nums[0];
        dp[0][1]=0;
        for(int i=1;i<sz;i++)
        {
            if(i<2)
            {
                dp[i][0]=nums[i];
                dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
            }
            else
            {
                dp[i][0]=nums[i]+dp[i-1][1];
                dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
            }
        }
        return max(dp[sz-1][0],dp[sz-1][1]);
    }
};

int main()
{
    int t=1;cin >> t;
    while(t--){
        int sz;
        scanf("%d",&sz);
        vi nums(sz);
        for(int j=0;j<sz;j++)
            scanf("%d ",&nums[j]);
        Solution test;
        printf("%d\n",test.rob(nums));
    }

}