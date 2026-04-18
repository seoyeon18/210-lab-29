// Include necessary headers for file handling, map, array, list, string, and output
#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
using namespace std;
// Define a function to simulate caffeine effects over time
    // Parameters: map of people, number of time periods
void simulateCaffeineEffects(map<string, array<list<int>, 3>>& people, int timePeriods) {
    // Begin simulation loop
    for (int t = 1; t <= timePeriods; t++) {
        // Iterate through each person
        for (auto& person : people) {
            // Get the most recent values
            // Iterate through each person in the map
                // Get the most recent alertness, heart rate, and fatigue values
                int alertness = person.second[0].back();
                int heartRate = person.second[1].back();
                int fatigue = person.second[2].back();
            // Update the values based on simple caffeine effect rules
            // alertness may go up during early periods
            // heart rate may increase slightly
            // fatigue may go down at first
            // later, alertness may drop and fatigue may rise again
            if (t <= 5) {
                alertness += 2;
                heartRate += 1;
                fatigue -= 1;
            } else if (t <= 10) {
                alertness += 1;
                fatigue -= 1;
            } else {
                alertness -= 1;
                heartRate -= 1;
                fatigue += 2 ;
            }

            if (alertness < 0) alertness = 0;
            if (heartRate < 0) heartRate = 0;
            if (fatigue < 0) fatigue = 0;
                // Add the updated values to the correct lists
            person.second[0].push_back(alertness);
            person.second[1].push_back(heartRate);
            person.second[2].push_back(fatigue);
            // Print the updated state for that time period
            cout << "\nTime Period " << t << endl;
            for (const auto& person : people) {
            cout << person.first << " | ";
            cout << "Alertness: " << person.second[0].back() << ", ";
            cout << "Heart Rate: " << person.second[1].back() << ", ";
            cout << "Fatigue: " << person.second[2].back() << endl;
        }
        }
    }
}

// Define main function
int main() {
    // Initialize a map to store person information
    // Each key will be a person's name
        map<string, array<list<int>, 3>> people;
    // Open an external file to read the starting data
        ifstream inputFile("data.txt");
        // If file does not open, print an error message and exit
        if (!inputFile) {
        cout << "Error: Could not open data file." << endl;
        return 1;
    }
    // Read data from file and populate map
        // For each line, extract the person's name, alertness, heart rate, and fatigue
        // Insert each value into the correct list in the array for that person
    string name;
    int alertness, heartRate, fatigue;

    while (inputFile >> name >> alertness >> heartRate >> fatigue) {
        people[name][0].push_back(alertness);
        people[name][1].push_back(heartRate);
        people[name][2].push_back(fatigue);
    }
    // Close the file
    inputFile.close();
    // Display the initial state of the people in the simulation
    for (const auto& person : people) {
        cout << person.first;
        cout << "Alertness: " << person.second[0].back();
        cout << "Heart Rate: " << person.second[1].back();
        cout << "Fatigue: " << person.second[2].back();
    }
    // Begin a time-based simulation
        // For 25 time periods
            simulateCaffeineEffects(people, 25);

            return 0;
        }
    
