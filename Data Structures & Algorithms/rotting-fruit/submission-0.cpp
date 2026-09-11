class Solution {
public:
    int bfs(queue<pair<int,int>>&rotten,vector<vector<int>>& grid){
        int seconds=0;
        int xN[4]={0,1,0,-1};
        int yN[4]={1,0,-1,0};
        while(!rotten.empty()){
            int size=rotten.size();
            for(int i=0;i<size;i++){
                auto coords=rotten.front();
                rotten.pop();
                for(int j=0;j<4;j++){
                    int newX=coords.first+xN[j];
                    int newY=coords.second+yN[j];
                    if((newX>-1 && newX<grid.size())&&(newY>-1 && newY<grid[0].size())){
                        if(grid[newX][newY]==1){
                            grid[newX][newY]=2;
                            rotten.push({newX,newY});
                        }
                    }
                }
                
            }
            if(!rotten.empty()) seconds++;
        }
        return seconds;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>rotten;
        bool freshPresent = false;
        int size=grid.size();
        int ySize = grid[0].size();
        for(int i=0;i<size;i++){
            for(int j=0;j<ySize;j++){
                if(grid[i][j]==2){
                    rotten.push({i,j});
                }
                if(!freshPresent && grid[i][j]==1) freshPresent=true;
            }
        }
        if(rotten.size()==0 && freshPresent) return -1;
        if(rotten.size()==0 && !freshPresent) return 0;
        int seconds = bfs(rotten,grid);
        for(int i=0;i<size;i++){
            for(int j=0;j<ySize;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return seconds;
    }
};