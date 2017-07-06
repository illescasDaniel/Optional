# Optional

[![Version](https://img.shields.io/badge/version-1.0-blue.svg)](https://github.com/illescasDaniel/Optional/releases)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg?maxAge=2592000)](https://github.com/illescasDaniel/Optional/blob/master/LICENCE)

A class to manage an optional value; an object of the class can be either nullptr or the original value.

Class Structure
----
```c++
// Constructors
Optional(const std::nullptr_t& value = nullptr)
Optional(const Type& value)

// Returns the original value or nullptr in case the value is not initialised
inline Type valueOr(const Type& other)

inline bool isNull() const
inline bool isNotNull() const

// You can use the value with an ostream like "cout"; if the value is null, it will return an empty osstream
friend std::ostream& operator<<(std::ostream& os, const Optional& optionalValue)
```
**Note:** additionally, an "OldOptional" class is included in case it has to be used in older C++ versions.
