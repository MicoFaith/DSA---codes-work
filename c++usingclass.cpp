#include<iostream>
#include<string>
#include<regex>
using namespace std;

class PatientsLL {
public:
    int patient_id;
    string name;
    string dob;  
    string gender;
    PatientsLL* next;
};

class DoctorsLL {
public:
    int doctor_id;
    string name;
    string specialization;
    DoctorsLL* next;
};

class Appointments {
public:
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointments* next;
};

PatientsLL* patientsHead = NULL;
DoctorsLL* doctorsHead = NULL;
Appointments* appointmentsHead = NULL;

bool isValidPositiveInt(int num) {
    return num > 0;
}

bool isValidDate(const string& dob) {
    regex dobPattern(R"(\d{4}-\d{2}-\d{2})");
    return regex_match(dob, dobPattern);
}

bool patientExists(int patient_id) {
    PatientsLL* temp = patientsHead;
    while (temp != NULL) {
        if (temp->patient_id == patient_id) return true;
        temp = temp->next;
    }
    return false;
}

bool doctorExists(int doctor_id) {
    DoctorsLL* temp = doctorsHead;
    while (temp != NULL) {
        if (temp->doctor_id == doctor_id) return true;
        temp = temp->next;
    }
    return false;
}

bool appointmentExists(int appointment_id) {
    Appointments* temp = appointmentsHead;
    while (temp != NULL) {
        if (temp->appointment_id == appointment_id) return true;
        temp = temp->next;
    }
    return false;
}

void registerPatient() {
    PatientsLL* newPatient = new PatientsLL();
    cout << "PATIENT REGISTRATION" << endl;
    cout << "ID: ";
    cin >> newPatient->patient_id;

    if (!isValidPositiveInt(newPatient->patient_id) || patientExists(newPatient->patient_id)) {
        cout << "Error: Invalid Patient ID or ID already exists!" << endl;
        delete newPatient;
        return;
    }

    cout << "NAME: ";
    cin.ignore();
    getline(cin, newPatient->name);

    cout << "DoB (YYYY-MM-DD): ";
    getline(cin, newPatient->dob);
    if (!isValidDate(newPatient->dob)) {
        cout << "Error: Invalid date format. Use YYYY-MM-DD." << endl;
        delete newPatient;
        return;
    }

    cout << "GENDER: ";
    getline(cin, newPatient->gender);

    newPatient->next = patientsHead;
    patientsHead = newPatient;
}

void registerDoctor() {
    DoctorsLL* newDoctor = new DoctorsLL();
    cout << "DOCTOR REGISTRATION" << endl;
    cout << "ID: ";
    cin >> newDoctor->doctor_id;

    if (!isValidPositiveInt(newDoctor->doctor_id) || doctorExists(newDoctor->doctor_id)) {
        cout << "Error: Invalid Doctor ID or ID already exists!" << endl;
        delete newDoctor;
        return;
    }

    cout << "NAME: ";
    cin.ignore();
    getline(cin, newDoctor->name);

    cout << "SPECIALIZATION: ";
    getline(cin, newDoctor->specialization);

    newDoctor->next = doctorsHead;
    doctorsHead = newDoctor;
    cout << "Doctor registered successfully!" << endl;
}

void registerAppointment() {
    Appointments* newAppointment = new Appointments();
    cout << "APPOINTMENT REGISTRATION" << endl;
    cout << "ID: ";
    cin >> newAppointment->appointment_id;

    if (!isValidPositiveInt(newAppointment->appointment_id) || appointmentExists(newAppointment->appointment_id)) {
        cout << "Error: Invalid Appointment ID or ID already exists!" << endl;
        delete newAppointment;
        return;
    }

    cout << "P_ID: ";
    cin >> newAppointment->patient_id;
    if (!patientExists(newAppointment->patient_id)) {
        cout << "Error: Patient ID does not exist!" << endl;
        delete newAppointment;
        return;
    }

    cout << "D_ID: ";
    cin >> newAppointment->doctor_id;
    if (!doctorExists(newAppointment->doctor_id)) {
        cout << "Error: Doctor ID does not exist!" << endl;
        delete newAppointment;
        return;
    }

    cout << "DATE (YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, newAppointment->appointment_date);
    if (!isValidDate(newAppointment->appointment_date)) {
        cout << "Error: Invalid date format. Use YYYY-MM-DD." << endl;
        delete newAppointment;
        return;
    }

    newAppointment->next = appointmentsHead;
    appointmentsHead = newAppointment;
    cout << "Appointment registered successfully!" << endl;
}

void displayPatients() {
    if (patientsHead == NULL) {
        cout << "No patients registered." << endl;
        return;
    }
    PatientsLL* temp = patientsHead;
    cout << "\nRegistered Patients:" << endl;
    while (temp != NULL) {
        cout << "Patient ID: " << temp->patient_id << ", Name: " << temp->name
             << ", DoB: " << temp->dob << ", Gender: " << temp->gender << endl;
        temp = temp->next;
    }
}

void displayDoctors() {
    if (doctorsHead == NULL) {
        cout << "No doctors registered." << endl;
        return;
    }
    DoctorsLL* temp = doctorsHead;
    cout << "\nRegistered Doctors:" << endl;
    while (temp != NULL) {
        cout << "Doctor ID: " << temp->doctor_id << ", Name: " << temp->name
             << ", Specialization: " << temp->specialization << endl;
        temp = temp->next;
    }
}


void displayAppointments() {
    if (appointmentsHead == NULL) {
        cout << "No appointments registered." << endl;
        return;
    }
    Appointments* temp = appointmentsHead;
    cout << "\nRegistered Appointments:" << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->appointment_id << ", Patient ID: " << temp->patient_id
             << ", Doctor ID: " << temp->doctor_id
             << ", Date: " << temp->appointment_date << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Register a Patient" << endl;
        cout << "2. Register a Doctor" << endl;
        cout << "3. Register an Appointment" << endl;
        cout << "4. Display Patients" << endl;
        cout << "5. Display Doctors" << endl;
        cout << "6. Display Appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                registerDoctor();
                break;
            case 3:
                registerAppointment();
                break;
            case 4:
                displayPatients();
                break;
            case 5:
                displayDoctors();
                break;
            case 6:
                displayAppointments();
                break;
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

