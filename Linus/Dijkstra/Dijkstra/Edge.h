#pragma once

class Edge {
public:

	int distance{};

	class Vertex* edgeToVert;

	Vertex* prevVert = nullptr;

	Edge(Vertex* nextVert) {
		edgeToVert = nextVert;
	}

};