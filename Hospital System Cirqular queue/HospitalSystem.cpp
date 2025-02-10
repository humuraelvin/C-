#include<iostream>
#include<string>
#include<regex>
using namespace std;

struct Patient
{
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient *next;
};

struct Doctor
{
    int doctor_id;
    string name;
    string specializaiton;
    Doctor *next;
};

struct Appointment
{
    int appointment_id;
    int doctor_id;
    int patient_id;
    string appointment_date;
    Appointment *next;
};

Patient *patientsHead = nullptr;
Doctor *doctorsHead = nullptr;
Appointment *appointmentsHead = nullptr;

// Function to validate date format (DD/MM/YYYY)
bool isValidDate(const string &date)
{
    regex datePattern("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");
    return regex_match(date, datePattern);
}

// Function to validate ID input
bool isValidID(int id)
{
    return id > 0;
}

// Function to check if a patient ID already exists in the list
bool patientExists(int id)
{
    Patient *current = patientsHead;
    while (current)
    {
        if (current->patient_id == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to check if a doctor ID already exists in the list
bool doctorExists(int id)
{
    Doctor *current = doctorsHead;
    while (current)
    {
        if (current->doctor_id == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to check if an appointment ID already exists in the list
bool appointmentExists(int id)
{
    Appointment *current = appointmentsHead;
    while (current)
    {
        if (current->appointment_id == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to register a new patient
void registerPatient()
{
    Patient *newPatient = new Patient;

    cout << "Enter patient id: ";
    cin >> newPatient->patient_id;

    if (!isValidID(newPatient->patient_id) || patientExists(newPatient->patient_id))
    {
        cout << "Error, Invalid ID or Patient already exists!\n";
        delete newPatient;
        return;
    }

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newPatient->name);

    do
    {
        cout << "Enter the birthdate (DD/MM/YYYY): ";
        getline(cin, newPatient->dob);
        if (!isValidDate(newPatient->dob))
            cout << "Invalid date format! Please enter again.\n";
    } while (!isValidDate(newPatient->dob));

    cout << "Enter the gender: ";
    getline(cin, newPatient->gender);

    newPatient->next = patientsHead;
    patientsHead = newPatient;

    cout << "New Patient registered successfully!\n";
}

// Function to register a new doctor
void registerDoctor()
{
    Doctor *newDoctor = new Doctor;

    cout << "Enter the id: ";
    cin >> newDoctor->doctor_id;

    if (!isValidID(newDoctor->doctor_id) || doctorExists(newDoctor->doctor_id))
    {
        cout << "Error, Invalid ID or Doctor already exists!\n";
        delete newDoctor;
        return;
    }

    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, newDoctor->name);
    cout << "Enter the specialization: ";
    getline(cin, newDoctor->specialization);

    newDoctor->next = doctorsHead;
    doctorsHead = newDoctor;

    cout << "New Doctor Registered successfully!!!\n";
}

// Function to register a new appointment
void registerAppointment()
{
    Appointment *newAppointment = new Appointment;

    cout << "Enter the appointment id: ";
    cin >> newAppointment->appointment_id;

    if (!isValidID(newAppointment->appointment_id) || appointmentExists(newAppointment->appointment_id))
    {
        cout << "Error, Invalid ID or Appointment already exists!\n";
        delete newAppointment;
        return;
    }

    cout << "Enter the patient id: ";
    cin >> newAppointment->patient_id;
    if (!patientExists(newAppointment->patient_id))
    {
        cout << "Error, the Patient does not exist!!!!\n";
        delete newAppointment;
        return;
    }

    cout << "Enter the doctor id: ";
    cin >> newAppointment->doctor_id;
    if (!doctorExists(newAppointment->doctor_id))
    {
        cout << "Error, the Doctor does not exist!!!\n";
        delete newAppointment;
        return;
    }

    do
    {
        cout << "Enter the appointment date (DD/MM/YYYY): ";
        cin.ignore();
        getline(cin, newAppointment->appointment_date);
        if (!isValidDate(newAppointment->appointment_date))
            cout << "Invalid date format! Please enter again.\n";
    } while (!isValidDate(newAppointment->appointment_date));

    newAppointment->next = appointmentsHead;
    appointmentsHead = newAppointment;

    cout << "New Appointment Registered successfully!!!\n";
}
