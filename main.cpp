#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>
#include "iterator.h"
#include "MyForwardList.h"

using std::cout;
using std::endl;
using std::vector;

int main(){
    MyForwardList<int> list;

    Node<int>* n1 = new Node<int>(10);
    Node<int>* n2 = new Node<int>(20);
    Node<int>* n3 = new Node<int>(30);

    list.Add(n1);
    list.Add(n2);
    list.Add(n3);

    cout << "List after adding n1, n2, n3: ";
    list.printList(); 

    list.Delete(n2);
    cout << "List after deleting n2: ";
    list.printList(); 

    Node<int>* node4 = new Node<int>(40);
    list.Add(node4);
    cout << "List after adding n4: ";
    list.printList(); 

    list.Delete(n1);
    cout << "List after deleting n1: ";
    list.printList(); 

    list.Delete(node4);
    cout << "List after deleting n4: ";
    list.printList(); 

    list.Delete(n3);
    cout << "List after deleting n3: ";
    list.printList(); 
   
   /*
    vector<int> vec = {10, 20, 0, -5, 10};
    for(auto cit = vec.cbegin(); cit != vec.cend(); cit++){
        cout<<*cit<<endl;
    }


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