
// Connor Baron-Williams and the purpose of the code in this file
// How to use this software - why it is here - purpose
// This is software to support rental properties for a person to sublet, 
// lease or have a short term rental.

class location
{
    public:
        location();
        location(const address & from, const char * neighorhood);
        location(const location & from);
        ~location(); //destructor when dynamic memory is present
        void edit(const address & from);
        void edit(const char * neighborhood);
        void display() const;  //constant member function
        bool input();
        int is_match(const char * neighborhood_to_check) const;
    protected:
        address the_address;
        char * a_neighborhood;
};

class property: public location
{
    public:
        property();
        property(int bed, float bath, int sqfeet,
                 const address & from, const char * neigh);
        property(const property & from);
        //In the implemenation of this copy construction
        //    property::property(const property & from): location(from), bedrooms(from.bedrooms),
        //                       bathrooms(from.bathrooms), sqft(from.sqft), history(NULL) //This has to happen regardless of if the parent has dynamic memory!!!
        //    {//Write the code to copy the from object's history to this object's history node}
        //

        ~property();
        void display();
        bool input();
        bool is_match(int bed) const;
        bool is_match(float bath) const;
        bool is_match(int lower_end_sqft, int upper_end_sqft) const;

    
    protected:
        int bedrooms;
        float bathrooms;
        int sqft;
        node * history;
};

/*

In the .cpp file:
property::property(int bed, float bath, int sqfeet,
                   const address & from, const char * neigh): location(from, neigh), 
                   bedrooms(bed), bathrooms(bath), sqft(sqfeet)
{}

*/

/*
What can the client call?
property object;
object.any_public_function_derived();
object.any_public_function_base_not_hidden();
object.is_match(3); //call the derived version
object.is_match("forest heights"); //this won't compile, it will only check in the derived because it hides the base function
object.location::is_match("forest heights"); //this will work!

object.display(); //if we want everything to be displayed, location included, then:
//in the implementation of the derived display function
void property::display() const
{
    location::display();
    //display my own data members next
}
*/


class sublet: public property
{
};

class lease: public property
{
};

class rental: public property
{
};
