#ifndef KNN_DOUBLE_H
#define KNN_DOUBLE_H
#include <cmath>
#include <utility>
#include "Knn.h"

class KNN_Double : public KNN<std::pair<double, double>> {
    public:
        KNN_Double() : KNN<std::pair<double, double>>() {}
        KNN_Double(int k) : KNN<std::pair<double, double>>(k) {}

        double similarityMeasure(const std::pair<double, double>& a, const std::pair<double, double>& b) override {
            double dx = a.first - b.first;
            double dy = a.second - b.second;
            return std::sqrt(dx * dx + dy * dy);
        }
};
#endif // KNN_DOUBLE_H