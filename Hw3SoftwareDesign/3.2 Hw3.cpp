#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;


int sales[NUM_AGENTS][NUM_MONTHS] = {
{1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
{5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
{23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
};


// calculate the monthly sales average for an agent
double calculateMonthlyAverage(const int agentIndex) {
double totalSales = 0;
for (int month = 0; month < NUM_MONTHS; ++month) {
totalSales += sales[agentIndex][month];
}
return totalSales / NUM_MONTHS;
}


// calculate the median sales for an agent
int calculateMedian(const int agentIndex) {
vector<int> monthlySales(sales[agentIndex], sales[agentIndex] + NUM_MONTHS);
sort(monthlySales.begin(), monthlySales.end());
return monthlySales[NUM_MONTHS / 2];
}


int main() {
// agent with the best monthly sales average
int bestAgent = 0;
double bestAverage = calculateMonthlyAverage(0);
for (int agent = 1; agent < NUM_AGENTS; ++agent) {
double currentAverage = calculateMonthlyAverage(agent);
if (currentAverage > bestAverage) {
bestAgent = agent;
bestAverage = currentAverage;
}
}
cout << "Agent with the best monthly sales average: " << bestAgent + 1 << endl;


// agent with the highest median sales
int highestMedianAgent = 0;
int highestMedian = calculateMedian(0);
for (int agent = 1; agent < NUM_AGENTS; ++agent) {
int currentMedian = calculateMedian(agent);
if (currentMedian > highestMedian) {
highestMedianAgent = agent;
highestMedian = currentMedian;
}
}
cout << "Agent with the highest median sales: " << highestMedianAgent + 1 << endl;


return 0;
}