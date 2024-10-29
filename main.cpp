#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

// Function prototypes
void add_coordinate(Coordinate *list_end, float x, float y);
void forward_display(Coordinate *list_beginning);
void backward_display(Coordinate *list_end);
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete);
int list_length(Coordinate *list_beginning);
void closest_to(Coordinate *list_beginning, float x, float y);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number of coordinates>\n";
        return 1;
    }

    int num_coords = std::atoi(argv[1]);
    if (num_coords <= 0) {
        std::cerr << "Number of coordinates must be positive.\n";
        return 1;
    }

    std::srand(std::time(nullptr)); // Seed random number generator

    // Initialize the list
    Coordinate *list_beginning = nullptr;
    Coordinate *list_end = nullptr;

    // Add random coordinates to the list
    for (int i = 0; i < num_coords; ++i) {
        float x = static_cast<float>(std::rand() % 100);
        float y = static_cast<float>(std::rand() % 100);
        add_coordinate(list_end, x, y);
        if (!list_beginning) list_beginning = list_end; // Set the beginning if it's the first element
    }

    // Display list in forward order
    std::cout << "Forward Display:\n";
    forward_display(list_beginning);

    // Display list in backward order
    std::cout << "\nBackward Display:\n";
    backward_display(list_end);

    // Demonstrate delete and closest-to functions
    delete_coordinate(list_beginning, 2); // Example ID to delete
    closest_to(list_beginning, 50.0f, 50.0f); // Example x, y to find closest

    return 0;
}
