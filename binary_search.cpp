#include <iostream>
#include <vector>
// Needs to be sorted
// Halfs till target is found

// Check the middle value for the value if not check if its less or more,
// If less delete every other value above it 
// Then repeat get middle --> greate that or less than --> delete 
// Everytime i say delete its just disregard

//          When would this be effiecnt:
// - Only on large data sets small is just not needed
//    - This is because you disregard HALF the elements in one its alot and can be very fast

// O (log n), (time, data)



int main()
{
    std::vector<int> Numbers[100] = {}; // Declaring vector number set of 100 indexes
    int target = 90; // Target we want to find

    for (int i = 0; i < std::size(Numbers); i++)
    {
        Numbers[i].push_back(i);
    } // Just setting the values of 0-100 in Numbers
    
    // THIS IS THE BINARY SEARCH 
    int lower = 0;
    int top = std::size(Numbers) -1;

    while(lower <= top)
    {
        int middle = std::size(lower + top) /2;
        int value = Numbers[middle].at(0);
        std::cout << "Middle is currently: " << value << std::endl;

        if(value < target) lower = middle + 1;
        else if(value > target) top = middle -1;
        else {
            std::cout << "Target found at index" << middle << std::endl;
            break;
        }
        
        
    }
    




}