// COMSC-210 | Lab 25 | Ahmad Dharhan

#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <set>
#include <list>
using namespace std;
using namespace std::chrono;

int main() {

    vector<string> vec1;
    list<string> list1;
    set<string> set1;

    ifstream ("codes.txt");



    

    return 0;
}



/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/