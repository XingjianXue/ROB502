#include "robots.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


//define and implement a function here called compareBotsByName
//it should be of the proper form to be used as the comparison
//function in std::sort. You will use compareBotsByName and std::sort
//to sort a std::vector<Robot>
// --- Your code here
 bool compare(string a, string b){
      return a < b; 
  }



// ---


int main() {
  ifstream botfile("bots.txt");
  ifstream jobfile("jobs.txt");
  ofstream outfile("output.txt");

  //read the robots from botfile in to bot_queue
  //make sure you've looked at the definition 
  //of the Robot class in robots.h first
  // --- Your code here
queue<Robot> bot_queue;

  while (!botfile.eof()){
  string a;
  string b;
  botfile >> a >> b;
  bot_queue.emplace(a,b);
  }

  //cout << bot_queue.front().getName();


  // ---

  //read in each job id and job in jobfile
  //and assign them to the robots as described in the problem
  // --- Your code here
vector<Robot> bots;
 while (!jobfile.eof()){
  int c;
  string d;
  jobfile >> c >> d;  
  int j = 0;
  for(const pair<std::string, std::vector<std::string>> &elem : TYPES2JOBS)
    for(int i = 0; i < elem.second.size();i++){
       if (elem.second[i] == d){        
          if(bot_queue.front().getType() == elem.first){              
               bots.emplace_back(bot_queue.front().getName() + " " + to_string(c), bot_queue.front().getType());
               //bots[j].assignJob(c);
               bot_queue.pop();
               j++;
          }
          
       }
    }
  } 
  

  while(bot_queue.size() != 0){
    bots.emplace_back(bot_queue.front().getName(), bot_queue.front().getType());
    bot_queue.pop();
}

  vector<string>str;
  for (int i = 0; i < bots.size(); i++){
      str.push_back(bots[i].getName());
  }

 

  sort(str.begin(),str.end(),compare);

  for(int i = 0; i < str.size(); i++){
    outfile << str[i] << endl;
  }

  


 
 


  // ---

  
 

  //now that the jobs are assigned, get the robots from the queue
  //and put them in the bots vector
  //then sort that vector alphabetically using std::sort
  //you will need to use the compareBotsByName function above
  // --- Your code here



  // ---

  // print the bots to outfile and cout
  //for (int i = 0; i < bots.size(); i++) {
    //cout << bots[i].print(false);
    //outfile << bots[i].print(false);
  //}

  return 0;
}
