
#define DEBUG 

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <random>
#include "graph_utils/graph_types.h"
#include "graph_utils/graph_building.cpp"

using namespace std;

double randomDouble(double X, double Y) {
    // Use current time as seed for the random number generator
    static std::mt19937 gen(static_cast<unsigned int>(std::time(0))); 
    // Uniformly distributed in range [X, Y]
    std::uniform_real_distribution<> dis(X, Y);
    
    return dis(gen);
}
class RRT {
private:
	vector<Node> all_nodes;
	Node start;
	Node goal;
	double step_size;
	double number_of_iterations;
	GSpace map;
public:
	RRT(vector<Node> &nodes,GSpace &map, double step_size = 0.5, double number_of_iterations = 5000) {
		this->start = start;
		this->goal = goal;
		this->step_size = step_size;
		this->number_of_iterations = number_of_iterations;
		this->map = map;
		all_nodes = nodes;
		start = nodes[0];
		goal = nodes[1];
	}

	
	Node getNearestNode(Node New_node)
	{
		double min_dist = numeric_limits<double>::max();
		Node nearest_node = all_nodes[0];
		for (int i = 0;i < all_nodes.size();i++)
		{
			double d = dist(New_node , all_nodes[i]);
			if (d < min_dist)
			{
				min_dist = d;
				nearest_node = all_nodes[i];
			}
		}
		return nearest_node;
	}

	/* // requires random seeding 
	Node createRandomNode()
	{
		#error not suitable random function
		double x = (double)rand() / RAND_MAX * map.get_x();
		double y = (double)rand() / RAND_MAX * map.get_y();
		Node rand_node(x, y);
		return rand_node;
	}
	*/
	Node createRandomNode()
	{
		auto d1 = map.getDim(0) , d2 = map.getDim(1);
		double x = randomDouble(d1.first , d1.second);
		double y = randomDouble(d2.first , d2.second);
		Node rand_node(x, y);
		return rand_node;
	}
	Node steer(Node nearest_node, Node rand_node)
	{
		double d = dist(nearest_node, rand_node);
		double theta = atan2(rand_node.getY() - nearest_node.getY(), rand_node.getX() - nearest_node.getX());
		double new_x = nearest_node.getX() + step_size * cos(theta);
		double new_y = nearest_node.getY() + step_size * sin(theta);
		Node new_node(new_x, new_y);
		new_node.setParent(&nearest_node);
		return new_node;
	}

	bool isatgoal(Node new_node)
	{
		if (dist(new_node, goal) < step_size)
		{
			return true;
		}
		return false;
	}

	vector<Node> findPath()
	{
		for (int i = 0;i < number_of_iterations;i++)
		{
			Node rand_node = createRandomNode();
			Node nearest_node = getNearestNode(rand_node);
			Node new_node = steer(nearest_node, rand_node);
			#ifdef DEBUG
				cout<<"New node @ "<<new_node.getX()<<" , "<<new_node.getY()<<endl;
			#endif
			if (map.is_line_clear(nearest_node , new_node)) //el check beta3ak hena (new_node)
			{
				//cout<<"CLEAR PATH, Appending.."<<endl;
				all_nodes.push_back(new_node);
				if (isatgoal(new_node))
				{	//cout<<"GOAL FOUND"<<endl;
					vector<Node> path;
					Node* current_node = &new_node;
					while (current_node != nullptr)
					{
						path.push_back(*current_node);
						current_node = current_node->getParent();
					}
					path.push_back(start);
					reverse(path.begin(), path.end());
					return path;
				}
			}
		}
		vector<Node> empty;
		return empty;
	}

};