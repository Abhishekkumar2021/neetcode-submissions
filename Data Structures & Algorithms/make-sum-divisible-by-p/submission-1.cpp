
class Solution {
  public:
    int ok(vector<int> &nums, int target) {
        int n = nums.size();
        int sum = 0;
        int i = 0, j = 0;

        int min_len = n + 1;
        while (j < n) {
            sum += nums[j];
            while (sum > target) {
                sum -= nums[i];
                i++;
            }
            if (sum == target) {
              min_len = min(min_len, j - i + 1);
            }
            j++;
        }

        return min_len == n + 1 ? -1 : min_len;
    }

    int minSubarray(vector<int> &nums, int p) {
        int n = nums.size();
        int sum = 0;
        for (auto &x : nums)
            sum += x;

        int target = sum % p;
        if (target == 0) return 0;

        for(int s = target; s < sum; s += p) {
            int len = ok(nums, s);
            if (len != -1) {
                return len;
            }
        }

        return -1;
    }
};
