
//#define DEBUG//PRODUCTION // DEBUG OR PORDUCTION MODES 

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
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist100(0, 1000); 
double randomDouble(double X, double Y) {
<<<<<<< HEAD
    random_device random_device;
    // Use current time as seed for the random number generator
    static std::mt19937 engine{random_device()};
    // Uniformly distributed in range [X, Y]
    std::uniform_real_distribution<> dis(X, Y);
    
    // Generate random number and round to 2 decimal places
    double randomValue = dis(engine);
    return randomValue;
=======
    double randomValue = dist100(rng);
    return randomValue/1000;
>>>>>>> 9afdda2d076d6b071fb5cd0689073aedcd78cba2
}
class RRT {
private:
	vector<Node*> all_nodes;
	Node* start;
	Node* goal;
	double step_size;
	double number_of_iterations;
<<<<<<< HEAD
    double goal_bias = 0.5;
	GSpace map;
public:
	RRT(Node* start, Node* goal,GSpace &map, double step_size = 0.1, double number_of_iterations = 80000) {
=======
	double goal_radius;
	GSpace map;
public:
	RRT(Node* start, Node* goal,GSpace &map, double step_size = 0.3, double number_of_iterations = 5000, double goal_radius = 0.1) {
>>>>>>> 9afdda2d076d6b071fb5cd0689073aedcd78cba2
		this->start = start;
		this->goal = goal;
		this->step_size = step_size;
		this->number_of_iterations = number_of_iterations;
		this->map = map;
		this->start = start;
		this->goal = goal;
		this->goal_radius = goal_radius;
		all_nodes.push_back(start);
		
	}

	
	Node* getNearestNode(Node New_node)
	{
		double min_dist = numeric_limits<double>::max();
		Node* nearest_node = (all_nodes)[0];
		for (int i = 0;i < (all_nodes).size();i++)
		{
			double d = dist(New_node , *(all_nodes)[i]);
			if (d < min_dist)
			{
				min_dist = d;
				nearest_node = (all_nodes)[i];
			}
		}
		//cout<<nearest_node->ID<< " ? "<<endl;
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
        if (randomDouble(0, 1) <= goal_bias)
        {
            return *goal;
        }

		auto d1 = map.getDim(0) , d2 = map.getDim(1);
<<<<<<< HEAD
		double x = randomDouble(d1.first , d1.second)/100;
		double y = randomDouble(d2.first , d2.second)/100;
		
=======
		double x = randomDouble(0 , 0) - 0.5;
		double y = randomDouble(0 , 0) - 0.5;
>>>>>>> 9afdda2d076d6b071fb5cd0689073aedcd78cba2
		Node rand_node(x, y);
		return rand_node;
	}
	Node steer(Node nearest_node, Node rand_node)
	{
		//cout<<nearest_node.x << " , "<<nearest_node.y <<" ==> " <<rand_node.x <<" "<<rand_node.y<<endl;

		GVector v(rand_node.getX() - nearest_node.getX() , rand_node.getY() - nearest_node.getY());
		if(v.get_magnitude() == 0){
			v.x = goal->getX() - nearest_node.getX();
			v.y = goal->getY() - nearest_node.getY();
			
		}
		double mag = step_size;//min(v.get_magnitude() , step_size);
		v.divide_by(v.get_magnitude());//make it unit vector
		double rand = 1;//randomDouble(0 , 1);//randomized on d max ..?
		v.mult(rand * mag);
		double new_x = nearest_node.getX() + v.x , new_y = nearest_node.getY() + v.y;
		Node new_node(new_x, new_y);
		if(new_x != new_x ){
			cout<<nearest_node.x<<" , "<<nearest_node.y<<endl;
			cout<<rand_node.x<<" , "<<rand_node.y<<endl;
			
		}
		return new_node;
	}

	bool isatgoal(Node new_node)
	{
		if (dist(new_node, *goal) < goal_radius)
		{
			return true;
		}
		return false;
	}

	vector<Node> findPath( vector<Node*> &nodes)
	{
		for (int i = 0;i < number_of_iterations;i++)
		{
			Node rand_node = createRandomNode();
			Node* nearest_node = getNearestNode(rand_node);
			Node nnode = steer(*nearest_node, rand_node);
<<<<<<< HEAD
=======
			#ifdef DEBUG
				cout<<"New node @ "<<nnode.getX()<<" , "<<nnode.getY()<<endl;
			#endif
			
>>>>>>> 9afdda2d076d6b071fb5cd0689073aedcd78cba2
			if (map.is_line_clear(*nearest_node , nnode)) //el check beta3ak hena (new_node)
			{
				cout<<"Cool"<<endl;
				Node* new_node = new Node(nnode.getX() , nnode.getY());

				new_node->setID(all_nodes.back()->getID() + 1); 
				new_node->setParent(nearest_node);

				(all_nodes).push_back(new_node);
				
				if (isatgoal(*new_node))
				{	
					#ifdef DEBUG
					//cout<<"GOAL FOUND"<<endl;
					
					//cout<<"Num of Nodes  "<<all_nodes.size()<<endl;
					for(auto n : all_nodes){
						cout<<n->getID()<<" : "<<n->getParent()<<endl;
					}
					#endif
					
					vector<Node> path;
					Node* current_node = new_node;
					
					while (current_node != nullptr)
					{
						//cout<<current_node->getID()<<endl;
						path.push_back(*current_node);
						
						current_node = current_node->getParent();
					}
					
					reverse(path.begin(), path.end());
					nodes = all_nodes;
					return path;
				}
				
			}
			else{
				//cout<<"hmm : "<<nnode.x<<" , "<<nnode.y<<endl;
			}
		}
		nodes = all_nodes;
		vector<Node> empty;
		return empty;
	}

};