class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         // Vector to store the number of dissatisfied customers per minute
        vector<int> dissatisfied(customers.size());
        // Variable to store the total number of initially satisfied customers
        int satisfied = 0;

        // Calculate initial dissatisfied customers and satisfied customers when owner is not grumpy
        for (int i = 0; i < grumpy.size(); i++) {
            dissatisfied[i] = grumpy[i] * customers[i];
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        // Convert dissatisfied array to a prefix sum array
        for (int i = 1; i < dissatisfied.size(); i++) {
            dissatisfied[i] += dissatisfied[i - 1];
        }

        // Initialize the maximum additional satisfied customers by applying the technique for the first 'minutes' minutes
        int maxAdditionalSatisfied = dissatisfied[minutes - 1];
        // Slide the window of 'minutes' over the dissatisfied array to find the maximum additional satisfied customers
        for (int i = minutes; i < dissatisfied.size(); i++) {
            maxAdditionalSatisfied = max(maxAdditionalSatisfied, dissatisfied[i] - dissatisfied[i - minutes]);
        }

        // The total satisfied customers is the sum of initially satisfied customers and the maximum additional satisfied customers
        return satisfied + maxAdditionalSatisfied;
    }
};