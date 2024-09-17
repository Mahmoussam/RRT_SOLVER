#include<bits/stdc++.h>
#include "csv_utils.cpp"
#include "graph_utils/graph_types.h"
#include "graph_utils/graph_building.cpp"
#include "RRT.cpp"
using namespace std;

int main(){
    CSVReader obstacles_reader("task1/obstacles.csv") , nodes_reader("task1/nodes.csv");
    vector<vector<string>> obestacles_raw = obstacles_reader.readCSV() , nodes_raw = nodes_reader.readCSV();
    vector<CircleObstacle> obstacles;
    vector<Node> nodes;
    
    build_obstacles(obstacles, obestacles_raw);
    build_nodes(nodes , nodes_raw);
    GSpace space(obstacles);
    RRT solver(nodes , space);
    auto res = solver.findPath();
    cout<<"Nodes : "<<nodes.size()<<endl;
    cout<<"Path size : "<<res.size()<<endl; 
    cout<<"Path: ";
    for(auto n : res){
        cout<<n.getID()<<",";
    }cout<<endl;
    return 0;
}