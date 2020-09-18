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

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int right_extent = 0, x_coor = 0, y_coor =0;
        for(char i:instructions){
            if(i == 'R') right_extent++;
            else if(i == 'L') right_extent--;
            else
            {
                if(right_extent == 0) 
                    y_coor++;
                else if(right_extent == 1) 
                    x_coor++;
                else if(right_extent == 2) 
                    y_coor--;
                else 
                    x_coor--;
            }
            right_extent = (right_extent + 4) % 4;
        }
        cout<<right_extent<<"\n";
        if(x_coor == 0 && y_coor == 0) 
            return true;
        if(right_extent == 0) return false;
        return true;
    }
};

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t=1;cin >> t;
    while(t--){
        string instructions;
        cin>>instructions;
        char dir='U';
        int ans = 0,x=0,y=0;
        Solution ok;
        cout<<(ok.isRobotBounded(instructions)?"true":"false")<<"\n";
    }
}