class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        vector<int> res(2, -1);
        
        for(int i = 0; i < numbers.size() - 1; ++i){
            int first = i;
            for(int j = i + 1; j < numbers.size(); ++j){
                if(numbers[i] + numbers[j] == target){
                    res[0] = i; res[1] = j;
                    return res;
                }
            }
        }
        
        return res;
    }
};