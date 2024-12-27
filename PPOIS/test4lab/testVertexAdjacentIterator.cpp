#include "gtest/gtest.h"
#include "OrientedGraph.cpp"
TEST(test_vertexAdjacentIterator_class, vertexAdjacentIterator_test) {
	OrientedGraph<string> graph;
	graph.addVertex("a");
	graph.addVertex("b");
	graph.addVertex("c");
	graph.addEdge("a", "b");
	graph.addEdge("b", "c");
	graph.addEdge("c", "c");
	string expectedOutput = "";

	// смежность
	for (auto it = graph.begin_adjacentVertices("b"); it != graph.end_adjacentVertices("b"); ++it)
	{
		expectedOutput+= *it;
	}

	EXPECT_EQ(expectedOutput, "ac");

}