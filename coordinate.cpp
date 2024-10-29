#include <iostream>
#include <cmath>
#include <cstdlib>
#include "coordinate.h"

static int id_counter = 1; // Static counter to assign unique IDs

// Adds a new coordinate to the end of the list
void add_coordinate(Coordinate *list_end, float x, float y) {
    Coordinate *new_coord = new Coordinate;
    new_coord->x = x;
    new_coord->y = y;
    new_coord->coord_id = id_counter++;
    new_coord->next = nullptr;
    new_coord->previous = list_end;
    if (list_end) list_end->next = new_coord;
}

// Displays the list from beginning to end
void forward_display(Coordinate *list_beginning) {
    Coordinate *current = list_beginning;
    while (current) {
        std::cout << "ID: " << current->coord_id << " (x: " << current->x << ", y: " << current->y << ")\n";
        current = current->next;
    }
}

// Displays the list from end to beginning
void backward_display(Coordinate *list_end) {
    Coordinate *current = list_end;
    while (current) {
        std::cout << "ID: " << current->coord_id << " (x: " << current->x << ", y: " << current->y << ")\n";
        current = current->previous;
    }
}

// Deletes a coordinate with the specified ID
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete) {
    Coordinate *current = list_beginning;
    while (current) {
        if (current->coord_id == coord_id_to_delete) {
            if (current->previous) current->previous->next = current->next;
            if (current->next) current->next->previous = current->previous;
            delete current;
            std::cout << "Coordinate with ID " << coord_id_to_delete << " deleted.\n";
            return;
        }
        current = current->next;
    }
    std::cout << "Coordinate with ID " << coord_id_to_delete << " not found.\n";
}

// Returns the length of the list
int list_length(Coordinate *list_beginning) {
    int length = 0;
    Coordinate *current = list_beginning;
    while (current) {
        ++length;
        current = current->next;
    }
    return length;
}

// Finds and displays the coordinate closest to a given x, y
void closest_to(Coordinate *list_beginning, float x, float y) {
    Coordinate *current = list_beginning;
    Coordinate *closest = nullptr;
    float min_distance = std::numeric_limits<float>::max();

    while (current) {
        float distance = std::sqrt(std::pow(current->x - x, 2) + std::pow(current->y - y, 2));
        if (distance < min_distance) {
            min_distance = distance;
            closest = current;
        }
        current = current->next;
    }

    if (closest) {
        std::cout << "Closest coordinate to (" << x << ", " << y << ") is ID " << closest->coord_id 
                  << " (x: " << closest->x << ", y: " << closest->y << ") with distance: " << min_distance << "\n";
    }
}
