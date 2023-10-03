#include "iostream"
#include "list"
#include "chrono"

using namespace std;
using namespace chrono;
int main() {
    // Define a list of questions as strings
    list<string> questions = {
            // Variables and types
            "1In C++, variables must be declared before they can be used",
            "0A 'float' variable can store larger values than a 'double' variable",
            "1C++ supports both built-in data types (eg, int, char) and user-defined data types (e.g., classes)",

            // Constants
            "1A constant in C++ is declared using the 'const' keyword",
            "0A constant variable's value can be changed after it is initialized",
            "1The 'constexpr' keyword is used to declare constants that are computed at compile-time",

            // Operators
            "0The '==' operator is used for assignment, while '=' is used for comparison",
            "1The '&&' operator represents the logical AND operation",
            "0The '%' operator is used for exponentiation",

            // Basic Input/Output
            "1In C++, 'cin' is used for reading user input from the keyboard",
            "0The 'endl' manipulator in C++ is used to clear the screen",
            "1The '<<' operator is used to send output to the console using 'cout'",

            // Control Structures
            "1A 'for' loop is commonly used when you know the number of iterations in advance",
            "0The 'break' statement can only be used inside loops",
            "1The 'switch' statement can be used to make decisions based on the value of an expression",

            // Functions
            "1A function in C++ can have parameters that are used to pass data into the function",
            "0A function with the 'void' return type cannot return any value",
            "1Function prototypes are used to declare a function's signature before it is defined",

            // Overloads and templates
            "1Function overloading allows you to define multiple functions with the same name but different parameter lists",
            "0Templates in C++ are used to create concrete types with specific data members and methods",
            "1The Standard Template Library (STL) in C++ provides a collection of template classes and functions for common data structures and algorithms",

            // Name visibility
            "1In C++, variables declared inside a function are usually only visible within that function's scope",
            "0Global variables can be accessed and modified from any part of the program",
            "1C++ supports the concept of namespaces to avoid naming conflicts between different parts of the code",

            // Challenge problems
            "0In C++, a variable's type is written after its identifier",
            "1A c-style array declaration puts square brackets on the variable name",
            "0In C++, you must add a using statement before using a function from a certain namespace",
    };

    // Welcome message and instructions
    cout << "Welcome to Phoenix's Epic Fun ICS Quiz ft. additional game-like features!!!!!!!" << endl
         << "This quiz is about the ICS 4U course." << endl
         << "Good luck! Your time starts now." << endl << endl;

    // Start timing
    auto start = system_clock::now();

    int score = 0;

    // Loop through each question in the list
    for (const string &question : questions) {
        // Extract the question text (substring from index 1 to the end)
        cout << question.substr(1, question.length()) << ". (t)rue or (f)alse?" << endl;

        string cein;
        cin >> cein;

        // Check if the user's answer (t or f) matches the expected answer (1 or 0)
        if ((tolower(cein.at(0)) == 't') == (question.at(0) == '1')) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect!" << endl;
        }
    }

    // Calculate the elapsed time
    duration<double> elapsed_seconds = system_clock::now() - start;

    // Display the quiz results
    cout << "Thanks for playing. You got " << score << "/" << questions.size() << " correct in " << elapsed_seconds.count() << " seconds." << endl;

    return 0;
}