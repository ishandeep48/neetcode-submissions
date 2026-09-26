class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        int count = -1;
        for (int i : nums) {
            if (arr.size() == 0) {
                arr.push_back(i);
                count++;
                continue;
            }
            if (arr[count] < i) {
                arr.push_back(i);
                count++;
            } else if (arr[count] > i) {
                int low = 0;
                int high = count;
                while (low < high) {
                    int middle = low + (high - low) / 2;
                    if (arr[middle] >= i) {
                        high = middle;
                    } else {
                        low = middle + 1;
                    }
                }
                arr[low] = i;
            }
        }
        return arr.size();
    }
};