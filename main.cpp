#include<bits/stdc++.h>
#include "csv_utils.cpp"
#include "graph_utils/graph_types.h"
#include "graph_utils/graph_building.cpp"
using namespace std;

int main(){
    CSVReader obstacles_reader("task1/obstacles.csv") , nodes_reader("task1/nodes.csv");
    vector<vector<string>> obestacles_raw = obstacles_reader.readCSV() , nodes_raw = nodes_reader.readCSV();
    vector<CircleObstacle> obstacles;
    vector<Node> nodes;
    
    build_obstacles(obstacles, obestacles_raw);
    build_nodes(nodes , nodes_raw);
    GSpace space(obstacles,nodes);

    return 0;
}