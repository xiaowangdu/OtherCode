class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &nums, int target) {
        // write your code here
        if(nums.size() == 0){
            return -1;
        }
        int start = 0, end = nums.size() - 1;
        int temp = nums[end];
        while(start + 1 < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(temp == target){
                return nums.size() - 1;
            }
            if(temp < target){
                if(nums[mid] < target && nums[mid] > temp){
                    start = mid;
                }
                else{
                    end = mid;
                }
            }
            else{
                if(nums[mid] > target && nums[mid] < temp){
                    end = mid;
                }
                else{
                    start = mid;
                }
            } 
        }
        if(nums[start] == target){
            return start;
        }
        if(nums[end] == target){
            return end;
        }
        return -1;
    }
};