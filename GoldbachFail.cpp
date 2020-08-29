#include<bits/stdc++.h>
using namespace std;

vector <int> Primes;
const int sz = 1000000;
bool viable[sz];

void Sieves()
{
    memset(viable,true,sizeof(viable));
    
    for(int p = 2;p*p<=sz;p++)
    {
        if(viable[p])
        {
            for(int i = p*p;i<=sz;i+=p)
                viable[i] = false;
        }
    }
    
    for(int i = 2;i<=sz;i++)
    if(viable[i])
    Primes.push_back(i);
}

int main()
{
    Sieves();
    int ans;
    for(int i=9;i<=sz;i++)
    {
        if(!viable[i]&&i%2!=0)
        {
            int j=0;
            while(true&&i>Primes[j])
            {
                double resultant = i;
                resultant = sqrt((resultant-Primes[j])/2);
                resultant-=floor(resultant);
                if(resultant==0)
                {    break;}
                j++;
            }
            if(i<Primes[j])
            {
                ans = i;break;
            }
        } 
    }
    cout<<ans<<"\n";
}