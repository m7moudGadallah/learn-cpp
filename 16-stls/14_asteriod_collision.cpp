#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static bool is_reverse_direction(const int& ast) {
        return ast < 0;
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> line;

        for (const auto& ast : asteroids) {
            bool exploded = false;

            while (!line.empty() and is_reverse_direction(ast) and !is_reverse_direction(line.back())) {
                if (abs(ast) <= abs(line.back())) {
                    if (abs(ast) == abs(line.back())) {
                        line.pop_back();
                    }
                    exploded = true;
                    break;
                }
                line.pop_back();
            }

            if (!exploded) {
                line.emplace_back(ast);
            }
        }

        return line;
    }
};