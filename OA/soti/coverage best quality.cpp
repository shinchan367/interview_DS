#include <iostream>
#include <vector>
#include <algorithm>

int maximumQualitySub(const std::vector<int>& arr) {
    int max_quality = 0;

    for (int i = 0; i < arr.size(); ++i) {
        int min_element = arr[i];
        int length = 1;

        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] >= min_element) {
                length++;
            } else {
                break;
            }
        }

        int quality = min_element * length;
        max_quality = std::max(max_quality, quality);
    }

    return max_quality;
}

int main() {
    std::vector<int> arr = {3, 1, 6, 4, 5, 2};
    int result = maximumQualitySub(arr);
    std::cout << "Maximum Quality of Subarray: " << result << std::endl;

    return 0;
}
