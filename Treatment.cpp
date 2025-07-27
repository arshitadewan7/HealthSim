#include "Treatment.h"

Treatment::Treatment(std::string name, float effectiveness)
    : name(name), effectiveness(effectiveness) {}

void Treatment::applyTreatment(std::vector<Organ*>& organs) {
    for (auto& organ : organs) {
        if (organ) {
            float healAmount = effectiveness * 0.1f;
            organ->heal(healAmount);
        }
    }
}

std::string Treatment::getName() const {
    return name;
}

float Treatment::getEffectiveness() const {
    return effectiveness;
}
