
#include <vector>
using namespace std;

vector<int> termsOfAP(int x) {
    vector<int> result;
    int N = 1;

    while (result.size() < x) {
        int term = 3 * N + 2;
        if (term % 4 != 0) {
            result.push_back(term);
        }
        N++;
    }
    
    return result;
}
