#ifndef GRAPH_BUILDING_CPP
#define GRAPH_BUILDING_CPP
#include <vector>
#include <string>

#include "graph_types.h"

void build_obstacles(std::vector<CircleObstacle> &obstacles , const std::vector<std::vector<std::string>> &obstacles_raw ) {
    for(auto row : obstacles_raw){
        obstacles.push_back(CircleObstacle(std::stod(row[0]), std::stod(row[1]), std::stod(row[2])));
    }
}
void build_nodes(std::vector<Node> &nodes , const std::vector<std::vector<std::string>> &nodes_raw ) {
    for(auto row : nodes_raw){
        nodes.push_back(Node(stoi(row[0]) , stod(row[1]) , stod(row[2]) ,stod(row[3])));
    }
}


#endif