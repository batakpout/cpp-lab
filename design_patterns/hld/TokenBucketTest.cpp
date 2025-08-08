#include <iostream>

#include "TokenBucket.h"
#include <chrono>   // For high-resolution clock and time duration
#include <thread>   // For std::this_thread::sleep_for
#include <iomanip> //needed for setprecision

int main() {
    long bucketCapacity = 10;
    double refillRatePerSecond = 2; // 2 tokens per second

    cout << "--- Token Bucket Rate Limiter Demonstration ---" << endl;
    cout << "Bucket Capacity: " << bucketCapacity << " tokens" << endl;
    cout << "Refill Rate: " << refillRatePerSecond << " tokens/second" << endl;
    cout << "---------------------------------------------" << endl;

    TokenBucket rateLimiter(bucketCapacity, refillRatePerSecond);

    // Simulate 20 requests, each consuming 1 token.
    for (int i = 1; i <= 20; ++i) {
        int tokensNeeded = 1;
        bool allowed = rateLimiter.tryConsume(tokensNeeded);

        cout << fixed << setprecision(2); // Set precision for output

        if (allowed) {
            cout << "Request " << i << ": ALLOWED. Current tokens: " << rateLimiter.getCurrentTokens() << endl;
        } else {
            cout << "Request " << i << ": DENIED (Rate Limited). Current tokens: " << rateLimiter.getCurrentTokens() <<
                    endl;
        }

        // Introduce a small pause after every 5 requests to allow tokens to refill.
        if (i % 5 == 0 && i < 20) {
            long sleepTimeMs = 1500; // Sleep for 1.5 seconds
            cout << "\n--- Pausing for " << sleepTimeMs << "ms to allow tokens to refill ---\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(sleepTimeMs));
        }
    }

    cout << "\n--- End of Demonstration ---" << endl;

    // Another example: Try to consume a large number of tokens
    cout << "\n--- Testing large consumption ---" << endl;
    int largeTokensNeeded = 15;
    cout << "Attempting to consume " << largeTokensNeeded << " tokens..." << endl;
    bool allowedLarge = rateLimiter.tryConsume(largeTokensNeeded);

    cout << fixed << setprecision(2); // Set precision for output

    if (allowedLarge) {
        cout << "Large consumption: ALLOWED. Current tokens: " << rateLimiter.getCurrentTokens() << endl;
    } else {
        cout << "Large consumption: DENIED (Rate Limited). Current tokens: " << rateLimiter.getCurrentTokens() << endl;
    }

    return 0;
}
