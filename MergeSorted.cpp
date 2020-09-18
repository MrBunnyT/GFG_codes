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

// float solveMedian(vi &first,vi &second,int m,int n,bool cond,int middle)
// {
//     vi after(m+n);
//     // while(i<middle)
//     // {
//     //     merged.pushback()
//     //     track?a++:b++;i++;
//     //     if(first[a]<=second[b]&&!track)
//     //         solveMedian(first,second,middle,true,a,b,i,cond);
//     //     else if (second[b]<=first[a]&&track)
//     //         solveMedian(first,second,middle,false,a,b,i,cond);
//     // }
//     // if(i==middle && cond)
//     //     return 
//     merge(all(first),all(second),after.begin());
//     return cond?(float)(after[middle]+after[middle-1])/2:after[middle];
// }

class Solution {
public:
    // double findMedianSortedArrays(vector<int>&nums1,vector<int>&nums2){
    //     int m=nums1.size();
    //     int n=nums2.size();
    //     if(m>n)
    //         return findMedianSortedArrays(nums2,nums1);
    //     int begin=0,end=m;
    //     while(begin<=end){
    //         int xpart=begin+end/2;
    //         int ypart=(m+n+1)/2-xpart;
    //         int leftX=(xpart==0)?INT_MIN:nums1[xpart-1];
    //         int rightX=(xpart==m)?INT_MAX:nums1[xpart];
    //         int leftY=(ypart==0)?INT_MIN:nums2[ypart-1];
    //         int rightY=(ypart==n)?INT_MAX:nums2[ypart];
    //         if(leftX<=rightY&&leftY<=rightX){
    //             if((m+n)%2==0)
    //                 return (double)(max(leftX,leftY)+min(rightX,rightY))/2;
    //             return (double)(max(leftX,leftY));
    //         }
    //         else if(leftX>rightY)
    //             end=xpart-1;
    //         else
    //             begin=xpart+1;
    //     }
    //     return -1.0;
    // }
    double findMedianSortedArrays(vector<int>&nums1,vector<int>&nums2)
    {
        int m = nums1.size(),n=nums2.size();
        vector<int> result(m+n);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),result.begin());
        int middle = (m+n)/2;
        if(m+n%2==0)
            return (double)(result[middle]+result[middle-1])/2;
        return (double)(result[middle]);
    }
};

int main()
{
    int t;cin >> t;

    for(int i=0;i<t;i++) {
        int m,n;
        scanf("%d%d",&m,&n);
        vi  first(m),second(n);
        for(int j=0;j<m;j++)
            scanf("%d",&first[j]);
        for(int j=0;j<n;j++)
            scanf("%d",&second[j]);
    Solution test;
    printf("%f",test.findMedianSortedArrays(first,second));
    }
}