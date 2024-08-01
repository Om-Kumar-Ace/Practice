#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0; // Counter for seniors
        
        // Iterate through each detail in the vector
        for (const string& detail : details) {
            // Extract the age from positions 11 and 12
            int age = ((detail[11] - '0') * 10) + (detail[12] - '0');
            
            // Check if the age is greater than 60
            if (age > 60) {
                ans++;
            }
        }
        
        return ans; // Return the count of seniors
    }
};
int main() {
    Solution solution;
    vector<string> details = {"Name: John Doe, Age: 65", "Name: Jane Smith, Age: 58", "Name: Bob Johnson, Age: 62"};
    
    int count = solution.countSeniors(details);
    cout << "Number of seniors: " << count << endl; // Output: Number of seniors: 2
    
    return 0;
}
