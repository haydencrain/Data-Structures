#include <iostream>
#include "linked_list.h"

int main()
{
    linked_list<int> *l = new linked_list<int>();

    for (int i = 0; i < 10; i++)
    {
        l->append(i);
    }

    for (int i = 0; i < l->length(); i++)
    {
        std::cout << l->get(i) << " ";
    }
    std::cout << std::endl;
}
