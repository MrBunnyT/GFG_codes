#include <bits/stdc++.h>

using namespace std;

void solve(int data[],int student_count)
{
    int visit[student_count];
    memset(visit,0,student_count);
    for(int i=0;i<student_count;i++)
    {
        for(int j=i;j<student_count;++j)
        {
            if (data[i]>data[j]&&visit[j]==0)
            {
                visit[j]=1;
                printf("%d ",data[j]);
            }
            else
                cout<<"-1";
        }
    }
}

int main()
{
    int T;scanf("%d",T);
    while(T--)
    {
        int student_count;scanf("%d",student_count);
        int data[student_count];
        for(int i=0;i<student_count;++i)
            scanf("%d",data[i]);
        solve(data,student_count);
    }
}
