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

class double_list{//class untuk membuat prototype
   public:
      void inserthead(int value);//membuat node pada bagian head
      void insertail(int val);//membuat node pada bagian tail
      void insertbefore(int value,int pos);//membuat node pada posisi yang diinginkan
      void removehead();//menghapus node pada bagian head
      void removetail();//menghapus node pada bagian tail
      void removepost(int pos);//menghapus node pada posisi yang diinginkan
      void print();//menampilkan seluruh node

   double_list(){//mendefenisikan pointer head dan tail null
      head=NULL;
      tail=NULL;
   }

   private:
         node *head;//membuat pointer head
         node *tail;//membuat pointer tail
         node *current;//membuat pointer current
         int isempty();//mengembalikan 1 jika node kosong
         //mengembalikan 0 jika node berisi
};

int double_list::isempty(){//untuk mengembalikan nilai 1 atau 0
   if(head==NULL||tail==NULL){//jika node kosong return 1
      return 1;
   }
   else{//jika node berisi return 0
      return 0;
   }
}

int main(){
   
   return 0;
}