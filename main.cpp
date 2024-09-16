#include<bits/stdc++.h>
#include "csv_utils.h"
#include "graph_utils/graph_types.h"

using namespace std;

int main(){
    Node node1(1.0, 1.0);
    Node node2(4.0, 4.0);
    CircleObstacle circle(3.0, 3.0, 1.0);
    cout<<circle.intersects(node1, node2)<<endl;
    return 0;
}