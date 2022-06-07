#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL
      adjacency_list = new vertex[size];
      for (int i = 0; i < size; ++i)
      {
          adjacency_list[i].entry = NULL;
          adjacency_list[i].head = NULL;
      }
      
      list_size = size;
}

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{
      int index = 0;

      //return the location of this particular key value 
      if (!key_value) return 0;

      for (int i = 0; i < list_size; ++i)
      {
        if (adjacency_list[i].head->adjacent->entry->compare(key_value))
          index = i;
      }

      return index;
}


//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{

        //Place your code here
        node * temp = new node;
        temp->adjacent = new vertex;
        temp->adjacent->entry = new journal_entry;
        temp->adjacent->entry->copy_entry(to_add);
        temp->next = NULL;

        if (!(adjacency_list[0].head))
        {
            adjacency_list[0].head = temp; 
            return 1;
        }

        node * current = adjacency_list[0].head;

        while (current->next)
          current = current->next;

        current->next = temp;
        return 1;
}


//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{
       //Attach this vertices edge to the specified vertex
       int index = find_location(to_attach);
       
}

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{

}
