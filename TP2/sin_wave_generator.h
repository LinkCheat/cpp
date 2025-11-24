#ifndef SIN_WAVE_GENERATOR_H
#define SIN_WAVE_GENERATOR_H
#include "time_series_generator.h"
#include <vector>
#include <cmath>
#include <corecrt_math_defines.h>

class SinWaveGenerator : public TimeSeriesGenerator {
    private:
        double amplitude=1.0;
        double frequency=1.0;
        double phase=0.0;
    public:
        SinWaveGenerator(): TimeSeriesGenerator() {};
        std::vector<double> generateTimeSeries(int n) override{
            std::vector<double> series;
            for(int i=0; i<n; i++){
                double value = amplitude * sin(2 * M_PI * frequency * i / n + phase);
                series.push_back(value);
            }
            return series;
        }
};

#endif // SIN_WAVE_GENERATOR_H