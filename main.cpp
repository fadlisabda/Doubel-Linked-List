//double linked list 
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
         node *current;//untuk menyimpan nilai data pada element single linked list ketika diinputkan
         int isempty();//mengembalikan 1 jika node kosong
         //mengembalikan 0 jika node berisi
};

static int list=0;//menghitung jumlah node masuk dan dihapus

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
      current = new node();//membuat objek current dengan constructor kosong
      current->next=this->head;//meletakkan current didepan head
      this->head->prev=current;//meletakkan head di belakang current 
      current->value=val;//memasukkan nilai val kedalam objek current
      this->head=current;//menjadikan objek current head
   }
   list++;
}

//membuat node pada bagian tail/belakang
void double_list::inserttail(int val){
   if(isempty()==1){//jika node kosong
      current = new node(val);//membuat node current berisi nilai val
      head=current;//menjadikan current head
      tail=current;//menjadikan current tail
      tail->next=NULL;//node tail berikutnya 0
   }
   else{
      current = new node();//membuat objek current
      current->prev=this->tail;//membuat current dibelakang tail
      this->tail->next=current;//membuat current dibelakang tail
      current->value=val;//membuat nilai/data kedalam objek current
      this->tail=current;//memberi current tail
      current->next=NULL;//current berikutnya 0
   }
   list++;
}

//menghapus node pada bagian head
void double_list::removehead(){
   if(isempty()==1){
      //jika node kosong
      cout<<"Maaf,linked list kosong"<<endl;
   }
   //jika node berisi
   else{
      if(list==1){
         //jika node berisi hanya 1
         cout<<"nilai "<<head->value<<" telah dihapus"<<endl;//nilai dihapus
         tail=NULL;//tail 0
         head=NULL;//head 0
      }
      else{
         //jika node lebih dari satu
         int temp=head->value;//memberikan nilai/data node head ke variabel temp
         current=head->next;//current sebagai data setelah head
         head=current->prev;//current sebagai data setelah head
         current->prev->next=current;//menjadikan current head 
         head=current;//menjadikan current head
         cout<<"nilai "<<temp<<" telah dihapus"<<endl;//mengahapus nilai
      }
      list--;
   }
}

//fungsi untuk menghapus node tail/belakang
void double_list::removetail(){
   //jika node kosong
   if(isempty()==1){
      cout<<"maaf,linked list kosong"<<endl;
   }
   else{
      //jika jumlah node 1 
      if(list==1){
         //nilai di hapus 
         cout<<"nilai "<<tail->value<<" telah dihapus"<<endl;
         tail=NULL;//tail 0
         head=NULL;//head 0
         list--;//jumlah node dikurangi 1
      }
      else{
         int temp=tail->value;//simpan nilai tail ke temp
         current=tail;//penugasan current sebagai tail
         current=current->prev;//penggeseran current kenilai sebelum tail
         tail->prev->next=NULL;//penghapusan nilai tail
         tail=current;//penugasan nilai tail yang baru
         cout<<"nilai "<<temp<<" telah dihapus"<<endl;
         list--;
      }
   }
}

//menginput nilai pada posisi tertentu
void double_list::insertbefore(int value,int pos){
   //jika node kosong
   if(isempty()==1){
      cout<<"Maaf,linked list kosong"<<endl;
   }
   else{
      //jika posisi besar dari list
      if(pos>list){
         cout<<"jumlah list terlalu sedikit"<<endl;
      }
      else{
         if(pos==1){
            inserthead(value);//input data pada bagian head
         }
         
         else if(pos==list){
            inserttail(value);//input data pada bagian tail
         }
         else{
            current=head;
            node*fixed;
            for (int i = 1; i < pos; i++)
            {
               current=current->next;//penelusuran nilai double linked list
            }
            fixed=new node((value),current,current->prev);//instansiasi objek fixed
            current->prev->next=fixed;//penyisipan objek fixed
            current->prev=fixed;//penyisipan objek fixed
            current=fixed;
            list++;
         }
      }
   }
}

//menghapus nilai pada posisi tertentu
void double_list::removepost(int pos){
   //jika node kosong
   if(isempty()==1){
      cout<<"maaf,linked list kosong"<<endl;
   }
   else{
      //jika posisi besar dari list
      if(pos>list){
         cout<<"maaf,range terlalu sedikit"<<endl;
      }
      else{
         if(pos==1){
            removehead();//hapus data bagian head
         }
         else if(pos==list){
            removetail();//hapus data bagian tail
         }
         else{
            current=head;
            for(int i=1;i<pos;i++){
               current=current->next;//penelusuran nilai double linked list
            }
            int nilai=current->value;
            current->prev->next=current->next;//manipulasi objek current
            current->next->prev=current->prev;//manipulasi objek current
            cout<<"nilai "<<nilai<<" dihapus dari linked list"<<endl;
            list--;
         }
      }
   }
}

//menampilkan seluruh node
void double_list::print(){
   current=head;//untuk memulai perulangan dari head
   while(current!=NULL){//sampai ditemukan nilai null
      cout<<"isi list :"<<current->value<<endl;//menampilkan nilai
      current=current->next;
   }
}
int main(){
   int n,pos;
   double_list *st;
   st=new double_list();
   char pilih;
   cout<<"operasi linkedlist"<<endl;
   cout<<"1.inserthead"<<endl;
   cout<<"2.inserttail"<<endl;
   cout<<"3.removehead"<<endl;
   cout<<"4.removetail"<<endl;
   cout<<"5.insertbefore"<<endl;
   cout<<"6.removeposition"<<endl;
   cout<<"7.exit"<<endl;
   do
   {
      cout<<endl;
      cout<<"pilihan :";
      cin>>pilih;
      switch (pilih)
      {
      case '1':
         cout<<"masukkan data :";
         cin>>n;
         st->inserthead(n);
         st->print();
         break;
      case '2':
         cout<<"masukkan data :";
         cin>>n;
         st->inserttail(n);
         st->print();
         break;
      case '3':
         st->removehead();
         st->print();
         break;
      case '4':
         st->removetail();
         st->print();
         break;
      case '5':
         cout<<"masukkan data :";
         cin>>n;
         cout<<"masukkan posisi :";
         cin>>pos;         
         st->insertbefore(n,pos);
         st->print();
         break;
      case '6':
         int pos;
         cout<<"masukkan posisi angka yang ingin dihapus :";
         cin>>pos;         
         st->removepost(pos);
         st->print();
         break;
      case '7':
         cout<<"terimaa kasih :";
         break;
      default:
         cout<<"salah pilih";
         break;
      }
   } while (pilih!='7');
   return 0;
}