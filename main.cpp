

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
    GLRow(GLRow<DT>& anotherOne);//copy construtor
    GLRow<DT> operator = (GLRow& anotherOne);// make a deep copy
    int getNext();//This will get the next node if in same row
    int getDown();//This will go down the tree
    DT& getInfo();
    void setNext(int n);
    void setDown(int d);
    void setInfo(DT& x);
  
    ~GLRow();//destructor
    
};
template<class DT>
GLRow<DT>::GLRow(){
    info = NULL;
    Next = -1;// -1 becauce 0 points to a spot in the array
    Down = -1;
}
template<class DT>
GLRow<DT>::GLRow(DT& newInfo){
    info = new DT(newInfo);
    Next = -1;
    Down = -1;
}
template<class DT>
GLRow<DT>::GLRow(GLRow<DT>& copyGLRow){
    info =  copyGLRow.info;
    Next = copyGLRow.Next;
    Down = copyGLRow.Down;
}
template<class DT>
GLRow<DT> GLRow<DT>::operator =(GLRow& anotherOne){
   
    info = new DT (anotherOne.getInfo());
    Next = anotherOne.Next;
    Down = anotherOne.Down;
    return (*this);
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
    return *info;
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
    info = new DT(x);
}
template <class DT>
ostream& operator <<  (ostream& s,  GLRow<DT>& oneGLRow) {
    s<<"Down" <<oneGLRow.getDown()<<endl;
    s<<"next"<< oneGLRow.getNext()<<endl;
    s<<"info" <<oneGLRow.getInfo()<<endl;
   // s<<"info"<<oneGLRow.getInfo()<<endl;
   // s <<"not done yet in GLRow";
    return s;
}
template <class DT>
GLRow<DT>::~GLRow() {
   // delete info;
}

//end of GLROW class

// start of ArrayGLL
template<class DT>
class ArrayGLL{//Array generalized linked list
  friend ostream& operator << <DT>(ostream& s, ArrayGLL<DT>& OneGLL);
protected:
    GLRow<DT>* myGLL;// array created also be the address of the arry
    int maxSize;// max size of array
    int firstElement;//first Node?
    int firstFree;//Frist Free Node?
  
public:
    ArrayGLL();//default
    ArrayGLL(int size);//non-empty
    ArrayGLL (ArrayGLL<DT>& anotherOne);//copy construtor
    ArrayGLL<DT>& operator =(ArrayGLL<DT>& anotherOne);//Not sure!
    
    void display();// bonus we need to display in parenthesis format
    int find(DT& key);/* return  the index position where you find the element key; return false if not found, use recursive search**/
    
    void findDisplayPath(DT& Key);
    int noFree();
    int size();
    int parentPos(DT& Key);//bonus
    GLRow<DT>&  operator [] (int pos);// This will return the value that is in
    //this postion
    int getFirstFree();
    int getFirstElement();
    void setFirstFree(int pos);
    void setFirstElement(int pos);
    void nextOutput();
    int findIndex(DT& key, int root);
    void printOrder(DT& key, int root);
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
            maxSize = anotherOne.maxSize;
            myGLL = anotherOne.myGLL;// Maybe over write this
            firstElement = anotherOne.firstElement;
            firstFree = anotherOne.firstFree;
        return (*this);
    }

    template<class DT>
    void ArrayGLL<DT>::display(){// bonus
        /*This will display in parenthesis format*
         if parent has child open parenthesis if no more or no children close
         parenthesis*/
        
        cout<<"parenthes format "<<endl;
    
    }

    template<class DT>
    int ArrayGLL<DT>::find(DT& key){
        
        int index = findIndex(key,firstElement);
        return index;
        
    }
    template<class DT>
    int ArrayGLL<DT>::findIndex(DT& key, int root){
   
        if(root == -1){
            return -1;
        }
            
            if(myGLL[root].getInfo() == key){
                return root;
            }
            else{
                int tempNext = findIndex(key, myGLL[root].getNext());
                int tempDown = findIndex(key, myGLL[root].getDown());
                if( tempNext != -1){
                    return tempNext;//When doing the print also do a cout  and exit when key is found
                }
                if(tempDown != -1){
                    return tempDown;
                }
                else {
                    return -1;
                }
            }
        
    }

    template<class DT>
    void ArrayGLL<DT>::findDisplayPath(DT& key){
       /*We will travel through the tree and print values we encounter
        if value is print all values**/
        printOrder(key, firstElement);
        
       
    }
template<class DT>
void ArrayGLL<DT>::printOrder(DT& key, int root){
    //if(myGLL[root].getInfo() == NULL){
      //  return;
    //}
     if(myGLL[root].getInfo() == key){
         cout<< "finish"<<endl;;
               }
   else{
        int tempNext = findIndex(key, myGLL[root].getNext());
        int tempDown = findIndex(key, myGLL[root].getDown());
       
        if( tempNext != -1){
            cout<<root<<endl;
            cout<<"finished in next"<<tempNext<<endl;//When doing the print also do a cout  and exit when key is //found
        }
        if(tempDown != -1){
            cout<<root<<endl;
            cout<<"finsied in down "<< tempDown<<endl;
        }
        else {
            return;
        }
    }
  
}

    template<class DT>
    int ArrayGLL<DT>:: noFree(){
        /*return number of free locations need to use the _Next or Next(my nameing)
         and get the free locations**/
        int counter = 0;
       
        /*Think of this as a linked list so**/
        return counter;
    }
    template<class DT>
    int ArrayGLL<DT>::size(){
        //return number of elements stored
     
        return 0;
    }
    template<class DT>
    int ArrayGLL<DT>::parentPos(DT& key){//bonus
        /*This will return the node above the key ?**/
        return 0;
    }
    template<class DT>
    GLRow<DT>& ArrayGLL<DT>:: operator[](int pos){
        
        return myGLL[pos];
    }

    template<class DT>
    int ArrayGLL<DT>::getFirstFree(){
        return firstFree;
    }
    template<class DT>
    int ArrayGLL<DT>::getFirstElement(){
        return firstElement;
    }
    template<class DT>
    void ArrayGLL<DT>::setFirstFree(int pos){
        firstFree = pos;
    }
    template<class DT>
    void ArrayGLL<DT>::setFirstElement(int pos){
        firstElement = pos;
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
        firstGLL[i] = oneRow;
       
       // cout<<firstGLL[i]<<"\n"<<endl;
        
    }
   
     firstGLL.setFirstFree(noElements);// setter done
        firstGLL.setFirstElement(2);// setter done
        //cout<<firstGLL<<endl;//This is for ostream I think
       // firstGLL.display();
        ArrayGLL<int>* secondGLL = new ArrayGLL<int>(firstGLL);
     
     int passByRef = 600;
    int passByRef2 = 700;
    (*secondGLL)[1].setInfo(passByRef);
    (*secondGLL)[2].setInfo(passByRef2);
    
   // cout<<*secondGLL<<endl;
   // (*secondGLL).display();

    keyValues = 15;
    pos =(*secondGLL).find(keyValues);
    if(pos != -1){
       //cout<<(*secondGLL)[pos]<<endl;//is this only needing to return the index or everything in the
        (*secondGLL).findDisplayPath(keyValues);
    }
    //parentPos = (*secondGLL).parentPos(keyValues);
    //if(parentPos != -1){
      //  cout<< (*secondGLL)[parentPos]<<endl;
    //}
    //cout<< (*secondGLL).size();
    //cout<< (*secondGLL).noFree();

    //delete secondGLL;

    return 0;
}



/*if(myGLL[root].getInfo() == key){
                  return root;
       }
       else{
           if(myGLL[root].getInfo() != -1){
               if(myGLL[root].getNext() != -1){
                   return find(key,myGLL[root++].getNext());
               }
               if(myGLL[root].getDown() != -1){
                   return find(key,myGLL[root++].getDown());
               }
           }
       }*/


/* if(myGLL[root].getInfo() == key){
                       return root;
            }
            
                if(myGLL[root].getInfo() != -1){
                    if(myGLL[root].getNext() != -1){
                        return find(key,myGLL[root].getNext());
                    }
                    if(myGLL[root].getDown() != -1){
                        return find(key,myGLL[root].getDown());
                    }
                }
     return -1;
        }*/
