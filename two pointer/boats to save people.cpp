class Solution {
public:
   int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
    sort(people.begin(), people.end()); // Sort the people by weight
    int boats = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++; // Pair the lightest person with the heaviest person within the weight limit
        }
        right--; // Move to the next heaviest person
        boats++; // Increment the boat count for each pair (or single person if not paired)
    }
    return boats;
}
};
