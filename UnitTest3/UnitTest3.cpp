#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestExpTaylor
{
    double calculateSeries(double x, double eps, int& n) {
        double a = 1.0; // Перший доданок ряду
        double S = a;
        double R;
        n = 0;
        do {
            n++;
            R = -x * x / n; // Рекурентне співвідношення для ряду Тейлора
            a *= R;
            S += a;
        } while (abs(a) >= eps);
        return S;
    }

    TEST_CLASS(UnitTestExpTaylor)
    {
    public:

        TEST_METHOD(TestCalculateSeries)
        {
            double x = 0.5;
            double eps = 1e-5;
            int n = 0;
            double expectedValue = exp(-x * x);
            double calculatedValue = calculateSeries(x, eps, n);

            Assert::AreEqual(expectedValue, calculatedValue, 1e-5, L"Значення ряду не відповідає очікуваному.");
        }

        TEST_METHOD(TestSmallEps)
        {
            double x = 1.0;
            double eps = 1e-8;
            int n = 0;
            double expectedValue = exp(-x * x);
            double calculatedValue = calculateSeries(x, eps, n);

            Assert::AreEqual(expectedValue, calculatedValue, 1e-8, L"Значення ряду не відповідає очікуваному при малій точності.");
        }

        TEST_METHOD(TestZeroX)
        {
            double x = 0.0;
            double eps = 1e-5;
            int n = 0;
            double expectedValue = exp(-x * x); // exp(0) = 1
            double calculatedValue = calculateSeries(x, eps, n);

            Assert::AreEqual(expectedValue, calculatedValue, 1e-5, L"Значення ряду не відповідає очікуваному при x = 0.");
        }
    };
}
