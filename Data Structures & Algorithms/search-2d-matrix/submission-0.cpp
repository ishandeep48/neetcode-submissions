class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start_outer=0;
        int end_outer = matrix.size()-1;
        while(start_outer<=end_outer){
            int middle_outer =( start_outer + end_outer)/2;
            int size = matrix[middle_outer].size()-1;
            if(matrix[middle_outer][0]<=target && matrix[middle_outer][size]>=target){
                // BS on this 
                int start=0;
                int end = size;
                while(start<=end){
                    int middle =(start+ end ) /2;
                    if(matrix[middle_outer][middle] == target){
                        return true;
                    }
                    if(matrix[middle_outer][middle]>target){
                        end = middle -1;
                    }else{
                        start = middle+1;
                    }
                }
                return false;
            }
            if(target<matrix[middle_outer][0]){
                end_outer = middle_outer-1;
            }else{
                start_outer = middle_outer+1;
            }
        }
        return false;
    }
};