class doublyCircularLinkedList;
class Node
{
    Node *pPrev;
    int iData;
    Node *pNext;
    friend  doublyCircularLinkedList;
    Node(int iValue):iData(iValue)
    {
        pPrev = nullptr;
        pNext = nullptr;
    }
};
class doublyCircularLinkedList
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
    int  size();

    public:

    doublyCircularLinkedList();
};