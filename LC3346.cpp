class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int maxEl = *max_element(nums.begin(), nums.end()) + k;

        vector<int> freq(maxEl + 1, 0);

        for (int num : nums)
            freq[num]++;

        for (int i = 1; i <= maxEl; i++)
            freq[i] += freq[i - 1];

        int result = 0;

        for (int target = 0; target <= maxEl; target++) {

            int right = min(maxEl, target + k);
            int left = max(0, target - k);

            int totalcount = freq[right] - ((left > 0) ? freq[left - 1] : 0);
            int targetFreqCount =
                freq[target] - ((target > 0) ? freq[target - 1] : 0);

            int needConversion = totalcount - targetFreqCount;

            result = max(result,
                         targetFreqCount + min(numOperations, needConversion));
        }

        return result;
    }
};
