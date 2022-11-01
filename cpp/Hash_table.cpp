// a simple hash table using an array of linked list buckets and a modulo hash function
// implement a bucket class which abstracts the implementation of the bucket from the hash set


#include <list>
#include <array>

class bucket{
   private: 
    std::list<int>* theBucket;
public:
    bucket() {
    theBucket = new std::list<int>{};
    }
    void add(int val){ 
        //search if value exists, if not, append it
        theBucket->push_front(val);
    }
    void remove(int val){
        theBucket->remove(val);
    }
    bool contains(int val){

      auto it = theBucket->begin();
        while(it != theBucket->end())
        {
            if(*it == val){
                return true;
            }
        it++;
        }
        return false;
    }
    ~bucket(){
        delete theBucket;
    }
};

class MyHashSet{
    private:
    const static int keyRange{769};
    std::array<bucket*,keyRange>* theBuckets;
    
    public:
    MyHashSet(){
        theBuckets = new std::array<bucket*,keyRange>{};
        for (int i = 0; i < keyRange; ++i){
            theBuckets->at(i) = new bucket();
        }
    }
    int get_key(int value){
        return value % keyRange;
    }
    
    void add(int value){
        //insert if it doesnt exist or else dont
        int key = get_key(value);
        theBuckets->at(key)->add(value);
    }
    void remove(int value){
        int key = get_key(value);
        theBuckets->at(key)->remove(value);
    }
    bool contains(int value){
        int key = get_key(value);
        return theBuckets->at(key)->contains(value);
    }

    ~MyHashSet(){
        for (int i = 0; i < keyRange; ++i){
            theBuckets->at(i)->~bucket();
        }
    }
};

int main(){
//   Your MyHashSet object will be instantiated and called as such:
MyHashSet& obj = *new MyHashSet();
int key = 3;
obj.add(key);
bool param_3 = obj.contains(key);
obj.add(4);
obj.add(23243);
obj.remove(4);
obj.add(0);
param_3 = obj.contains(0);
obj.remove(0);
bool param_5 = obj.contains(key);
obj.remove(key);
bool param_4 = obj.contains(key);
obj.~MyHashSet();
return (param_3 && !param_4);
}