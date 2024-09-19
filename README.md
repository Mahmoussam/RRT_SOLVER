# RRT Solver in C++
This project is an implementation of the Rapidly-exploring Random Tree (RRT) algorithm in C++. RRT is a path planning algorithm designed for efficiently searching non-convex high-dimensional spaces. It is widely used in robotics and autonomous systems for motion planning.
## I/O
  - The input is a file describing circular obstacles in our 2D space (X,Y,radius) and 'in_nodes.csv' describing the start, and end nodes.
  - The output is 2 files describing the generated nodes and the path created.
## Settings:
  RRT solver class accepts various parameters with which you may play with and test the effects 
    - Step size: a maximum step taken between 2 consecutive nodes
    - Iterations: Maximum number of iterations
    - Goal radius: the radius of the region defining the goal.
    - Goal biasing rate : the rate at which RRT solver biases its randomized selection 
## More?
  we provide 2 different (with slight difference) implementations for
    -  geometry operations (approximations , analytical geo solutions)
    -  random sampling: 
          -  pre-sample the space to fixed number of points ,between which the solver may randomize its selection for next node
          -  purely randomized coordinates 
## Simulation
  We used CoppeliaSim to visualize and test the generated nodes and path.
  Scene 5 was used:
  ![test_1](https://github.com/Mahmoussam/RRT_SOLVER/blob/master/Screenshot%202024-09-19%20001632.png)
  ![test_2](https://github.com/Mahmoussam/RRT_SOLVER/blob/master/Screenshot%202024-09-19%20001657.png)
