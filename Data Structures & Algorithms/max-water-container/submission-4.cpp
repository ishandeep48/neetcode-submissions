class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maxWater = 0;
        while(i<j){
            int curr_water = min(heights[i],heights[j])*(j-i); 
            maxWater = max(maxWater,curr_water);
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxWater;
    }
};
