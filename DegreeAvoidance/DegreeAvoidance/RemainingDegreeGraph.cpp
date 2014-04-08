//
//  Graph.cpp
//  DegreeAvoidance
//
//  Created by Stephen Dailey on 4/1/14.
//  Copyright (c) 2014 Stephen Dailey. All rights reserved.
//

#include "RemainingDegreeGraph.h"

RemainingDegreeGraph::RemainingDegreeGraph(int numberOfVertices)
{
    vertices = vector<Vertex>();
    edges = vector<Edge>();
    
    connectedComponents = vector<vector<vector<RDConnectedComponent>>>();
    
    for(int i = 0; i < 7; i++)
    {
        connectedComponents.push_back(vector<vector<RDConnectedComponent>>());
    }
    vector<RDConnectedComponent> temp = vector<RDConnectedComponent>();
    connectedComponents[0].push_back(temp);
    
    for(int i = 0; i < numberOfVertices; i++)
    {
        Vertex temp = Vertex(i+1);
        vertices.push_back(temp);
        RDConnectedComponent rdcc = RDConnectedComponent(temp);
        connectedComponents[rdcc.getRType()][0].push_back(rdcc);
    }
}

vector<Vertex> RemainingDegreeGraph::getVertices()
{
    return vertices;
}

ostream& operator<<(ostream& out, RemainingDegreeGraph& obj)
{
    out << "Remaining Degree Graph: " << endl << "V: ";
    for(int i = 0; i < obj.vertices.size(); i++)
    {
        out << obj.vertices[i] << " ";
    }
    out << endl << "E: ";
    for(int i = 0; i < obj.edges.size(); i++)
    {
        out << obj.edges[i] << " ";
    }
    out << endl << "CC: ";
    for(int i = 0; i < 7; i++)
    {
        out << "[";
        for(int j = 0; j < obj.connectedComponents[i].size(); j++)
        {
            out << "[";
            for(int k = 0; k < obj.connectedComponents[i][j].size(); k++)
            {
                out <<obj.connectedComponents[i][j][k] << ",";
            }
            out << "]";
        }
        out << "]" << endl;
    }
	return out;
}