class Solution {
public:
    void dfs(vector<vector<char>>& grid,const int&x , const int&y){
        int xC[4]={0,1,0,-1};
        int yC[4]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int tempX=x+xC[i];
            int tempY=y+yC[i];
            if((tempX>-1 && tempX<grid.size())&&(tempY>-1 && tempY<grid[0].size())){
                if(grid[tempX][tempY]=='1'){
                    grid[tempX][tempY]='#';
                    dfs(grid,tempX,tempY);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int count=0;
        int n=grid[0].size();
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]=='1'){
                    grid[x][y]='#';
                    count++;
                    dfs(grid,x,y);
                }
            }
        }
        return count;
    }
};