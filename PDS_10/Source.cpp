#include"Graph.h"

#include<Windows.h>

bool readGraphFromFile(const string& filePath, Graph& graph) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ����. �������� ����." << endl;
        return false;
    }

    unsigned int n, m;
    file >> n >> m;

    if (n <= 0 || m <= 0) {
        cerr << "ʳ������ ������ � ����� ������ ���� ����� ����." << endl;
        return false;
    }

    graph = Graph(n);

    for (unsigned int i = 0; i < m; ++i) {
        unsigned int v, u, w;
        if (!(file >> v >> u >> w)) {
            cerr << "������� ��� ��������� �����." << endl;
            return false;
        }
        
        if (u < 1 || u > n) {
            cerr << "�������: ����� ������� �����: " << v << " -> " << u << endl;
            continue;
        }
        graph.addEdge(v, u, w);
    }

    file.close();
    return true;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    string filePath;
    cout << "������ ���� �� ����� �����:";
    getline(cin, filePath);
    Graph graph(0);
    
    if (readGraphFromFile(filePath, graph)) {
        graph.print();
    }
    else {
        cerr << "������� ��� ��������� �����" << endl;
        return 0;
    }
    graph.printWeightMatrix();
    string saveFilePath;
    cout << "������ ���� ��� ��������� ������� ���:";
    getline(cin, saveFilePath);
    graph.saveWeightMatrixToFile(saveFilePath);
    return 0;
}