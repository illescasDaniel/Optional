/*
 The MIT License (MIT)
 
 Copyright (c) 2017 Daniel Illescas Romero <https://github.com/illescasDaniel>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#pragma once

#include <cstddef>
#include <ostream>
#include <stdexcept>

#if (__cplusplus > 201103L)
#define CONSTEXPR constexpr
#else
#define CONSTEXPR
#endif

namespace evt {
	
	namespace internalEVT {
		struct badAccess: public std::runtime_error {
			badAccess(): std::runtime_error("Null pointer found") {}
		};
	}
	
	template <typename Type>
	class Optional {
		
	private:
		Type* value_ { nullptr };
		
		void freePointer() {
			if (this->isNotNull()) {
				delete value_;
				value_ = nullptr;
			}
		}
		
	public:
		
		CONSTEXPR Optional(const Optional& other) { this->operator=(other); }
		CONSTEXPR Optional(std::nullptr_t value = nullptr) { this->value_ = value; }
		CONSTEXPR Optional(const Type& value) { this->value_ = new Type{value}; }
		CONSTEXPR Optional(Type&& value) { this->value_ = new Type{std::move(value)}; }
		
		CONSTEXPR Type valueOr(const Type& other) const { return (this->isNotNull()) ? this->value() : other; }
		CONSTEXPR Type orEmpty() const { return (this->isNotNull()) ? this->value() : Type{}; }
		CONSTEXPR bool isNull() const { return value_ == nullptr; }
		CONSTEXPR bool isNotNull() const { return value_ != nullptr; }
		CONSTEXPR bool operator==(const Optional& other) const { return value_ == other.value_; }
		CONSTEXPR bool operator!=(const Optional& other) const { return value_ != other.value_; }
		CONSTEXPR bool operator==(const Type& otherValue) const noexcept { return this->isNotNull() ? (*value_ == otherValue) : false; }
		CONSTEXPR bool operator!=(const Type& otherValue) const noexcept { return this->isNotNull() ? (*value_ != otherValue) : false; }
		CONSTEXPR bool operator==(std::nullptr_t none) const noexcept { return value_ == none; }
		CONSTEXPR bool operator!=(std::nullptr_t none) const noexcept { return value_ != none; }
		CONSTEXPR Type& operator*() const { return *value_; }
		CONSTEXPR Type& value() const {
			if (this->isNull()) { throw internalEVT::badAccess(); }
			return *value_;
		}
		CONSTEXPR explicit operator bool() const { return this->isNotNull(); }
		CONSTEXPR operator Type() const { return this->orEmpty(); }
		
		CONSTEXPR friend std::ostream& operator<<(std::ostream& os, const Optional& optionalValue) {
			return os << optionalValue.orEmpty();
		}
		
		CONSTEXPR Optional& operator=(const Optional& other) {
			freePointer();
			if (other.isNull()) {
				this->value_ = nullptr;
			} else {
				this->value_ = new Type{other.value()};
			}
			
			return *this;
		}
		
		CONSTEXPR Optional& operator=(const Type& value) {
			if (this->isNull()) {
				this->value_ = new Type{value};
			} else {
				*this->value_ = value;
			}
			return *this;
		}
		
		CONSTEXPR Optional& operator=(Type&& value) {
			if (this->isNull()) {
				this->value_ = new Type{std::move(value)};
			} else {
				*this->value_ = std::move(value);
			}
			return *this;
		}
		
		CONSTEXPR Optional& operator=(std::nullptr_t none) {
			if (none == nullptr) {
				freePointer();
				std::cout << this->isNotNull() << std::endl;
			}
			return *this;
		}
		
		~Optional() {
			if (this->isNotNull()) {
				delete value_;
				value_ = nullptr;
			}
		}
	};
}
