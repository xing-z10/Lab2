#include <stdio.h>

// Define the Student struct
struct Student {
    char name[50];
    int grades[3];
    float average; // To store the average grade
};

// Function to calculate the average (pass-by-reference)

void calculateAverage(struct Student *student){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum = sum + *(student->grades+i); // Calculate the sum
    }
    student->average = sum /3.0; // Calculate the average
};

// Main function
int main(){
    // Create and initilize an array of 3 students
    struct Student students[3] = {
        {"Andy", {85, 90, 78}, 0},
        {"Randy", {88, 76, 92}, 0},
        {"Sandy", {70, 80, 75}, 0}
    };

    // Call calculateAverage for each studnet
    for (int i = 0; i < 3; i++){
        // Pass each student by reference
        calculateAverage(&students[i]);
    }

    // Print student details
    for (int i = 0; i < 3; i++){
        printf("Name: %s\n", students[i].name);
        printf("Grades: %d, %d, %d\n", students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        printf("Average: %.2f\n\n", students[i].average);
    }
    return 0;
}
