#include "graph_types.h"

CircleObstacle::CircleObstacle(double x, double y, double radius)
    : x(x), y(y), radius(radius) {}

// Accessor methods
double CircleObstacle::getX() const { return x; }
double CircleObstacle::getY() const { return y; }
double CircleObstacle::getRadius() const { return radius; }

// Intersects method
bool CircleObstacle::intersects(const Node& node1, const Node& node2) const {
    // Circle center and radius
    double cx = x;
    double cy = y;

    // Coordinates of the line segment's endpoints
    double x1 = node1.x;
    double y1 = node1.y;
    double x2 = node2.x;
    double y2 = node2.y;

    // Vector from node1 to node2
    double dx = x2 - x1;
    double dy = y2 - y1;

    // Vector from node1 to the circle center
    double fx = cx - x1;
    double fy = cy - y1;

    // Projection of the circle center onto the line segment
    double a = dx * dx + dy * dy;
    double b = 2 * (fx * dx + fy * dy);
    double t = -b / (2 * a);

    // Clamp t to the closest point on the segment
    if (t < 0.0) t = 0.0;
    if (t > 1.0) t = 1.0;

    // Find the closest point on the segment to the circle center
    double closestX = x1 + t * dx;
    double closestY = y1 + t * dy;

    // Distance from the closest point to the circle center
    double distanceSquared = (closestX - cx) * (closestX - cx) + (closestY - cy) * (closestY - cy);

    // Check if the distance is less than or equal to the circle's radius
    return distanceSquared - radius * radius <= EPS;
}