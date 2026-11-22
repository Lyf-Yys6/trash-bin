
#include <iostream>
using namespace std;

int n,k,a[25];
int ans;

bool jud(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

void poccess(int cnt,int sum,int poi)
{
    if(cnt==k)
    {
        cout<<sum<<endl;
        if(jud(sum))ans++;
        return;
    }
    for(int i=poi;i<=n-(k-cnt-1);i++)
    {
        poccess(cnt+1,sum+a[i],i+1);
    }
}

int main()
{
   
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    poccess(0,0,1);
    cout<<ans;
    
    
    return 0;
}