#include <iostream>
#include <queue>
using namespace std;

typedef struct FEdge
{
	int Start;
	int End;
	int Cost;

	FEdge(int NewStart, int NewEnd, int NewCost) : Start(NewStart), End(NewEnd), Cost(NewCost) { }
} FEdge;

struct COMP
{
	bool operator()(FEdge* A, FEdge* B)
	{
		return A->Cost > B->Cost;
	}
};

int V, E, Answer = 0;
int Start, End, Cost;
int Parent[10'001];
priority_queue<FEdge*, vector<FEdge*>, COMP> PQ;

int GetParent(int VertexNum)
{
	if (Parent[VertexNum] == VertexNum) return VertexNum;

	Parent[VertexNum] = GetParent(Parent[VertexNum]);

	return Parent[VertexNum];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V >> E;

	for (int i = 1; i <= V; ++i)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < E; ++i)
	{
		cin >> Start >> End >> Cost;
		FEdge* Edge = new FEdge(Start, End, Cost);
		PQ.push(Edge);
	}

	while (PQ.empty() == false)
	{
		FEdge* Edge = PQ.top(); PQ.pop();

		Start = Edge->Start;
		End = Edge->End;
		Cost = Edge->Cost;

		delete Edge;

		int StartParent = GetParent(Start);
		int EndParent = GetParent(End);
		if (StartParent == EndParent) continue;

		Parent[StartParent] = EndParent;
		Answer += Cost;
	}

	cout << Answer << '\n';

	return 0;
}