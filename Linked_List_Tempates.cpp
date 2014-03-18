#include <iostream>
using namespace std;

template <class T>
struct node
{
  T data;
  node * next;
};



template <class T>
class LinkedList
{
public:
  LinkedList() : head(NULL), size(0) {};
  ~LinkedList() { destroyList(); };
  bool addnode(T data);
  bool deletenode(T data);
  node<T> * searchnode(T data);
  void printList();
  void reverseList();
  void sortList();
private:
  node<T> * head;
  int size;
  void destroyList();
  node<T>* mergeSort(node<T> * head, int total);
  node<T>* Merge(node<T>* left, int lcount, node<T>* right, int rcount);
  void print(node<T> * tmp);
};

template <class T>
bool LinkedList<T>::addnode(T data)
{
try
  {
    node<T> * tmp = new node<T>();
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    ++size;
    return true;
  }
catch(std::exception & ex)
  {
    return false;
  }
}

template <class T>
bool LinkedList<T>::deletenode(T data)
{
  node<T> *curr = head, *prev = NULL;

  while (curr)
  {
    if (curr->data == data) break;

    prev = curr;
    curr = curr->next;
  }

  if (curr)
    {
      if (prev)
        {
          prev->next = curr->next;
        }
      else
        {
          head = curr->next;
        }
      delete(curr);
      --size;
      return true;
    }
  else
    {
      return false;
    }
}

template <class T>
node<T> * LinkedList<T>::searchnode(T data)
{
  node<T> * tmp = head;
  while (tmp)
    {
      if (tmp->data == data)
        {
          return tmp;
        }
      tmp = tmp->next;
    }
  return NULL;
}

template <class T>
void LinkedList<T>::print(node<T> * tmp)
{
  bool printNewLine = (tmp) ? true : false;
  while (tmp)
    {
      std::cout << tmp->data << ",";
      tmp = tmp->next;
    } 

  if (printNewLine)
    {
      std::cout << std::endl;
    }
}

template <class T>
void LinkedList<T>::printList()
{
  node<T> * tmp = head;
  bool printNewLine = (tmp) ? true : false;
  while (tmp)
    {
      std::cout << tmp->data << "|";
      tmp = tmp->next;
    } 

  if (printNewLine)
    {
      std::cout << std::endl;
    }
}

template <class T>
void LinkedList<T>::destroyList()
{
  node<T> * tmp = NULL;
  while (head)
    {
      tmp = head;
      head = head->next;
      //std::cout << "deleting data " << tmp->data << std::endl;
      delete(tmp);
    }
}

template <class T>
void LinkedList<T>::reverseList()
{
  node<T> *curr = head, *prev = head, *save = NULL;

  while (curr)
    {
      save = curr->next;
      curr->next = prev;
      prev = curr;
      curr = save;
    }

  head->next = NULL;
  head = prev;
}

//use merge sort
template <class T>
void LinkedList<T>::sortList()
{
  head = mergeSort(head, size);
}

template <class T>
node<T>* LinkedList<T>::mergeSort(node<T> * first, int total)
{
  if (total < 1) { return first; }
  if (total < 2) { first->next = NULL; return first;}

  node<T> * curr = first;
  int count = total/2;
  while (count--)
    {
      curr = curr->next;
    }


  count = total/2;
  first = mergeSort(first, count);

  curr = mergeSort(curr, total-count);

  return Merge(first, count, curr, total-count);
}

template <class T>
node<T>* LinkedList<T>::Merge(node<T>* left, int lcount, node<T>* right, int rcount)
{
  node<T> * h = new node<T>();
  h->next = NULL;
  node<T> * tmp = h;

  while (lcount > 0 && rcount > 0)
    {
      if (left->data < right->data)
        {
          tmp->next = left;
          tmp = tmp->next;
          left = left->next;
          --lcount;
        }
      else if (right->data < left->data)
        {
          tmp->next = right;
          tmp = tmp->next;
          right = right->next;
          --rcount;
        }
      else
        {
          tmp->next = left;
          tmp = tmp->next;
          left = left->next;
          --lcount;

          tmp->next = right;
          tmp = tmp->next;
          right = right->next;
          --rcount;
        }
    }

  while (lcount > 0)
    {
      tmp->next = left;
      tmp = tmp->next;
      left = left->next;
      --lcount;
    }

  while (rcount > 0)
    {
      tmp->next = right;
      tmp = tmp->next;
      right = right->next;
      --rcount;
    }

  tmp = h;
  h = h->next;
  delete(tmp);

  return h;
}

int main()
{
  LinkedList<int> l;
  l.addnode(3);
  l.addnode(2);
  l.addnode(6);
  l.addnode(4);
  l.addnode(3);

  l.printList();
  l.reverseList();
  l.printList();

  l.sortList();
  l.printList();

  l.deletenode(3);
  l.deletenode(3);
  l.deletenode(4);

  l.printList();
  l.reverseList();
  l.printList();

  l.sortList();
  l.printList();

  if (l.searchnode(2))
    {
      std::cout << "2 found \n";
    }

  if (!l.searchnode(5))
    {
      std::cout << "5 not found \n";
    }

  return 0;
}

