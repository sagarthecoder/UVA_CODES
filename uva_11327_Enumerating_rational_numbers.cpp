#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum[200002];
ll GCD(ll a,ll b)
{
    if(a==0)return b;
    if(b==0)return a;
    if(a%b==0)
        return b;
    else
        return GCD(b,a%b);
}
ll go(ll x)
{
    ll ans=x;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            while(x%i==0)x=x/i;
            ans-=ans/i;
        }
    }
    if(x>1)ans-=ans/x;
    return ans;
}
int main()
{
    sum[1]=2;
    for(ll i=2;i<=200000;i++){
        sum[i]=sum[i-1]+go(i);
    }
    while(true)
    {
        scanf("%lld",&n);if(!n)break;
        ll low=lower_bound(sum,sum+200001,n)-sum;
        ll baki=n-sum[low-1];
        for(ll i=0;i<=low;i++)
        {
            if(GCD(i,low)==1){
                baki--;
                if(baki==0){
                    printf("%lld/%lld\n",i,low);break;
                }
            }
        }
    }
    return 0;
}
