/**
Time - O(3^m*n)
Space - O(m*n)
**/
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int empty = 0;
        int startX, startY;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1)
                    startX = i,startY = j;
                if(grid[i][j]==0)
                    empty++;
            }
        }
        
        int paths = 0;
        dfs(startX, startY, m, n, 0, empty, grid, paths);
        return paths;
    }
    
    void dfs(int x, int y, int& m, int& n, int count, int& empty, vector<vector<int>>& grid, int& paths){
        
        int original = grid[x][y];
        grid[x][y] = -1;
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=-1){
                if(grid[nx][ny]==2 && count==empty){
                    paths++;
                }
                if(grid[nx][ny]==0){
                    dfs(nx, ny, m, n, count+1, empty, grid, paths);
                }
            }
        }
        
        grid[x][y] = original;
    }
};
