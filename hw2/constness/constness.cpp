#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

// holds entries with int key and string values
class Table {
    // you'll probably want use to use std::pair
    // you will need to make some methods const since they'll be used in processSentence which requires a const Table
    // --- Your code here



public:

    class C{
        public:
        int k_key;
        string c_contents; 
    };
    

    
    Table() = default;
    Table(vector<C> dictionary){
    _dictionary = dictionary;
    }

    string get(const int k) const{    
        int j = 0;
        for (int i = 0; i < _dictionary.size(); i++)
        {
            if(_dictionary[i].k_key == k){
                j++;
                return _dictionary[i].c_contents;
            }
        }
        if(j == 0) 
        {return " ";}
    }
    void add(int a, string b){
        _dictionary.push_back({a, b});
    }
    int t_size() const{
        return _dictionary.size();
    }
    int getkey(int n) const{
        return _dictionary[n].k_key;
    }
    string getcontent(int n) const{
        return _dictionary[n].c_contents;
    }

private:
    vector<C> _dictionary;
};

string processSentence(const Table& t, const vector<int>& keySequence) {
    string ret = "";
    for (int key : keySequence) {
        // should return " " if it's not in the table, otherwise it should return the value
        ret += t.get(key);
    }
    return ret;
}

Table updateTable(const Table& t1, const Table& t2) {
    // make a copy of t1 with overwriting entries from t2
    // replace entries of t1 with entries of t2, where they overlap
    // --- Your code here
    Table temp_t;
    const int t1_s = t1.t_size();
    const int t2_s = t2.t_size();
    int overlap = t1_s - t2_s; 
    int overlap_size = 0;
    
    for (int i = 0; i < t2_s; i++)
    {
        temp_t.add(t2.getkey(i), t2.getcontent(i));
    }
    
    for (int i = 0; i < t1_s; i++)
    {
        if(t2.get(t1.getkey(i)) == " ") temp_t.add(t1.getkey(i), t1.getcontent(i));
    }
    return temp_t;
}
// --- Your code here

Table filter(const Table t){
    Table temp_t;
    for (int i = 0; i < t.t_size(); i++)
    {
        if(t.getkey(i)%2 == 0) temp_t.add(t.getkey(i), t.getcontent(i));
    }
    return temp_t;
}

// ---

int main(int argc, char* argv[]) {
    // figure out what constructor allows for this initialization
    // since this table is const, the functions you implement that use it must also take in a const table
    const Table t1{{
        {1, "alpha"},
        {2, "beta"},
        {3, "gamma"},
        {4, "delta"},
        }};
    Table t2;

    ifstream input{"input.txt"};
    ofstream output{"output.txt"};

    // should output "alphagamma delta" (without parenthesis)
    output << processSentence(t1, {1, 3, 5, 4}) << endl;

    while (input.peek() != ifstream::traits_type::eof()) {
        int key;
        string value;
        input >> key >> value;

        t2.add(key, value);
    }
    output << processSentence(t2, {2, 1, 5, 6}) << endl;


    // create a constant table that is t1 updated with t2
    // you should use the updateTable function here
    // note that for it to be constant, its value has to be finalized at definition time
    // --- Your code here

    const Table t3 = updateTable(t1, t2);

    // ---

    output << is_const<decltype(t3)>::value << endl;

    // should not change the original tables
    output << processSentence(t1, {1, 3, 5, 4}) << endl;
    output << processSentence(t2, {2, 1, 5, 6}) << endl;

    // should have entries of t1 with overriding values from t2
    output << processSentence(t3, {1, 3, 5, 4}) << endl;
    // you need to implement this function to create a copy of the Table with only even keys
    output << processSentence(filter(t3), {2, 1, 3, 5, 4}) << endl;
}
