class Solution {
public:
    int trap(vector<int>& height) {
        int maxL = height[0];
        int maxR = height[height.size()-1];
        int i=0;
        int j=height.size()-1;
        int res=0;
        while(i<j){
            if(maxL<maxR){
                i++;
                int water = maxL-height[i];
                if(water>0) res+=water;
                maxL = max(maxL,height[i]);                
            }else{
                j--;
                int water = maxR-height[j];
                if(water>0) res+=water;
                maxR = max(maxR,height[j]);                
            }
        }
        return res;
    }
};