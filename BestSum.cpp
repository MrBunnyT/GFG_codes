#include _CRT_SECURE_NO_WARNINGS
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


int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t=1;
    while(t--){
        int sz;cin>>sz;
        long long data[sz],cur_sum=0;
        for(int j=0;j<sz;++j)
        {
            int temp;
            cin>>temp;
            cur_sum+=temp;
            data[j]=cur_sum;
        }

        // for(int j=0;j<sz;j++)
        //     cout<<data[j]<<" ";
        // cout<<"\n";

        cur_sum=1;
        int sz_copy = 0;
        while (sz_copy+cur_sum<=sz)
        {
            sz_copy+=cur_sum;
            cur_sum++;
        }
        cur_sum--;
        // cout<<sz_copy<<" "<<cur_sum<<"\n";
        ll max_value;
        for(int i=0;i<sz;i++)
        {
            if(i==0)
            {
                max_value=data[sz_copy-1];
            }
            else if(data[i+sz_copy-1]-data[i-1]>max_value)
            {
                max_value = data[i+sz_copy-1]-data[i-1];
            }
            if(sz-i==sz_copy)
            {
                sz_copy-=cur_sum;
                cur_sum--;
            }
        }
        cout<<max_value<<"\n";
    }
}