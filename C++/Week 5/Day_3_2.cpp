#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <execution>

static auto _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        std::vector<std::pair<std::string, int>> pairs{};
        for (std::size_t i = 0; i < names.size(); i++)
            pairs.push_back(std::make_pair(names[i], heights[i]));

        std::sort(std::execution::par_unseq, pairs.begin(), pairs.end(), [](const auto& a, const auto& b) -> bool {
            return a.second > b.second;
        });

        std::vector<std::string> ret;
        for (const auto& p : pairs)
            ret.push_back(p.first);

        return ret;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
    std::vector<int> heights = {155, 180, 165};

    std::vector<std::string> sortedNames = solution.sortPeople(names, heights);

    for (const auto& name : sortedNames) {
        std::cout << name << " ";
    }

    return 0;
}
