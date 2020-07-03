#include <iostream>
using namespace std;
class node{
   public:
      int value;
      node *next;
      node *prev;
   
   node(int val,node *n,node *p)
   {
      value=val;
      next=n;
      prev=p;
   }   

   node(int v){
      value=v;
   }

   node(){

   }
};

int main(){
   
   return 0;
}