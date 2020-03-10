

#include <iostream>
using namespace std;

template<class DT>
class GLRow;
template<class DT>
ostream& operator <<(ostream& s, GLRow<DT>& oneGLRow);

template<class DT>
class ArrayGLL;
template<class DT>
ostream& operator <<(ostream& s, ArrayGLL<DT>& OneGLL);

//Start of GLROW class
template<class DT>
class GLRow{
    friend ostream& operator << <DT>(ostream& s, GLRow<DT>& oneGLRow);
protected:
    DT* _info;
    int _Next;
    int _Down;
    
public:
    GLRow();
    GLRow(DT& newInfo);
    GLRow(GLRow<DT>& anotherOne);//copy construtor?
    GLRow<DT> operator = (GLRow& anotherOne);// make a deep copy
    int getNext();
    int getDown();
    DT& getInfo();
    int setNext(int n);
    int setDown(int d);
    int setInfo(DT& x);
    ~GLRow();//destructor
    
};
template<class DT>
GLRow<DT>::GLRow(){
    
}
template<class DT>
GLRow<DT>::GLRow(DT& newInfo){
    
}
template<class DT>
GLRow<DT>::GLRow(GLRow<DT>& anotherOne){
    
}
template<class DT>
GLRow<DT> GLRow<DT>::operator =(GLRow& anotherOne){
    
}
template<class DT>
int GLRow<DT>::getNext(){
    return 0;
}
template<class DT>
int GLRow<DT>::getDown(){
    return 0;
}
template<class DT>
DT& GLRow<DT>::getInfo(){
    
}
template<class DT>
int GLRow<DT>::setNext(int n){
   // int n = n;
    return n;
}
template<class DT>
int GLRow<DT>::setDown(int d){
  //  int a = d;
    return d;
}
template<class DT>
int GLRow<DT>::setInfo(DT& x){
  //  int x = x;
    return x;
}
template <class DT>
GLRow<DT>::~GLRow() {
   
}

//end of GLROW class

// start of ArrayGLL
template<class DT>
class ArrayGLL{//Array generalized linked list
  friend ostream& operator << <DT>(ostream& s, ArrayGLL<DT>& OneGLL);
protected:
    GLRow<DT>* myGLL;// array created also be the address of the arry
    int maxSize;// max size of array
    int firstElement;
    int firstFree;
public:
    ArrayGLL();
    ArrayGLL(int size);
    ArrayGLL (ArrayGLL<DT>& anotherOne);
    ArrayGLL<DT>& operator =(ArrayGLL<DT>& anotherOne);
    void display();// bonus we need to display in parenthesis format
    int find(DT& key);/* return  the index position where you find the element key; return false if not found, use recursive search**/
    int findDisplayPath(DT& Key);
    int noFree();
    int size();
    int parentPos(DT& Key);//bonus
    GLRow<DT>&  operator [] (int pos);// This will return the value that is in
    //this postion
    int getFirstFree();
    int getFirstElement();
    void setFirstFree(int pos);
    void setFirstElement(int pos);
   ~ArrayGLL();//destructor
};
template<class DT>
ArrayGLL<DT>::ArrayGLL(){
    
}
template<class DT>
ArrayGLL<DT>::ArrayGLL(int size){
    
}
template<class DT>
ArrayGLL<DT>::ArrayGLL (ArrayGLL<DT>& anotherOne){
    
}
template<class DT>
ArrayGLL<DT>& ArrayGLL<DT>::operator =(ArrayGLL<DT>& anotherOne){
    
}
template<class DT>
void ArrayGLL<DT>::display(){// bonus
    
}
template<class DT>
int ArrayGLL<DT>::find(DT& key){
    return key;
}
template<class DT>
int ArrayGLL<DT>::findDisplayPath(DT& key){
    return key;
}
template<class DT>
int ArrayGLL<DT>:: noFree(){
    return 0;
}
template<class DT>
int ArrayGLL<DT>::size(){
    return 0;
}
template<class DT>
int ArrayGLL<DT>::parentPos(DT& key){
    return 0;
}
template<class DT>
GLRow<DT>& ArrayGLL<DT>:: operator[](int pos){
    
}
template<class DT>
int ArrayGLL<DT>::getFirstFree(){
    return 0;
}
template<class DT>
int ArrayGLL<DT>::getFirstElement(){
    return 0;
}
template<class DT>
void ArrayGLL<DT>::setFirstFree(int pos){
    
}
template<class DT>
void ArrayGLL<DT>::setFirstElement(int pos){
    
}
template <class DT>
ArrayGLL<DT>::~ArrayGLL() {
   
}
//end of arrayGLL

int main() {
    
    cout<<"Hello"<<endl;
    ArrayGLL<int> firstGLL(20);//I think this is the size of the list?
    int noElements,value,next,down,parentPos;
    int pos = -1;
    int keyValues;
    int tempValue = 0;
    GLRow<int> oneRow(0);// This is statically defined
    
    //All variables must be defined
    
    cin>> noElements;
    for(int i = 0; i < noElements; ++i){
        cin >> value >> next >> down ;
        oneRow.setInfo(value);
        oneRow.setNext(next);
        oneRow.setDown(down);
        firstGLL[i];
    }
    
    firstGLL.setFirstFree(noElements);
    firstGLL.setFirstElement(0);
    cout<<firstGLL<<endl;
    firstGLL.display();
    ArrayGLL<int>* secondGLL = new ArrayGLL<int>(firstGLL);

    (*secondGLL[1]).setInfo(600);
    (*secondGLL[2]).setInfo(700);
    cout<<*secondGLL<<endl;
    (*secondGLL).display();

    keyValues = 700;
    pos = (*secondGLL).find(keyValues);
    if(parentPos != -1){
        cout<< (*secondGLL)[parentPos]<<endl;
    }
    cout<< (*secondGLL).size();
    cout<< (*secondGLL).noFree();

    delete secondGLL;

    return 0;
}
