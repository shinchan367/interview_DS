/*Alex want to buy a new phone, as much he held love to personally go over to a store and purchase the phone,
  he cant because we are all lockdown. So Alex visits an online shopping website and browsers through phone
he likes he finally brings down. Options to final 2 Alex want to compare features of both forms.
  Alec lets help Alex makes his choice write a function that accepts as a function to list of features one
for the phone X and one for the phone y and return all the features that are present in y that,Present in x.*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<std::string> compareFeatures(const std::vector<std::string>& phoneX, const std::vector<std::string>& phoneY) {
    // Step 1: Store features of phoneX in an unordered set for quick lookup
    std::unordered_set<std::string> featuresX(phoneX.begin(), phoneX.end());
    
    // Step 2: Create a vector to store unique features found only in phoneY
    std::vector<std::string> uniqueFeatures;

    // Step 3: Loop through phoneY features and find those that are not in phoneX
    for (const auto& feature : phoneY) {
        if (featuresX.find(feature) == featuresX.end()) {
            uniqueFeatures.push_back(feature);  // Add unique features to the result
        }
    }

    // Return the list of unique features
    return uniqueFeatures;
}

int main() {
    // Input: Features of phoneX and phoneY
    std::vector<std::string> phoneX = {"long lasting battery", "clear display", "great camera", "storage space"};
    std::vector<std::string> phoneY = {"clear display", "long lasting battery", "great camera", "spread word processing", "great sound"};

    // Step 4: Call compareFeatures to find unique features in phoneY
    std::vector<std::string> result = compareFeatures(phoneX, phoneY);

    // Step 5: Print the result
    std::cout << "Features in phone Y but not in phone X:" << std::endl;
    for (const auto& feature : result) {
        std::cout << feature << std::endl;
    }

    return 0;
}
