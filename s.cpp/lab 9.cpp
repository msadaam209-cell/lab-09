#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Writing data to file
    ofstream fout("data.txt");   // Create and open file

    fout << "Alice 20 3.5\n";
    fout << "Bob 22 3.7\n";

    fout.close();   // Close file after writing

    // Reading data from file
    ifstream fin("data.txt");

    string name;
    int age;
    float gpa;

    while (fin >> name >> age >> gpa) {
        cout << name << " " << age << " " << gpa << endl;
    }

    fin.close();  // Close file after reading

    return 0;
}

