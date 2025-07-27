#include "Organ.h"

Organ::Organ(std::string name, float healthScore)
    : name(name), healthScore(healthScore) {}

void Organ::damage(float amount) {
    healthScore -= amount;
    if (healthScore < 0) healthScore = 0;
}

void Organ::heal(float amount) {
    healthScore += amount;
    if (healthScore > 100) healthScore = 100;
}

std::string Organ::getName() const {
    return name;
}

float Organ::getHealthScore() const {
    return healthScore;
}
