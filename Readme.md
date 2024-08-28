## cpp

This repository is a comprehensive resource for C++ programming, covering various C++ standards from C++11 to C++23. Each section will delve into the key features and improvements introduced in that particular standard.

### C++11

- **auto:** Automatically deduces the type of a variable from its initializer, making code more concise and readable.
- **decltype:** Determines the declared type of an expression.
- **nullptr:** Type-safe null pointer value in C++.
- **enum:** Better type safety and scoping compared to traditional C++ enums.
- **template_alias:** Alias templates allow you to create type aliases using templates, simplifying complex types and improving code readability.
- **uniform_initialization:** Offers a consistent syntax for initializing variables of any type and prevents potential issues like narrowing conversions and the most vexing parse problem.
- **initializer_list:** Allows the initialization of containers and objects with a list of values using a consistent and intuitive syntax.
- **range_based_for_loops:** Provide a concise and readable way to iterate over elements in a container without the need for explicit iterators or index variables.
- **lambdas**: Allows the creation of anonymous, inline functions that can capture variables from their surrounding scope.
- **default_delete**: Allows developers to explicitly specify or prevent the compiler from generating certain special member functions.
- **constexpr**: Allows functions and variables to be evaluated at compile time, ensuring they are constant expressions.
- **trailing_return_type**: Allows you to specify the return type of a function after the parameter list, using the auto keyword and -> syntax.
- **rvalue_reference**: Allows the distinction between lvalues and rvalues, enabling move semantics for efficient resource transfer.
- **delegating_constructor**: Allows a constructor to call another constructor of the same class, enabling code reuse and simplifying initialization.
- **static_assert**: Performs compile-time assertions, ensuring that certain conditions or properties are met during compilation, particularly useful for type checking.
- **alignof_alignas**: alignof queries the alignment requirements of a type, while alignas specifies custom alignment for types or variables.
- **noexcept**: Specifies that a function will not throw exceptions, enabling optimizations and providing stronger exception safety guarantees.

- **array**: Fixed-size container that represents arrays with a known constant size, providing the advantages of both static arrays and standard library containers.
- **unordered_map**: Associative container (Tree/Hash/Fast Lookup) that stores key-value pairs with fast average-time complexity for lookups, insertions, and deletions, using a hash table.
- **unordered_set**: Associative container that stores unique elements in no particular order, providing fast average-time complexity for lookups, insertions, and deletions using a hash table.
- **unordered_multimap**: Associative container that stores key-value pairs, allowing multiple pairs with the same key, and provides average constant-time complexity for operations due to its underlying hash table.
- **unordered_multiset**: Associative container that stores elements, allowing multiple occurrences of the same element, and provides average constant-time complexity for operations using a hash table.
- **algorithms**: std::all_of, std::any_of, std::none_of, std::copy_n, std::iota, and std::move.

### C++14

### C++17

### C++20

### C++23
