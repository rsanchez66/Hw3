#include <iostream>
#include <vector>
#include <algorithm>


// Calculate the average sales excluding -1 values
double calculateAverage(const std::vector<int>& sales) {
    int sum = 0;
    int count = 0;
    for (int sale : sales) {
        if (sale != -1) {
            sum += sale;
            count++;
        }
    }
    return count > 0 ? static_cast<double>(sum) / count : 0.0;
}


// Calculate the median sales excluding -1 values
double calculateMedian(const std::vector<int>& sales) {
    std::vector<int> validSales;
    for (int sale : sales) {
        if (sale != -1) {
            validSales.push_back(sale);
        }
    }
    size_t n = validSales.size();
    if (n == 0) {
        return 0.0;
    }
    std::sort(validSales.begin(), validSales.end());
    if (n % 2 == 0) {
        return (validSales[n / 2 - 1] + validSales[n / 2]) / 2.0;
    } else {
        return validSales[n / 2];
    }
}


// The agent with the highest average or median sales
std::string findAgentWithHighestSales(const std::vector<std::vector<int>>& salesData, bool useAverage) {
    std::string highestAgent;
    double highestValue = 0.0;
    for (size_t i = 0; i < salesData.size(); ++i) {
        double value = useAverage ? calculateAverage(salesData[i]) : calculateMedian(salesData[i]);
        if (value > highestValue) {
            highestValue = value;
            highestAgent = "Agent " + std::to_string(i + 1);
        }
    }
    return highestAgent;
}


int main() {
    std::vector<std::vector<int>> salesData = {
        {10, 6, 2, 14, -1, -1},   // Agent 1
        {12, 15, 8, 11, 5, 17, 9},// Agent 2
        {20, 25, 18, -1, -1, -1, -1} // Agent 3
    };


    // The agent with the highest average sales
    std::string highestAverageAgent = findAgentWithHighestSales(salesData, true);
    std::cout << "Agent with the highest average sales: " << highestAverageAgent << std::endl;


    // The agent with the highest median sales
    std::string highestMedianAgent = findAgentWithHighestSales(salesData, false);
    std::cout << "Agent with the highest median sales: " << highestMedianAgent << std::endl;


    return 0;
}