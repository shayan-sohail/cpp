#include <iostream>
#include <filesystem>

/*
    `std::filesystem` was introduced in C++17 to provide tools for file system operations.

    Key Features:
    1. Path manipulation: Work with file and directory paths.
    2. File and directory operations: Create, delete, copy, and move files or directories.
    3. Querying file properties: Check if a file exists, get its size, and other metadata.
    4. Iteration over directories: Traverse through directories and their contents.

    Benefits:
    - Portable and standardized file system API.
    - Avoids platform-specific code for file operations.
*/

// https://godbolt.org/z/zG4M685vc

// Namespace alias to avoid long names
namespace fs = std::filesystem;

int main() {
    // Example 1: Working with paths
    fs::path filePath = "example.txt";
    std::cout << "File path: " << filePath << "\n";               // Output: example.txt
    std::cout << "File name: " << filePath.filename() << "\n";    // Output: example.txt
    std::cout << "File extension: " << filePath.extension() << "\n";  // Output: .txt

    // Example 2: Checking if a file exists
    if (fs::exists(filePath)) {
        std::cout << filePath << " exists.\n";
    } else {
        std::cout << filePath << " does not exist.\n";
    }

    // Example 3: Creating a directory
    fs::path dirPath = "example_dir";
    if (!fs::exists(dirPath)) {
        fs::create_directory(dirPath);  // Create a new directory
        std::cout << "Directory created: " << dirPath << "\n";    // Output: example_dir created
    }

    // Example 4: Iterating over files in a directory
    fs::path currentDir = fs::current_path();
    std::cout << "Files in current directory (" << currentDir << "):\n";
    for (const auto& entry : fs::directory_iterator(currentDir)) {
        std::cout << " - " << entry.path() << "\n";
    }

    // Example 5: Copying and removing files
    fs::path sourceFile = "source.txt";
    fs::path destinationFile = "destination.txt";

    // Copying the file
    if (fs::exists(sourceFile)) {
        fs::copy(sourceFile, destinationFile);
        std::cout << "File copied from " << sourceFile << " to " << destinationFile << "\n";
    } else {
        std::cout << sourceFile << " does not exist.\n";
    }

    // Removing a file
    if (fs::exists(destinationFile)) {
        fs::remove(destinationFile);
        std::cout << destinationFile << " has been removed.\n";
    }

    return 0;
}
