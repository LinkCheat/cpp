#ifndef KNN_H
#define KNN_H

#include <vector>
#include <utility>
#include <algorithm>

template<typename T>
class KNN {
    private:
        int k;
    public:
        KNN() : k(3) {}
        KNN(int k) : k(k) {}

        int getK() const { return k; }

        std::vector<int> findNearestNeighbors(const std::vector<T>& trainData, const T& target) {
            std::vector<std::pair<double, int>> distances; // pair of distance and index

            for (size_t i = 0; i < trainData.size(); ++i) {
                double dist = similarityMeasure(trainData[i], target);
                distances.push_back({dist, static_cast<int>(i)});
            }

            std::sort(distances.begin(), distances.end());

            std::vector<int> neighbors;
            for (int i = 0; i < k && i < static_cast<int>(distances.size()); ++i) {
                neighbors.push_back(distances[i].second);
            }

            return neighbors;
        }

        virtual double similarityMeasure(const T& a, const T& b) = 0;

};
#endif // KNN_H