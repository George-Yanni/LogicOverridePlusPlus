// George Yanni
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double acceleration, maxSpeed, totalRoad, camera, speedLimit;
    cin >> acceleration >> maxSpeed >> totalRoad >> camera >> speedLimit;

    double totalTime = 0.0;
    double currentSpeed = 0.0;

    // -------- Part 1: start -> camera (must arrive with <= speedLimit) --------
    
    // If speedLimit is higher than max speed, the limit doesn't matter
    // If you can't even reach speedLimit within the 'camera' distance, the limit doesn't matter
    if (speedLimit >= maxSpeed || (speedLimit * speedLimit) / (2.0 * acceleration) >= camera) {
        double timeToReachMax = maxSpeed / acceleration;
        double distanceToReachMax = (maxSpeed * maxSpeed) / (2.0 * acceleration);

        if (distanceToReachMax >= camera) {
            totalTime = sqrt(2.0 * camera / acceleration);
            currentSpeed = acceleration * totalTime;
        } else {
            totalTime = timeToReachMax + (camera - distanceToReachMax) / maxSpeed;
            currentSpeed = maxSpeed;
        }
    } else {
        // Must consider the speedLimit (w)
        // peak speed: Vpeak^2 = (2*a*camera + speedLimit^2) / 2
        double peakSpeed = sqrt((2.0 * acceleration * camera + speedLimit * speedLimit) / 2.0);

        if (peakSpeed <= maxSpeed) {
            double t1 = peakSpeed / acceleration;
            double t2 = (peakSpeed - speedLimit) / acceleration;
            totalTime = t1 + t2;
        } else {
            // Cap at maxSpeed: Accel to maxSpeed, Cruise, Brake to speedLimit
            double accelDist = (maxSpeed * maxSpeed) / (2.0 * acceleration);
            double brakeDist = (maxSpeed * maxSpeed - speedLimit * speedLimit) / (2.0 * acceleration);
            double cruiseDist = camera - accelDist - brakeDist;

            double t1 = maxSpeed / acceleration;
            double t2 = cruiseDist / maxSpeed;
            double t3 = (maxSpeed - speedLimit) / acceleration;

            totalTime = t1 + t2 + t3;
        }
        currentSpeed = speedLimit;
    }

    // -------- Part 2: camera -> finish (accelerate as much as possible) --------
    double remaining = totalRoad - camera;
    
    // Time to reach maxSpeed from currentSpeed:
    double timeToReachMax = (maxSpeed - currentSpeed) / acceleration;
    double distanceToReachMax = currentSpeed * timeToReachMax + 0.5 * acceleration * timeToReachMax * timeToReachMax;

    if (distanceToReachMax >= remaining) {
        // Solve: remaining = currentSpeed*t + 0.5*acceleration*t^2
        // Using quadratic formula: 0.5*a*t^2 + v0*t - dist = 0
        // t = (-v0 + sqrt(v0^2 + 2*a*dist)) / a
        double t = (sqrt(currentSpeed * currentSpeed + 2.0 * acceleration * remaining) - currentSpeed) / acceleration;
        totalTime += t;
    } else {
        // Reach maxSpeed, then cruise the rest
        totalTime += timeToReachMax + (remaining - distanceToReachMax) / maxSpeed;
    }

    cout << fixed << setprecision(12) << totalTime << "\n";
    return 0;
}
