#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define ll long long int
ll w[1020], p[1020];
//map<ll,map<ll,ll> >dp;
ll dp[1004][37];
ll knap(ll i,ll weight,ll n,ll load)
{
    ll x,y;
    if(i==n)return 0;
    if(dp[i][weight]!=0)return dp[i][weight];
    if(weight+w[i]<=load)x=p[i]+knap(i+1,weight+w[i],n,load);
    else x=0;
    y=knap(i+1,weight,n,load);
    return dp[i][weight]= max(x,y);
}
int main()
{
    ll t,n,load,man,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=0;
        //memset(w,0,sizeof(w));
        //memset(p,0,sizeof(p));

        for(int i=0;i<n;i++)scanf("%lld %lld",&p[i],&w[i]);
        scanf("%lld",&man);
        for(int i=0;i<man;i++)
        {
            scanf("%lld",&load);
            memset(dp,0,sizeof(dp));
            ans+=knap(0,0,n,load);
            //dp.clear();
        }
            printf("%lld\n",ans);

    }
    return 0;
}
