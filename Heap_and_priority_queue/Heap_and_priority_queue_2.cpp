#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    public: 
        int arr[50];  // array can be initiallized
        int idx = 1;  // we cannot intialize here  --> (int , vector) cannot be initiallized 
        int top(){
            return arr[1];
        }
        MinHeap(){
            idx = 1;
        }
        void push(int x){
            arr[idx] = x;
            int i = idx;
            idx++;
            while(i!=1){
                if(arr[i]<arr[i/2]) swap(arr[i],arr[i/2]);
                else break;
                i /= 2;
            }
        }
        int size(){
            return idx-1;
        }
        void pop(){
            idx--;
            arr[1] = arr[idx];
            int i=1;
            while(true){
                int left = 2*i, right = (2*i)+1;
                if(left > idx-1) break;
                if(right > idx-1){
                    if(arr[i] > arr[left]){
                        swap(arr[i],arr[left]);
                        i = left;
                    }
                    break;
                } 
                if(arr[left] < arr[right]){
                    if(arr[i] > arr[left]){
                        swap(arr[i],arr[left]);
                        i = left;
                    }
                    else break;
                }
                else{
                    if(arr[i] > arr[right]){
                        swap(arr[i],arr[right]);
                        i = right;
                    }
                    else break;
                }
            }
        }
        void display(){
            for(int i=1; i<=idx-1; i++) cout<<arr[i]<<" ";  cout<<endl;
        }
};

int main(){

//********************************************************************************************************************//

    // MinHeap pq;  // Try to implement MaxHeap by yourself ans try to implement array by limited size 
    // pq.push(10);  pq.push(20);  pq.push(30);  pq.push(40);
    // pq.display();
    // cout<<pq.size()<<endl;
    // cout<<pq.top()<<endl;
    // pq.display();
    // pq.pop();  pq.pop();
    // cout<<pq.size()<<endl;
    // cout<<pq.top()<<endl;

//********************************************************************************************************************//

    

//********************************************************************************************************************//



//********************************************************************************************************************//



//********************************************************************************************************************//



//********************************************************************************************************************//



//********************************************************************************************************************//



//********************************************************************************************************************//



//********************************************************************************************************************//



//********************************************************************************************************************//



    return 0;
}







