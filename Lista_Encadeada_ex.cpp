#include <iostream>

#include <string>
using std::string;

struct _node; 
typedef struct _node
{ 
    string value; 
    struct _node* next; 
} node_t;

node_t* add_node(node_t* list, string value)
{ 
    if (list && list->next) //vai para o final da lista de list e list.next forem diferentes de NULL
        return add_node(list->next, value); 
     
    node_t* node = new node_t; 
    node->value = value; 
    node->next = NULL; 
    if (list) 
        list->next = node; 
    return list ? list : node; 
} 

void set_node(node_t* list)
{
std::cout << "Digite um valor" << std::endl;
string valor;
getline(std::cin,valor);
add_node(list, valor);
}

int main()
{
    node_t* my_list = add_node(NULL, "");
    set_node(my_list);
    set_node(my_list);
    set_node(my_list);

    while (my_list != NULL)
    {
        std::cout << my_list->value << std::endl;
        my_list=my_list->next ;
    }
    return 0;
}