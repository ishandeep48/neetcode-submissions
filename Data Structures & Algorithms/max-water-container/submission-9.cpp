class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maxWater=0;
        while(i<j){
            // cout<<i<<" "<<j<<" "<<heights[i]<<" "<<heights[j]<<endl;
            int water = (min(heights[i],heights[j])*(j-i));
            maxWater = max((min(heights[i],heights[j])*(j-i)),maxWater);
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxWater;
    }
};
