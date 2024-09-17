#ifndef GRAPH_TYPES_H
#define GRAPH_TYPES_H

#include <cmath>
#include <algorithm>
#include <vector>


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
    Node* parent;
    
    Node(){}
    Node(double x , double y){
        this->x = x;
        this->y = y;
        this->h = 0;
        this->parent = nullptr;

    }
    Node(int ID , double x , double y ,double h , Node* parent = nullptr){
        this->ID  = ID;
        this->x = x;
        this->y = y;
        this->h = h;
        this->parent = parent;
    }
    double getX(){return x;}
    double getY(){return y;}
    void setParent(Node* parent){
        this->parent = parent;
    }
    Node* getParent(){return parent;}
    int getID(){return ID;}
    void setID(int i){
        ID = i;
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
#include<iostream>
class GSpace{
private:
    std::vector<std::pair<double,double>> dimensions = {{-0.5 , 0.5} , {-0.5 , 0.5}} ;

public:
    std::vector<CircleObstacle> obstacles;//let these as public for now..
    
    GSpace(){

    }
    GSpace(std::vector<CircleObstacle> obs ){
        obstacles = obs;
    }
    /**
     * returns the size of a dimension..
    */
    std::pair<double , double> getDim(int dim_idx){
        return dimensions[dim_idx];
    }
    
    bool is_line_clear(Node n1 , Node n2){
        bool clear = true;
        for(auto obs : obstacles){
            if(obs.intersects(n1,n2)){
                //std::cout<<"Caught : "<<n1.x<<" "<<n1.y<<" "<<n2.x<<" "<<n2.y<<std::endl;
                //std::cout<<"@ obs : "<<obs.getX()<<" "<<obs.getY()<<" "<<obs.getRadius()<<std::endl;
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
