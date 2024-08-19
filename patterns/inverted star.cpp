class Solution{
public:
	
	void printTriangle(int n) {
    // Outer loop to control the number of rows
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            cout << "*";
        }
        // Print trailing spaces (optional, not needed here for correct pattern)
        
        // Move to the next line after printing each row
        cout << endl;
    }
}
};
