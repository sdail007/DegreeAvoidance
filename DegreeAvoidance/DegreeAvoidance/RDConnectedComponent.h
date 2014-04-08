//
//  RDConnectedComponent.h
//  DegreeAvoidance
//
//  Created by Stephen Dailey on 4/7/14.
//  Copyright (c) 2014 Stephen Dailey. All rights reserved.
//

#ifndef __DegreeAvoidance__RDConnectedComponent__
#define __DegreeAvoidance__RDConnectedComponent__

#include <iostream>
#include <vector>
#include "GraphComponents.h"

enum componentType{
    singleton3,
    singleton2,
    singleton1,
    path11,
    path21,
    path22,
    cycle
};

class RDConnectedComponent: Graph{
private:
    componentType rType;
public:
    RDConnectedComponent();
    RDConnectedComponent(Vertex &v0);
    vector<Vertex> getVertices();
    int getRType();
    void Update();
    
    const RDConnectedComponent &operator=(const RDConnectedComponent &copy);
    friend ostream& operator<<(ostream& out, RDConnectedComponent& obj);
};

#endif /* defined(__DegreeAvoidance__RDConnectedComponent__) */
