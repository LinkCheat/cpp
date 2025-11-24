#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H
#include "time_series_generator.h"
#include <vector>
#include <random>

class StepGenerator : public TimeSeriesGenerator {
    private:
        double step_value=1.0;
    public:
        StepGenerator(): TimeSeriesGenerator() {};
        std::vector<double> generateTimeSeries(int n) override{
            std::vector<double> series;
            std::default_random_engine generator;
            std::uniform_real_distribution<double> distribution(0.0,100.0);
            double value = 0;
            for(int i=0; i<n; i++){
                if (rand() % 2 == 0) {
                    value = distribution(generator);
                }
                series.push_back(value);
            }
            return series;
        }
};

#endif // STEP_GENERATOR_H