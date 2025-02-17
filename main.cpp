#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>
#include "iterator.h"

using std::cout;
using std::endl;
using std::vector;

int main(){
    vector<int> vec = {10, 20, 0, -5, 10};
    for(auto cit = vec.cbegin(); cit != vec.cend(); cit++){
        cout<<*cit<<endl;
    }



    /*
    IntArr a;

    for (auto i = a.begin(); i != a.end(); i++){
        *i = 10;
        cout<<*i<<endl;
    }

    int count = 0;
    auto i = a.begin(); 
    while ( count < 5){
        i++;
        count++;
    }
    std::cout<<*i<<"\n";

*/
    //Iterator asd = a.begin();
    //auto ptri = asd.operator->();
    


    //vector<int> vec = {10, 20, 0, -5, 10};

    /*
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
    */
    return 0;
}