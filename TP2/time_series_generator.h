#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H
#include <vector>
#include <iostream>

class TimeSeriesGenerator {
    private:
        int seed=0;

    public:
        TimeSeriesGenerator()=default;
        TimeSeriesGenerator(int s): seed(s) {}
        ~TimeSeriesGenerator()=default;

        virtual std::vector<double> generateTimeSeries(int)=0;
        static void printTimeSeries(const std::vector<double> &timeSeries){
            for(const auto& val : timeSeries){
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
};

#endif // TIME_SERIES_GENERATOR_H