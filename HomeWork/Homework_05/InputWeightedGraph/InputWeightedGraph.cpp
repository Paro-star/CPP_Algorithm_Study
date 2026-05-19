//
// Created by duong on 5/19/2026.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e, n;
    cin >> v >> e >> n;
    set<pair<int, string>> VertexList;
    unordered_map<string, unordered_map<string, int>> GRAPH;

    for (int i = 0; i < v; i++) {
        string VertexName;
        cin >> VertexName;
        VertexList.insert({i, VertexName});
    }

    for (int i = 0; i < e ; i++) {
        int Weight;
        string From, To;
        cin >> From >> To >> Weight;

        GRAPH[From][To] = Weight;
    }

    int Choice;
    for (int i = 0; i < n; i++) {
        cin >> Choice;
        if (Choice == 1) {
            string From, To;
            cin >> From >> To;
            // In Trong So
            if (GRAPH.count(From) && GRAPH[From].count(To))
                cout << GRAPH[From][To] << endl;
            else
                cout << "FALSE" << endl;
        }
        else if (Choice == 2) {
            string Vertex;
            cin >> Vertex;
            int NearVertex = 0;

            // Xuat ra trong so cua cac dinh ke voi Vertex
            for (auto x : VertexList) {
                if (GRAPH.count(Vertex) && GRAPH[Vertex].count(x.second)) {
                    cout << GRAPH[Vertex][x.second] << " ";
                    NearVertex++;
                }
            }
            cout << endl;

            // Neu khong co dinh nao ke thi xuat None
            if (NearVertex == 0)
                cout << "NONE" << endl;
        }
    }


    return 0;
}