#include<iostream>
using namespace std;

void Factorial(int n,int ans)
{
    if(n==0)
        cout<<ans;
    else
    {
        ans=ans*n;
        Factorial(n-1,ans);
    }
}

int main()
{
    int n;cin>>n;
    Factorial(n,1);
}
