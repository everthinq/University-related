//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <conio.h>
#include <iostream.h>
#include <cassert>

template <class T> class D_List
{
private:

  struct D_Node
  {
    D_Node *next;
    D_Node *prev;
    T val; // Поле данного

    D_Node(T node_val) : val(node_val) { }
    D_Node() {}
    ~D_Node(){}
    void print_val() {cout << val << " ";}
  };

public:

  class iterator;

private:

  D_Node *head;
  D_Node *tail;     
  D_List &operator= (const D_List &);
  D_List (const D_List &);

  iterator head_iterator;
  iterator tail_iterator;

public:

  D_List ();
  D_List (T node_val);
  ~D_List ();
  T &operator[] (int num);
  void operator= (T val);
  T &operator+ (T val);
  int is_empty();
  iterator front();
  iterator rear();
  void add_front(T node_val);
  void add_rear(T node_val);
  int remove_it (iterator &key_i);
  iterator find (T node_val) const;
  int size (void) const;
  void print (void) const;
};

template <class T> class D_List<T>::iterator
{

private:

  friend class D_List<T>;
  D_Node *the_node; //текущий итератор

public:

  iterator () : the_node (0) { }
  iterator (D_Node *dn) : the_node (dn) { }
  iterator (const iterator &it) : the_node (it.the_node) { }

  iterator &operator= (const iterator &it)
  {
    the_node = it.the_node;
    return *this;
  }

  bool operator== (const iterator &it) const
  {
    return (the_node == it.the_node);
  }

  bool operator!= (const iterator &it) const
  {
    return !(it == *this);
  }

  iterator& operator++ ()
  {
    if (the_node == 0) cout << "Error1;
    if (the_node->next == 0) cout << "Error2";
    the_node = the_node->next;
    return *this;
  }

  iterator& operator-- ()
  {
    if (the_node == 0) cout << "Error3";
    if (the_node->prev == 0) cout << "Error4";
    the_node = the_node->prev;
    return *this;
  }

  //Cсылкf на значение элемента по итератору
  T &operator* () const
  {
    if (the_node == 0) cout << "Error5";
    return the_node->val;
  }
};

template <class T> D_List<T>::D_List ()
{
  head = tail = new D_Node;
  tail->next = 0;
  tail->prev = 0;
  head_iterator = iterator (head);
  tail_iterator = iterator (tail);
}

template <class T> D_List<T>::D_List (T node_val)
{
  head = tail = new D_Node;
  tail->next = 0;
  tail->prev = 0;
  head_iterator = iterator(head);
  tail_iterator = iterator(tail);
  add_front (node_val);
}

template <class T> D_List<T>::~D_List ()
{
  D_Node *node_to_delete = head;

  for (D_Node *sn = head; sn != tail;)
  {
    sn = sn->next;
    delete node_to_delete;
    node_to_delete = sn;
  }

  delete node_to_delete;
}

template <class T> T &D_List<T>::operator[] (int num)
{
  iterator it = head_iterator;
  while (num && it != tail_iterator)
  {
    it++;
    num++;
  }

  if (it == tail_iterator) cout << "bad index";

  return *it;
}

template <class T> void D_List<T>::operator= (T val)
{
  iterator it = head_iterator;
  while (it != tail_iterator)
  {
    *it = val;
    ++it;
  }
}

template <class T> T &D_List<T>::operator+ (T val)
{
  iterator it = head_iterator;
  while (it != tail_iterator)
  {
    *it = *it + val;
    ++it;
  }
  return *head_iterator;  //возвращает первый элeмент списка
}

template <class T> int D_List<T>::is_empty()
{
  return head == tail;
}

template <class T> D_List<T>::iterator D_List<T>::front()
{
  return head_iterator;
}

template <class T> D_List<T>::iterator D_List<T>::rear()
{
  return tail_iterator;
}

template <class T> void D_List<T>::add_front (T node_val)
{
  D_Node *node_to_add = new D_Node (node_val);
  node_to_add->next = head;
  node_to_add->prev = 0;
  head->prev = node_to_add;
  head = node_to_add;
  head_iterator = iterator (head);
}

template <class T> void D_List<T>::add_rear(T node_val)
{
  if (is_empty ()) add_front (node_val);
  else
  {
    D_Node *node_to_add = new D_Node (node_val);
    node_to_add->next = tail;
    node_to_add->prev = tail->prev;
    tail->prev->next  = node_to_add;
    tail->prev = node_to_add;
    tail_iterator = iterator (tail);
  }
}

// Удалить элемент списка, на который указывает итератор
template <class T> int D_List<T>::remove_it (iterator &key_i)
{
  for (D_Node *dn = head; dn != tail; dn = dn->next)
  {
    if (dn == key_i.the_node) // Найден узел для удаления?
    {
      dn->prev->next = dn->next;
      dn->next->prev = dn->prev;
      delete dn;
      key_i.the_node = 0;
      return 1;
    }
  }
 return 0;
}

// Поиск итератора по значению узла
template <class T> D_List<T>::iterator D_List<T>::find (T node_val) const
{
  for (D_Node *dn = head; dn != tail; dn = dn->next)
  {
    if (dn->val == node_val) return iterator (dn);
  }
  return tail_iterator;
}

// Вернуть размер списка
template <class T> int D_List<T>::size() const
{
  int count = 0;
  for (D_Node *dn = head; dn != tail; dn = dn->next)
   ++count;
  return count;
}

template <class T> void D_List<T>::print() const
{
  cout << "Print list: ";
  for (D_Node *dn = head; dn != tail; dn = dn->next)
  {
    dn->print_val ();
  }
  cout << endl;
}

D_List<int> the_list;

int main()
{
  D_List<int>::iterator list_iter, tmp_iter;
  for (int j = 0; j < 5; j++)
  {
    the_list.add_front(j);
  }

  the_list.print();

  cout << "Print iter list: ";
  for (list_iter = the_list.front (); list_iter != the_list.rear (); ++list_iter)
  {
    cout << *list_iter << " ";
  }
  cout << endl;

  cout << "Print back list: ";
  for (list_iter = the_list.rear (); list_iter != the_list.front ();)
  {
    list_iter--;
    cout << *list_iter << " ";
  }

  cout << endl << endl;

  tmp_iter = the_list.find(3);
  the_list.remove_it(tmp_iter);
  cout << "Remove it: " << endl;
  the_list.print();

  cout << endl;
  cout << "Operation index: " << endl;
  cout << "[2] = " << the_list[2] << endl;
  cout << "[3] = " << the_list[3] << endl;
  the_list[2] = the_list[3];
  cout << "[2] = " << the_list[2] << endl;
  the_list.print();

  cout << endl;
  cout << "Operation =" << endl;
  the_list = -13;
  the_list.print();

  cout << endl << "Operation +" << endl;
  the_list + 13;
  the_list.print();

  cout << endl << "List size: " << the_list.size() << endl;
  cout << endl << "Press any key for exit... ";

  getch();

  return 0;
}

