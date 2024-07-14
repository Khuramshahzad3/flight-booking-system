#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;
void main_menu();
void admin_menu();
void user_menu();
void welcome();
class Utility
{
public:
    static int GetNumberFromUser(long double len)
    {
        char strNum[30];
        char ch;
        int i = 0;
        while (i < len)
        {
            ch = _getch();
            if (ch >= '0' && ch <= '9')
            {
                cout << ch;
                strNum[i] = ch;
                i++;
            }
            if (ch == '\r')
            {
                break;
            }
            if (ch == '\b' && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        }
        strNum[i] = '\0';
        cout << endl;
        if (i == 0)
        {
            return 0;
        }
        else
        {
            return atoi(strNum);
        }
    }
    static string GetStringFromUser(long long int len)
    {
        char strNum[256];
        char ch;
        int i = 0;
        while (i < len)
        {
            ch = _getch();
            if (ch >= 'A' && ch <= 'z' || ch == ' ')
            {
                cout << ch;
                strNum[i] = ch;
                i++;
            }
            if (ch == '\r')
            {
                break;
            }
            if (ch == '\b' && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        }
        strNum[i] = '\0';
        cout << endl;
        if (i <= 0)
        {
            return "";
        }
        else
        {
            return (strNum);
        }
    }
};
class person
{
public:
    string name;
    string CNIC;
    string contactNo;
    person()
    {
        name = '\0';
        CNIC = '\0';
        contactNo = '\0';
    }
    ~person()
    {
    }
};
class Airport

{
public:
    int AID;
    string SairportName;
    string SairportCity;
    string SairportCountry;
    string DairportName;
    string DairportCity;
    string DairportCountry;
    Airport()
    {
        SairportName = '\0';
        SairportCity = '\0';
        SairportCountry = '\0';
        DairportName = '\0';
        DairportCity = '\0';
        DairportCountry = '\0';
        AID = 0;
    }
    void displayAirportDetails()
    {
        cout << setw(15) << AID
             << setw(20) << SairportName
             << setw(20) << SairportCity
             << setw(20) << SairportCountry
             << setw(20) << DairportName
             << setw(20) << DairportCity
             << setw(20) << DairportCountry << endl;
    }
    ~Airport()
    {
        // Destructor for Airport class
    }
    static void airport_menu()
    {

        cout << "\t\t\t\t\t\t\tAirport Records Management" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\t1. Add     Airports" << endl;
        cout << "\t\t\t\t\t\t\t2. Display Airports" << endl;
        cout << "\t\t\t\t\t\t\t3. Search  Airports" << endl;
        cout << "\t\t\t\t\t\t\t4. Update  Airports" << endl;
        cout << "\t\t\t\t\t\t\t5. Delete  Airports" << endl;
        cout << "\t\t\t\t\t\t\t6. Go Back" << endl;
        cout << "\t\t\t\t\t\t\t7. Exit From Program" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice --> ";
    }
    void ParseValues(string line)
    {
        string delimiter = ",";
        size_t pos;
        string token;
        pos = line.find(delimiter);
        token = line.substr(0, pos);
        AID = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        SairportName = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        SairportCity = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        SairportCountry = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        DairportName = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        DairportCity = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        DairportCountry = token;
        line.erase(0, pos + delimiter.length());
    }
};
class airportcollection
{
public:
    Airport airportarr[100];
    int airportcounter = 0;
    int FindAirportByID(int id)
    {

        for (int i = 0; i < airportcounter; i++)
        {
            if (id == airportarr[i].AID)
            {
                return i;
            }
        }
        return -1;
    }
    int FindAirportBySairportCountry(string con)
    {

        for (int i = 0; i < airportcounter; i++)
        {
            if (con == airportarr[i].SairportCountry)
            {
                return i;
            }
        }
        return -1;
    }
    void manageAirportRecords()
    {
        int indx;
        int choice;
        do
        {
            Airport::airport_menu();
            choice = Utility::GetNumberFromUser(4);
            switch (choice)
            {
            case 1:
                if (airportcounter < 100)
                {
                    addAirportRecord();
                }
                break;
            case 2:
                if (airportcounter <= 0)
                {
                    cout << "--------List is empty-------- " << endl;
                }
                else
                {
                    cout << "\t\t\t\t\tList of all Airports " << endl;
                    cout << "_____________________________________________________________________________________________________________________________________________" << endl
                         << endl;
                    cout << left << setw(15) << "AID"
                         << setw(20) << "SairportName"
                         << setw(20) << "SairportCity"
                         << setw(20) << "SairportCountry"
                         << setw(20) << "DairportName"
                         << setw(20) << "DairportCity"
                         << setw(20) << "DairportCountry" << endl;
                    cout << "_____________________________________________________________________________________________________________________________________________" << endl;

                    for (int i = 0; i < airportcounter; i++)

                        airportarr[i].displayAirportDetails();
                }
                break;
            case 3:
                cout << "Search by Airport ID:";
                int id;
                id = Utility::GetNumberFromUser(4);
                indx = FindAirportByID(id);
                if (indx >= 0)
                {
                    cout << "_____________________________________________________________________________________________________________________________________________" << endl
                         << endl;
                    cout << left << setw(15) << "AID"
                         << setw(20) << "SairportName"
                         << setw(20) << "SairportCity"
                         << setw(20) << "SairportCountry"
                         << setw(20) << "DairportName"
                         << setw(20) << "DairportCity"
                         << setw(20) << "DairportCountry" << endl;
                    cout << "_____________________________________________________________________________________________________________________________________________" << endl;

                    airportarr[indx].displayAirportDetails();
                }
                else
                    cout << "Airport not found" << endl;
                break;
            case 4:
                updateAirportRecord();
                break;
            case 5:
                deleteAirportRecord();
                break;
            case 6:
                cout << "Exiting Airport Records Management..." << endl;
                admin_menu();
                break;
            case 7:
                cout << "Have a nice Day";
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                system("pause");
            }

            cout << endl;
        } while (choice != 6);
    }
    void addAirportRecord()
    {
        cout << "Adding new Airport " << endl;
        airportarr[airportcounter].AID = airportcounter + 1;

        cout << "Enter SairportName: ";
        airportarr[airportcounter].SairportName = Utility::GetStringFromUser(100);

        cout << "Enter SairportCity: ";
        airportarr[airportcounter].SairportCity = Utility::GetStringFromUser(100);

        cout << "Enter SairportCountry: ";
        airportarr[airportcounter].SairportCountry = Utility::GetStringFromUser(100);
        cout << "Enter DairportName: ";
        airportarr[airportcounter].DairportName = Utility::GetStringFromUser(100);
        cout << "Enter DairportCity: ";
        airportarr[airportcounter].DairportCity = Utility::GetStringFromUser(100);
        cout << "Enter DairportCountry: ";
        airportarr[airportcounter].DairportCountry = Utility::GetStringFromUser(100);
        cout << "Airport added Successfully " << endl;
        airportcounter++;
    }
    void updateAirportRecord()
    {
        cout << "Enter Airport ID to update: ";
        int id = Utility::GetNumberFromUser(100);
        int index = FindAirportByID(id);
        if (index >= 0)
        {

            cout << "Enter new Source Airport Name: ";
            airportarr[index].SairportName = Utility::GetStringFromUser(100);

            cout << "Enter new Source airportCity: ";
            airportarr[index].SairportCity = Utility::GetStringFromUser(100);

            cout << "Enter new Source airportCountry: ";
            airportarr[index].SairportCountry = Utility::GetStringFromUser(100);
            cout << "Enter new Destination Airport: ";
            airportarr[index].DairportName = Utility::GetStringFromUser(100);
            cout << "Enter new Destination Airport City: ";
            airportarr[index].DairportCity = Utility::GetStringFromUser(100);
            cout << "Enter new Destination Airport Country: ";
            airportarr[index].SairportCountry = Utility::GetStringFromUser(100);

            cout << "Airport updated successfully" << endl;
        }
        else
        {
            cout << "Airport not found" << endl;
        }
    }

    void deleteAirportRecord()
    {
        cout << "Enter Airport ID to delete: ";
        int id = Utility::GetNumberFromUser(5);
        int index = FindAirportByID(id);
        if (index >= 0)
        {
            // Shift elements to delete the record
            for (int i = index; i < airportcounter - 1; i++)
            {
                airportarr[i] = airportarr[i + 1];
            }
            airportcounter--;
            cout << "Airport deleted successfully" << endl;
        }
        else
        {
            cout << "Airport not found" << endl;
        }
    }
    void WriteDataToFile3()
    {
        ofstream fileWriter;
        fileWriter.open("Airports.txt");
        if (!fileWriter.is_open())
        {
            cout << "File open error\n";
        }
        else
        {
            for (int i = 0; i < airportcounter; i++)
            {
                fileWriter << airportarr[i].AID << "," << airportarr[i].SairportName << "," << airportarr[i].SairportCity << "," << airportarr[i].SairportCountry << "," << airportarr[i].DairportName << "," << airportarr[i].DairportCity << "," << airportarr[i].DairportCountry << endl;
            }
            fileWriter.close();
        }
    }

    void ReadDataFromFile3()
    {
        ifstream fileReader;
        fileReader.open("Airports.txt");
        if (!fileReader)
        {
            cout << "File open error\n";
        }
        else
        {
            while (1)
            {
                string line;
                if (getline(fileReader, line))
                {
                    airportarr[airportcounter].ParseValues(line);
                    airportcounter++;
                }
                else
                    break;
            }
            fileReader.close();
        }
    }
} mga;
class Flight
{
public:
    string flightNumber;
    string source;
    string destination;
    int capacity;
    int date;
    string deptime;
    string arrivaltime;
    string airline;
    int remcapacity;
    Airport *ptrairports; // Pointer to Airport class

public:
    Flight()
    {
        flightNumber = '\0';
        source = '\0';
        destination = '\0';
        date = 0;
        capacity = 0;
        remcapacity = 0;
        deptime = '\0';
        arrivaltime = '\0';
        airline = '\0';
        ptrairports = nullptr;
    }

    static void flight_menu()
    {
        cout << "\t\t\t\t\t\t Flights Records/Schedule Management" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\t1. Add     Flights" << endl;
        cout << "\t\t\t\t\t\t\t2. Display Flights" << endl;
        cout << "\t\t\t\t\t\t\t3. Search  Flights" << endl;
        cout << "\t\t\t\t\t\t\t4. Update  Flights" << endl;
        cout << "\t\t\t\t\t\t\t5. Delete  Flights" << endl;
        cout << "\t\t\t\t\t\t\t6. Go Back" << endl;
        cout << "\t\t\t\t\t\t\t7. Exit From Program" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice --> ";
    }
    void ParseValues(string line)
    {
        string delimiter = ",";
        size_t pos;
        string token;
        pos = line.find(delimiter);
        token = line.substr(0, pos);
        flightNumber = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        source = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        destination = token;
        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        token = line.substr(0, pos);
        capacity = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        token = line.substr(0, pos);
        remcapacity = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        date = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        deptime = token;
        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        token = line.substr(0, pos);
        arrivaltime = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        airline = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        int id = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());
        int index = mga.FindAirportByID(id);
        ptrairports = &mga.airportarr[index];
    }
    void displayFlightDetails()
    {
        // Output data in tabular form for each field

        cout << setw(15) << flightNumber
             << setw(15) << source
             << setw(15) << destination
             << setw(10) << capacity
             << setw(10) << date
             << setw(10) << deptime
             << setw(15) << arrivaltime
             << setw(15) << airline
             << setw(15) << ptrairports->SairportName
             << setw(15) << ptrairports->DairportName << endl;
    }
    ~Flight()
    {
    }
};

class Passenger : public person
{
public:
    string passengerName;
    int age;
    string passportNumber;
    int passengerID;

public:
    Passenger()
    {
        passengerName = '\0';
        age = 0;
        passportNumber = '\0';
        passengerID = 0;
    }
    ~Passenger()
    {
        // Destructor for Passenger class
    }
    void displayPassengerRecord()
    {
        cout << left << setw(20) << passengerID
             << setw(20) << passengerName
             << setw(8) << age
             << setw(20) << CNIC
             << setw(20) << passportNumber
             << setw(20) << contactNo << endl;
    }
    static void passernger_menu()
    {

        cout << "\t\t\t\t\t\t    Passenger Records Management" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\t1. Add     Passenger" << endl;
        cout << "\t\t\t\t\t\t\t2. Display Passenger Records" << endl;
        cout << "\t\t\t\t\t\t\t3. Search  Passenger" << endl;
        cout << "\t\t\t\t\t\t\t4. Update  Passenger Record" << endl;
        cout << "\t\t\t\t\t\t\t5. Delete  Passenger Record " << endl;
        cout << "\t\t\t\t\t\t\t6. Go Back" << endl;
        cout << "\t\t\t\t\t\t\t7. Exit From Program" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice --> ";
    }
    void ParseValues(string line)
    {
        string delimiter = ",";
        size_t pos;
        string token;

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        passengerID = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        passengerName = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        age = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        CNIC = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        passportNumber = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        contactNo = token;
        line.erase(0, pos + delimiter.length());
    }
};

class flightscollection
{
public:
    Flight flightarr[100];
    int flightcounter = 0;
    int FindFlightBydes(string no)
    {
        for (int i = 0; i < flightcounter; i++)
        {
            if (no == flightarr[i].destination)
            {
                return i;
            }
        }
        return -1;
    }
    int FindFlightByflightno(string no)
    {
        for (int i = 0; i < flightcounter; i++)
        {
            if (no == flightarr[i].flightNumber)
            {
                return i;
            }
        }
        return -1;
    }
    void manageFlightRecords()
    {
        int choice1;
        do
        {
            Flight::flight_menu();
            choice1 = Utility::GetNumberFromUser(4);

            switch (choice1)
            {
            case 1:
                if (flightcounter < 100)
                {
                    addFlightRecord();
                }
                break;
            case 2:
                showflights();
                break;
            case 3:
            {
                int choice;

                cout << "1. Search Flight by Flight Number " << endl;
                cout << "2. Search Flight by Destination " << endl;
                choice = Utility::GetNumberFromUser(4);
                if (choice == 1)
                {
                    searchflightbyno();
                }
                if (choice == 2)
                {
                    searchflight();
                }
            }
            break;
            case 4:
                updateFlightRecord();
                break;
            case 5:
                deleteFlightRecord();
                break;
            case 6:
                cout << "Exiting Flight Records Management..." << endl;
                admin_menu();
                break;
            case 7:
                cout << "Have a nice Day";
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }

            cout << endl;
        } while (choice1 != 6);
    }
    void showflights()
    {
        if (flightcounter <= 0)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "\t\t\t\t\t\t\tList of all Flights" << endl;
            cout << "________________________________________________________________________________________________________________________________________" << endl
                 << endl;
            cout << left << setw(15) << "FlightNumber"
                 << setw(15) << "Source"
                 << setw(15) << "Destination"
                 << setw(10) << "Capacity"
                 << setw(10) << "Date"
                 << setw(10) << "Deptime"
                 << setw(15) << "Arrivaltime"
                 << setw(15) << "Airline"
                 << setw(15) << "SairportName"
                 << setw(15) << "DairportName" << endl;
            cout << "________________________________________________________________________________________________________________________________________" << endl;
            cout << endl;
            for (int i = 0; i < flightcounter; i++)
            {

                flightarr[i].displayFlightDetails();
            }
        }
    }
    void searchflight()
    {
        int indx;
        cout << "Search by Destination:";
        string des;
        getline(cin, des);
        indx = FindFlightBydes(des);
        if (indx >= 0)
        {
            cout << "________________________________________________________________________________________________________________________________________" << endl
                 << endl;
            cout << left << setw(15) << "FlightNumber"
                 << setw(15) << "Source"
                 << setw(15) << "Destination"
                 << setw(10) << "Capacity"
                 << setw(10) << "Date"
                 << setw(10) << "Deptime"
                 << setw(15) << "Arrivaltime"
                 << setw(15) << "Airline"
                 << setw(15) << "SairportName"
                 << setw(15) << "DairportName" << endl;
            cout << "________________________________________________________________________________________________________________________________________" << endl;
            cout << endl;
            flightarr[indx].displayFlightDetails();
        }
        else
            cout << "Flight not found" << endl;
    }
    void searchflightbyno()
    {
        int indx;
        cout << "Search by Flight Number:";
        string no;
        getline(cin, no);
        indx = FindFlightByflightno(no);
        if (indx >= 0)
        {
            cout << "________________________________________________________________________________________________________________________________________" << endl
                 << endl;
            cout << left << setw(15) << "FlightNumber"
                 << setw(15) << "Source"
                 << setw(15) << "Destination"
                 << setw(10) << "Capacity"
                 << setw(10) << "Date"
                 << setw(10) << "Deptime"
                 << setw(15) << "Arrivaltime"
                 << setw(15) << "Airline"
                 << setw(15) << "SairportName"
                 << setw(15) << "DairportName" << endl;
            cout << "________________________________________________________________________________________________________________________________________" << endl;
            cout << endl;
            flightarr[indx].displayFlightDetails();
        }
        else
            cout << "Flight not found" << endl;
    }

    void addFlightRecord()
    {

        cout << "Enter Flight number : ";
        getline(cin, flightarr[flightcounter].flightNumber);
        cout << "Enter Flight source : ";
        flightarr[flightcounter].source = Utility::GetStringFromUser(100);
        cout << "Enter Flight destination : ";
        getline(cin, flightarr[flightcounter].destination);
        cout << "Enter Flight capacity : ";
        flightarr[flightcounter].capacity = Utility::GetNumberFromUser(4);
        flightarr[flightcounter].remcapacity = flightarr[flightcounter].capacity;
        cout << "Enter Flight date(DDMMYYYY): ";
        // getline(cin, flightarr[flightcounter].date);
        // flightarr[flightcounter].date = Utility::GetNumberFromUser(9);
        cin >> flightarr[flightcounter].date;
        // system("pause");
        cin.ignore();
        cout << "Enter Flight departure time: ";
        getline(cin, flightarr[flightcounter].deptime);

        cout << "Enter Flight arrival time: ";
        getline(cin, flightarr[flightcounter].arrivaltime);
        cout << "Enter Airline: ";
        flightarr[flightcounter].airline = Utility::GetStringFromUser(100);

        cout << "Enter Airport ID To Add:";
        int pid = Utility::GetNumberFromUser(4);
        int index = mga.FindAirportByID(pid);
        cout << "Please wait......." << endl;
        cout << "Checking for Airport" << endl;
        Sleep(2000);
        if (index < 0)
        {
            cout << "Airport not found.Kindly Add Airport First to Add Flight " << endl;
        }
        else
        {
            flightarr[flightcounter].ptrairports = &mga.airportarr[index];
            cout << "Flight added Successfully " << endl;
            flightcounter++;
        }
    }

    void updateFlightRecord()
    {
        cout << "Enter Flight Number to update: ";
        string no;
        getline(cin, no);
        int index = FindFlightByflightno(no);
        if (index >= 0)
        {
            cout << "Enter new Flight source: ";
            flightarr[index].source = Utility::GetStringFromUser(100);

            cout << "Enter new Flight destination: ";
            flightarr[index].destination = Utility::GetStringFromUser(100);

            cout << "Enter new Flight capacity: ";
            flightarr[index].capacity = Utility::GetNumberFromUser(100);
            flightarr[index].remcapacity = flightarr[index].capacity;
            cout << "Enter new Flight date(DDMMYYYY): ";
            cin >> flightarr[index].date;
            system("pause");
            cout << "Enter new Flight departure time: ";
            getline(cin, flightarr[index].deptime);

            cout << "Enter new Flight arrival time: ";
            getline(cin, flightarr[index].arrivaltime);

            cout << "Enter Airport ID To Add:";
            int pid = Utility::GetNumberFromUser(4);
            int index = mga.FindAirportByID(pid);
            cout << "Please wait......." << endl;
            cout << "Checking for Airport" << endl;
            Sleep(2000);
            if (index < 0)
            {
                cout << "Airport not found.Kindly Add Airport First to Add Flight From this Airport " << endl;
            }
            else
            {
                flightarr[flightcounter].ptrairports = &mga.airportarr[index];
                cout << "Flight Updated Successfully " << endl;
            }
        }
        else
        {
            cout << "Flight not found" << endl;
        }
    }

    void deleteFlightRecord()
    {
        cout << "Enter Flight Number to delete: ";
        string no;
        getline(cin, no);
        int index = FindFlightByflightno(no);
        if (index >= 0)
        {
            // Shift elements to delete the record
            for (int i = index; i < flightcounter - 1; i++)
            {
                flightarr[i] = flightarr[i + 1];
            }
            flightcounter--;
            cout << "Flight deleted successfully" << endl;
        }
        else
        {
            cout << "Flight not found" << endl;
        }
    }
    void WriteDataToFile1()
    {
        ofstream fileWriter;
        fileWriter.open("Flights.txt");
        if (!fileWriter.is_open())
        {
            cout << "File open error\n";
        }
        else
        {
            for (int i = 0; i < flightcounter; i++)
            {
                fileWriter << flightarr[i].flightNumber << ",";
                fileWriter << flightarr[i].source << ",";
                fileWriter << flightarr[i].destination << ",";
                fileWriter << flightarr[i].capacity << ",";
                fileWriter << flightarr[i].remcapacity << ",";
                fileWriter << flightarr[i].date << ",";
                fileWriter << flightarr[i].deptime << ",";
                fileWriter << flightarr[i].arrivaltime << ",";
                fileWriter << flightarr[i].airline << ",";
                fileWriter << flightarr[i].ptrairports->AID << endl;
            }

            fileWriter.close();
        }
    }

    void ReadDataFromFile1()
    {
        ifstream fileReader;
        fileReader.open("Flights.txt");

        if (!fileReader.is_open())
        {
            cout << "File open error\n";
        }
        else
        {
            while (1)
            {
                string line;
                if (getline(fileReader, line))
                {
                    flightarr[flightcounter].ParseValues(line);
                    flightcounter++;
                }
                else
                    break;
            }
            fileReader.close();
        }
    }
} mgf;
class passengercollection
{
public:
    Passenger passengerarr[100];
    int passengercounter = 0;

    void managePassengerRecords()
    {
        int choice;
        do
        {
            Passenger::passernger_menu();
            choice = Utility::GetNumberFromUser(4);

            switch (choice)
            {
            case 1:
                if (passengercounter < 100)
                {
                    addPassengerRecord();
                }
                break;
            case 2:
                if (passengercounter <= 0)
                {
                    cout << "----- List is empty -----\n";
                    break;
                }
                else
                {
                    cout << " \n\n\t\t\t\t\t\tList of all Passengers" << endl;
                    cout << "_____________________________________________________________________________________________________________________________________________" << endl
                         << endl;

                    cout << left << setw(20) << "PassengerID"
                         << setw(20) << "PassengerName"
                         << setw(8) << "Age"
                         << setw(20) << "CNIC"
                         << setw(20) << "PassportNumber"
                         << setw(20) << "ContactNumber" << endl;

                    cout << "_____________________________________________________________________________________________________________________________________________" << endl;
                    for (int i = 0; i < passengercounter; i++)
                    {
                        passengerarr[i].displayPassengerRecord();
                    }
                }
                break;
            case 3:
                searchPassengerRecord();
                break;
            case 4:
                updatePassengerRecord();
                break;
            case 5:
                deletePassengerRecord();
                break;
            case 6:
                int choice;
            a:
                cout << "1. To Go To Adminmenu" << endl;
                cout << "2. To Go To Usermenu" << endl;
                cout << "Enter your choice-> " << endl;
                choice = Utility::GetNumberFromUser(4);
                if (choice == 1)
                {
                    cout << "Exiting Passenger Records Management..." << endl;
                    admin_menu();
                }
                else if (choice == 2)
                {
                    cout << "Exiting Passenger Records Management..." << endl;
                    user_menu();
                }
                else
                {
                    cout << "Please Enter choice from available" << endl;
                    goto a;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }

            cout << endl;
        } while (choice != 7);
    }
    void addPassengerRecord()
    {
        cout << "----------Adding new Passenger---------- " << endl;
        passengerarr[passengercounter].passengerID = passengercounter + 1;
        cout << "Enter Passenger Name : ";
        passengerarr[passengercounter].passengerName = Utility::GetStringFromUser(100);

        cout << "Enter Age : ";
        passengerarr[passengercounter].age = Utility::GetNumberFromUser(15);
        cout << "Enter CNIC : ";
        // passengerarr[passengercounter].CNIC = Utility::GetNumberFromUser(15);
        cin >> passengerarr[passengercounter].CNIC;

        cout << "Enter passport Number : ";
        passengerarr[passengercounter].passportNumber = Utility::GetNumberFromUser(15);
        cout << "Enter Contact Number : ";
        passengerarr[passengercounter].contactNo = Utility::GetNumberFromUser(15);
        cout << "Passenger added Successfully " << endl;
        passengercounter++;
    }
    void searchPassengerRecord()
    {
        cout << "Search by ID:";
        int id;
        id = Utility::GetNumberFromUser(4);
        int indx = Findpassengerbyid(id);
        if (indx >= 0)
        {
            cout << "_____________________________________________________________________________________________________________________________________________" << endl
                 << endl;

            cout << left << setw(20) << "PassengerID"
                 << setw(20) << "PassengerName"
                 << setw(8) << "Age"
                 << setw(20) << "CNIC"
                 << setw(20) << "PassportNumber"
                 << setw(20) << "ContactNumber" << endl;

            cout << "_____________________________________________________________________________________________________________________________________________" << endl;
            passengerarr[indx].displayPassengerRecord();
        }
        else
        {
            cout << "Passenger not found" << endl;
        }
    }
    int Findpassengerbyid(int id)
    {
        for (int i = 0; i < passengercounter; i++)
        {
            if (id == passengerarr[i].passengerID)
            {
                return i;
            }
        }
        return -1;
    }
    void updatePassengerRecord()
    {
        cout << "Enter Passenger ID to update: ";
        int id;
        id = Utility::GetNumberFromUser(4);
        int index = Findpassengerbyid(id);
        if (index >= 0)
        {
            cout << "Enter new Age: ";
            passengerarr[index].age = Utility::GetNumberFromUser(15);
            cout << "Enter new CNIC: ";
            passengerarr[index].CNIC = Utility::GetNumberFromUser(15);
            cout << "Enter new Passport Number: ";
            passengerarr[index].passportNumber = Utility::GetNumberFromUser(15);
            cout << "Enter new Contact Number: ";
            passengerarr[index].contactNo = Utility::GetNumberFromUser(15);
            cout << "Passenger Details updated successfully" << endl;
        }
        else
        {
            cout << "Passenger not found" << endl;
        }
    }

    void deletePassengerRecord()
    {
        cout << "Enter Passenger id to delete: ";
        int id;
        id = Utility::GetNumberFromUser(4);
        int index = Findpassengerbyid(id);
        if (index >= 0)
        {
            // Shift elements to delete the record
            for (int i = index; i < passengercounter - 1; i++)
            {
                passengerarr[i] = passengerarr[i + 1];
            }
            passengercounter--;
            cout << "Passenger deleted successfully" << endl;
        }
        else
        {
            cout << "Passenger not found" << endl;
        }
    }
    void WriteDataToFile2()
    {
        ofstream fileWriter;
        fileWriter.open("Passenger.txt");
        if (!fileWriter.is_open())
        {
            cout << "File open error\n";
        }
        else
        {
            for (int i = 0; i < passengercounter; i++)
            {
                fileWriter << passengerarr[i].passengerID << "," << passengerarr[i].passengerName << "," << passengerarr[i].age << "," << passengerarr[i].CNIC << "," << passengerarr[i].passportNumber << "," << passengerarr[i].contactNo << endl;
            }
            fileWriter.close();
        }
    }
    void ReadDataFromFile2()
    {
        ifstream fileReader;
        fileReader.open("Passenger.txt");
        if (!fileReader)
        {
            cout << "File open error\n";
        }
        else
        {
            while (1)
            {
                string line;
                if (getline(fileReader, line))
                {
                    passengerarr[passengercounter].ParseValues(line);
                    passengercounter++;
                }
                else
                    break;
            }
            fileReader.close();
        }
    }
} mgp;
class Reservation
{
public:
    int reservationId;
    int seatNumber;
    string reservationStatus;
    int date;
    string res_type;
    Passenger *ptrpassenger;
    Flight *ptrflight;
    Reservation()
    {
        reservationId = 0;
        seatNumber = 0;
        reservationStatus = '\0';
        date = '0';
        res_type = '\0';
        ptrpassenger = nullptr;
        ptrflight = nullptr;
    }
    void displayReservationDetails()
    {
        // if (ptrpassenger && ptrflight != nullptr)
        // {
        cout << setw(18) << reservationId
             << setw(20) << ptrflight->flightNumber
             << setw(30) << ptrpassenger->passengerName
             << setw(10) << seatNumber
             << setw(15) << reservationStatus
             << setw(15) << res_type
             << setw(15) << date << endl;
        // }
    }

    ~Reservation()
    {
        // Destructor for Reservation class
    }
    static void reservation_menu()
    {

        cout << "\t\t\t\t\t\t    Reservation Records Management" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\t1. Add     Reservation" << endl;
        cout << "\t\t\t\t\t\t\t2. Display Reservations" << endl;
        cout << "\t\t\t\t\t\t\t3. Search  Reservation" << endl;
        cout << "\t\t\t\t\t\t\t4. Update  Reservation" << endl;
        cout << "\t\t\t\t\t\t\t5. Cancell  Reservation" << endl;
        cout << "\t\t\t\t\t\t\t6. Go Back" << endl;
        cout << "\t\t\t\t\t\t\t7. Exit From Program" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice --> ";
    }
    void ParseValues(string line)
    {
        string delimiter = ",";
        size_t pos;
        string token;
        pos = line.find(delimiter);
        token = line.substr(0, pos);
        reservationId = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        string no = token;
        line.erase(0, pos + delimiter.length());
        int index = mgf.FindFlightByflightno(no);
        ptrflight = &mgf.flightarr[index];

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        int id = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());
        int index1 = mgp.Findpassengerbyid(id);
        ptrpassenger = &mgp.passengerarr[index1];

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        seatNumber = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        reservationStatus = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        res_type = token;
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        token = line.substr(0, pos);
        date = atoi(token.c_str());
        line.erase(0, pos + delimiter.length());
    }
};

class reservationcollection
{
public:
    Reservation resarr[100];
    int rescounter = 0;
    void managereservationRecords()
    {

        int indx;
        int choice1;
        do
        {
            Reservation::reservation_menu();
            choice1 = Utility::GetNumberFromUser(4);
            switch (choice1)
            {
            case 1:
            {
                if (rescounter < 100)
                {
                    addreservationRecord();
                }
                break;
            }
            case 2:
            {
                if (rescounter <= 0)
                {
                    cout << "List is empty" << endl;
                }
                else
                {
                    cout << " \n\t\t\t\t\t\tList of all Reservations  " << endl;
                    cout << "______________________________________________________________________________________________________________________" << endl
                         << endl;
                    cout << left << setw(18) << "ReservationId"
                         << setw(20) << "FlightNumber"
                         << setw(30) << "PassengerName"
                         << setw(10) << "Seat No"
                         << setw(15) << "Status"
                         << setw(15) << "ResType"
                         << setw(15) << "Date" << endl;
                    cout << "______________________________________________________________________________________________________________________" << endl;

                    for (int i = 0; i < rescounter; i++)
                    {

                        resarr[i].displayReservationDetails();
                    }
                }
                break;
            }
            case 3:
            {
                cout << "Search Reservation by ID:";
                int id = -1;
                cin >> id;
                indx = FindreservationByID(id);
                if (indx >= 0)
                {
                    cout << "______________________________________________________________________________________________________________________" << endl
                         << endl;
                    cout << left << setw(18) << "ReservationId"
                         << setw(20) << "FlightNumber"
                         << setw(30) << "PassengerName"
                         << setw(10) << "Seat No"
                         << setw(15) << "Status"
                         << setw(15) << "ResType"
                         << setw(15) << "Date" << endl;
                    cout << "______________________________________________________________________________________________________________________" << endl;

                    resarr[indx].displayReservationDetails();
                }
                else
                {
                    cout << "Reservation not found" << endl;
                }
                break;
            }
            case 4:
            {
                updateReservationRecord();
                break;
            }
            case 5:
            {
                deleteReservationRecord();
                break;
            }

            case 6:
            {
                int choice;
            a:
                cout << "1. To Go To Adminmenu" << endl;
                cout << "2. To Go To Usermenu" << endl;
                cout << "Enter your choice-> " << endl;
                choice = Utility::GetNumberFromUser(4);
                if (choice == 1)
                {
                    cout << "Exiting Reservation Records Management..." << endl;
                    admin_menu();
                }
                else if (choice == 2)
                {
                    cout << "Exiting Reservation Records Management..." << endl;
                    user_menu();
                }
                else
                {
                    cout << "Please Enter choice form available" << endl;
                    goto a;
                }
                break;
            }
            case 7:
            {
                exit(0);
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                system("pause");
            }

            cout << endl;
        } while (choice1 != 7);
    }
    int FindreservationByID(int id)
    {
        for (int i = 0; i < rescounter; i++)
        {
            if (id == resarr[i].reservationId)
            {
                return i;
            }
        }
        return -1;
    }
    void addreservationRecord()
    {
        resarr[rescounter].reservationId = rescounter + 1;
    a:
        cout << "Enter Flight Number:";
        string no;
        getline(cin, no);
        int index = mgf.FindFlightByflightno(no);
        if (index < 0)
        {
            cout << "There is no Flight with this Number.Kindly Enter correct Flight Number " << endl;
            goto a;
        }
        else
        {
            resarr[rescounter].ptrflight = &mgf.flightarr[index];
            resarr[rescounter].ptrflight->remcapacity--;
        }
    b:
        cout << "Enter Passenger ID :";
        int id = Utility::GetNumberFromUser(4);
        int index2 = mgp.Findpassengerbyid(id);
        if (index2 < 0)
        {
            cout << "There is no Passenger with this name.Kindly Enter correct Passenger Name " << endl;
            goto b;
        }
        else
        {
            resarr[rescounter].ptrpassenger = &mgp.passengerarr[index2];
        }

        cout << "Enter seat number : ";
        resarr[rescounter].seatNumber = Utility::GetNumberFromUser(6);

        cout << "Enter reservationStatus : ";
        resarr[rescounter].reservationStatus = Utility::GetStringFromUser(100);
        cout << "Enter reservation Type : ";
        resarr[rescounter].res_type = Utility::GetStringFromUser(100);
        cout << "Enter reservation date (DDMMYYYY): ";
        resarr[rescounter].date = Utility::GetNumberFromUser(10);

        cout << "Reservation added Successfully " << endl;
        cout << "Remaining capacity in Flight Number " << resarr[rescounter].ptrflight->flightNumber << " is " << resarr[rescounter].ptrflight->remcapacity
             << endl;

        rescounter++;
    }
    void updateReservationRecord()
    {
        cout << "Enter Reservation ID to update: ";
        int id = Utility::GetNumberFromUser(4);
        int index = FindreservationByID(id);
        if (index >= 0)
        {
            cout << "Enter new Seat Number: ";
            resarr[index].seatNumber = Utility::GetNumberFromUser(4);

            cout << "Enter new Reservation Status: ";
            resarr[index].reservationStatus = Utility::GetStringFromUser(100);

            cout << "Enter new reservation Type: ";
            resarr[index].res_type = Utility::GetStringFromUser(100);

            cout << "Enter reservation date (DDMMYYYY): ";
            resarr[index].date = Utility::GetNumberFromUser(10);

            cout << "Reservation updated successfully" << endl;
        }

        else
        {
            cout << "Reservation not found" << endl;
        }
    }

    void deleteReservationRecord()
    {
        cout << "Enter Reservation ID to delete: ";
        int id = Utility::GetNumberFromUser(6);
        int index = FindreservationByID(id);
        if (index >= 0)
        {
            // Shift elements to delete the record
            for (int i = index; i < rescounter - 1; i++)
            {
                resarr[i] = resarr[i + 1];
            }
            rescounter--;
            cout << "Reservation deleted successfully" << endl;
        }
        else
        {
            cout << "Reservation not found" << endl;
        }
    }

    void WriteDataToFile4()
    {
        ofstream fileWriter;
        fileWriter.open("Reservations.txt");
        if (!fileWriter.is_open())
        {
            cout << "File open error\n";
        }
        else
        {

            for (int i = 0; i < rescounter; i++)
            {
                fileWriter << resarr[i].reservationId << "," << resarr[i].ptrflight->flightNumber << "," << resarr[i].ptrpassenger->passengerID << "," << resarr[i].seatNumber << "," << resarr[i].reservationStatus << "," << resarr[i].res_type << "," << resarr[i].date << endl;
            }

            fileWriter.close();
        }
    }
    void ReadDataFromFile4()
    {
        ifstream fileReader;
        fileReader.open("Reservations.txt");
        if (!fileReader.is_open())
        {
            cout << "File open error\n";
        }
        else
        {

            while (1)
            {
                string line;
                if (getline(fileReader, line))
                {
                    resarr[rescounter].ParseValues(line);
                    rescounter++;
                }
                else
                    break;
            }
            fileReader.close();
        }
    }
} mgr;
class Ticket
{
public:
    int ticketNumber;
    double ticket_price;
    Reservation *ptrreservation;
    int ticketcounter = 0;
    int storing;

public:
    Ticket()
    {
        ticketNumber = 0;
        ticket_price = 0;
        storing = 0;
        ptrreservation = nullptr;
    }
    void issueticket()
    {
    a:
        cout << "Enter Reservation ID : ";
        int id = Utility::GetNumberFromUser(5);
        int index = mgr.FindreservationByID(id);
        if (index < 0)
        {
            cout << "There is no Reservation with this ID.Kindly Enter correct ID " << endl;
            goto a;
        }
        else
        {
            storing = id;
            ptrreservation = &mgr.resarr[index];
            string DairportCountry = ptrreservation->ptrflight->ptrairports->DairportCountry;
            cout << "Please wait......" << endl;
            cout << "Checking your Flight and Reservation" << endl;
            Sleep(2000);
            if (DairportCountry == "Pakistan")
            {
                cout << "Your are Flying Domestically and your ticket type is " << ptrreservation->res_type << endl;
            }
            else
            {
                cout << "Your are Flying Internationally and your ticket type is " << ptrreservation->res_type << endl;
            }
        }
        cout << "Enter Ticket Number : ";
        ticketNumber = Utility::GetNumberFromUser(5);
        cout << "\n\n\t\t\t\t\t\tToday Ticket Prices" << endl
             << endl;
        cout << "\t\t\t\t\t\t         International Flights  " << endl;
        cout << "\t\t\t\t\t\tBusinuss Class        | Economy Class " << endl;
        cout << "\t\t\t\t\t\t60000                 | 50000 " << endl;

        cout << "\n\n\t\t\t\t\t\t\t   Domestic Flights  " << endl;
        cout << "\t\t\t\t\t\tBusinuss Class        | Economy Class " << endl;
        cout << "\t\t\t\t\t\t30000                 | 20000 " << endl;

        cout << "Enter Ticket Prices : ";
        ticket_price = Utility::GetNumberFromUser(10);
        ticketcounter++;
        cout << "Ticket issued " << endl;

        cout << "\n\n\t\t\t\t\t\tTicket for Passenger " << ptrreservation->ptrpassenger->passengerName << endl;
        cout << "\t\t\t\t_____________________________________________________________" << endl;
        cout << "\t\t\t\t*************************************************************" << endl
             << endl;
        cout << "\t\t\t\t\t\tTicket Number        : " << ticketNumber << endl;
        cout << "\t\t\t\t\t\tReservation ID       : " << ptrreservation->reservationId << endl;
        cout << "\t\t\t\t\t\tFlight Number        : " << ptrreservation->ptrflight->flightNumber << endl;
        cout << "\t\t\t\t\t\tPassenger Name       : " << ptrreservation->ptrpassenger->passengerName << endl;
        cout << "\t\t\t\t\t\tSeat Number          : " << ptrreservation->seatNumber << endl;
        cout << "\t\t\t\t\t\tSource               : " << ptrreservation->ptrflight->source << endl;
        cout << "\t\t\t\t\t\tSource Country       : " << ptrreservation->ptrflight->ptrairports->SairportCountry << endl;
        cout << "\t\t\t\t\t\tDestination          : " << ptrreservation->ptrflight->destination << endl;
        cout << "\t\t\t\t\t\tDestination Country  : " << ptrreservation->ptrflight->ptrairports->DairportCountry << endl;
        cout << "\t\t\t\t\t\tDeparture Time       : " << ptrreservation->ptrflight->deptime << endl;
        cout << "\t\t\t\t\t\tArrival Time         : " << ptrreservation->ptrflight->arrivaltime << endl;
        cout << "\t\t\t\t\t\tDate                 : " << ptrreservation->ptrflight->date << endl;
        cout << "\t\t\t\t\t\tAirline              : " << ptrreservation->ptrflight->airline << endl;
        cout << "\t\t\t\t\t\tTicket Price         : " << ticket_price << endl;
        cout << "\t\t\t\t\t\tTicket Type          : " << ptrreservation->res_type << endl;
        cout << "\t\t\t\t_____________________________________________________________" << endl;
        cout << "\t\t\t\t*************************************************************" << endl
             << endl;
    }
    void seeticket()
    {
    b:
        cout << "Enter Reservation ID : ";
        int id = Utility::GetNumberFromUser(5);
        if (id != storing)
        {
            cout << "There is no ticket with this ID.Kindly Enter correct ID " << endl;
            goto b;
        }
        else
        {

            cout << "\n\n\t\t\t\t\t\tTicket for Passenger " << ptrreservation->ptrpassenger->passengerName << endl;
            cout << "\t\t\t\t_____________________________________________________________" << endl;
            cout << "\t\t\t\t*************************************************************" << endl
                 << endl;
            cout << "\t\t\t\t\t\tTicket Number        : " << ticketNumber << endl;
            cout << "\t\t\t\t\t\tReservation ID       : " << ptrreservation->reservationId << endl;
            cout << "\t\t\t\t\t\tFlight Number        : " << ptrreservation->ptrflight->flightNumber << endl;
            cout << "\t\t\t\t\t\tPassenger Name       : " << ptrreservation->ptrpassenger->passengerName << endl;
            cout << "\t\t\t\t\t\tSeat Number          : " << ptrreservation->seatNumber << endl;
            cout << "\t\t\t\t\t\tSource               : " << ptrreservation->ptrflight->source << endl;
            cout << "\t\t\t\t\t\tSource Country       : " << ptrreservation->ptrflight->ptrairports->SairportCountry << endl;
            cout << "\t\t\t\t\t\tDestination          : " << ptrreservation->ptrflight->destination << endl;
            cout << "\t\t\t\t\t\tDestination Country  : " << ptrreservation->ptrflight->ptrairports->DairportCountry << endl;
            cout << "\t\t\t\t\t\tDeparture Time       : " << ptrreservation->ptrflight->deptime << endl;
            cout << "\t\t\t\t\t\tArrival Time         : " << ptrreservation->ptrflight->arrivaltime << endl;
            cout << "\t\t\t\t\t\tDate                 : " << ptrreservation->ptrflight->date << endl;
            cout << "\t\t\t\t\t\tAirline              : " << ptrreservation->ptrflight->airline << endl;
            cout << "\t\t\t\t\t\tTicket Price         : " << ticket_price << endl;
            cout << "\t\t\t\t\t\tTicket Type          : " << ptrreservation->res_type << endl;
            cout << "\t\t\t\t_____________________________________________________________" << endl;
            cout << "\t\t\t\t*************************************************************" << endl
                 << endl;
        }
    }
    ~Ticket()
    {
        // Destructor for Ticket class
    }
} t;

int main()
{
    system("COLOR 6");
    mga.ReadDataFromFile3();
    mgf.ReadDataFromFile1();
    mgp.ReadDataFromFile2();
    mgr.ReadDataFromFile4();
    welcome();
    main_menu();

    return 0;
}
void welcome()
{
    system("cls");
    cout << endl
         << endl;
    cout << "\t\t\t------------------------------- WELCOME TO FLIGHT BOOKING SYSTEM ---------------------------------\n"
         << endl;

    cout << "\t\t\t|                                                                                                 |\n"
         << endl;

    cout << "\t\t\t| ------------------------------------------------------------------------------------------------|\n"
         << endl;

    cout << "\t\t\t|-------------------------------------------------------------------------------------------------|\n"
         << endl;

    cout << "\t\t\t|-----------------------------------------  W E L C O M E  ---------------------------------------|\n"
         << endl;

    cout << "\t\t\t|-------------------------------------          T O        ---------------------------------------|\n"
         << endl;

    cout << "\t\t\t|------------------------     F L I G H T---B O O K I N G ---S Y S T E M     ---------------------|\n"
         << endl;

    cout << "\t\t\t|-------------------------------------------------------------------------------------------------|\n"
         << endl;
}
void main_menu()
{

    int choice6;
    do
    {

        cout << "\t\t\t\t\t\t\tLogIn As   " << endl;
        cout << "\t\t\t\t\t\t_________________________________" << endl;
        cout << "\t\t\t\t\t\t*********************************"
             << endl
             << endl;
        cout << "\t\t\t\t\t\t\t1.Admin  " << endl;
        cout << "\t\t\t\t\t\t\t2.User " << endl;
        cout << "\t\t\t\t\t\t\t3.Exit " << endl;
        cout << "\t\t\t\t\t\t_________________________________" << endl;
        cout << "\t\t\t\t\t\t*********************************" << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice --> ";
        choice6 = Utility::GetNumberFromUser(4);
        cout << endl
             << endl;
        switch (choice6)
        {

        case 1:
        {

            admin_menu();
            break;
        }
        case 2:
        {
            user_menu();
            break;
        }
        case 3:
        {
            cout << "Have a nice Day";
            mgf.WriteDataToFile1();
            mgp.WriteDataToFile2();
            mga.WriteDataToFile3();
            mgr.WriteDataToFile4();
            exit(0);
        }
        default:
        {
            cout << endl
                 << endl;
            cout << "Please Enter correct choice " << endl;

            break;
        }
        }
    } while (choice6 != 3);
}
void admin_menu()
{
    int choice3;
    do
    {
        cout << "\n\n\t\t\t\t\t\t\tWelcome to Admin Menu" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t1.Flights    Management  " << endl;
        cout << "\t\t\t\t\t\t\t2.Airports   Management  " << endl;
        cout << "\t\t\t\t\t\t\t3.Passenger  Management  " << endl;
        cout << "\t\t\t\t\t\t\t4.Reservaion Management  " << endl;
        cout << "\t\t\t\t\t\t\t5.Issue the Ticket " << endl;
        cout << "\t\t\t\t\t\t\t6.Return to Main Menu " << endl;
        cout << "\t\t\t\t\t\t\t7.Exit From Program " << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice --> ";
        choice3 = Utility::GetNumberFromUser(4);
        cout << endl
             << endl;
        switch (choice3)
        {
        case 1:
        {
            mgf.manageFlightRecords();
            break;
        }
        case 2:
        {
            mga.manageAirportRecords();
            break;
        }
        case 3:
        {
            mgp.managePassengerRecords();
            break;
        }
        case 4:
        {
            mgr.managereservationRecords();
            break;
        }
        case 5:
        {
            t.issueticket();
            system("pause");
            break;
        }
        case 6:
        {
            main_menu();
            break;
        }
        case 7:
        {
            cout << "Have a nice Day";
            mgf.WriteDataToFile1();
            mgp.WriteDataToFile2();
            mga.WriteDataToFile3();
            mgr.WriteDataToFile4();
            exit(0);
            break;
        }
        default:
        {
            cout << endl
                 << endl;
            cout << "Please Enter correct choice " << endl;
            break;
        }
        }
    } while (choice3 != 6);
}
void user_menu()
{
    int choice3;
    do
    {
        cout << "\n\n\t\t\t\t\t\t\tWelcome to User Menu" << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\n\t\t\t\t\t\t\t1.Display Flight Schedule  " << endl;
        cout << "\t\t\t\t\t\t\t2.Search Flights by Destination " << endl;
        cout << "\t\t\t\t\t\t\t3.Passenger Management  " << endl;
        cout << "\t\t\t\t\t\t\t4.Reservaion Management " << endl;
        cout << "\t\t\t\t\t\t\t5.To See Ticket " << endl;
        cout << "\t\t\t\t\t\t\t6.Return to Main Menu " << endl;
        cout << "\t\t\t\t\t\t\t7.Exit From Program " << endl;
        cout << "\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\t\t\t\t\t\t*************************************" << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice --> ";
        choice3 = Utility::GetNumberFromUser(4);
        cout << endl
             << endl;
        switch (choice3)
        {

        case 1:
        {
            mgf.showflights();
            user_menu();
            break;
        }
        case 2:
        {
            mgf.searchflight();
            user_menu();
            break;
        }
        case 3:
        {
            mgp.managePassengerRecords();
            break;
        }
        case 4:
        {
            mgr.managereservationRecords();
            break;
        }
        case 5:
        {
            if (t.ticketcounter <= 0)
            {
                cout << "Ticket is not issued" << endl;
            }
            else
            {

                t.seeticket();
            }
            system("pause");
            break;
        }
        case 6:
        {
            main_menu();
            break;
        }
        case 7:
        {
            cout << "Have a nice Day";

            exit(0);
            break;
        }

        default:
        {
            cout << endl
                 << endl;
            cout << "Please Enter correct choice " << endl;
            break;
        }
        }
    } while (choice3 != 5);
}