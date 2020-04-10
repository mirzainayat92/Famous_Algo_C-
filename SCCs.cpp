/*
    mirza_inayat
    SCCs using Tarjan's Algorithm
*/
#include <bits/stdc++.h>
using namespace std;
#define F(i,k,n) for(int i=k;i<n;i++)
#define N 10
vector<int> G[N];
int timer=-1;
int id[N],low[N];
stack<int> st;
bool onStack[N];

void dfs(int x) {
    if(id[x] >= 0)
        return;
    id[x] = low[x] = ++timer;
    st.push(x);
    onStack[x] = 1;
    for(int i : G[x]){
        dfs(i);
        if(onStack[i])
            low[x] = min(low[i],low[x]);
    }
    //On dfs() Callback if we comes back at the starting of one of the SCCs 
    //then pushoff all the element of that SCCs from the stack 
    //id[x] = low[x] states that x is the starting of one of the SCCs  
    if(id[x] == low[x])
        while(1){
            int node = st.top();
            st.pop();
            onStack[node] = 0;
            low[node] = id[x];
            if(node == x)
                break;
        }
}
void tarjan(int n){
    F(i,0,N)
        id[i] = -1;    //also used as visited[]

    F(i,0,n)
        dfs(i);
    
    vector<int> scc[N];
    set<int> s;
    F(i,0,n){
        s.insert(low[i]);
        scc[low[i]].push_back(i);
    }

    cout << "Total no. of SCCs - " << s.size() << endl;
    for(int i : s){
        for(int j : scc[i])
            cout << j << " " ;
        cout << endl;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int a,b; 
    F(i,0,m){
        cin >> a >> b;
        G[a].push_back(b); 
    }
    tarjan(n);
}