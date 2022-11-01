// Design a HashMap without using any built-in hash table libraries.

// To be specific, your design should include these functions:

// put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
// get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

// Example:

// MyHashMap hashMap = new MyHashMap();
// hashMap.put(1, 1);          
// hashMap.put(2, 2);         
// hashMap.get(1);            // returns 1
// hashMap.get(3);            // returns -1 (not found)
// hashMap.put(2, 1);          // update the existing value
// hashMap.get(2);            // returns 1 
// hashMap.remove(2);          // remove the mapping for 2
// hashMap.get(2);            // returns -1 (not found) 

// Note:

// All keys and values will be in the range of [0, 1000000].
// The number of operations will be in the range of [1, 10000].
// Please do not use the built-in HashMap library.

#include <list>
#include <array>
#include <utility>
#include <iostream>

class map_bucket{
   private: 
    std::list<std::pair<int,int>>* theBucket;
public:
    map_bucket() {
    theBucket = new std::list<std::pair<int,int>>{};
    }
    void add(std::pair<int,int> input){ 
        //search if value exists,
        auto it = theBucket->begin();
        while(it != theBucket->end())
        {
            // case1: we found it, so update the value
            if((*it).first == input.first){
                (*it).second = input.second;
                return;
            }
        it++;
        }
        // case2: it does not exist, so append it to the list.
        theBucket->push_front(input);
        return;
    }

    void remove(int input_key){
        auto it = theBucket->begin();
        while(it != theBucket->end())
        {
            // case1: we found it, so return the second
            if((*it).first == input_key){ 
                theBucket->remove(*it);
                return;
            }
        it++;
        }
    }

    int get(int input_key){ 
        //search if value exists,
        auto it = theBucket->begin();
        while(it != theBucket->end())
        {
            // case1: we found it, so return the second
            if((*it).first == input_key){
                return (*it).second;
            }
        it++;
        }
        return -1;
    }

    ~map_bucket(){
        delete theBucket;
    }
};

class MyHashMap {
private: 
    const static int keyRange{769};
    std::array<map_bucket*,keyRange>* theBuckets;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        theBuckets = new std::array<map_bucket*,keyRange>{};
        for (int i = 0; i < keyRange; ++i){
            theBuckets->at(i) = new map_bucket();
        }
    }
    int get_key(int value){
        return value % keyRange;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket_key = get_key(key);
        std::pair<int,int> input{key,value};
        theBuckets->at(bucket_key)->add(input);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucket_key = get_key(key);
        return theBuckets->at(bucket_key)->get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucket_key = get_key(key);
        return theBuckets->at(bucket_key)->remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main(){
    MyHashMap* hashMap = new MyHashMap();
    hashMap->put(1, 1);          
    hashMap->put(2, 2);         
    std::cout << hashMap->get(1)<< "1" << std::endl ;            // returns 1
    std::cout <<  hashMap->get(3) <<"-1" <<std::endl;          // returns -1 (not found)
    hashMap->put(2, 1);          // update the existing value
    std::cout << hashMap->get(2) << "1"<< std::endl;            // returns 1 
    hashMap->remove(2);          // remove the mapping for 2
    std::cout << hashMap->get(2) << "returns -1 "<< std::endl;            // returns -1 (not found) 
}