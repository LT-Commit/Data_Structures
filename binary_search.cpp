#include <iostream>
#include <vector>


#include <chrono> // For time measurement
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
    int cap;
    int target = 90; // Target we want to find

    std::cout << "Whats the amount of numbers you want to check?" << std::endl;
    std::cin >> cap;
    std::cout << "Whats the target Num?" << std::endl;
    std::cin >> target;


     // Start measuring time
     auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> Numbers(cap); // Declaring vector number set of 100 indexes
    for (int i = 0; i < cap; i++)
    {
        Numbers[i].push_back(i);
    } // Just setting the values of 0-cap in Numbers
    
    // THIS IS THE BINARY SEARCH 
    int lower = 0;
    int top = cap -1;
    int Attempts = 0;

    while(lower <= top)
    {
        
        int middle = (lower + top) /2;
        int value = Numbers[middle].at(0);
        std::cout << "Middle is currently: " << value << std::endl;

        if(value < target)
        {
            lower = middle + 1; //adjusts the search range of the check same as below
            Attempts++;
        } 
        else if(value > target) 
        {
            top = middle -1;
            Attempts++;
        }
        else {
            std::cout << "Target found at index: " << middle << std::endl;
            std::cout << "It took: " << Attempts << " Attempts to find\n"; 
            break;
        }
        
        
    }

    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Output the runtime in seconds
    std::cout << "Program runtime: " << duration.count() << " seconds." << std::endl;
    




}