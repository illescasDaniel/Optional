# Optional

[![Version](https://img.shields.io/badge/version-1.2-green.svg)](https://github.com/illescasDaniel/Optional/releases)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg?maxAge=2592000)](https://github.com/illescasDaniel/Optional/blob/master/LICENCE)

A class to manage an optional value; an object of the class can be either nullptr or the original value.

Class Structure
----
```c++
// Constructors
Optional(const std::nullptr_t& value = nullptr)
Optional(const Type& value)

// Return the original value or nullptr in case the object is not initialised to a non-null value
inline Type valueOr(const Type& other)

// Return the original value or an empty string in case the object is not initialised
inline Type orEmpty()

inline bool isNull() const
inline bool isNotNull() const

Optional& operator=(const Optional& other)
Optional& operator=(const Type& value)

// Return the internal value
inline Type& operator*() const
inline Type& value() const

// Compare the internal values
inline bool operator==(const Optional& other) const
inline bool operator!=(const Optional& other) const

// You can use the value with an ostream like "cout"; if the value is null, it will return an empty std::ostream
friend std::ostream& operator<<(std::ostream& os, const Optional& optionalValue)
```
