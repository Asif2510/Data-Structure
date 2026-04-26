class SinglyCircularLinkedList;
class Node
{
    int iData;
    Node *pNext;
    friend  SinglyCircularLinkedList;
};
class SinglyCircularLinkedList
{
    private:

    Node * head;
    Node * Last;
    int iSize;

    public:

    bool insertFirst(int iData);
    bool insertLast(int iData);
    bool insertMidel(int iData,int iPos);

    bool DeleteFirst();
    bool DeleteLast();
    bool DeleteMidel(int iPos); 

    void Show();
    int size();

    public:

    SinglyCircularLinkedList();
};