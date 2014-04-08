//
//  RDConnectedComponent.cpp
//  DegreeAvoidance
//
//  Created by Stephen Dailey on 4/7/14.
//  Copyright (c) 2014 Stephen Dailey. All rights reserved.
//

#include "RDConnectedComponent.h"

RDConnectedComponent::RDConnectedComponent()
{}

RDConnectedComponent::RDConnectedComponent(Vertex &v0)
{
    vertices = vector<Vertex>();
    vertices.insert(vertices.end(),Vertex(v0));
    Update();
}

int RDConnectedComponent::getRType()
{
    return rType;
}

vector<Vertex> RDConnectedComponent::getVertices()
{
    return vertices;
}

void RDConnectedComponent::Update()
{
    vector<int> ds = getDegreeSequence();
    if(ds.size() == 1)
    {
        if(ds[0] == 0)
            rType = singleton3;
        else if(ds[0] == 1)
            rType = singleton2;
        else if(ds[0] == 2)
            rType = singleton1;
    }
    else if(ds.size() == 2)
    {
        if(ds[0] == 1)
            rType = path22;
        else if(ds[1] == 2)
            rType = path11;
        else
            rType = path21;
    }
    else if(ds.size() > 2)
    {
        int i;
        for(i = 0; i < ds.size(); i++)
        {
            if(ds[i] != 2)
                break;
        }
        
        if(i == ds.size() - 2)		//all twos and 2 ones 	(2,2) path
            rType = path22;
        else if(i == ds.size() - 1)	//all twos and 1 ones 	(2,1) path
            rType = path21;
        else if(i == ds.size())		//all twos				(1,1) path
        {
            if(edges.size() == i)	//Cycle
                rType = cycle;
            else
                rType = path11;
        }
    }
//    calculatedPathsandCycles();
//    calculateConnectors();
//    calculateInternalEdges();
}


const RDConnectedComponent& RDConnectedComponent::operator=(const RDConnectedComponent &copy)
{
    cout << vertices[0];
    return *this;
}

ostream& operator<<(ostream& out, RDConnectedComponent& obj)
{
    switch (obj.rType) {
        case 0:
            out << "singleton3";
            break;
        case 1:
            out << "singleton2";
            break;
        case 2:
            out << "singleton1";
            break;
        case 3:
            out << "path11";
            break;
        case 4:
            out << "path21";
            break;
        case 5:
            out << "path22";
            break;
        case 6:
            out << "cycle";
            break;
        default:
            break;
    }
    out << " " << obj.vertices[0];
	return out;
}