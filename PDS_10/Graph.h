#pragma once
#include"Edge.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include<iomanip>

using namespace std;

class Graph {
public:
    vector<vector<unsigned int>> weightMatrix;
    vector<vector<Edge>> adjList;

    Graph(unsigned int n) : adjList(n), weightMatrix(n, vector<unsigned int>(n, INF)) {      
        for (unsigned int i = 0; i < n; ++i) {
            weightMatrix[i][i] = 0;
        }
    }

    static const unsigned int INF = std::numeric_limits<unsigned int>::max();

    void addEdge(unsigned int from, unsigned int to, unsigned int weight) {
        if (from >= 1 && from <= adjList.size() && to >= 1 && to <= adjList.size()) {
            adjList[from - 1].push_back({ to - 1, weight }); 
            weightMatrix[from - 1][to - 1] = weight; 
        }
        else {
            cerr << "Помилка: невірні індекси при додаванні ребра: " << from << " -> " << to << endl;
        }
    }

    void printWeightMatrix() const {
        cout << "Матриця ваг:\n";
        for (size_t i = 0; i < weightMatrix.size(); ++i) {
            for (size_t j = 0; j < weightMatrix[i].size(); ++j) {
                if (weightMatrix[i][j] == INF) {
                    cout << setw(10) << "INF ";
                }
                else {
                    cout << setw(10) << weightMatrix[i][j] << setw(10);
                }
            }
            cout << endl;
        }
    }

    void saveWeightMatrixToFile(const string& filePath) const {
        ofstream file(filePath);
        if (!file.is_open()) {
            cerr << "Не вдалося відкрити файл для запису." << endl;
            return;
        }

        for (size_t i = 0; i < weightMatrix.size(); ++i) {
            for (size_t j = 0; j < weightMatrix[i].size(); ++j) {
                if (weightMatrix[i][j] == INF) {
                    file << setw(10) << "INF ";
                }
                else {
                    file << setw(10) << weightMatrix[i][j] << setw(10);
                }
            }
            file << endl;
        }
        file.close();
        cout << "Матриця ваг успішно збережена у файл: " << filePath << endl;
    }

    void print() const {
        for (size_t i = 0; i < adjList.size(); ++i) {
            cout << "Вершина " << (i + 1) << ": ";
            for (const auto& edge : adjList[i]) {
                cout << "-> " << (edge.to + 1) << " (вага: " << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};