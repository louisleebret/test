#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T> class Stack{

  private:
    int max_index;
    int num_el;
    int size;
    T s [];

  public:

  Stack(){
    max_index = 0;
    num_el = 0;
    size = 20;
    s[20];
  }

  Stack(int n){
    max_index = 0;
    num_el = 0;
    size = n;
    s[n];
  }

  void push(T t){
    if(this->num_el>=0 && this->num_el<this->size){
      this->s[this->max_index++] = t;
      this->num_el++;
    }
  }

  void pop(){
    if(this->num_el>0){
      --this->max_index;
      --this->num_el;
    }

  }

  T top(){
    if(this->num_el>0){
      return this->s[this->max_index-1];
    }
    else{
      return this->s[0];
    }
  }



  void print(){
    cout<<"------------------------"<<endl;
    if(this->num_el==0){
      cout<<"The Stack is empty"<<endl;
    }
    else{
      for(int i = this->max_index-1; i>=0;i--){
        if(i == this->max_index-1){
          cout<<"Top of the stack: "<<this->s[i]<<endl;
        }
        else{
          cout<<"                  "<<this->s[i]<<endl;
        }
        
      }
    }
    cout<<"------------------------"<<endl;
  }

  bool is_empty(){
    if(this->num_el==0){
      return true;
    }
    else{
      return false;
    }
  }

};
int main(){

  Stack<int> s = Stack<int>(5);

  s.print();
  cout<<s.is_empty()<<endl;


  s.push(2);
  s.push(3);
  s.push(4);
  s.push(3);
  s.push(7);

  s.print();
  cout<<s.is_empty()<<endl;

  s.pop();
  s.print();
  s.pop();
  cout<<"The top of the stack is now: "<<s.top()<<endl;
  s.print();
  return 0;
}