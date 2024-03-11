#include "util.hpp"

float util::RadsToDegs(float angleInDegs) { 
    // Why 25?
    return (angleInDegs / M_PI * 180.F) - 25.F; 
}