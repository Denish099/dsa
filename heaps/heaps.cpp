#include<iostream>
using namespace std;

class Heap{
    public:
     int arr[100];
     int size = 0;

     void insert(int val){
        size++;
        int index = size;
        arr[index] = val;


        while(index > 1){
            int par = index/2; 
            if(arr[par] < arr[index]){
                swap(arr[par],arr[index]);
                index = par;
            }else{
                return; 
            }
        }
     }
     void print(){
        for(int i=1;i<=size;i++){
            cout<< arr[i]<<" ";
        }
     } 
 
};
int main(){

    Heap h;
    h.insert(7);
    h.insert(10);
    h.insert(12);
    h.insert(14);
    h.insert(5);

    h.print();
    return 0;
}