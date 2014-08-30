//
//  FirstClass.cpp
//  TestTwo
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "FirstClass.h"

#include <iostream>

using namespace std;

FirstClass::FirstClass() {
	
}

void FirstClass::addNum(int numOne, int numTwo) {
	int sum = numOne + numTwo;
	cout << sum << endl;
}