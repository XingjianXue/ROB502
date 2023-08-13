#include "maze.h"
#include "bfs.h"
#include "dfs.h"
using namespace std;
/** \brief Return the valid next states from a given state */
State operator+(State const &c1, State const &c2)
{
    return {c1.x + c2.x, c1.y + c2.y};
}
std::vector<State> ProblemDefinition::validStates(const State &state) const
{
    // HINT: use isStateValid()
    // --- Your code here
    if (!allow_diagonal_)
    {   
        vector<State> neighbor1;
        vector<State> offset{{1,0},{-1,0},{0,1},{0,-1}};
        for (const State &element:offset){
            State x = state + element;
            neighbor1.push_back(x);
        }

        vector<State> result;
        for (int i = 0; i < neighbor1.size(); i++)
        {
            if (isStateValid(neighbor1[i]))
            {
                result.push_back(neighbor1[i]);
            }
            
        }
        
        return result;
    }else{
        vector<State> neighbor2;
        vector<State> offset{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        for (const State element:offset){
            State x = state + element;
            neighbor2.push_back(x);
        }

        std::vector<State> result;
        for (int i = 0; i < neighbor2.size(); i++)
        {
            if (isStateValid(neighbor2[i]))
            {
                result.push_back(neighbor2[i]);
            }
            
        }
        return result;
    }
    // ---
}

/** \brief Given a node, extract the path from it to the root */
void TreeSearch::extractPath(NodePtr node)
{
    // --- Your code here
    NodePtr temp_node = node;
    while (temp_node->parent != nullptr)
    {
        path_.push_back(temp_node->state);
        temp_node = temp_node -> parent;
    }
    path_.push_back(temp_node->state);
    std::reverse(path_.begin(),path_.end());
    // ---
}

/** \brief Solve the planning problem. Override TreeSearch::solve() */
bool BFS::solve()
{
    // check start and goal are valid
    if (!pdef_.isStateValid(pdef_.startState()) ||
        !pdef_.isStateValid(pdef_.goalState()))
    {

        return false;
    }

    // if start and goal coincide, terminate
    State start = pdef_.startState();
    if (pdef_.isGoal(start))
    {
        // std::cout << "Start and goal are equal\n";
        return true;
    }

    NodePtr solution;
    // --- Your code here
    NodePtr rootPtr{new Node()};
    rootPtr->state = start;
    addNode(rootPtr);
    while (!bfs_nodes_.empty())
    {
        NodePtr temp_node = bfs_nodes_.front();
        if (temp_node->state == pdef_.goalState())
        {
            solution = temp_node;
        }
        
        addNode(temp_node);
        bfs_nodes_.pop();
    }
    // ---
    // get the path from last node to root
    extractPath(solution);

    return true;
}

/** \brief add node to the tree */
bool BFS::addNode(const NodePtr &node)
{
    // --- Your code here
     if (isVisited(node))
    {
        return false;
    }
    
    visited_.push_back(node->state);
    //Node current_node = *node;
    std::vector<State> next_states = pdef_.validStates(node->state);
    for (const State &element:next_states)
    {
        NodePtr temp_next{new Node()};
        temp_next->state = element;
        if (isVisited(temp_next))
        {
            continue;
        }

        temp_next->parent = node;
        bfs_nodes_.push(temp_next);
        
    }
    return true;
    // ---
}

/** \brief Solve the planning problem. Override TreeSearch::solve() */
bool DFS::solve()
{
    // check start and goal are valid
    if (!pdef_.isStateValid(pdef_.startState()) ||
        !pdef_.isStateValid(pdef_.goalState()))
    {
        return false;
    }

    // if start and goal coincide, terminate
    State start = pdef_.startState();
    if (pdef_.isGoal(start))
    {
        std::cout << "Start and goal are equal\n";
        return true;
    }

    NodePtr solution;
    // --- Your code here
    NodePtr presentPtr{new Node()};
    presentPtr->state = start;
    while (!pdef_.isGoal(presentPtr->state))
    {
        visited_.push_back(presentPtr->state);
        addNode(presentPtr);
        presentPtr = dfs_nodes_.top();   
        dfs_nodes_.pop();     
    }
    solution = presentPtr;
    // ---
    // get the path from last node to root
    extractPath(solution);
    return true;
}

/** \brief add node to the tree */
bool DFS::addNode(const NodePtr &node)
{
    // --- Your code here
    //Node current = *node;
    std::vector<State> next_states = pdef_.validStates(node->state);
    //std::vector<NodePtr> child_node;
    for (const State &element:next_states)
    {
        NodePtr temp_node{new Node()};
        temp_node->state = element;
        if (isVisited(temp_node))
        {
            continue;
        }
        dfs_nodes_.push(temp_node);
        //child_node.push_back(temp_node);
        temp_node->parent = node;
    }
    return true;
    // ---
}