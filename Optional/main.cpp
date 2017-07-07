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
	
	Optional<string> name {"hi"};
	cout << name.orEmpty() << endl;
	cout << name << endl;
	
	// Calling methods
	cout << name.orEmpty().length() << endl;
	
	if (name.isNotNull()) {
		cout << "Lol" << endl;
	}
	
	cout << test(0).valueOr("null") << endl;
	
	Optional<int> number1 {1};
	Optional<int> number2 {2};
	
	cout << *number1 + *number2 << endl;
	
	cout << boolalpha << (number1 == number2) << endl;
	
	number1 = number2;
	
	cout << number1 << " " << number2 << endl;
	
	number2 = 100;
	
	cout << number1 << " " << number2 << endl;
}
