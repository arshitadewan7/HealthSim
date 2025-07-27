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
    patient.addOrgan(heart);
    patient.addOrgan(liver);
    patient.addOrgan(pancreas);

    patient.addCondition(diabetes);
    patient.addTreatment(insulin);

    // Simulate 12 months with lifestyle inputs (dietQuality, exerciseLevel, sleepHours, stressLevel)
    for (int month = 1; month <= 12; ++month) {
        std::cout << "Month " << month << " simulation:\n";
        patient.simulateMonth(
            0.6f,   // diet quality (0-1)
            0.5f,   // exercise level (0-1)
            7.0f,   // sleep hours
            3.0f    // stress level (0-10)
        );
        patient.printHealthReport();
    }

    return 0;
}
