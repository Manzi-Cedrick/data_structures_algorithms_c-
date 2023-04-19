#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int a)
    {
        this->data = a;
        next = NULL;
    }
};

bool search(Node *head, int x)
{
    while (head != NULL)
    {
        if (head->data == x)
        {
            return true;
        }
        head = head->next;
    }

    return false;
}

int position(Node *head, int x)
{
    int position = 1;

    while (head != NULL)
    {
        if (head->data == x)
        {
            return position;
        }
        head = head->next;
        position++;
    }

    return -1;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << "The head data: " << head->data << endl;
        head = head->next;
    }
}
Node *deleteFirst(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteLastNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *secondLast = head;

    while (secondLast->next->next != NULL)
    {
        secondLast = secondLast->next;
    }

    Node *last = secondLast->next;

    delete last;

    secondLast->next = NULL;

    return head;
}
Node *deleteSecondLast(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *thirdLast = head;
    Node *current = head->next;
    while (current->next != NULL)
    {
        if (current->next->next == NULL)
        {
            Node *secondLast = current;
            current = current->next;
            thirdLast->next = current;
            delete secondLast;
            break;
        }
        thirdLast = current;
        current = current->next;
    }
    return head;
}
Node *deleteThirdLast(Node *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL || head->next->next->next == NULL)
    {
        cout << "NULL LIST";
        delete head;
        return NULL;
    }
    Node *fourLast = head;
    Node *current = head->next;
    while (current->next->next != NULL)
    {
        fourLast = current;
        current = current->next;
    }
    Node *thirdLast = fourLast;
    fourLast = fourLast->next;
    thirdLast->next = fourLast->next;
    delete fourLast;
    return head;
}
Node *deleteNodePosition(Node *head, int i)
{
    if (i <= 0)
    {
        return head;
    }
    if (i == 1 && head)
    {
        Node *newHead = head->next;
        head->next = NULL;
        delete head;
        return newHead;
    }
    Node *curr = head;
    int count = 1;
    while (count < i - 1 && curr != NULL)
    {
        curr = curr->next;
        count++;
    }
    if (curr && curr->next)
    {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    return head;
}
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *ahead = prev;
    while (current != NULL)
    {
        ahead = current->next;
        current->next = prev;
        current = ahead;
    }
    return prev;
}
Node *midNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
    Node *n1 = new Node(5);
    Node *n2 = new Node(6);
    Node *n3 = new Node(8);
    Node *n4 = new Node(10);
    Node *n5 = new Node(15);
    Node *n6 = new Node(20);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    // search(n1, 16) ? cout << "Found" << endl : cout << "Not Found" << endl;
    // int ps = position(n1, 8);
    // !(ps == -1) ? cout << "Position of node in lists : " << ps << endl : cout << "Not found" << endl;
    // Node *head = deleteLastNode(n5);
    // Node *head = deleteThirdLast(n1);
    // Node *head = deleteNodePosition(n1,6);
    // Node *head = n1;
    // display(head);
    // cout << "After reverse";
    // Node *root = reverse(n1);
    // display(root);
    Node *head = midNode(n1);
    cout << "Mid data: " << head->data;

    return 0;
}