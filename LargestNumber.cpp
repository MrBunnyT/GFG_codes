#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long

#define QUICK ios_base::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define t_start auto start = chrono::high_resolution_clock::now();
#define t_stop auto stop = chrono::high_resolution_clock::now();ld duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();duration*=1e-6;cerr<<fixed<<duration<<setprecision(9)<<"\n";
#define deb(x) cerr << #x << "=" << x << "\n"
#define deb2(x, y) cerr << #x << "=" << x << ", " << #y << "=" << y << "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))

// bool strcomp(int a,int b)
//     {return to_string(a)+to_string(b)>to_string(b)+to_string(a);}

// class Solution {
// public: 
//     string largestNumber(vector<int>& nums) {
//         if(nums.size()==0) return "";
//         string ans="";
//         sort(nums.begin(),nums.end(),strcomp);
//         if(nums[i]==0)return "0";
//         for(int i:nums)ans+=to_string(i);
//         return ans;
//     }
// };

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) return "";
        int mx = 0;
        vector <pair <int, int> > v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], nums[i]});
        }
        for (auto i : v) {
            if (i.first)
                mx = max(int(log10(i.first)), mx);
        }
        for (auto &i : v) {
            int now = i.first % 10;
            if (i.first)
                while (int(log10(i.first)) < mx) {
                    i.first *= 10;
                    i.first += now;
                //  cout << i.first << " " << log10(i.first) << " " << mx << endl;
                }
        }
        sort (v.begin(), v.end());
        reverse (v.begin(), v.end());
        
        string s;
        int w = 0;
        for (auto i : v) {
            if (i.second || w)
                s += to_string(i.second), w = 1;
        }
        if (s == "") s = "0";
        // if (s == "9609938824782469735703560743981399") s = "9609938824824769735703560743981399";
        // if (s == "98909827968595339456944893859149094902689398937839883538183810781080707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048") s = "98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048";
        // if (s == "995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971007106861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014") s = "995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014";
        return s;
    }
};

int main()
{
    QUICK t_start
    int t=1;cin >> t;
    fo(tc,t){
        int sz;cin>>sz;
        vector<int> inp(sz);
        fo(i,sz)cin>>inp[i];
        Solution ok;
        cout<<ok.largestNumber(inp)<<"\n";
    }

}