#include <iostream>
#include <string>

using namespace std;

void decode_huff(node* root, string s) {
    string decoded_str = "";
    node* current = root;
    
    for (char bit : s) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        // If a leaf node is reached
        if (current->left == nullptr && current->right == nullptr) {
            decoded_str += current->data;
            current = root;
        }
    }

    cout << decoded_str << endl;
}
