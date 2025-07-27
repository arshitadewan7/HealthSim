#include <iostream>
#include "Patient.h"
#include "Organ.h"
#include "Condition.h"
#include "Treatment.h"

int main() {
    // Create organs
    Organ heart("Heart");
    Organ liver("Liver");
    Organ pancreas("Pancreas");

    // Create condition and link affected organs
    Condition diabetes("Diabetes", 10.0f);
    diabetes.addAffectedOrgan(&pancreas);
    diabetes.addAffectedOrgan(&liver);

    // Create treatment
    Treatment insulin("Insulin Therapy", 70.0f);

    // Create patient
    Patient patient("John Doe", 55);
    patient.addOrgan(&heart);
    patient.addOrgan(&liver);
    patient.addOrgan(&pancreas);

    patient.addCondition(diabetes);
    patient.addTreatment(insulin);

    int months;
    std::cout << "Enter number of months to simulate: ";
    std::cin >> months;

    for (int month = 1; month <= months; ++month) {
        float diet, exercise, sleep, stress;

        std::cout << "\n--- Month " << month << " ---\n";
        
        // Input diet quality
        do {
            std::cout << "Enter diet quality (0.0 - 1.0): ";
            std::cin >> diet;
        } while (diet < 0.0f || diet > 1.0f);

        // Input exercise level
        do {
            std::cout << "Enter exercise level (0.0 - 1.0): ";
            std::cin >> exercise;
        } while (exercise < 0.0f || exercise > 1.0f);

        // Input sleep hours
        do {
            std::cout << "Enter sleep hours (0 - 12): ";
            std::cin >> sleep;
        } while (sleep < 0.0f || sleep > 12.0f);

        // Input stress level
        do {
            std::cout << "Enter stress level (0 - 10): ";
            std::cin >> stress;
        } while (stress < 0.0f || stress > 10.0f);

        patient.simulateMonth(diet, exercise, sleep, stress);
        patient.printHealthReport();
    }

    return 0;
}
