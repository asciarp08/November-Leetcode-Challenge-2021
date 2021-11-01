/**
Time = O(m*n)
Space = O(m*n)
**/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        bool flip = 0;
        //first and the last row
        for(int j = 0; j<n; j++){
            if(board[0][j]=='O')
                dfs(0,j,m,n,board, flip);
            if(board[m-1][j]=='O')
                dfs(m-1,j,m,n, board, flip);
        }
        
        //first and the last column
        for(int i = 0; i<m; i++){
            if(board[i][0]=='O')
                dfs(i,0,m,n,board, flip);
            if(board[i][n-1]=='O')
                dfs(i,n-1,m,n,board, flip);
        }
        
        flip = 1;
        for(int i = 0;i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='O')
                    dfs(i,j,m,n,board, flip);
            }
        }
        
        for(int i = 0;i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='*')
                    board[i][j] = 'O';
            }
        }
        
    }
    
    void dfs(int x, int y, int& m, int& n, vector<vector<char>>& board, bool flip){
        if(flip)
            board[x][y] = 'X';
        else{
            board[x][y] = '*';
        }
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]=='O')
                dfs(nx, ny, m, n, board, flip);
        }
    }
};
