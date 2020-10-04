#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long

#define QUICK                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);cout.tie(NULL);     \
    cerr.tie(NULL);
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define t_start auto start = chrono::high_resolution_clock::now();
#define t_stop                                                                       \
    auto stop = chrono::high_resolution_clock::now();                                \
    ld duration = chrono::duration_cast<chrono::microseconds>(stop - start).count(); \
    duration *= 1e-6;                                                                \
    cerr << fixed << duration << setprecision(9) << "\n";
#define deb(x) cerr << #x << "=" << x << "\n"
#define deb2(x, y) cerr << #x << "=" << x << ", " << #y << "=" << y << "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))

/* int main() {

	QUICK 
    t_start
    set<int> init;
    ll K,M,N;
    cin>>K>>M>>N;
    fo(i,N){
        ll temp;cin>>temp;
        init.insert(temp);
    }
    set<int> new_init,next_init;
    new_init.insert(1);
    int check = 0;
    for(unsigned ll mask=(ll)1<<40;mask;mask>>=1){    
        for(auto j=new_init.begin();j!=new_init.end();j++){
            for(auto k=j;k!=new_init.end();k++){
                    // deb2(*j,*k);
                    ll temp = ((*j)*(*k))%M;
                    next_init.insert(temp);
            }
        }
        new_init.swap(next_init);
        next_init.clear();check<<=1;
        int enter_check = K&mask;
        if(K&mask){
            for(auto j=init.begin();j!=init.end();j++){
                for(auto k=new_init.begin();k!=new_init.end();k++){
                    ll temp = ((*j)*(*k))%M;
                    next_init.insert(temp);
                }
            }
            new_init.swap(next_init);
            next_init.clear();
            check++;
        }
    }
    for(int i:new_init) cout<<i<<" ";cout<<"\n";
    t_stop
} */
int main()
{
    QUICK
    t_start int t;
    ll K, M, N;
    cin >> K >> M >> N;
    /* deb2(K,M);deb(N); */
    char init[M];
    memset(init, 0, M);
    fo(i, N) cin >> t && (init[t] = 1);
    /* fo(i,M)if(init[i])deb(i); */
    char new_inits[2][M];
    int switcher = 0;
    unsigned ll check = 0;
    memset(new_inits, 0, 2 * M);
    new_inits[switcher][1] = 1;
    for (unsigned ll mask = (ll)1 << 63; mask; mask >>= 1)
    {
        memset(new_inits[!switcher], 0, M);
        fo(i, M)
        {
            for (int j = i; j < M; j++)
            {
                if (new_inits[switcher][i] && new_inits[switcher][j])
                    new_inits[!switcher][(i * j) % M] = 1;
            }
        }
        /*         cerr<<"enter\n";
        fo(i,M)if(new_inits[0][i])deb(i);
        fo(i,M)if(new_inits[1][i])deb(i); */
        switcher = !switcher;
        check <<= 1;
        if (mask & K)
        {
            /* cerr<<"enters odd------------------------------------------------\n"; */
            memset(new_inits[!switcher], 0, M);
            fo(i, M)
            {
                fo(j, M)
                {
                    if (init[i] && new_inits[switcher][j])
                    {
                        new_inits[!switcher][(i * j) % M] = 1;
                    }
                }
            }
            switcher = !switcher;
            check++;
        }
    }
    fo(i, M) if (new_inits[switcher][i]) cout << i << " ";
    t_stop
}