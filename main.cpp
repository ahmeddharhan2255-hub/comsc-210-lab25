// COMSC-210 | Lab 25 | Ahmad Dharhan

#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <set>
#include <list>
using namespace std;
using namespace std::chrono;

void reading(vector<string>& vec1, list<string>& list1, set<string>& set1, ifstream& file);
void sorting(vector<string> vec1, list<string> list1, set<string> set1);

int main() {

    vector<string> vec1;
    list<string> list1;
    set<string> set1;

    ifstream file("codes.txt");

    if(!file.is_open()){
        cout << "File could not be opened! Try Again!" << endl;
        return 1;
    }


    reading(vec1, list1, set1, file);

    return 0;
}

void reading(vector<string>& vec1, list<string>& list1, set<string>& set1, ifstream& file){
    string code;

    auto start = high_resolution_clock::now();

    while(file >> code){
        vec1.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    cout << "Vector: " << duration.count() << endl;

    file.clear();
    file.seekg(0);

    auto start1 = high_resolution_clock::now();

    while(file >> code){
        list1.push_back(code);
    }

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    cout << "List: " << duration1.count() << endl;

    file.clear();
    file.seekg(0);

    auto start2 = high_resolution_clock::now();

    while(file >> code){
        set1.insert(code);
    }

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    cout << "Set: "<< duration2.count() << endl;
}

void sorting(vector<string> vec1, list<string> list1, set<string> set1){
    
}