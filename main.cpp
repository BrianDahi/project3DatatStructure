

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
    int seetDown(int d);
    int setInfo(DT& x);
    ~GLRow();//destructor
    
};


template<class DT>
class ArrayGLL{
  friend ostream& operator << <DT>(ostream& s, ArrayGLL<DT>& OneGLL);
protected:
    GLRow<DT>* myGLL;// array created
    int maxSize;// max size of array
    int firstElement;
    int firstFree;
public:
    ArrayGLL();
    ArrayGLL(int size);
    ArrayGLL<DT>& operator =(ArrayGLL<DT>& anotherOne);
    void display();// bonus we need to display in parenthesis format
    int find(DT& key);/* return  the index position where you find the element key; return false if not found, use recursive search**/
    int findDisplayPath(DT& Key);
    int noFree();
    int size();
    int parentPos(DT& Key);//bonus
    GLRow<DT& operator [] (int pos);
    int getFirstFree();
    int getFirstElemt();
    void setFirstFree(int pos);
    void setFirstElement(int pos);
   ~ArrayGLL();//destructor
    
    
};



int main() {
    
    cout<<"Hello"<<endl;
    
    return 0;
}
