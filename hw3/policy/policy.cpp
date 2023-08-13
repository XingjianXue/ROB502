#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;


using State = vector<int>; //this defines the type State to be a vector of ints
using Action = vector<int>; //this defines the type Action to be a vector of ints


//this function should print out a state to the given stream
//the ostream could be something like cout, or cerr
//or it could be a filestream
void printState(const State& state, ostream & stream){
    // --- Your code here



    // ---
}


State dynamics(const State& state, const Action& action)
{
    State next_state(state.size());
    for (int j = 0; j < state.size();j++)
    {
        next_state[j] = state[j] + action[j];
    }
    return next_state;
}


int main () {
    
    ifstream policyfile("policy.txt");
    ofstream outputfile("output.txt");

    const int StateSize = 2;
    const int ActionSize = 2;    

    State key(StateSize);
    Action value(ActionSize);
    map<State,Action> policy;

    while(!policyfile.eof()){
    policyfile >> key[0] >> key[1] >> value[0] >> value[1];
    policy.insert({key,value});
    }

    for (const pair<State,Action>&elem: policy){
        cout << elem.first[0] << elem.first[1] << " " << elem.second[0] << elem.second[1] << endl;
    }

    //read the policy file information into std::pair objects,
    //insert each std::pair into the map
    // --- Your code here



    // ---

    //optional (but recommended) print out the policy to cout
    //to make sure that it was read in correctly
    // --- Your code here



    // ---

    //read in rollout
    ifstream rolloutfile ("rollout.txt");
    State startState(StateSize); //this stores the start state
    int numSteps; //this is the number of steps in the rollout
    rolloutfile>>startState[0];
    rolloutfile>>startState[1];
    rolloutfile>>numSteps;
    rolloutfile.close();

    //Now use the the policy map to do the rollout
    // --- Your code here
    int sum = 0;
      for (const pair<State,Action>&elem: policy){
           if (elem.first[0] == startState[0] && elem.first[1] == startState[1]){
            outputfile << startState[0] << " " << startState[1] << endl;
            sum++;
        }
    }
    if (sum == 0){
        outputfile << "State " << startState[0] << " " << startState[1] << " is not in policy, terminating." << endl;
        return 0;
    }


    for (int i = 0; i < numSteps; i++){
      for (const pair<State,Action>&elem: policy){
           if (elem.first[0] == startState[0] && elem.first[1] == startState[1]){
            startState[0] = elem.first[0] + elem.second[0];
            startState[1] = elem.first[1] + elem.second[1];
            outputfile << startState[0] << " " << startState[1] << endl; 
            break;
        }
      }
    }


    // ---

    outputfile.close();
    return 0;
}
