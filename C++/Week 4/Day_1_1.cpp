#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

class Solution
{
public:
    std::vector<int> survivedRobotsHealths(std::vector<int> &positions,
                                           std::vector<int> &healths, std::string directions)
    {
        int n = positions.size();
        std::vector<int> indices(n), result;
        std::stack<int> stack;

        for (int index = 0; index < n; ++index)
        {
            indices[index] = index;
        }

        std::sort(indices.begin(), indices.end(),
                  [&](int lhs, int rhs)
                  { return positions[lhs] < positions[rhs]; });

        for (int currentIndex : indices)
        {
            if (directions[currentIndex] == 'R')
            {
                stack.push(currentIndex);
            }
            else
            {
                while (!stack.empty() && healths[currentIndex] > 0)
                {
                    int topIndex = stack.top();
                    stack.pop();

                    if (healths[topIndex] > healths[currentIndex])
                    {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    }
                    else if (healths[topIndex] < healths[currentIndex])
                    {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    }
                    else
                    {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int index = 0; index < n; ++index)
        {
            if (healths[index] > 0)
            {
                result.push_back(healths[index]);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> positions = {1, 2, 3, 4, 5};
    std::vector<int> healths = {10, 5, 8, 3, 7};
    std::string directions = "RRLLL";

    std::vector<int> result = solution.survivedRobotsHealths(positions, healths, directions);

    std::cout << "Survived robots' healths: ";
    for (int health : result)
    {
        std::cout << health << " ";
    }
    std::cout << std::endl;

    return 0;
}
