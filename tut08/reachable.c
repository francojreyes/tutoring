
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"
#include "Queue.h"
#include "Stack.h"

static Set reachable(Graph g, Vertex src);
static Graph createGraph();

int main(void) {
    Graph g = createGraph();

    Vertex vertices[4] = {0, 5, 1, 6};
    for (int i = 0; i < 4; i++) {
        Set r = reachable(g, vertices[i]);
        printf("Reachable from %d: ", vertices[i]);
        SetShow(r);
        printf("\n");
        SetFree(r);
    }

    GraphFree(g);
}

static Set reachable(Graph g, Vertex src) {
    Set reachable = SetNew();
    return reachable;
}

static Graph createGraph() {
    Graph g = GraphNew(10);
    GraphInsertEdge(g, (Edge){0, 1, 1});
    GraphInsertEdge(g, (Edge){0, 2, 1});
    GraphInsertEdge(g, (Edge){0, 3, 1});
    GraphInsertEdge(g, (Edge){2, 1, 1});
    GraphInsertEdge(g, (Edge){2, 3, 1});
    GraphInsertEdge(g, (Edge){2, 4, 1});
    GraphInsertEdge(g, (Edge){2, 5, 1});
    GraphInsertEdge(g, (Edge){3, 0, 1});
    GraphInsertEdge(g, (Edge){3, 4, 1});
    GraphInsertEdge(g, (Edge){4, 2, 1});
    GraphInsertEdge(g, (Edge){4, 5, 1});
    GraphInsertEdge(g, (Edge){4, 7, 1});
    GraphInsertEdge(g, (Edge){4, 8, 1});
    GraphInsertEdge(g, (Edge){5, 1, 1});
    GraphInsertEdge(g, (Edge){6, 5, 1});
    GraphInsertEdge(g, (Edge){6, 7, 1});
    GraphInsertEdge(g, (Edge){6, 9, 1});
    GraphInsertEdge(g, (Edge){7, 4, 1});
    GraphInsertEdge(g, (Edge){7, 5, 1});
    GraphInsertEdge(g, (Edge){7, 8, 1});
    GraphInsertEdge(g, (Edge){8, 7, 1});
    GraphInsertEdge(g, (Edge){9, 7, 1});
    GraphInsertEdge(g, (Edge){9, 8, 1});
    return g;
}
