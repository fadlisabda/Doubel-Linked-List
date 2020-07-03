#include <iostream>
using namespace std;
class node{//membuat node
   public:
      int value;//memberi data/nilai pada node
      node *next;//pointer untuk menuju node berikutnya
      node *prev;//pointer untuk menuju node sebelumnya
   
   node(int val,node *n,node *p)//mendefenisikan data dan pointer
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