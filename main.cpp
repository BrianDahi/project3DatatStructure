

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
    DT* info;
    int Next;
    int Down;
    
public:
    GLRow();
    GLRow(DT& newInfo);
    GLRow(GLRow<DT>& anotherOne);//copy construtor?
    GLRow<DT> operator = (GLRow& anotherOne);// make a deep copy
    int getNext();
    int getDown();
    DT& getInfo();
    void setNext(int n);
    void setDown(int d);
    void setInfo(DT& x);
    ~GLRow();//destructor
    
};
template<class DT>
GLRow<DT>::GLRow(){
    info = NULL;
    Next = 0;
    Down = 0;
}
template<class DT>
GLRow<DT>::GLRow(DT& newInfo){
    info = new DT(newInfo);
    Next = 0;
    Down = 0;
}
template<class DT>
GLRow<DT>::GLRow(GLRow<DT>& copyGLRow){
    info = copyGLRow.info;
    Next = copyGLRow.Next;
    Down = copyGLRow.Down;
}
template<class DT>
GLRow<DT> GLRow<DT>::operator =(GLRow& anotherOne){
    
}
template<class DT>
int GLRow<DT>::getNext(){
    return Next;
}
template<class DT>
int GLRow<DT>::getDown(){
    return Down;
}
template<class DT>
DT& GLRow<DT>::getInfo(){
    return info;
}
template<class DT>
void GLRow<DT>::setNext(int n){
    Next = n;
   
}
template<class DT>
void GLRow<DT>::setDown(int d){
    Down = d;
    
}
template<class DT>
void GLRow<DT>::setInfo(DT& x){
    info = &x;
    
}
template <class DT>
ostream& operator <<  (ostream& s,  GLRow<DT>& oneGLRow) {
    s <<"not done yet in GLRow";
    return s;
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
    ArrayGLL<DT>::ArrayGLL(){//default constructor
        myGLL = NULL;
        firstElement = 0;
        firstFree = 0;
    }
    template<class DT>
    ArrayGLL<DT>::ArrayGLL(int size){
        myGLL = new GLRow<DT> [int(size)];
        maxSize = size;
        firstElement = 0;
        firstFree = 0;
    }
    template<class DT>
    ArrayGLL<DT>::ArrayGLL (ArrayGLL<DT>& anotherOne){
    
        maxSize = anotherOne.maxSize;
        myGLL = anotherOne.myGLL;
        firstElement = anotherOne.firstElement;
        firstFree = anotherOne.firstFree;
    }

    template<class DT>
    ArrayGLL<DT>& ArrayGLL<DT>::operator =(ArrayGLL<DT>& anotherOne){
        this-> anotherOne;
    }

    template<class DT>
    void ArrayGLL<DT>::display(){// bonus
    
    }
    template<class DT>
    int ArrayGLL<DT>::find(DT& key){
        /*This method will use recurison to find the key and return the index
         if not o found return -1**/
        return key;
    }
    template<class DT>
    int ArrayGLL<DT>::findDisplayPath(DT& key){
        return key;
    }
    template<class DT>
    int ArrayGLL<DT>:: noFree(){
        int counter = 0;
       
        /*Think of this as a linked list so**/
        return counter;
    }
    template<class DT>
    int ArrayGLL<DT>::size(){
    
        return maxSize;
    }
    template<class DT>
    int ArrayGLL<DT>::parentPos(DT& key){//bonus
        return 0;
    }
    template<class DT>
    GLRow<DT>& ArrayGLL<DT>:: operator[](int pos){
        
        if ((pos < 0) || (pos >= size()))
            cout<< "Array is out of bounds"<<endl;
            
        return myGLL[pos];
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
ostream& operator <<  (ostream& s, ArrayGLL<DT>& OneGLL) {
    s <<"not done yet in ArrayGLL";
    return s;
}
    template <class DT>
    ArrayGLL<DT>::~ArrayGLL() {
        delete[] myGLL;
    }
//end of arrayGLL

class Exception{
    
};

class ArrayBoundsException : Exception{
  
};

class SegmentsException : Exception{
    
};


int main() {
    
    cout<<"Hello"<<endl;
    ArrayGLL<int> firstGLL(20);//I think this is the size of the list?
    int noElements,value,next,down,parentPos;
    int pos = -1;
    int keyValues;
    int tempValue = 0;
    int zero = 0;
    GLRow<int> oneRow(zero);// This is statically defined
    
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
    
    int passByRef = 600;
    int passByRef2 = 700;
    (*secondGLL)[1].setInfo(passByRef);
    (*secondGLL)[2].setInfo(passByRef2);
    
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
