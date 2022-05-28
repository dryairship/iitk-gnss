#include <queue>
#include <vector>
#include <thread>

bool calculate_position(std::vector<std::queue<float>> &satellite_data, std::atomic<int> *numThreadsTracking, int maxThreads);
