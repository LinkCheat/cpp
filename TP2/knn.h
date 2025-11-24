#ifndef KNN_H
#define KNN_H
#include <vector>
#include <algorithm>
#include "time_series_dataset.h"
#include <string>

class KNN {
    private:
        int k;
        std::string similarity_measure;
    public:
        KNN(int neighborsn, std::string sim_measure)
            : k(neighborsn), similarity_measure(sim_measure) {}
        double evaluate(TimeSeriesDataset& trainSet, TimeSeriesDataset& testSet, std::vector<int>& testLabels) {
            double accuracy = 0.0;
            for (int i = 0; i < testSet.numberOfSamples; i++) {
                accuracy += (1/testSet.numberOfSamples)* (testSet.getTimeSeries(i)==trainSet.getTimeSeries(i));
            }
            return accuracy;
        }
};

#endif // KNN_H