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

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int minp=nums[0],maxp=nums[0],ans=INT_MIN;
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]>0)
//             {
//                 maxp = maxp*nums[i];
//                 minp = minp*nums[i];
//             }
//             else if(nums[i]<0)
//             {
//                 maxp = max(maxp*nums[i],nums[i]);
//                 minp = minp * nums[i];
//             }
//             else
//             {
//                 while(nums[i]==0)
//                     i++;
//             }
//         maxp=max(maxp,minp);
//         ans = max(maxp,minp);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int res,ma,mi;
        res=ma=mi=nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]<0)
                swap(ma, mi);
            
            ma = max<long long int>(ma*nums[i], nums[i]);
            mi = min<long long int>(mi*nums[i], nums[i]);
            res = max(res, ma);
        }
        return res;
    }
    int removeDuplicates(vector<int>& nums) {
        int cur_emp=1;
        if(nums.size()<=1)
            return nums.size();
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[cur_emp] = nums[i];
                cur_emp++;
            }
        }
        return cur_emp;
    }
    }
};



int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t=1;cin >> t;
    for(int i=0;i<t;i++) {
        int sz;cin>>sz;
        vi data(sz);
        for(int j=0;j<sz;j++)
            cin>>data[j];       
        Solution test;
        cout<<test.removeDuplicates(data)<<"\n";
        for(int j=0;j<sz;j++)
            cout<<data[j]<<' ';
        cout<<"\n";
    }

}