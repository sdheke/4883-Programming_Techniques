// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 10/21/2020
// Problem 920

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;

struct Peak { int x, y; };

// Return the Euclidean distance between a and b
double dist(Peak a, Peak b)
{
    return sqrt((double)(a.x - b.x) * (a.x - b.x)
                      + (a.y - b.y) * (a.y - b.y));
}

bool comp(const Peak &a, const Peak &b)
{
    return b.x < a.x;
}

int main()
{    
    int C;
    cin >> C;
    while ( C-- )
    {
        int N;
        cin >> N;
        vector<Peak> points;
        for (int i = 1; i <= N; ++i)
        {
            Peak point;
            cin >> point.x >> point.y;
            points.push_back(point);
        }

        // Sort the points in descending order of x-coordinate.
        sort(points.begin(), points.end(), comp);

        
        int currentMaxY = 0;
        double length = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i].y > currentMaxY)
            {
                length += dist(points[i], points[i - 1]) 
                          * (points[i].y - currentMaxY) / (points[i].y - points[i - 1].y); 
                currentMaxY = points[i].y;
            }
        }

        // Print with two decimal digits.
        cout << setprecision(2)
             << setiosflags(ios::fixed)
             << length << endl;
    }
    return 0;
}
