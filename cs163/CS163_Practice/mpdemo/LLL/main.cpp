#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    //int count = 0;
    //node * new_head = NULL;
    build(head);

    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
/*
    int counter = remove_last_recursive(head);
    cout << "The first version gave us this count: " << counter << endl;

    counter = remove_last_refined(head);
    cout << "Now the counter will be one less: " << counter << endl;
*/
    //int counter = remove_largest(head);
    //cout << "We removed " << counter << " nodes." << endl;
   // int count_match = append_end(head);
    //cout << "We found " << count_match << " number of matches to the first"
     //    << endl;

    //int node_count = count_node(head);
    //int sum = sum_all(head);
    //int sum_even = sum_even2(head);
    //float avg = average(head);
    //copy_new(head, new_head);

    //cout << "count: " << node_count << endl << "sum: " << sum << endl << "sum_even: " << sum_even << endl
    //     << "average: " << avg << endl << endl;

    //add_at_beginning(head);
    //add_at_end(head);
    //duplicate_last(head);
    //add_after_any_2(head);
    //remove_first(head);
    //remove_last_node(head);
    //if(!first_equal_last(head, data))
    //    cout << "no match" << endl << endl;
    //remove_last_two_nodes(head);
    //remove_every_node(head);
    //delete_all_but_first(head);
    //int morefour = count_greater_than_4(head);
    //cout << "more than 4: " << morefour << endl;
   // copy_even_only(head, new_head);
    //float avg = average_even(heag);
    //cout << "Even average: " << avg << endl;
    //int sum_low = sum_less_than_10 (head);
    //cout << "low sum: " << sum_low << endl;
    //int same_first = count_same_first(head);
    //int same_last = count_same_last(head);
    //cout << "same as last: " << same_last << endl;
    //remove_first_place_last(head);
    //int largest = remove_largest(head);
    //cout << "largest was: " << largest << endl << endl;
    //remove_last_2(head);
    int count = remove_match(head, 2);
    cout << "This many removed " << count << endl;

    //if (find_last2(head))
    //    cout << "SUCCESS!! Look where 99 is..." << endl;

    display(head); //redisplay the list after your function
    destroy(head); 
    
    //display(new_head); //redisplay the list after your function
    //destroy(new_head); 
    return 0;
}
