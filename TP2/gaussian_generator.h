#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H
#include "time_series_generator.h"
#include <random>
#include <corecrt_math_defines.h>

class GaussianGenerator : public TimeSeriesGenerator {
    private:
        double moyenne=0.0;
        double ecart_type=1.0;
    public:
        GaussianGenerator(): TimeSeriesGenerator() {};
        std::vector<double> generateTimeSeries(int n) override{
            double u1, u2, Z, value;
            std::vector<double> series;
            std::default_random_engine generator;
            std::uniform_real_distribution<double> distribution(0.0,1.0);
            
            for(int i=0; i<n; i++){
                u1=distribution(generator);
                u2=distribution(generator);
                Z=sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
                value = Z * ecart_type + moyenne;
                series.push_back(value);
            }
            return series;
        }
};

#endif // GAUSSIAN_GENERATOR_H