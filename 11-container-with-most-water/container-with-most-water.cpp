class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        int start = 0, end = n - 1;
        while(start <= end){
            int currentBase = end - start;
            int minHeight = min(height[start], height[end]);
            int currentArea = currentBase * minHeight;
            if(maxArea < currentArea){
                maxArea = currentArea;
            }

            if(height[start] >= height[end]){
                end--;
            }else{
                start++;
            }
        }
        return maxArea;
    }
};