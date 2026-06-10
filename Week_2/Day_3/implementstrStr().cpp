#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {

    if (needle.length() == 0)
        return 0;

    if (needle.length() > haystack.length())
        return -1;

    int i = 0;

    while (i < haystack.length()) {

        if (i + needle.length() > haystack.length())
            break;

        int j = 0;

        while (j < needle.length()) {

            if (needle[j] != haystack[i + j])
                break;

            j++;
        }

        if (j == needle.length())
            return i;

        i++;
    }

    return -1;
}

int main() {
    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    cout << "Result: " << strStr(haystack, needle) << endl;

    return 0;
}