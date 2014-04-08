//
//  Graph.h
//  DegreeAvoidance
//
//  Created by Stephen Dailey on 4/1/14.
//  Copyright (c) 2014 Stephen Dailey. All rights reserved.
//

#ifndef DegreeAvoidance_RemainingDegreeGraph_h
#define DegreeAvoidance_RemainingDegreeGraph_h

#include "GraphComponents.h"
#include "RDConnectedComponent.h"
#include <vector>
using namespace std;

class RemainingDegreeGraph: Graph{
private:
    //3 dimensional vector
    //1st dimension: by rType
    //2nd dimension: different sizes
    //3rd dimension: components of same size
    vector<vector<vector<RDConnectedComponent>>> connectedComponents;
public:
    RemainingDegreeGraph(int vertices);
    vector<Vertex> getVertices();
    friend ostream& operator<<(ostream& out, RemainingDegreeGraph& obj);
};

#endif
