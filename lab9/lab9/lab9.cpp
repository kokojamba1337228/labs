#include <iostream>
#include<vector>
#include<ctime>
#include<algorithm>

template<class T, class Iterator>
std::vector<std::vector<T>> input_vec(Iterator rows, Iterator clmns) {
    std::vector<std::vector<T>> vec(rows, std::vector<T> (clmns));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < clmns; ++j)
        {
            std::cout << "Input [" << i << "][" << j << "]: ";
            std::cin >> vec[i][j];
        }
    }
    if (vec.empty()) {
        std::cout << "Unable to create array\n";
        return std::vector<std::vector<T>>();
    }
    return vec;
}

template<class T, class Iterator>
std::vector<std::vector<T>> fill_vec(Iterator rows, Iterator clmns) {
    std::srand(time(0));
    std::vector<std::vector<T>> vec(rows, std::vector<T>(clmns));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < clmns; ++j)
        {
            vec[i][j] = std::rand() % 7 - 9;
        }
    }
    if (vec.empty()) {
        std::cout << "Unable to create array\n";
        return std::vector<std::vector<T>>();
    }
    return vec;
}

template<class T, class Iterator>
std::vector<std::vector<T>> change_step(Iterator rows, Iterator clmns) {
    std::vector<std::vector<T>> vec(rows, std::vector<T>(clmns));
    int abc = 309;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < clmns; ++j, abc -= 6)
        {
            vec[i][j] = abc;
        }
    }
    if (vec.empty()) {
        std::cout << "Unable to create array\n";
        return std::vector<std::vector<T>>();
    }
    return vec;
}

template<class T>
std::vector<std::vector<T>> reverse_vec(std::vector<std::vector<T>>& vec) {
    for (auto& inner : vec) {
        std::reverse(inner.begin(), inner.end());
    }
    return vec;
}

template<class T>
void print_vec(const std::vector<std::vector<T>>& vec) {
    int rows = vec.size();
    int clmns = vec[0].size();
    std::cout << "\nPrint array:\n";
    for (int i = 0; i < rows; ++i)
    {
        std::cout << "| ";
        for (int j = 0; j < clmns; ++j)
        {
            std::cout << vec[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

template<class T>
void print_vec2(std::vector<std::vector<T>>& vec) {
    int rows = vec.size();
    int clmns = vec[0].size();
    std::cout << "\nPrint array:\n";
    for (int i = 0; i < rows; ++i)
    {
        std::cout << "| ";
        for (int j = 0; j < clmns; ++j)
        {
            if(i != j)
                std::cout << vec[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows;
    int clmns;
    int type;
    std::cout << "Input vector size: ";
    std::cin >> rows >> clmns;
    while (rows < 1 || clmns < 1) {
        std::cin >> rows >> clmns;
    }
    std::cout << "Choose data type: 1 for int, 2 for char, 3 for double, 4 for other tasks: ";
    std::cin >> type;
    if (type == 1) {
        auto vec = input_vec<int>(rows, clmns);
        print_vec(vec);
    }
    else if (type == 2) {
        auto vec = input_vec<char>(rows, clmns);
        print_vec(vec);
    }
    else if (type == 3) {
        auto vec = input_vec<double>(rows, clmns);
        print_vec(vec);
    }
    else if (type == 4) {
        int choice;
        std::cout << "Choose variant:\n\n1)print reverse random arr\n"
            << "2)print arr from 309 to n1 with step -6\n"
            << "3)print arr, where i != j\n"
            << "0 for nothing\n"
            << "Your choice: ";
        std::cin >> choice;
        if (choice == 1) {
            auto vec = fill_vec<double>(rows, clmns);
            reverse_vec(vec);
            print_vec(vec);
        }
        else if (choice == 2) {
            auto vec = change_step<double>(rows, clmns);
            print_vec(vec);
        }
        else if (choice == 3) {
            std::vector<std::vector<double>> vec{ {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
        {0.7, 0.8, 0.9, 1.0, 1.1, 1.2},
        {1.3, 1.4, 1.5, 1.6, 1.7, 1.8},
        {1.9, 2.0, 2.1, 2.2, 2.3, 2.4},
        {2.5, 2.6, 2.7, 2.8, 2.9, 3.0},
        {3.1, 3.2, 3.3, 3.4, 3.5, 3.6} };
            print_vec2(vec);
        }
    }
    else {
        std::cout << "Invalid type selected!";
    }
}
