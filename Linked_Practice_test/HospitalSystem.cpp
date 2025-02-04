#include <iostream>
#include <string>
using namespace std;

// Definition of the Patient structure for storing patient information
struct Patient
{
    int patient_id; 
    string name;    
    string dob;    
    string gender;  
    Patient *next;  
};

// Definition of the Doctor structure for storing doctor information
struct Doctor
{
    int doctor_id;         
    string name;           
    string specialization; 
    Doctor *next;          
};

// Definition of the Appointment structure for storing appointment information
struct Appointment
{
    int appointment_id;      
    int patient_id;          
    int doctor_id;           
    string appointment_date;
    Appointment *next;       
};

// Pointers to the head nodes of the linked lists
Patient *patientsHead = nullptr;        
Doctor *doctorsHead = nullptr;           
Appointment *appointmentsHead = nullptr; 

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

    
    if (patientExists(newPatient->patient_id))
    {
        cout << "Error, Patient trying to be registered already exists!!!\n";
        delete newPatient;
        return;
    }

    
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newPatient->name);
    cout << "Enter the birthdate (DD/MM/YYYY): ";
    getline(cin, newPatient->dob);
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

   
    if (doctorExists(newDoctor->doctor_id))
    {
        cout << "Error, Doctor trying to be registered already exists!!!\n";
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

   
    if (appointmentExists(newAppointment->appointment_id))
    {
        cout << "Error, Appointment trying to be registered already exists!!!\n";
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

   
    cout << "Enter the appointment date (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, newAppointment->appointment_date);

    
    newAppointment->next = appointmentsHead;
    appointmentsHead = newAppointment;

    cout << "New Appointment Registered successfully!!!\n";
}

// Function to display all registered doctors
void displayDoctors()
{
    Doctor *current = doctorsHead;

    if (!current)
    {
        cout << "No doctors found!\n";
        return;
    }

    
    while (current)
    {
        cout << "ID: " << current->doctor_id << ", Name: " << current->name
             << ", Specialization: " << current->specialization << "\n";
        current = current->next;
    }
}

// Function to display all registered patients
void displayPatients()
{
    Patient *current = patientsHead; 

    if (!current)
    {
        cout << "No patients found!\n";
        return;
    }

    
    while (current)
    {
        cout << "ID: " << current->patient_id << ", Name: " << current->name
             << ", DOB: " << current->dob << ", Gender: " << current->gender << "\n";
        current = current->next;
    }
}

// Function to display all registered appointments
void displayAppointments()
{
    Appointment *current = appointmentsHead; 

    if (!current)
    {
        cout << "No appointments found!\n";
        return;
    }

    
    while (current)
    {
        cout << "ID: " << current->appointment_id << ", Patient ID: " << current->patient_id
             << ", Doctor ID: " << current->doctor_id << ", Date: " << current->appointment_date << "\n";
        current = current->next;
    }
}

// Menu function to handle user interactions
void menu()
{
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Register a Patient\n";
        cout << "2. Register a Doctor\n";
        cout << "3. Register an Appointment\n";
        cout << "4. Display Patients\n";
        cout << "5. Display Doctors\n";
        cout << "6. Display Appointments\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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
            cout << "Exiting the program.... Goodbye!\n";
            break;
        default:
            cout << "Invalid number choice. Please try again.\n";
        }
    } while (choice != 7);
}


int main()
{
    menu(); // Call the menu function to start the program
    return 0;
}
