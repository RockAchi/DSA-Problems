//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void swap(vector<int>& nums, int pos1, int pos2) {
        int temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }
    void sortColors(vector<int>& nums) {

        int lo = 0, mid = 0, high = nums.size()-1;
        while (mid <= high) {
            if (nums[mid] == 0)
                swap(nums, lo++, mid++);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums, mid, high--);
        }
    }
};
