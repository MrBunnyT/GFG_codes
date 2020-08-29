#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;

pair<int,int> solve()
{
    int n, sum;
    cin >> n >> sum;
    vector <int> v(n);
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v[i] = num;
    }

    int left{0};
    int curSum = v[0];
    int right{0};
    while( !(left > n-1 && right > n-1))
    {
        if( curSum == sum)
        {
            return make_pair(left + 1 , right + 1);
        }
        else if( curSum < sum)
        {
            if( right == n -1)
            {
                break;
            }

            right++;
            curSum += v.at(right);
        }
        else
        {
            curSum -= v.at(left);
            left++;
            if( right < left&&left<n)
            {
                right = left;
                curSum = v.at(right);
            }

        }
    }

    return make_pair(-1, 0);
}

int main() 
{
    int t;
    cin >> t;
    vector < pair <int,int> > op;
    for(int i = 0; i < t; i++)
    {
        op.push_back(solve());
    }

    for( auto p : op)
    {
        if (p.first == -1)
            cout << -1 << endl;
        else
        {
            cout << p.first << " " << p.second << endl;
        }
    }

}