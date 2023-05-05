#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////
// Structure for Singly Linear and Singly Circular
template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

////////////////////////////////////////////////////////////////
// Structure for Doubly Linear and doubly Circular
template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

////////////////////////////////////////////////////////////////
// Class of Singly Linear Linked List
template <class T>
class SinglyLL
{
    public:
        struct nodeS <T>* First;
        int iCount;

        // Behaviours
        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no ,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeS <T> * newn = new struct nodeS<T> ;

    newn->data = no;
    newn->next =  NULL;

    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one nodeS
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    // Step1 : Allocate memory for nodeS
    struct nodeS <T>* newn = new struct nodeS<T> ;

    // Step2 : Initialise nodeS
    newn->data = no;
    newn->next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one nodeS
    {
        struct nodeS <T>* temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>:: InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new struct nodeS<T> ;

        newn->data = no;
        newn->next = NULL;

        struct nodeS <T>* temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> * temp = First;
        First = First -> next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: DeleteLast()
{    
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

template <class T>
void SinglyLL<T> :: DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS <T>* temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeS <T>* temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct nodeS <T>* temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

////////////////////////////////////////////////////////////////
// Class of Singly Circular Linked List
template <class T>
class SinglyCL
{
    public:
        struct nodeS <T>* First;
        struct nodeS <T>* Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one nodeS
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    //PnodeS newn = new nodeS;
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one nodeS
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    struct nodeS <T>* temp = First;
    
    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    struct nodeS <T>* temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    struct nodeS <T>* temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single nodeS in LL
    {
        //free(*First);
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 nodeS
    {
        First = (First)->next;
        //free(temp);
        delete temp;

        (Last) ->next = First;
    }
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeS <T>* temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single nodeS in LL
    { 
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 nodeS
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    int inodeSCnt = 0, iCnt = 0;
    inodeSCnt = Count();
    struct nodeS <T>* newn = NULL;
    struct nodeS <T>* temp = First;

    if((ipos < 1) || (ipos > inodeSCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == inodeSCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS <T>* newn = new struct nodeS <T>;
        
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int inodeSCnt = 0, iCnt = 0;
    inodeSCnt = Count();
    struct nodeS <T>* temp1 = First;
    struct nodeS <T>* temp2 = NULL;

    if((ipos < 1) || (ipos > inodeSCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == inodeSCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

////////////////////////////////////////////////////////////////
// Class of Doubly Linear Linked List
template <class T>
class DoublyLL
{
    public:
        struct nodeD <T>* First;

        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        
        void Display();
        int Count();

};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
}

template <class T>
void DoublyLL<T>:: InsertFirst(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;  // X

        First = newn;
    }
}

template <class T>
void DoublyLL<T>:: InsertLast(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>;
    
    struct nodeD <T>* temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeD <T>* temp = First;
    cout<<"Elements of Linked list are"<<"\n";

    cout<<"NULL<=> ";

    while(temp != NULL)
    {
        cout<<"|"<< temp->data<<" |<=> ";
        temp = temp->next;
    }
    cout<<"NULL \n";
}

template <class T>
int DoublyLL<T>::Count()
{
    int iCnt = 0;
    struct nodeD <T>* temp = First ;
    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if(First->next == NULL) // LL contains 1 nodeD
    {
        delete First;
        First = NULL;
    }
    else    // LL contains more than 1 nodeD
    {
        First = First-> next;
        delete First->prev;               // X
        First->prev = NULL;              // X
    }
}

template <class T>
void DoublyLL<T>:: DeleteLast()
{
    struct nodeD <T>* temp = First;

    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if(First->next == NULL) // LL contains 1 nodeD
    {
        delete First;
        First = NULL;
    }
    else    // LL contains more than 1 nodeD
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

template <class T>
void DoublyLL<T>:: InsertAtPos(T no, int ipos)
{
    int nodeDCnt = 0, iCnt = 0;
    struct nodeD <T>* newn = NULL;
    struct nodeD <T>* temp = NULL;

    nodeDCnt = Count();

    if((ipos < 1) || (ipos > (nodeDCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == nodeDCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD <T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      // X

        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    // X
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

template <class T>
void DoublyLL<T>:: DeleteAtPos(int ipos)
{
    struct nodeD <T>* temp1 = NULL;
    struct nodeD <T>* temp2 = NULL;
    int iCnt = 0, nodeDCnt = 0;
    nodeDCnt = Count();

    if((ipos < 1) || (ipos > nodeDCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == nodeDCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;  
        temp2->next->prev = temp1;      // X
        delete temp2;
    }
}

////////////////////////////////////////////////////////////////

// Class of Doubly Circular Linked List

template <class T>
class DoublyCL
{
    public:
        struct nodeD <T>* First;
        struct nodeD <T>* Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

template <class T>
DoublyCL<T> :: DoublyCL()  // Default constructor
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCL <T>:: InsertFirst(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodeDs
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL <T>:: InsertLast(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodeDs
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T>
void DoublyCL <T>:: Display()
{
    struct nodeD <T>* temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template <class T>
int DoublyCL <T>:: Count()
{
    int iCnt = 0;
    struct nodeD <T>* temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template <class T>
void DoublyCL <T>:: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single nodeD
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one nodeD
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL <T>:: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single nodeD
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one nodeD
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL <T>:: InsertAtPos(T no, int ipos)
{
    int inodeDCnt = Count();
    struct nodeD <T>* newn = NULL;
    struct nodeD <T>* temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > inodeDCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == inodeDCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD <T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyCL <T>:: DeleteAtPos(int ipos)
{
    int inodeDCnt = Count();
    struct nodeD <T>*  temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > inodeDCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == inodeDCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}
////////////////////////////////////////////////////////////////

int main()
{

    return 0;
}