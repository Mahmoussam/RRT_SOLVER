#include "graph_types.h"
//#include <iostream>
CircleObstacle::CircleObstacle(double x, double y, double radius)
    : x(x), y(y), radius(radius) {}

// Accessor methods
double CircleObstacle::getX() const { return x; }
double CircleObstacle::getY() const { return y; }
double CircleObstacle::getRadius() const { return radius; }

// Intersects method
bool CircleObstacle::intersects(const Node& node1, const Node& node2) const {
    //use node 1 as reference.. 
    // Create arrays to represent points
    std::vector<double> p1 = {node1.x, node1.y};
    std::vector<double> p2 = {node2.x, node2.y};

    // Compute directional vector of the line (p2 - p1)
    std::vector<double> dp = {p2[0] - p1[0], p2[1] - p1[1]};

    // Compute magnitude of the direction vector
    double magnitude = std::sqrt(dp[0] * dp[0] + dp[1] * dp[1]);

    // Compute unit vector (normalize the direction vector)
    std::vector<double> unit_vector = {dp[0] / magnitude, dp[1] / magnitude};

    // Sample 20 points between p1 and p2
    for (int i = 1; i <= 20; ++i) {
        // Calculate the new sampled point along the line
        std::vector<double> new_point = {
            (p1[0] + unit_vector[0] * (i / 20.0) * magnitude),
            (p1[1] + unit_vector[1] * (i / 20.0) * magnitude)
        };

        // Calculate the distance between the new point and the circle's center
        double distance_to_circle = std::sqrt((new_point[0] - x) * (new_point[0] - x) +
                                              (new_point[1] - y) * (new_point[1] - y));

        // If the distance is less than or equal to the circle's radius, return false
        if (distance_to_circle <= radius) {
            return true;  // Intersection detected
        }
    }

    return false;  // No intersection
    
    
    
    
    
    
    
    /*const double EPS = 1e-30;
    GVector vc(x - node1.x , y - node1.y)
        ,vn(node2.x - node1.x ,  node2.y - node1.y);
        double t = (vc * vn) / (vn * vn);
        t = std::max(0.0 , t);
        t = std::min(1.0 , t);
        double new_x = node1.x + t * vn.x
            , new_y = node1.y + t * vn.y;
        //std::cout<<new_x<<", "<<new_y<<std::endl;
        double some = (new_x - x) * (new_x - x) + (new_y - y) * (new_y - y) - radius * radius;
        return (some <= EPS);
        */
}
bool CircleObstacle::contains_node(const Node& node)const{
    return dist_2(Node(x,y) , node) <= radius * radius;
}

double dist_2(Node n1 , Node n2){
    return (n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y);
}
double dist(Node n1 , Node n2){
    return std::sqrt(dist_2(n1 , n2));
}