#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

set<int> arti_points;
vector<int> gr[N];
vector<bool> vis(N, false);

int disc[N], low[N];

int tme = 1;

void dfs(int curr, int par){
    vis[curr] = true;
    int child = 0;
    disc[curr] = low[curr] = tme++;
    for(auto x : gr[curr]){
        if(!vis[x]){
            child++;
            dfs(x, curr);
            
            //check if low of curr is less than low of child
            low[curr] = min(low[x], low[curr]);//This is not for anything that we require
            
            if(par!=0 && low[x]>=disc[curr])
                arti_points.insert(curr);
            
            
        }else if(x!=par){
            low[curr] = min(disc[x],low[curr]);
        }
    }
    if(par==0 && child>1)
        arti_points.insert(curr);
        
        return;
}

void solve(int n){
    dfs(1,0);
}

vector<bool> destructiveBob(int n, vector<vector<int>> edges, vector<int>queries)
{
    vector<bool> ans;
    ans.clear();
    
  for(auto it : edges){
      gr[it[0]].push_back(it[1]);
      gr[it[1]].push_back(it[0]);
  }
  solve(n);

  for(auto a : arti_points)
    cout<<a<<" -- ";

  cout<<"Queries Solving";
  for(auto q : queries){
      if(arti_points.find(q)!=arti_points.end()){
          ans.push_back(true);
      }else{
          ans.push_back(false);
      }
  }
  return ans;
}

int main(){
    vector<vector<int> >edges = {{1,2},{2,4},{2,3},{4,5},{1,3}};
    vector<int> q = {1,2,3,4,5};

    vector<bool> ans = destructiveBob(5, edges, q);

    for(auto x: ans){
        cout<<x<<endl;
    }
}