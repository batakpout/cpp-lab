

#include<iostream>
#include <chrono>
using namespace std;

class TokenBucket {
    long capacity;
     double refillRate;
    double currentTokens;
    chrono::high_resolution_clock::time_point lastRefillTime;

public:
    TokenBucket(long cap, double rate) {
        if (cap <= 0) {
            throw invalid_argument("capacity must be positive.");
        }
        if (rate <= 0) {
            throw invalid_argument("refill rate must be positive.");
        }
        capacity = cap;
        refillRate = rate;
        currentTokens = cap;
        lastRefillTime = chrono::high_resolution_clock::now();
    }

    void refillTokens() {
        auto now = chrono::high_resolution_clock::now();

        // Calculate the time elapsed in seconds.
        chrono::duration<double> timeElapsed = now - lastRefillTime;
        double timeElapsedSeconds = timeElapsed.count();

        double tokensToAdd = timeElapsedSeconds * refillRate;
        currentTokens += tokensToAdd;

        if (currentTokens > capacity) {
            currentTokens = capacity;
        }

        lastRefillTime = now;
    }

    bool tryConsume(int tokensToConsume) {
        if (tokensToConsume <= 0) {
            return true;
        }
        refillTokens();

        if (currentTokens >= tokensToConsume) {
            currentTokens -= tokensToConsume;

            lastRefillTime = chrono::high_resolution_clock::now();
            return true;
        } else {
            return false;
        }
    }

    double getCurrentTokens() const {
        return currentTokens;
    }

};