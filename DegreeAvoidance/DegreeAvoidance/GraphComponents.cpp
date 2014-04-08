//
//  GraphComponents.cpp
//  DegreeAvoidance
//
//  Created by Stephen Dailey on 4/1/14.
//  Copyright (c) 2014 Stephen Dailey. All rights reserved.
//

#include "GraphComponents.h"

bool sortHightoLow (int i,int j) { return (i>j); }

Vertex::Vertex (int id):id(id)
{
}
Vertex::Vertex(const Vertex& copy)
{
    id = copy.id;
}
const Vertex& Vertex::operator=(const Vertex &copy)
{
    id = copy.id;
    return *this;
}

bool Vertex::operator==(Vertex &other) const
{
    return id == other.id;
}

int Vertex::getID()
{
    return id;
}

Edge::Edge(Vertex *a, Vertex *b)
{
    vi = a; vj = b;
}
Edge::Edge(const Edge &copy)
{
    vi = copy.vi;
    vj = copy.vj;
}
Vertex* Edge::first(){return vi;}
Vertex* Edge::last(){return vj;}
const Edge& Edge::operator=(const Edge &copy)
{
    vi = copy.vi;
    vj = copy.vj;
    return *this;
}

bool Edge::operator==(Edge &other) const
{
    return (vi == other.first() && vj == other.last()) || (vj == other.first() && vi == other.last());
}

ostream& operator<<(ostream& out, Vertex& obj)
{
	out << obj.id;
	return out;
}

ostream& operator<<(ostream& out, Edge& obj)
{
	out << "{" << *(obj.vi) << "," << *(obj.vj) << "} ";
	return out;
}


Graph::Graph(){}    //Default Constructor
Graph::Graph(int numberOfVertices)
{
    vertices = vector<Vertex>();
    edges = vector<Edge>();
    for(int i = 0; i < numberOfVertices; i++)
    {
        vertices.push_back(Vertex(i+1));
    }
}

Graph::Graph(vector<Vertex> vertices, vector<Edge> edges)
{
    
}

vector<Vertex> Graph::getVertices()
{
    return vertices;
}

vector<Edge> Graph::getEdges()
{
    return edges;
}

vector<int> Graph::getDegreeSequence()
{
    vector<int> degreeSequence = vector<int>();
    for(int i = 0; i < vertices.size(); i++)
    {
        int degree = 0;
        for(int j = 0; j < edges.size(); j++)
        {
            if(vertices[i].getID() == edges[j].first()->getID() ||
               vertices[i].getID() == edges[j].last()->getID())
            {
                degree+=1;
            }
        }
        degreeSequence.push_back(degree);
    }
    std::sort(degreeSequence.begin(), degreeSequence.end(), sortHightoLow);
    return degreeSequence;
}

Vertex& Graph::getVertex(int vertexNumber)
{   
    for(vector<Vertex>::iterator i = vertices.begin(); i != vertices.end(); ++i)
    {
        if((i->getID()) == vertexNumber)
        {
            return (*i);
        }
    }
    return *(new Vertex(-1));      //If reaches here, fail and return invalid vertex
}

void Graph::addEdge(Vertex* from, Vertex* to)
{
    edges.push_back(Edge(from, to));
}

void Graph::removeEdge(Vertex* from, Vertex* to)
{
    removeEdge(Edge(from, to));
}

void Graph::removeEdge(Edge e)
{
    for(int i = 0; i < edges.size(); i++)
    {
        if (edges[i] == e) {
            edges.erase(edges.begin()+i);
            break;
        }
    }
}

ostream& operator<<(ostream& out, Graph& obj)
{
    out << "Graph: " << endl << "V: ";
    for(int i = 0; i < obj.vertices.size(); i++)
    {
        out << obj.vertices[i] << " ";
    }
    out << endl << "E: ";
    for(int i = 0; i < obj.edges.size(); i++)
    {
        out << obj.edges[i] << " ";
    }
	return out;
}

