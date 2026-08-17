class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int start1 = 0;
        int start2 = 0;
        int end1 = nums1.size();
        int total_size = (nums1.size() + nums2.size());
        int middle1, middle2;
        while (start1 <= end1) {
            middle1 = start1 + (end1 - start1) / 2;
            middle2 = ((total_size + 1) / 2) - (middle1);
            int left1 = (middle1 > 0) ? nums1[middle1-1] : INT_MIN;
            int right1 =
                (middle1  < nums1.size()) ? nums1[middle1] : INT_MAX;

            int left2 = (middle2 > 0) ? nums2[middle2-1] : INT_MIN;
            int right2 =
                (middle2  < nums2.size()) ? nums2[middle2 ] : INT_MAX;
            if (left1 > right2) {
                end1 = middle1 - 1;
            } else if (left2 > right1) {
                start1 = middle1 + 1;
            } else {
                break;
            }
        }
        int left1 = (middle1 > 0) ? nums1[middle1-1] : INT_MIN;
        int right1 =
            (middle1  < nums1.size()) ? nums1[middle1 ] : INT_MAX;

        int left2 = (middle2 > 0) ? nums2[middle2-1] : INT_MIN;
        int right2 =
            (middle2  < nums2.size()) ? nums2[middle2] : INT_MAX;

        if (total_size % 2 == 0) {
            return (max(left1, left2) + min(right1, right2)) / 2.0;
        } else {
            return max(left1, left2);
        }
    }
};