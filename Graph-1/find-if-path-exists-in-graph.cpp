#include<bits/stdc++.h>
using namespace std;

    bool validPath(int n, vector<vector<int>>& vect, int st, int dest) {
         unordered_map<int,vector<int>> mp;
         for(auto x:vect){
              mp[x[0]].push_back(x[1]);
              mp[x[1]].push_back(x[0]);
         }
         vector<bool> visited(n,0);
         queue<int> q;
         q.push(st);
         visited[st]=1;
         while(!q.empty()){
            int x=q.front();
            q.pop();
            vector<int> v=mp[x];
            for(int i=0;i<v.size();i++){
                 if(visited[v[i]]==false){
                    visited[v[i]]=1;
                    q.push(v[i]);
                 }
            }
         }
         return visited[dest];
    } 
    int main(){
        int st,dest,n;
        cout<<"Enter No of vect:\n";
        cin>>n;
        vector<vector<int>> vect(n,vector<int>(2));
        cout<<"enter the vect:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cin>>vect[i][j];
            }
        }
        cout<<"Enter sts ans dest:  ";
        cin>>st>>dest;
        bool ans=validPath(n,vect,st,dest);
        if(ans){
            cout<<"The Valid Path is Possible!";
        }
        else{
            cout<<"NOT Possible";
        }
        return 0;
    }
