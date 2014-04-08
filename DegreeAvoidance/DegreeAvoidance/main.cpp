//
//  main.cpp
//  DegreeAvoidance
//
//  Created by Stephen Dailey on 4/1/14.
//  Copyright (c) 2014 Stephen Dailey. All rights reserved.
//

#include <iostream>
#include "GraphComponents.h"
#include "RemainingDegreeGraph.h"
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{

	RemainingDegreeGraph myGraph = RemainingDegreeGraph(5);
    cout << myGraph << endl;
	return 0;
}

