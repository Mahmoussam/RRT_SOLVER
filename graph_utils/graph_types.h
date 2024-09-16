#ifndef GRAPH_TYPES_H
#define GRAPH_TYPES_H

#include <cmath>
#include <algorithm>
#include <vector>

const double EPS = 1e-6;
/**
 * Geometric 2D vector
*/
struct GVector{
    double x , y;
    GVector(double x , double y){
        this->x = x;
        this->y = y;
    }
    /** dot product */
    double operator*(const GVector& other) const {
        return x * other.x + y * other.y;
    }
    void mult(double magnitude){
        x *= magnitude;
        y *= magnitude;
    }
    double get_magnitude(){
        return sqrt(x * x + y * y);
    }
};
/**
 * graph (tree) node 
*/
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
/**
 * a Solid obstacle circle shaped representation class
*/
class CircleObstacle {
public:
    CircleObstacle(double x, double y, double radius);

    double getX() const;
    double getY() const;
    double getRadius() const;
    bool intersects(const Node& node1, const Node& node2) const;
    bool contains_node(const Node& node)const;
private:
    double x;
    double y;
    double radius;
};

class GSpace{
private:
    

public:
    std::vector<CircleObstacle> obstacles;//let these as public for now..
    std::vector<Node>nodes;

    GSpace(std::vector<CircleObstacle> obs , std::vector<Node>nos){
        obstacles = obs;
        nodes = nos;
    }

    bool is_line_clear(Node n1 , Node n2){
        bool clear = true;
        for(auto obs : obstacles){
            if(obs.intersects(n1,n2)){
                clear = false;
                break;
            }
        }
        return clear;
    }
    bool is_node_clear(Node node){
        bool clear = true;
        for(auto obs : obstacles){
            if(obs.contains_node(node)){
                clear = false;
                break;
            }
        }
        return clear;
    }
};
/**
 * Returns distance between 2 nodes
*/
double dist(Node n1 , Node n2);
/**
 * Returns distance squared between 2 nodes..
*/
double dist_2(Node n1 , Node n2);

#include "graph_types.cpp"
#endif // GRAPH_TYPES_H
