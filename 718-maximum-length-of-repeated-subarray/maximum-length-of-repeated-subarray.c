int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dp[1001][1001] = {0};
    int ans = 0;

    for (int i = nums1Size - 1; i >= 0; i--) {
        for (int j = nums2Size - 1; j >= 0; j--) {
            if (nums1[i] == nums2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
    }

    return ans;
}