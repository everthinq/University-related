#ifndef LIST_H
#define LIST_H

#include <memory>
#include <iostream>

template <class Type>
class list
{
private: // fields

    struct mylist
       {
            std::shared_ptr<mylist> next = nullptr;        // pointer to the next
            Type data = 0;                                 // value

            mylist(Type data) : data (data) {}

            ~mylist() { std::cout << "Destructor\n"; }
       };

    std::shared_ptr<mylist> top = nullptr;         // pointer to the head of list

    size_t size = 0;    // current size


//----------------------METHODS---------------------

public:

    list () {}

    list(std::initializer_list <Type> initlist)
                {
                    for (auto & item : initlist)
                                    push_back( item );
                }

    size_t push_back ( Type data )
                {
                    std::shared_ptr <mylist> created = std::make_shared <mylist>(data);

                    return top ? AddToEnd (created) : AddFirst(created);
                }

    size_t pop_back ()
                {
                    if (!top) // if there are no elements
                        {
                            std::cout << "Pop_back, but list is empty\n";
                            return 0;
                        }

                    if (!top->next)         // IF THERE IS just one element then to erase it
                            return eraseFirst();

                    std::shared_ptr <mylist> temp = top; //otherwise

                    while ( temp->next->next )
                                 temp = temp->next;

                    temp->next = nullptr;
                    return --size;
                }

    size_t Size () const { return size; }

    void Print () const
            {
                if (!top)
                    {
                        std::cout << "list is empty" << std::endl;
                        return;
                    }

                std::shared_ptr <mylist> temp = top;

                while (temp)
                {
                    std::cout << temp -> data << " ";
                    temp = temp -> next;
                }

                std::cout << '\n' << "Current size : " << size << '\n';
            }

    size_t Add ( Type data, size_t position )
            {
                std::shared_ptr<mylist> temp = std::make_shared <mylist> (data);

                if ( !size || !position ) return AddFirst( temp );
                // if there are no elements in our list or user want to add at "0" position we add first

                if ( position >= size ) return AddToEnd( temp );
                // if user want to add an element at the end

                return AddInto ( temp, position ); //now we add in the middle
            }

    size_t erase ( size_t position )
            {
                if (!top)
                    {
                        std::cout << "Deleting from empty list\n" ;
                        return 0;
                    }
                if ( !position || position < 0 ) return eraseFirst();

                if ( position >= size ) return pop_back();

                return eraseFromMiddle( position );
            }
    void eraseAll ()
            {
                top = nullptr;
                size = 0;
            }



private:

    size_t AddFirst ( std::shared_ptr<mylist> created ) // here we add to a list start
            {
                if ( top ) created->next = top;
                else created->next = nullptr;
                top = created;              // head of list is new elemet
                return ++size;              // now make increment of size and return (it's equal "return 1")
            }

    size_t AddToEnd ( std::shared_ptr<mylist> created )
            {
                std::shared_ptr <mylist> temp = top;

                while (temp->next)          // The loop'll stop when temp will last element
                            temp = temp -> next;

                temp -> next = created;       // early temp->next was equaled nullptr. Now I make it as a created element
                created -> next = nullptr;    // if we add to the end then last element should indicate nullptr

                return ++size;
            }

    size_t AddInto( std::shared_ptr <mylist> created, size_t position) // Addition into the middle of the list
            {
                std::shared_ptr <mylist> temp = top;

                size_t i;

                //make iterations before won't stop on (position - 1)
                for ( i = 0 ; i < (position - 1); i++)
                                temp = temp -> next;

                created -> next = temp -> next;     // for a start I attach the tail of list
                temp -> next = created;             // later I connect first elements to created one

                size++;

                return ++i;
            }

    size_t eraseFirst ()
            {
                top = top -> next; //deleting is automatically
                return --size;
            }

    size_t eraseFromMiddle ( size_t position )
            {
                size_t i;
                std::shared_ptr <mylist> temp = top;

                for ( i = 0; i < (position - 1); i++)
                            temp = temp->next;

                temp->next = temp->next->next;

                size--;
                return ++i;
            }
};

#endif // LIST_H
