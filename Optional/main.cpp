//
//  main.cpp
//  Optional
//
//  Created by Daniel Illescas Romero on 06/07/2017.
//  Copyright © 2017 Daniel Illescas Romero. All rights reserved.
//

#include <iostream>
#include "Optional.hpp"
#include "OldOptional.hpp"

using namespace evt;
using namespace std;

// When the return type is an Optional you can return the type or null
Optional<string> test(bool testing) {
	string test = "daniel";
	if (testing) { return nullptr; }
	else { return test; }
}

int main() {
	
	Optional<string> name("hi");
	cout << name.valueOr("null") << endl;
	cout << name << endl;
	
	if (name.isNotNull()) {
		cout << "Lol" << endl;
	}
	
	cout << test(0).valueOr("null") << endl;
	
	// For older C++ versions
	OldOptional<int> number(10);
	cout << number << endl;
}
