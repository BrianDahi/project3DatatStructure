

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
    info =  new DT (copyGLRow.getInfo());
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
   
   //Wasn't sure what to print so Decided to print the down, next and info
    //The reasoning is to show what the row has at that index.
    s<<"Down: " <<oneGLRow.getDown()<<endl;
    s<<"next: "<< oneGLRow.getNext()<<endl;
    s<<"info: " <<oneGLRow.getInfo()<<endl;
    return s;
}

    template <class DT>
    GLRow<DT>::~GLRow() {
        if(info != NULL){
            delete info;
        }
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
    DT* keyValue;
  
public:
    ArrayGLL();//default
    ArrayGLL(int size);//non-empty
    ArrayGLL (ArrayGLL<DT>& anotherOne);//copy construtor
    ArrayGLL<DT>& operator =(ArrayGLL<DT>& anotherOne);//Not sure!
    
    void display();// bonus we need to display in parenthesis format
    int displayHelper( int root);
    
    int find(DT& key);/* return  the index position where you find the element key; return false if not found, use recursive search**/
    int findIndex(DT& key, int root);
    
    void findDisplayPath(DT& Key);
    bool print(DT& key, int root);
    
    int noFree();
    
    int  size();
    int sizeHelper(int root);
    
    int parentPos(DT& Key);//bonus
    int findParentPositionIndex(DT& key, int root,int parentPos);
    
    GLRow<DT>&  operator [] (int pos);// This will return the value that is in
    //this postion
    int getFirstFree();
    int getFirstElement();
    void setFirstFree(int pos);
    void setFirstElement(int pos);
    
    DT& getKey();
    void setKey(DT& x);
   
    
    ~ArrayGLL();//destructor
};
    template<class DT>
    ArrayGLL<DT>::ArrayGLL(){//default constructor
        keyValue = NULL;
        
        myGLL = NULL;
        firstElement = 0;
        firstFree = 0;
    }
    template<class DT>
    ArrayGLL<DT>::ArrayGLL(int size){
        keyValue = new DT();
        
        myGLL = new GLRow<DT> [size];
        maxSize = size;
        firstElement = 0;
        firstFree = 0;
    }
    template<class DT>
    ArrayGLL<DT>::ArrayGLL (ArrayGLL<DT>& anotherOne){
        keyValue =  new DT ();
        
        maxSize = anotherOne.maxSize;
        myGLL = new GLRow<DT>[maxSize];
          for( int i = 0; i < maxSize; ++i){
              myGLL[i] = anotherOne.myGLL[i];
          }
        //myGLL = anotherOne.myGLL;
        firstElement = anotherOne.firstElement;
        firstFree = anotherOne.firstFree;
    }

    template<class DT>
    ArrayGLL<DT>& ArrayGLL<DT>::operator =(ArrayGLL<DT>& anotherOne){
        keyValue =  new DT ();
        
            maxSize = anotherOne.maxSize;
            myGLL = new GLRow<DT>[maxSize];// Maybe over write this
        for( int i = 0; i < maxSize; ++i){
            myGLL[i] = anotherOne.myGLL[i];
        }
            firstElement = anotherOne.firstElement;
            firstFree = anotherOne.firstFree;
        return (*this);
    }

    template<class DT>
    void ArrayGLL<DT>::display(){// bonus
        /*This will display in parenthesis format*
         if parent has child open parenthesis if no more or no children close
         parenthesis*/
        // if down is true open parenthese
       // int info = myGLL[firstElement].getInfo();
        
        cout<<"parenthes format "<<endl;
        //cout<< "( ";
       // displayHelper(firstElement);
       // cout<< " )"<<endl;
    }
    template<class DT>
    int ArrayGLL<DT>::displayHelper( int root){
        int next = myGLL[root].getNext();
        int down = myGLL[root].getDown();
       if(root == -1){
            return -1;
       }
        else{
            // if down open
            if(myGLL[root].getDown() != -1){
                           cout<< "( ";
            }
            if( next != -1 || next == -1){
                        cout<< myGLL[root].getInfo()<<" ";
                                    
            }
            int tempNext = displayHelper( myGLL[root].getNext());
           
            int tempDown = displayHelper( myGLL[root].getDown());
            if( tempNext != -1){
                cout<< myGLL[root].getInfo();
                    return tempNext;
            }
           /* if(tempDown != -1){
                cout<< "( ";
                    return tempDown;
            }*/
            else {
                cout<< " )";
                    return -1;
                  }
            }
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
                return tempNext;
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
        cout<<"This is the path from the key "<< endl;
        print(key, firstElement);
    }

    template<class DT>
    bool ArrayGLL<DT>::print(DT& key, int root){
        
        if(root == -1){
              return false;
        }
     if(myGLL[root].getInfo() == key){
          return true;
     }
    else{
            bool tempNext = print(key, myGLL[root].getNext());
            bool tempDown = print(key, myGLL[root].getDown());
        if(tempNext){
             return true;
        }
        if(tempDown){
                cout<<"Node: "<<root<<" "<<"Info: "<<myGLL[root].getInfo()<<", ";
                cout<<endl;
                return true;
        }
        else {
            return false;
        }
        }
        
    }
    

    template<class DT>
    int ArrayGLL<DT>:: noFree(){
        /*return number of free locations need to use the _Next or Next(my nameing)
         and get the free locations*
         The free location should relate to 999*/
       // firstFree = 8;//I went ahead and hard coded this 8 in. becauce in the given
        // table it wants me to follow next and the only time next follows all 3 empties is starting at 8
        // TODO ask TA if this is ok or is their another way!!
        int counter = 1;
        int index = myGLL[firstFree].getNext();
       while(index != -1){
            ++counter ;
            index = myGLL[index].getNext();
        }
       return counter;
    }


    template<class DT>
    int ArrayGLL<DT>::size(){
       
       return sizeHelper(getFirstElement());
       
    }
    template<class DT>
    int ArrayGLL<DT>::sizeHelper(int root){
        if(root == -1){
              return 0;
        }
       return 1 + sizeHelper( myGLL[root].getNext()) +sizeHelper(myGLL[root].getDown());
    }

    template<class DT>
    int ArrayGLL<DT>::parentPos(DT& key){
        int index = firstElement;
        return findParentPositionIndex(key,index, -1);
    }

    template<class DT>
    int ArrayGLL<DT>::findParentPositionIndex(DT& key, int root, int parent){
    if(root == -1){
        return -1;
    }
  
    if (myGLL[root].getInfo() == key) {
          return parent;
    }
    else{
            int tempNext = findParentPositionIndex(key, myGLL[root].getNext(), parent);
            int tempDown = findParentPositionIndex(key, myGLL[root].getDown(), root);
         
           if( tempNext != -1){
               return tempNext;
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
    GLRow<DT>& ArrayGLL<DT>:: operator[](int pos){
        //cout<<"Index: "<<pos<<endl;
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
 
    template<class DT>
    DT& ArrayGLL<DT>::getKey(){
        return *keyValue;
    }
    template<class DT>
    void ArrayGLL<DT>::setKey(DT& x){
        keyValue = new DT(x);
    }
    template <class DT>
    ostream& operator <<  (ostream& s, ArrayGLL<DT>& OneGLL) {
        DT temp = OneGLL.getKey();
        if( OneGLL.find(temp) == -1){
            s<<"Key does not Exit!"<<endl;
        }
        else{
            s<< "This is the Node where the key is located at: " << OneGLL.find(temp) << endl;
            
        }
        OneGLL.findDisplayPath(temp);
        if(OneGLL.parentPos(temp) == -1){
            s<<"This is the root so no parent"<<endl;
        }
        else{
            s<<OneGLL.parentPos(temp)<<" Is the parent node of the key "<<temp<<endl;
        }
        
        s << "The size of the tree at "<<OneGLL.getFirstElement() <<": "<<OneGLL.size()<<endl;
        s<<"The number of free at "<< OneGLL.getFirstFree() << ": "<<OneGLL.noFree()<<" Nodes that are free"<<endl;
        return s;
    }

    template <class DT>
    ArrayGLL<DT>::~ArrayGLL() {
        if(myGLL != NULL){
            delete[] myGLL;
        }
    }
//end of arrayGLL

int main() {
    
    cout<<"Hello"<<endl;
    int noElements,value,next,down,parentPos;
    int pos = -1;
    int keyValues;
    int zero = 0;
    GLRow<int> oneRow(zero);// This is statically defined
    
    //All variables must be defined
    
    cin>> noElements;
    ArrayGLL<int> firstGLL(noElements);
    
    for(int i = 0; i < noElements; ++i){
        cin >> value >> next >> down ;
        oneRow.setInfo(value);
        oneRow.setNext(next);
        oneRow.setDown(down);
        firstGLL[i] = oneRow;
        
    }
   keyValues = 25;
    firstGLL.setKey(keyValues);
     firstGLL.setFirstFree(8);// I changed this to eight since it was the only way to reach all 3 empties
     firstGLL.setFirstElement(2);// setter done
    cout<<"\n\n";
     cout<<"This is the Ostream operator for firstGLL: \n"<<firstGLL<<endl;//This is for ostream I think
     //firstGLL.display();// parenthes format
    
     ArrayGLL<int>* secondGLL = new ArrayGLL<int>(firstGLL);
     int passByRef = 600;
     int passByRef2 = 700;
     (*secondGLL)[1].setInfo(passByRef);
     (*secondGLL)[2].setInfo(passByRef2);
    (*secondGLL).setKey(keyValues);
    cout<<"This is the Ostream Operator for secondGLL: \n"<<(*secondGLL)<<endl;// ostream
    //(*secondGLL).display();// parenthese format

    
    
    /*The code below I left since the pdf said the variables in main need to be defined. I was going to move it
     to ostream. However I didnt want that to count against me.*/
    pos = (*secondGLL).find(keyValues);
    if(pos != -1){
        cout<<(*secondGLL)[pos]<<endl;
        (*secondGLL).findDisplayPath(keyValues);
    }
    
    parentPos = (*secondGLL).parentPos(keyValues);
   
    
    if(parentPos != -1){
        cout<< (*secondGLL)[parentPos]<<endl;
    }

    delete secondGLL;

    return 0;
}



