/*
    mirza_inayat
    Graph : vertices are from 0 to n-1
    low[] - same for all the components in a scc. It is minimum tin[u] of all the u present in the particular scc 
    tin[] - time of encounter for any vertex. It is unique for all 
*/
#include <bits/stdc++.h>
using namespace std;
#define F(i,k,n) for(int i=k;i<n;i++)
#define N 10
vector<int> G[N];
int tl=-1;
int tin[N],low[N];
void dfs(int x){
    if(tin[x] >= 0)
        return;
    tin[x] = low[x] = tl++;
    for(int i : G[x]){
        dfs(i);
        low[x] = min(low[x],low[i]);
        if(low[i] > tin[x])
            printf("(%d,%d) is a bridge.\n",x,i);      
    }    
}
void bridges(int n){
    F(i,0,n)
        dfs(i);
}
int main(){
    int n,m;
    cin >> n >> m;
    int a,b; 
    F(i,0,m){
        cin >> a >> b;
        G[a].push_back(b); 
    }
    F(i,0,N){
        tin[i] = -1;    //also used as visited[]
        low[i] = N;
    }
    bridges(n);
}