class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    int partition(int start, int end, vector<int> &nums){
        int pivoit = nums[start];
        
        while(start < end){
            while(start < end && pivoit <= nums[end]) end--;
            nums[start] = nums[end];
            
            while(start < end && pivoit >= nums[start]) start++;
            nums[end] = nums[start];  
        }
    
        nums[start] = pivoit;
        return start;
    }
     
     
    void quicksort(int start, int end, vector<int> &nums){
        if(start >= end){
            return;
        }
        
        int cen = partition(start, end, nums);
        quicksort(start, cen - 1, nums);
        quicksort(cen + 1, end, nums);
    }
    
    void wiggleSort(vector<int> &nums) {
        // write your code here
        
        //sort
        quicksort(0, nums.size() - 1, nums);
        
        for(int i = 2; i < nums.size(); i += 2){
            int tmp = nums[i];
            nums[i] = nums[i - 1];
            nums[i - 1] = tmp;
        }
    }
};