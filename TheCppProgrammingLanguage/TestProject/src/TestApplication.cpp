#include "pch.h"
#include "Vector.h"
#include "complex.h"

#include <cmath>
#include <iostream>
#include <string>

// using namespace std;

enum class Color {
    red,
    blue,
    green
};

enum class Traffic_light : int {
    green,
    yellow,
    red
};

Traffic_light& operator++(Traffic_light& t) {
    switch (t) {
        case Traffic_light::green:
            return t = Traffic_light::yellow;
        case Traffic_light::yellow:
            return t = Traffic_light::red;
        case Traffic_light::red:
            return t = Traffic_light::green;
        default:
            std::cerr << "Traffic_light#operator++ unknown value" << std::endl;
            return t;
    }
}

void test_traffic_light() {
    Traffic_light traffic_light = Traffic_light::yellow;
    if (traffic_light == Traffic_light::yellow) {
        std::cout << "(1) yellow" << std::endl;
    } else {
        std::cout << "(1) not yellow" << std::endl;
    }

    ++traffic_light;
    if (traffic_light == Traffic_light::yellow) {
        std::cout << "(2) yellow" << std::endl;
    } else if (traffic_light == Traffic_light::red) {

        std::cout << "(2) red" << std::endl;
    }
}

namespace My_code {
    class complex {

    public:
        complex(double rval, double ival) :
                r{rval}, i{ival} {
        }

        double real() {
            return r;
        }

        double imag() {
            return i;
        }

    private:
        double r;
        double i;
    };

    complex sqrt(complex);

    int main();
}

My_code::complex My_code::sqrt(My_code::complex c) {
    return My_code::complex(std::sqrt(c.real()), std::sqrt(c.imag()));
}

int My_code::main() {
    complex z{1, 2};
    auto z2 = sqrt(z);
    std::cout << "{" << z2.real() << "," << z2.imag() << "}\n";
    return 0;
}

constexpr double C = 299792.458;

void f(double speed) {
    // 書籍ではconst指定になっているが，以下記載の通りビルドエラーのため，const -> constexprに変更。
    // const double local_max = 160.0 / (60 * 60);
    constexpr double local_max = 160.0 / (60 * 60);

    // speedは定数でないため 以下はコンパイルエラー
    // static_assert(speed < C, "can\7t go that fast.")

    // 書籍ではlocal_maxをconst宣言してコンパイルエラーにならないと書いてあるが，
    // constは実行時に評価されるもので，初期値からは変えられないという性質。
    // つまり右辺に動的変数を指定できる。
    // static_assertはコンパイル時にエラー検出するものなので，const修飾された変数は，
    // 対象には出来ないはずで，書籍が誤っている気がする(書籍を私が読み違えてる?)
    // 対してconstexprはコンパイル時に評価(インライン化)されるため，static_assert対象にできる。
    static_assert(local_max < C, "can't go that fast.");
}

int main() {
    std::cout << "Hello World!\n";

    //std::cout << read_and_sum(3);
    Vector v2 = Vector(2);
    //Vector v3 = Vector(3);
    //vector_f(Vector(1), v2, &v3);

    Color x = Color::red;
    test_traffic_light();

    My_code::main();

    try {
        v2[9];
    } catch (std::out_of_range) {
        std::cout << "out_of_range occurred." << std::endl;
    }

    try {
        Vector{-1};
    } catch (std::length_error) {
        std::cout << "Vector length_error." << std::endl;
        // throw;
    } catch (std::bad_alloc) {
        std::cout << "Vector bad_alloc." << std::endl;
    }

    std::cout << "sizeof int = " << sizeof(int);
    // 整数の大きさを検査
    static_assert(4 <= sizeof(int), "Integers are too small.");

    my_complex::complex complex_z = {3, 2.1};
    my_complex::f(complex_z);

    fct(3);

    // Vectorをinitializer_listで初期化
    Vector vl1 = {1, 2, 3, 4, 5};
    Vector vl2 = {1.23, 3.45, 6.7, 8};


}
