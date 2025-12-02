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
            int correct=0;
            double accuracy = 0.0;
            if (similarity_measure == "euclidean_distance") {
                for (size_t i = 0; i < testSet.numberOfSamples; i++) {
                    std::vector<std::pair<double, int>> distances;
                    std::vector<double> testSeries = testSet.getTimeSeries(i);
                    for (size_t j = 0; j < trainSet.numberOfSamples; j++) {
                        std::vector<double> trainSeries = trainSet.getTimeSeries(j);
                        double dist = trainSet.euclidean_distance(testSeries, trainSeries);
                        distances.push_back({ dist, trainSet.getLabel(j) });
                    }
                    std::sort(distances.begin(), distances.end());
                    std::vector<int> votes;
                    for (int n = 0; n < k; n++) {
                        votes.push_back(distances[n].second);
                    }
                    int predictedLabel = *std::max_element(votes.begin(), votes.end(),
                        [&votes](int a, int b) {
                            return std::count(votes.begin(), votes.end(), a) < std::count(votes.begin(), votes.end(), b);
                        });
                    if (predictedLabel == testLabels[i]) {
                        correct++;
                    }
                }
            } else if (similarity_measure == "dtw") {
                for (size_t i = 0; i < testSet.numberOfSamples; i++) {
                    std::vector<std::pair<double, int>> distances;
                    std::vector<double> testSeries = testSet.getTimeSeries(i);
                    for (size_t j = 0; j < trainSet.numberOfSamples; j++) {
                        std::vector<double> trainSeries = trainSet.getTimeSeries(j);
                        double dist = trainSet.DTW(testSeries, trainSeries);
                        distances.push_back({ dist, trainSet.getLabel(j) });
                    }
                    std::sort(distances.begin(), distances.end());
                    std::vector<int> votes;
                    for (int n = 0; n < k; n++) {
                        votes.push_back(distances[n].second);
                    }
                    int predictedLabel = *std::max_element(votes.begin(), votes.end(),
                        [&votes](int a, int b) {
                            return std::count(votes.begin(), votes.end(), a) < std::count(votes.begin(), votes.end(), b);
                        });
                    if (predictedLabel == testLabels[i]) {
                        correct++;
                    }
                }
            } else {
                throw std::invalid_argument("Unsupported similarity measure");
            }

            accuracy = static_cast<double>(correct) / testSet.numberOfSamples;
            return accuracy;
        }
};

#endif // KNN_H