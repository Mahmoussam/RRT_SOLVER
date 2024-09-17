#include<bits/stdc++.h>
#include "csv_utils.cpp"
#include "graph_utils/graph_types.h"
#include "graph_utils/graph_building.cpp"
#include "RRT.cpp"
using namespace std;
void write_nodes_file(vector<Node*> &nodes){
    CSVWriter writer("task1/nodes.csv");
    
    for(auto node : nodes){
        
        writer.addRow({to_string(node->getID()), to_string(node->getX()) , to_string(node->getY()) , to_string(node->h)});
    }
    
    writer.writeCSV();
}
void write_path_file(vector<Node> path){
    CSVWriter writer("task1/path.csv");
    vector<string> row;
    for(auto i : path){
        row.push_back(to_string(i.getID()));
    }
    writer.addRow(row);
    writer.writeCSV();
}

int main(){


    CSVReader obstacles_reader("task1/obstacles.csv") , nodes_reader("task1/in_nodes.csv");
    vector<vector<string>> obestacles_raw = obstacles_reader.readCSV() , nodes_raw = nodes_reader.readCSV();
    vector<CircleObstacle> obstacles;
    vector<Node*> nodes;
    
    build_obstacles(obstacles, obestacles_raw);
    build_nodes(nodes , nodes_raw);
    
    GSpace space(obstacles);
    //cout<<space.is_line_clear(nodes[0] , Node(-.5,-.4923132))<< " ?"<<endl;;
    RRT solver(nodes[0], nodes[1] , space , 0.1 , 1e3 , 0.2);
    auto res = solver.findPath(nodes);
    
    cout<<"Path size : "<<res.size()<<endl; 
    cout<<"Path: ";
    for(auto n : res){
        cout<<n.getID()<<",";
    }cout<<endl;
    cout<<"Nodes found : "<<nodes.size()<<endl;
    write_nodes_file(nodes);
    write_path_file(res);
    return 0;
}