#include <iostream>
#include<vector>
#include<ctime>

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

template<class T>
void print_vec(const std::vector<std::vector<T>>& vec) {
    int rows = vec.size();
    int clmns = vec[0].size();
    std::cout << "\nPrint array:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < clmns; ++j)
        {
            std::cout << vec[i][j];
            if(j != clmns - 1)
                std::cout << " ; ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows;
    int clmns;
    std::cout << "Input vector size: ";
    std::cin >> rows >> clmns;
    while (rows < 1 || clmns < 1) {
        std::cin >> rows >> clmns;
    }
    auto vec = fill_vec<double>(rows, clmns);
    print_vec(vec);
}
