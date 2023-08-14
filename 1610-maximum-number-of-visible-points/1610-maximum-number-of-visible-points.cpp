#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
 double calculateAngle(int x, int y, const std::vector<int>& location) {
        int dx = x - location[0];
        int dy = y - location[1];
        double angle = std::atan2(dy, dx) * 180.0 / M_PI;
        if (angle < 0) {
            angle += 360.0;
        }
        return angle;
    }

    int visiblePoints(std::vector<std::vector<int>>& points, int angle, std::vector<int>& location) {
        std::vector<double> angles;
        int ans = 0;
        int overlappingPoints = 0;

        for (const auto& point : points) {
            if (point == location) {
                overlappingPoints++;
            } else {
                double angle = calculateAngle(point[0], point[1], location);
                angles.push_back(angle);
                angles.push_back(angle + 360.0); // To handle circular cases
            }
        }

        std::sort(angles.begin(), angles.end());

        int n = angles.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && angles[j] - angles[i] <= angle) {
                j++;
            }
            ans = std::max(ans, j - i);
        }

        return ans + overlappingPoints;
    }
};

