#include "Condition.h"

Condition::Condition(std::string name, float severity)
    : name(name), severity(severity) {}

void Condition::addAffectedOrgan(Organ* organ) {
    affectedOrgans.push_back(organ);
}

void Condition::progress(float amount) {
    severity += amount;
    if (severity > 100) severity = 100;
}

void Condition::treat(float amount) {
    severity -= amount;
    if (severity < 0) severity = 0;
}

std::string Condition::getName() const {
    return name;
}

float Condition::getSeverity() const {
    return severity;
}

void Condition::affectOrgans() {
    // Example: damage each affected organ based on severity
    for (auto organ : affectedOrgans) {
        if (organ) {
            float damageAmount = severity * 0.1f; // damage proportional to severity
            organ->damage(damageAmount);
        }
    }
}
