#ifndef TIME_SERIES_DATASET_H
#define TIME_SERIES_DATASET_H
#include <vector>
#include "time_series_generator.h"

class TimeSeriesDataset {
    private:
        bool znormalize;
        bool isTrain;
        std::vector<double> data;
        std::vector<int> labels;
        int numberOfSamples = 0;
    public:
        TimeSeriesDataset(bool znorm=false, bool train=false)
            : znormalize(znorm), isTrain(train) {}
        void addTimeSeries(const std::vector<double>& series, int label) {
            data.insert(data.end(), series.begin(), series.end());
            labels.push_back(label);
            numberOfSamples++;
        }
        double euclidean_distance(const std::vector<double>& ts1, const std::vector<double>& ts2) {
            if (ts1.size() != ts2.size()) {
                throw std::invalid_argument("Time series must be of the same length");
            }
            double euclidean_dist = 0.0;
            for (size_t i = 0; i < ts1.size(); i++) {
                euclidean_dist += (ts1[i] - ts2[i]) * (ts1[i] - ts2[i]);
            }
            return std::sqrt(euclidean_dist);
        }
        double DTW(const std::vector<double>& ts1, const std::vector<double>& ts2) {
            size_t n = ts1.size();
            size_t m = ts2.size();
            std::vector<std::vector<double>> dtw(n + 1, std::vector<double>(m + 1, std::numeric_limits<double>::infinity()));
            dtw[0][0] = 0.0;

            for (size_t i = 1; i <= n; i++) {
                for (size_t j = 1; j <= m; j++) {
                    double cost = (ts1[i] - ts2[j])*(ts1[i] - ts2[j]);
                    dtw[i][j] = cost + std::min({ dtw[i][j - 1],    // insertion
                                                  dtw[i][j - 1],    // deletion
                                                  dtw[i - 1][j - 1] // match
                                                });
                }
            }
            return sqrt(dtw[n][m]);
        }
        std::vector<double> getTimeSeries(int index) {
            if (index < 0 || index >= numberOfSamples) {
                throw std::out_of_range("Index out of range");
            }
            size_t seriesLength = data.size() / numberOfSamples;
            return std::vector<double>(data.begin() + index * seriesLength, data.begin() + (index + 1) * seriesLength);
        }
        int getLabel(int index) {
            if (index < 0 || index >= numberOfSamples) {
                throw std::out_of_range("Index out of range");
            }
            return labels[index];
        }
        friend class KNN;
};

#endif // TIME_SERIES_DATASET_H