//
//  GraphComponents.h
//  DegreeAvoidance
//
//  Created by Stephen Dailey on 4/1/14.
//  Copyright (c) 2014 Stephen Dailey. All rights reserved.
//

#ifndef DegreeAvoidance_GraphComponents_h
#define DegreeAvoidance_GraphComponents_h


#include <iostream>
#include <vector>

using namespace std;

class Vertex
{
private:
    int id;
public:
    Vertex () {};
    Vertex (int id);
    Vertex(const Vertex &copy);
    const Vertex &operator=(const Vertex &copy);
    bool operator==(Vertex &other) const;
    int getID();
    friend ostream& operator<<(ostream& out, Vertex& obj);
};

class Edge
{
private:
    Vertex* vi;
    Vertex* vj;
    
public:
    Vertex* first();
    Vertex* last();
    
    Edge () {};
    Edge (Vertex* a, Vertex* b);
    Edge(const Edge &copy);
    const Edge &operator=(const Edge &copy);
    bool operator==(Edge &other) const;
    friend ostream& operator<<(ostream& out, Edge& obj);
};

ostream& operator<<(ostream& out, Vertex& obj);

ostream& operator<<(ostream& out, Edge& obj);

class Graph
{    
protected:
    vector<Vertex> vertices;
    vector<Edge> edges;
public:
    Graph();        //Default Constructor
    Graph(int numberOfVertices);
    Graph(vector<Vertex> vertices, vector<Edge> edges);
    
    vector<Vertex> getVertices();
    vector<Edge> getEdges();
    vector<int> getDegreeSequence();
    
    Vertex& getVertex(int);
    void addEdge(Vertex* from, Vertex* to);
    void removeEdge(Vertex* from, Vertex *to);
    void removeEdge(Edge e);
    
    friend ostream& operator<<(ostream& out, Graph& obj);
};


#endif
