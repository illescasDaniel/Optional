//
//  main.cpp
//  Optional
//
//  Created by Daniel Illescas Romero on 06/07/2017.
//  Copyright © 2017 Daniel Illescas Romero. All rights reserved.
//

#include <iostream>
#include "Optional.hpp"

using namespace evt;
using namespace std;

// When the return type is an Optional you can return a value of the internal type or null
Optional<string> test(bool testing) {
	string test("daniel");
	if (testing) { return nullptr; }
	else { return test; }
}

int main() {
	
	string originalName = "hi";
	
	Optional<string> name {std::move(originalName)};
	cout << name.orEmpty() << endl;
	cout << name << endl;
	
	cout << "Original name: " << originalName << endl;
	
	// Calling methods
	cout << name.orEmpty().length() << endl;
	
	if (name) {
		cout << "Lol" << endl;
	}
	
	string otherName = name;
	
	cout << otherName << endl;
	
	cout << test(0).valueOr("null") << endl;
	
	Optional<int> number1 {1};
	Optional<int> number2 {2};
	
	cout << *number1 + *number2 << endl;
	
	cout << boolalpha << (number1 == number2) << endl;
	
	number1 = number2;
	
	cout << number1 << " " << number2 << endl;
	
	number2 = 100;
	
	cout << number1 << " " << number2 << endl;
	
	//
	
	Optional<int> test{10};
	cout << test << endl;
	
	Optional<int> test2{test};
	cout << test2 << endl;
	
	cout << (test2 == 10) << endl;
	
	if (test2.isNotNull()) {
		cout << "not null!" << endl;
	}
	
	cout << (test2 == nullptr) << endl;
	test2 = nullptr;
	// throw exception: cout << (test2 == 10) << endl;
}
