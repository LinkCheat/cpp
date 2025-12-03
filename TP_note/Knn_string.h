#ifndef KNN_STRING_H
#define KNN_STRING_H
#include <string>
#include <vector>
#include <algorithm>
#include "Knn.h"

class KNN_String : public KNN<std::vector<std::string>> {
    public:
        KNN_String() : KNN<std::vector<std::string>>() {}
        KNN_String(int k) : KNN<std::vector<std::string>>(k) {}

        double similarityMeasure(const std::vector<std::string>& a, const std::vector<std::string>& b) override {
            double totalDistance = 0.0;
            size_t len = std::min(a.size(), b.size());
            for (size_t i = 0; i < len; ++i) {
                totalDistance += levenshteinFullMatrix(a[i], b[i]);
            }
            // Penalize for length differences
            totalDistance += std::abs(static_cast<int>(a.size()) - static_cast<int>(b.size())) * 5.0;
            return totalDistance;
        }

        int levenshteinFullMatrix(const std::string& str1,const std::string& str2) {
            int m = str1.length();
            int n = str2.length();

            std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));

            for (int i = 0; i <= m; i++) {
                dp[i][0] = i;
            }

            for (int j = 0; j <= n; j++) {
                dp[0][j] = j;
            }

            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = 1
                                + std::min(

                                    // Insert
                                    dp[i][j - 1],
                                    std::min(

                                        // Remove
                                        dp[i - 1][j],

                                        // Replace
                                        dp[i - 1][j - 1]));
                    }
                }
            }

            return dp[m][n];
        }
};
#endif // KNN_STRING_H