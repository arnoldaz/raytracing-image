#pragma once

inline double normalizeToUnitInterval(double value, double minValue, double maxValue) {
    return (value - minValue) / (maxValue - minValue);
}