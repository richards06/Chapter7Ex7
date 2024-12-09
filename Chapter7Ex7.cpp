/*
Program Title: Chapter7Ex7
Programmer: Josh Richards
Date:
Requirements:

Write a program that asks the user for a file name. Assume the file contains a series of numbers, each written on a separate line. The program should read the contents of the file into an array then display the following data:
• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool readFile(const string& fileName, vector<int>& numbers);
int findLowest(const vector<int>& numbers);
int findHighest(const vector<int>& numbers);
int calculateTotal(const vector<int>& numbers);
double calculateAverage(const vector<int>& numbers);

int main()
{
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    vector<int> numbers;
    if (!readFile(fileName, numbers)) {
        cout << "Error: Could not open the file or it contains invalid data.\n";
        return 1;
    }
    cout << "Lowest number: " << findLowest(numbers) << '\n';
    cout << "Highest number: " << findHighest(numbers) << '\n';
    cout << "Total of numbers: " << calculateTotal(numbers) << '\n';
    cout << "Average of numbers: " << calculateAverage(numbers) << '\n';

    return 0;
}

bool readFile(const string& fileName, vector<int>& numbers) {
    ifstream inputFile(fileName);
    if (!inputFile) {
        return false;
    }

    int number;
    while (inputFile >> number) {
        numbers.push_back(number);
    }
    inputFile.close();

    return !numbers.empty();
}

int findLowest(const vector<int>& numbers) {
    return *min_element(numbers.begin(), numbers.end());
}

int findHighest(const vector<int>& numbers) {
    return *max_element(numbers.begin(), numbers.end());
}

int calculateTotal(const vector<int>& numbers) {
    int total = 0;
    for (int num : numbers) {
        total += num;
    }
    return total;
}

double calculateAverage(const vector<int>& numbers) {
    int total = calculateTotal(numbers);
    return static_cast<double>(total) / numbers.size();
}