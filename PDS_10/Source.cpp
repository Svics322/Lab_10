#include"Graph.h"

#include<Windows.h>

bool readGraphFromFile(const string& filePath, Graph& graph) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл. Перевірте шлях." << endl;
        return false;
    }

    unsigned int n, m;
    file >> n >> m;

    if (n <= 0 || m <= 0) {
        cerr << "Кількість вершин і ребер повинні бути більше нуля." << endl;
        return false;
    }

    graph = Graph(n);

    for (unsigned int i = 0; i < m; ++i) {
        unsigned int v, u, w;
        if (!(file >> v >> u >> w)) {
            cerr << "Помилка при зчитуванні ребра." << endl;
            return false;
        }
        
        if (u < 1 || u > n) {
            cerr << "Помилка: невірні індекси ребра: " << v << " -> " << u << endl;
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
    cout << "Введіть шлях до файлу графу:";
    getline(cin, filePath);
    Graph graph(0);
    
    if (readGraphFromFile(filePath, graph)) {
        graph.print();
    }
    else {
        cerr << "Помилка при зчитуванні файлу" << endl;
        return 0;
    }
    graph.printWeightMatrix();
    string saveFilePath;
    cout << "Введіть шлях для збережння матриці ваг:";
    getline(cin, saveFilePath);
    graph.saveWeightMatrixToFile(saveFilePath);
    return 0;
}