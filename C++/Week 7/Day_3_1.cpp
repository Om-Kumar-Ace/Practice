#include <iostream>
#include <cmath>

int findMinAngle(int H, int M) {
    // Calculate the positions of hour and minute hands in degrees
    double hour_angle = (H % 12) * 30 + M * 0.5;
    double minute_angle = M * 6;

    // Calculate the absolute difference between the two angles
    double angle = std::abs(hour_angle - minute_angle);

    // Find the minimum of the two possible angles
    double min_angle = std::min(angle, 360 - angle);

    // Return the floor value of the minimum angle
    return static_cast<int>(min_angle);
}

int main() {
    int T;
    std::cin >> T; // Read number of test cases

    while (T--) {
        int H, M;
        std::cin >> H >> M; // Read hour and minute
        std::cout << findMinAngle(H, M) << std::endl; // Print the minimum angle
    }

    return 0;
}
