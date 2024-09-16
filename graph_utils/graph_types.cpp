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
    GVector vc(x - node1.x , y - node1.y)
        ,vn(node2.x - node1.x ,  node2.y - node1.y);
        double t = (vc * vn) / (vn * vn);
        t = std::max(0.0 , t);
        t = std::min(1.0 , t);
        double new_x = node1.x + t * vn.x
            , new_y = node1.y + t * vn.y;
        //std::cout<<new_x<<", "<<new_y<<std::endl;
        return (new_x - x) * (new_x - x) + (new_y - y) * (new_y - y) - radius * radius <= EPS;
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