#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>

using namespace std;

void create_file_if_not_exists(const string &filename) {
    ifstream infile(filename);
    if (!infile.good()) {  // Проверяем, существует ли файл
        ofstream outfile(filename);  // Создаем файл, если его нет
        outfile.close();
        cout << "File '" << filename << "' created." << endl;
    }
}

void handle_query(const string &filename, const string &query, int element) {
    unordered_set<int> my_set;
    ifstream infile(filename);
    int value;

    // Загрузка элементов из файла в множество
    while (infile >> value) {
        my_set.insert(value);
    }
    infile.close();

    // Обработка запроса
    if (query == "SETADD") {
        my_set.insert(element);
    } else if (query == "SETDEL") {
        my_set.erase(element);
    } else if (query == "SET_AT") {
        cout << (my_set.count(element) ? "YES" : "NO") << endl;
        return;
    }

    // Сохранение множества обратно в файл
    ofstream outfile(filename, ios::trunc);
    for (const auto &el : my_set) {
        outfile << el << endl;
    }
    outfile.close();
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        cerr << "Usage: ./set_operations --file <filename> --query <query> <element>" << endl;
        return 1;
    }

    string filename = argv[2];
    string query = argv[4];
    int element = stoi(argv[5]);

    create_file_if_not_exists(filename);
    handle_query(filename, query, element);

    return 0;
}
