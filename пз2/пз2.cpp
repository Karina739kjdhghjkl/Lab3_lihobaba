#include <iostream>
#include <vector>
#include <Windows.h>

// Базовий клас
class Function {
public:
    virtual double compute(double x) = 0; // Віртуальна функція
};

// Похідний клас 1
class LinearFunction : public Function {
public:
    double compute(double x) override {
        return x; // f(x) = x
    }
};

// Похідний клас 2
class QuadraticFunction : public Function {
public:
    double compute(double x) override {
        return x * x; // f(x) = x^2
    }
};

// Похідний клас 3
class CubicFunction : public Function {
public:
    double compute(double x) override {
        return x * x * x; // f(x) = x^3
    }
};

// Клас-контейнер
class FunctionContainer {
private:
    std::vector<Function*> functions;
public:
    void add(Function* function) {
        functions.push_back(function);
    }
    double computeSum(double x) {
        double sum = 0;
        for (Function* function : functions) {
            sum += function->compute(x);
        }
        return sum;
    }
};

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    FunctionContainer container;
    container.add(new LinearFunction());
    container.add(new QuadraticFunction());
    container.add(new CubicFunction());

    double x;
    std::cout << "Введіть значення для X: ";
    std::cin >> x;

    std::cout << "Сума значень функцій для x=" << x << " є " << container.computeSum(x) << std::endl;

    return 0;
}
