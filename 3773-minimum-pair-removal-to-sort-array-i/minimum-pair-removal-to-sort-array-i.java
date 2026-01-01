class Solution {
    public int minimumPairRemoval(int[] nums) {
        int ops = 0;

        while (!isNonDecreasing(nums)) {
            int n = nums.length;
            int minSum = Integer.MAX_VALUE;
            int idx = 0;

            // find leftmost adjacent pair with minimum sum
            for (int i = 0; i < n - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            // merge nums[idx] and nums[idx + 1]
            int[] next = new int[n - 1];
            int k = 0;
            for (int i = 0; i < n; i++) {
                if (i == idx) {
                    next[k++] = nums[i] + nums[i + 1];
                    i++; // skip next
                } else {
                    next[k++] = nums[i];
                }
            }

            nums = next;
            ops++;
        }

        return ops;
    }

    private boolean isNonDecreasing(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
}
