#include<iostream>
#include<stdio.h>
#include<string.h>
#define ll long long int
using namespace std;
ll dp[1002][1002],n,T=1,M=1000000007;
ll vis[1002][1002];
ll call(ll i,ll maxi)
{
    if(i==1)
        return 1;
    if(vis[i][maxi]==T)
        return dp[i][maxi];
    ll ret=0;
    ret+=(maxi)*call(i-1,maxi);
    ret%=M;
    ret+=call(i-1,maxi+1);
    ret%=M;
    vis[i][maxi]=T;
    //cout<<ret<<endl;
    return dp[i][maxi]=ret;
}
int main()
{
    int t,i,j,pos;
   //A n=1000;
    //T++;
    //call(1000,1);
    //T++;
    scanf("%d",&t);
    while(t--)
    {
        //memset(vis,false,sizeof(vis));
        scanf("%lld",&n);
        printf("%lld\n",call(n,1));
        //T++;
    }
    return 0;
}
