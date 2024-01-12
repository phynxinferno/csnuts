//
// Created by phoenix on 06/11/23.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string getLine() {
    string line;
    cin >> line;
    return line;
}

string reverse(string str, int position) {
    if(position == str.length() - 1) return str;
    char temp = str[position];
    str[position] = str[str.length() - position - 1];
    str[str.length() - position - 1] = temp;
    return reverse(str, position + 1);
}

bool isPalindrome(string str, string rev, int position) {
    if(position == str.length() - 1) return str[position] == rev[position];
    return (str[position] == rev[position]) ? isPalindrome(str, rev, position + 1) : false;
}

int main(int argc, char** argv) {
    string str = getLine();
    string rev = reverse(str, 0);
    cout << rev << endl;
    rev.erase(remove(rev.begin(), rev.end(), 'a'), rev.end());
    str.erase(remove(str.begin(), str.end(), 'a'), str.end());
    for(int i = 0; i < rev.length(); i++) {
        rev[i] = tolower(rev[i]);
        str[i] = tolower(str[i]);
    }
    cout << ((isPalindrome(str, rev, 0)) ? "true" : "false");

}