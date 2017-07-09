//
// Created by LIU Qingpei on 9/7/2017.
//

#ifndef MAXHEAP_V2_MAXHEAPO_H
#define MAXHEAP_V2_MAXHEAPO_H

#include <algorithm>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeapO{
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        Item e = data[k];
        while(k>1&&data[k/2]<e) {
            data[k] = data[k / 2];
            k/=2;
        }
        data[k] = e;
    }

    void shiftDown(int k){
        Item e = data[k];
        while(2*k<=count) {
            int j = 2 * k;
            if (j + 1 <= count && data[j + 1] > data[j]) j++;
            if (e >= data[j]) break;
            data[k] = data[j];
            k=j;
        }
        data[k] = e;
    }

public:
    MaxHeapO(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    MaxHeapO(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;
        for(int i=0;i<n;i++)
            data[i+1] = arr[i];
        count = n;
        for(int i=count/2;i>=1;i--)
            shiftDown(i);
    }
    ~MaxHeapO(){
        delete[] data;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count==0;
    }
    void insert(Item item){
        assert(count+1<=capacity);
        data[count+1] = item;
        shiftUp(count+1);
        count++;
    }
    Item extractMax(){
        assert(count>0);
        Item ret = data[1];
        data[1] = data[count];
        count--;
        shiftDown(1);
        return ret;
    }
    Item getMax(){
        assert(count>0);
        return data[1];
    }
};

#endif //MAXHEAP_V2_MAXHEAPO_H
