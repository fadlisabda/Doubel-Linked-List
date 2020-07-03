#include <iostream>
using namespace std;
//membuat node
class node{
   public:
      int value;//memberi data/nilai pada node
      node *next;//pointer untuk menuju node berikutnya
      node *prev;//pointer untuk menuju node sebelumnya
   
   //mendefenisikan data dan pointer next dan prev
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

//class untuk membuat prototype
class double_list{
   public:
      void inserthead(int value);//membuat node pada bagian head
      void inserttail(int val);//membuat node pada bagian tail
      void insertbefore(int value,int pos);//membuat node pada posisi yang diinginkan
      void removehead();//menghapus node pada bagian head
      void removetail();//menghapus node pada bagian tail
      void removepost(int pos);//menghapus node pada posisi yang diinginkan
      void print();//menampilkan seluruh node

   //mendefenisikan pointer head dan tail null
   double_list(){
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

//untuk mengembalikan nilai 1 atau 0
int double_list::isempty(){
   if(head==NULL||tail==NULL){
      return 1;//jika node kosong return 1
   }
   else{
      return 0;//jika node berisi return 0
   }
}

//membuat node pada bagian head/depan
void double_list::inserthead(int val){
   if(isempty()==1){//jika node kosong
      current = new node(val);//membuat node current berisi nilai val
      head=current;//nilai dalam node current menjadi head
      tail=current;//nilai dalam node current menjadi tail
      tail->prev=NULL;//node setelah tail 0
      head->next=NULL;//node sebelum head 0
   }
   else{
      current = new node();//membuat node dengan nilai/data kosong
      current->next=this->head;//meletakkan node didepan head
      this->head->prev=current;//meletakkan head di belakang node baru 
      current->value=val;//memberi nilai/data pada node baru
      this->head=current;//memberi node baru head
   }
}

//membuat node pada bagian tail/belakang
void double_list::inserttail(int val){
   if(isempty()==1){//jika node kosong
      current = new node(val);//membuat node current berisi nilai val
      head=current;//menjadikan node head
      tail=current;//menjadikan node tail
      tail->next=NULL;//node tail berikutnya 0
   }
   else{
      current = new node();//membuat node baru
      current->prev=this->tail;//membuat node dibelakang tail
      this->tail->next=current;//membuat node didepan tail
      current->value=val;//membuat nilai/data pada node baru
      this->tail=current;//memberi node baru tail
      current->next=NULL;//node berikutnya 0
   }
}

int main(){
   
   return 0;
}