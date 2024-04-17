#include<bits/stdc++.h>
using namespace std;

    
void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j){
        if(i<0 || j<0 ||i>=grid.size() || j>=grid[0].size() || grid[i][j]=='X' || vis[i][j]){
            return;
        }
        vis[i][j]=1;
        bfs(grid,vis,i-1,j);
        bfs(grid,vis,i,j+1);
        bfs(grid,vis,i+1,j);
        bfs(grid,vis,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
         vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),0));
         for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
            bfs(board,vis,i,0);
            }
         }
         for(int i=0;i<board.size();i++){
             if(board[i][board[i].size()-1]=='O'){
            bfs(board,vis,i,board[i].size()-1);
             }
         }
        for(int i=0;i<board[0].size();i++){
             if(board[0][i]=='O'){
            bfs(board,vis,0,i);
             }
         }
         for(int i=0;i<board[0].size();i++){
             if(board[board.size()-1][i]=='O'){
            bfs(board,vis,board.size()-1,i);
             }
         }
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                 if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                 }
            }
         }
    }
 int main(){
       
           vector<vector<char>> grid={{'X','X','X','X','O'},
                                    {'X','X','O','X','O'},
                                    {'X','X','X','O','X'},
                                    {'O','O','X','O','X'} };
         solve(grid);
         
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                 cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
         }
        return 0;
    }