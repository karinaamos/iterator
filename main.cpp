#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>

using std::cout;
using std::endl;
using std::vector;

int main(){
    vector<int> vec = {10, 20, 0, -5, 10};

    for(auto it = vec.begin(); it != vec.end(); it++){
        cout<<*it<<endl;
    }

    std::sort(vec.begin(), vec.end());

    for(auto it = vec.begin(); it != vec.end(); it++){
        cout<<*it<<endl;
    }
    std::forward_list<int> list = {1,4,5,7,-1};

    std::sort(list.begin(), list.end());

    for(auto it = list.begin(); it != list.end(); it++){
        cout<<*it<<endl;
    }

    return 0;
}