#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;

    cout<<"size (number of elements in vector): "<<v.size()<<endl;
    cout<<"capacity (number of elements the vector can hold): "<<v.capacity()<<endl<<endl;

    v.push_back(1);
    cout<<"size (number of elements in vector): "<<v.size()<<endl;
    cout<<"capacity (number of elements the vector can hold): "<<v.capacity()<<endl<<endl;


    v.push_back(2);
    cout<<"size (number of elements in vector): "<<v.size()<<endl;
    cout<<"capacity (number of elements the vector can hold): "<<v.capacity()<<endl<<endl;


    v.push_back(3);
    cout<<"size (number of elements in vector): "<<v.size()<<endl;
    cout<<"capacity (number of elements the vector can hold): "<<v.capacity()<<endl<<endl;


    v.push_back(4);
    cout<<"size (number of elements in vector): "<<v.size()<<endl;
    cout<<"capacity (number of elements the vector can hold): "<<v.capacity()<<endl<<endl;

    
    v.push_back(5);
    cout<<"size (number of elements in vector): "<<v.size()<<endl;
    cout<<"capacity (number of elements the vector can hold): "<<v.capacity()<<endl<<endl;


    cout<<"before pop : "<<endl;
    for(int i:v ){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();

    cout<<"after pop : "<<endl;
    for(int i:v ){
        cout<<i<<" ";
    }cout<<endl<<endl;

    cout<<"before clear"<<endl;    
    cout<<"size : "<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl;

    v.clear();

    cout<<"after clear"<<endl;
    cout<<"size : "<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl<<endl;

    cout<<"iterator at start of the array : v.begin()"<<endl;
    cout<<"iterator at end of the array : v.end()"<<endl<<endl;

    cout<<"vector<int> v(5,1)"<<endl;
    vector<int> v2(5,1);
    cout<<"this will initialise a vector of size 5, and will fill all elements as 1"<<endl;
    cout<<"size : "<<v2.size()<<endl;
    cout<<"capacity : "<<v2.capacity()<<endl<<endl;

    cout<<"copy of another vector"<<endl;
    vector<int> v3 (v2);
    for(int i : v3){
        cout<<i<<" ";
    }cout<<endl;

}
