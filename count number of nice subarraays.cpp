import java.util.HashMap;

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length; // Get the length of the input array
        HashMap<Integer, Integer> mpp = new HashMap<>(); // Initialize hashmap to store prefix sums
        int sum = 0; // Initialize sum to count odd numbers
        int ans = 0; // Initialize answer to count subarrays with exactly 'k' odd numbers
        mpp.put(0, 1); // Initialize hashmap with 0 sum to handle cases where subarray starts from index 0

        for (int i = 0; i < n; i++) { // Iterate through the array
            if (nums[i] % 2 == 1) { // Check if the current number is odd
                sum += 1; // Increment the sum if the number is odd
            }
            int diff = sum - k; // Calculate the difference needed to form a subarray with 'k' odd numbers
            ans += mpp.getOrDefault(diff, 0); // Add the count of subarrays found with the required difference
            mpp.put(sum, mpp.getOrDefault(sum, 0) + 1); // Update the hashmap with the current sum
        }

        return ans; 
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example input
        int[] nums = {1, 1, 2, 1, 1};
        int k = 3;

        // Call the function and print the result
        int result = solution.numberOfSubarrays(nums, k);
        System.out.println("Number of subarrays with exactly " + k + " odd numbers: " + result);
    }
}
