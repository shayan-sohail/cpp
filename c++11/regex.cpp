#include <iostream>
#include <regex>
#include <string>

/*
std::regex: Defines a regular expression pattern.
std::smatch: Holds the results of a match search in a string.
std::regex_search: Searches a string for a pattern match.
std::regex_match: Checks if an entire string matches a pattern.
std::regex_replace: Replaces parts of a string that match a pattern with a new value.
*/

// https://godbolt.org/z/o1a6E4eWd

int main() {
    // Define a regular expression pattern
    std::regex pattern(R"(\d{3}-\d{2}-\d{4})"); // Matches a pattern like 123-45-6789 (e.g., a Social Security Number)

    // Text to search
    std::string text = "My SSN is 123-45-6789.";

    // Search for the pattern
    std::smatch match;
    if (std::regex_search(text, match, pattern)) {
        std::cout << "Found: " << match.str() << std::endl;
    }

    // Check if the entire string matches the pattern
    if (std::regex_match("123-45-6789", pattern)) {
        std::cout << "Exact match found for SSN format!" << std::endl;
    }

    // Replace SSN with XXX-XX-XXXX
    std::string replaced = std::regex_replace(text, pattern, "XXX-XX-XXXX");
    std::cout << "Text after replacement: " << replaced << std::endl;

    // A complex pattern with capturing groups
    std::regex email_pattern(R"((\w+)(@)(\w+\.\w+))"); // Matches an email pattern like example@example.com
    std::string email_text = "Contact me at example@example.com.";

    // Extract and print parts of the matched email
    if (std::regex_search(email_text, match, email_pattern)) {
        std::cout << "User: " << match[1].str() << ", Domain: " << match[3].str() << std::endl;
    }

    return 0;
}
