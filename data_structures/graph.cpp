/*
copyright 2021, Oleksandr Chastukhin

Graph is a data structure that shows relations between data. To represnt the graph in the code we can use a martix in which a column and row corresponds to the relation with 2 items. The matrix elements represent a relation between items and values can be 0 or 2 if crossed items have the relation.

graph jargon:
vertex - this is one added item
edge - this a string, relation between items

how to present a graph in the code?
- adjacency matrix

the example:
  1 2 3 - vertexes for first any item
1 0 0 0
2 1 0 0 - edges
3 0 1 1
|- vertexes for second any item

- list

the example:
item1 : {edges - links to other items}
item2 : {edges - links to other items}
item3 : {edges - links to other items}
  |- vertexes

below there in my pesonal implementation of a graph. the underlying structure is a list.
*/

#include <iostream>
#include <list>
#include <string>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::set;

struct vertex final
{
    list<vertex*> edges;
    string data;
};

struct graph final
{
    set<vertex> vertexes;

    // it creates a relation between two vertexes
    /*void add_edge(vertex* const item1, vertex* const item2)
    {
        vertexes[&item1].edges.push_back(item2);
        vertexes[&item2].edges.push_back(item1);
    }*/

    // remove a relation between two vertexes
    void remove_edge(vertex* const item1, vertex* const item2)
    {}
};


int main()
{
    graph world_map;
    return 0;
}
