class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    int minOperations(vector<int>& nums) {

        int n = nums.size();

        int count = 0;

        for (int x : nums)
            if (x == 1)
                count++;

        if (count > 0)
            return n - count;

        int minStepsTo1 = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            int GCD = nums[i];

            for(int j = i + 1 ; j < n ; j++){
                GCD = gcd(GCD , nums[j]);

                if(GCD == 1){
                    minStepsTo1 = min(minStepsTo1 , j - i);
                    break;
                }
            }

        }

        if(minStepsTo1 == INT_MAX) return -1;
        else return (minStepsTo1 + n - 1);

    }
};
