#ifndef GRAPH_TYPES_H
#define GRAPH_TYPES_H

#include <cmath>

const double EPS = -1e6;

struct Node {
    int ID;
    double x, y, h;
    int parent_ID;
    Node(double x , double y){
        this->x = x;
        this->y = y;
        this->h = 0;
        this->parent_ID = -1;

    }
    Node(int ID , double x , double y ,double h , int parent_ID = -1){
        this->ID  = ID;
        this->x = x;
        this->y = y;
        this->h = h;
        this->parent_ID = parent_ID;
    }
};

class CircleObstacle {
public:
    CircleObstacle(double x, double y, double radius);

    double getX() const;
    double getY() const;
    double getRadius() const;
    bool intersects(const Node& node1, const Node& node2) const;

private:
    double x;
    double y;
    double radius;
};
#include "graph_types.cpp"
#endif // GRAPH_TYPES_H
