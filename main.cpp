// COMSC-210 | Lab 25 | Ahmad Dharhan

#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
using namespace std::chrono;

void reading(vector<string>& vec1, list<string>& list1, set<string>& set1, ifstream& file);
void sorting(vector<string> vec1, list<string> list1);
void inserting(vector<string> vec1, list<string> list1, set<string> set1);
void deleting(vector<string> vec1, list<string> list1, set<string> set1);

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
    sorting(vec1, list1);
    inserting(vec1, list1, set1);
    deleting(vec1, list1, set1);

    return 0;
}

void reading(vector<string>& vec1, list<string>& list1, set<string>& set1, ifstream& file){
    cout << "READING RACE" << endl;
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
    
    cout << endl;
}

void sorting(vector<string> vec1, list<string> list1){
    cout << "SORTING RACE" << endl;
    auto start = high_resolution_clock::now();

    list1.sort();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    cout << "List: " << duration.count() << endl;


    auto start1 = high_resolution_clock::now();

    sort(vec1.begin(),vec1.end());

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    cout << "Vector: " << duration1.count() << endl;

    cout << "Set: " << -1 << endl;
    cout << endl;
}

void inserting(vector<string> vec1, list<string> list1, set<string> set1){
    cout << "INSERTING RACE" << endl;

    auto start = high_resolution_clock::now();

    vec1.insert(vec1.begin() + vec1.size()/2,"TESTCODE");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    cout << "Vector: " << duration.count() << endl;

    auto it = list1.begin();
    advance(it,list1.size()/2);
    auto start1 = high_resolution_clock::now();

    list1.insert(it,"TESTCODE");

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    cout << "List: " << duration1.count() << endl;

    auto start2 = high_resolution_clock::now();

    set1.insert("TESTCODE");

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    cout << "Set: "<< duration2.count() << endl;
    
    cout << endl;
}

void deleting(vector<string> vec1, list<string> list1, set<string> set1){
    cout << "DELETING RACE" << endl;

    auto it = list1.begin();
    advance(it,list1.size()/2);

    auto it2 = set1.begin();
    advance(it2,set1.size()/2);

    auto it3 = vec1.begin() + vec1.size()/2;

    auto start = high_resolution_clock::now();

    vec1.erase(it3);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    cout << "Vector: " << duration.count() << endl;

    auto start1 = high_resolution_clock::now();

    list1.erase(it);

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    cout << "List: " << duration1.count() << endl;

    auto start2 = high_resolution_clock::now();

    set1.erase(it2);

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    cout << "Set: "<< duration2.count() << endl;
    
    cout << endl;

}