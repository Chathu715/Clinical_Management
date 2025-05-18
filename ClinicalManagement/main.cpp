#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include<conio.h>// for getch() (Windows)
#include <algorithm>
#include <unistd.h>
using namespace std;

//Function prototype
void DoctorLoginMenu();
void DoctorLogin();
void DoctorRegister();
void DoctorDetails();
void doc_availability();
void ViewSheduld();
void DoctorTask();
void DoctorExit();
void MedicalRecord();
void medical_rec_menu ();
void availabilityStat();
void PatientLoginMenu();
void PatientLogin();
void PatientTask();
void PatientSignUp();
void AddAppointment();
void PatientExit();
void updateMedical();
void AccessMedicalRec();
void AppointmentSearching();
void AppointmentDeleting();
void AppointmentUpdating();
bool DateValidation(int day, int month, int year);

int main(){

	string loginOption;			//variable declaration
system("color 1F");// Change the color of the background blue

		// Displaying the main menu
	cout << "\n\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "\t\t**                        ________________________________________                       **" << endl;
	cout << "\t\t**                       |                                        |                      **" << endl;
	cout << "\t\t**                       | WELCOME TO CLINICAL MANAGEMENT SYSTEM  |                      **" << endl;
	cout << "\t\t**                       |________________________________________|                      **" << endl;
	cout << "\t\t**                                                                                       **" << endl;
	cout << "\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout<<"\n\n";

	cout << "\n"<<endl;
	cout << "\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;
	cout << "\t                \t  Please Choose Any Option Number To Login \n" << endl;
	cout << "\t           			   1. Doctor                                              	" << endl;
	cout << "\t           			   2. Patient                                          	" << endl;
	cout << "\t           		   	   3. Exit                                               	\n" << endl;
	cout << "\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;
	cout << "\t  Enter the option number : ";
	cin >> loginOption;							//getting user input for the option

	if(loginOption == "1"){
		DoctorLoginMenu();		// Calling the function to display the Doctor login menu
	}
	else if(loginOption == "2"){
		PatientLoginMenu();		// Calling the function to display the Patient login menu
	}
	else if(loginOption == "3"){
		cout << "\n\t\t Thank You! \n";
	}
	else{
		system("cls");		// Clear screen
		cout << "\n Please select from the given options \n";
		main();				//calling back the main function
	}

	return 0;
}




// Implementation of the function to display the Doctor login menu


void DoctorLoginMenu(){
	string DoctorOption;		//variable declaration
	string DocId;
    system("color 1F");		// Change the color of the text to green and background color to white

	cout << "\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;
	cout << "\t                \t\t\t  Doctor  \n                               " << endl;
	cout << "\t                \t\t\t -------- \n                               " << endl;
	cout << "\t           			   1. Login \n                                            	" << endl;
	cout << "\t           			   2. Register \n                                            	" << endl;
	cout << "\t           			   3. Go back to main menu\n                                        	" << endl;
	cout << "\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "\t Enter the option number : ";
	cin >> DoctorOption;							//getting user input for the option

	if(DoctorOption == "1"){
		DoctorLogin();			//calling the function to get the login details of the Doctor
	}
		else if(DoctorOption == "2"){
		DoctorRegister();			//function calling to display the main menu
	}
	else if(DoctorOption == "3"){
		system("cls");		// Clear screen
		main();				//function calling to display the main menu
	}
	else{
		system("cls");
		cout << "\n Please select from the given options \n";
		DoctorLoginMenu();			//calling back the DoctorLoginMenu function
	}
}



void DoctorDetails(){
     string DocSpeciality,Doc_name,A_time,A_date;
     string Doc_ID;
     string doc_status = "-";
     int Doc_number;

      system("color 1F");


    ifstream checkFile("doctor.txt");
    //openfile to get doctor details

    string storedDoctorId;
    bool IdExists = false;

    while (checkFile >> storedDoctorId) {
         if(Doc_ID == storedDoctorId) {
            IdExists = true;
            break;
        }
    }

    checkFile.close();

    if (IdExists) {

        cout << "\n Error: Docter ID already exists. Please Choose different id.\n";
        cout << "_______________________________________________________________________________\n";

         DoctorRegister();// If it exsits re calling the function of Doctor register for register back

    }


    cout << "\n Enter Docter ID : ";
    cin >> Doc_ID;

    cout << "\n Enter Speciality : ";
    cin >> DocSpeciality;

    cout << "\n Enter Your Full Name : ";
     cin.ignore();
    getline(cin,Doc_name);


     cout << "\n Enter Your Mobile Number : ";
     cin >>Doc_number;

     cout << " ";

     cout << "\n Enter Available Dates (Weekdays or weekends) : ";
     cin>>A_date;


     cout << "\n  Enter Available time (morning/noon/night): ";
     cin>> A_time;

    // Save the registration information to a file
    ofstream outFile("doctor.txt", ios::app); // Open file in append mode

    if (outFile.is_open()) {
        outFile << Doc_ID << " | " << DocSpeciality << " | " << Doc_name << " | " << Doc_number <<" | "<<A_date<<" | " <<A_time<<" | "<<doc_status<<endl<< endl;
        outFile.close();
        cout << "\n Detail Entered Successfully!\n";
        DoctorTask();
    }
    else {
        cerr << "\n Error: Unable to open file for registration\n";
        DoctorExit();
    }
}



void DoctorRegister() {
    string DocId, Docpwd;

  system("color 1F");

    // Getting Doctor username and password for registration
    cout << "\n\n\t\t Doctor Registration \n\n";
    cout << "\t\t----------------------";
    cout << "\n Enter Doctor Username : ";
    cin >> DocId;

    // Open file to check if the username already exists
    ifstream checkFile("doctorCredentials.txt");

    string storedDoctorId, storedDoctorPassword;
    bool usernameExists = false;

    while (checkFile >> storedDoctorId >> storedDoctorPassword) {
        if (DocId == storedDoctorId) {
            usernameExists = true;
            break;
        }
    }

    checkFile.close();

    if (usernameExists) {
        cout << "\n Error: Username already exists. Please enter a different username.\n";
        cout << "_______________________________________________________________________________\n";
        DoctorRegister(); // If it exists, recall the function for re-registration
    }

    cout << " Enter Doctor Password: ";
    cin >> Docpwd;

    // Save the registration information to a file
    ofstream outFile("doctorCredentials.txt", ios::app); // Open file in append mode

    if (outFile.is_open()) {
        outFile << DocId << " " << Docpwd << "\n"; // Save without extra spaces and newlines
        outFile.close();
        cout << "\n Registration Successful!\n";
        DoctorLoginMenu();
    } else {
        cout << "\n Error: Unable to open file for registration\n";
        DoctorLoginMenu();
    }
}



void doc_availability(){// Implementation of the function to display available doctors //

	system("cls");

	char doc_availableOption;

	fstream available_doc("doctor.txt", ios::in);

	cout << "\n\n\t ----- Display Doctors and available time Menu ----- \n" << endl;
	cout << "\t   1. Display all doctors and times" << endl;
	cout << "\t   2. Search" << endl;
	cout << "\t ----------------------------" << endl;
	cout << " Enter the option number : ";
	cin >> doc_availableOption;

	switch (doc_availableOption){
		//Display all option
	case '1': {
            char dLine[500];  // Variable declaration to store the data on the lines of the file doctor.txt

            if (available_doc.getline(dLine, 500)) {  // Checks if the first line of the file "doctor.txt" can be successfully read.
                available_doc.seekg(0, ios::beg);  // This moves the file pointer back to the beginning of the file to read the file from the beginning.

                cout << "\n\n=======================================================================================================================\n" << endl;
                cout << " Doctor ID" << " | " << "Speciality"<< " | " << "\tName"<< " | " << "\tMobile Number" << " | "<< "\tAvailable Days"<< " | " << "\tAvailable Time"<< " | " << "\tStatus" << "\n";

                while (available_doc.getline(dLine, 500)) {  // This loop continues until there are lines left to read from the file.
                    cout << "\n\n " << dLine;  // Display the data on the lines of the file docDetail
                }
                cout << "\n\n=======================================================================================================================\n\n";
                PatientExit();
            } else {
                cout << "\n No Doctors Found.";
                PatientExit();
        }

                break;
        }


		//Search option
		case '2':{
			char sLine[500]; 		//Variable declaration to read the lines on the file doctor.txt
			char docDetail[50];	//Variable declaration to get a detail of the doc using user input

			//getting user inputs
			cout << "\n Enter a doctor detail to find doctor : ";
			cin.ignore();						//Ignoring the ENTER key as a string
			cin.getline(docDetail, 50);	//Reads a line of input from the user and stores it in the docDetail array. The function getline is used to capture the user's input.

			if (available_doc.getline(sLine, 500)){	//Checks if the first line of the file "docDetail.txt" can be successfully read.
				available_doc.seekg(0, ios::beg);	//This moves the file pointer back to the beginning of the file to read the file from the beginning.
				int found = 1;	//Initializes a flag variable found with the value 1. This flag will be used to indicate whether a doc matching the input detail was found or not.

				cout << "\n\n=======================================================================================================================";
				while (available_doc.getline(sLine, 500)) {		//This loop continues until there are lines left to read from the file.
					if (strstr(sLine, docDetail) != NULL ) {  //This line checks if the user's input detail (docDetail) is found within the line read from the file (sLine) using the strstr function,
															   //which searches for a substring within a string.

						 cout << " Doctor ID" << " | " << "Speciality"<< " | " << "\tName"<< " | " << "\tMobile Number" << " | "<< "\tAvailable Days"<< " | " << "\tAvailable Time"<< " | " << "\tStatus" << "\n";
                    cout << "\n\n " << sLine;	//Line from the file is displayed (doc details)
						found = 0;	//the flag found is set to 0 to indicate that a match was found.
					cout << "\n\n=======================================================================================================================\n\n";
					PatientExit();
					}
				}
				if (found == 1){	//After searching through the entire file, the code checks the value of the flag found.
					cout << "\n\t Doctor Not Found";	//If found is still 1, it means no matching doctors were found, and a "doctor not found" message is displayed.

				}
				cout << "\n\n=======================================================================================================================\n\n";

			}
			else{	//If the initial attempt to read the first line of the file fails, the program directly displays a "doc not found" message.
				cout << "\n\t Doctor Not Found";
				PatientExit();
			}
			break;
		}

		default:{
			system("cls");
			cout << "\n Please select from the given options \n";
			doc_availability();
			break;
		}
	}

	available_doc.close();
}





void DoctorLogin() {

    char ch;
    string DoctorPassword, DoctorId;

    system("cls"); // Clear screen

    // Getting userId & Password
    cout << "\n\t\t Doctor Login \n\n";
    cout << " Enter The Username To Log In : ";
    cin >> DoctorId;

    cout << " Enter The Password To Log In : ";
    ch = getch();

    while (ch != 13) { // Loop to get the password until we press ENTER key
        if (ch == 8) {  // Check for BACKSPACE key
            if (!DoctorPassword.empty()) {
                cout << "\b \b";
                DoctorPassword.erase(DoctorPassword.size() - 1);
            }
        } else {
            DoctorPassword += ch;
            cout << "*";
        }
        ch = getch();
    }




      fstream inFile("doctorCredentials.txt",ios::in); // Open file for reading
    string storedDoctorId, storedDoctorPassword;

    bool loginSuccessful = false;

    string lLine;


    if (inFile.is_open()) {
        while (inFile >> storedDoctorId >> storedDoctorPassword) {
            // Remove any extra spaces or characters from stored passwords
            storedDoctorPassword.erase(
                remove_if(
                    storedDoctorPassword.begin(),
                    storedDoctorPassword.end(),
                    [](char c) { return isspace(static_cast<unsigned char>(c)); }
                ),
                storedDoctorPassword.end()
            );

            if (DoctorId == storedDoctorId && DoctorPassword == storedDoctorPassword) {
                loginSuccessful = true;
                break;
            }
        }
        inFile.close();
    } else {
        cout << "\n Error: Unable to open file for login\n";
    }



    if (loginSuccessful) {
        cout << "\n\n Your LOGIN is successful \n";
        DoctorTask(); // Calling the function to display Doctor task menu
    } else {
        system("color 04");
        cout << "\n\n LOGIN ERROR \n  Please check your Username and Password \n\n";
        system("PAUSE");
        DoctorLoginMenu();
    }
}




//Implementation of the function to display the Doctor tasks //
void DoctorTask(){
	string DoctorTaskOption;		//declaring the variable to get the user input for the task option
	system ("color 71");		// Change the color of the text to blue and background color to white

	//displaying the Doctor task menu
	cout << "\n\n\t -------------------- Doctor TASKS --------------------\n" << endl;
	cout << "\t\t  1. Update Available Time" << endl;
	cout << "\t\t  2. View Appointment Sheduld" << endl;
	cout << "\t\t  3. Medical records" << endl;
	cout << "\t\t  4. Update appointment status" << endl;
	cout << "\t\t  5. Add Your Details and working days      " << endl;
	cout << "\t\t  6. Go Back To Main Menu" << endl;
	cout << "\t ----------------------------------------------------\n" << endl;
	cout << "\t Enter the option number : ";
	cin >> DoctorTaskOption;

	if(DoctorTaskOption == "1"){
		//function calling to update doctor availability status
        availabilityStat();
	}
	else if(DoctorTaskOption == "2"){
		ViewSheduld();			//Function calling to view appointment shedulds
						//Calling the Doctor exit function
	}
	else if(DoctorTaskOption == "3"){
		 medical_rec_menu();

	}
	else if(DoctorTaskOption == "4"){
		AppointmentUpdating();	//Function calling to change status of patient and details

	}

	else if(DoctorTaskOption == "5"){
		system("cls");				// Clear screen
		DoctorDetails();// Add own docter details full name speciality availability and etc :
	}
	else if(DoctorTaskOption == "6"){
		system("cls");				// Clear screen
		main();// going back to main menu
	}
	else{
		system("cls");
		cout << "\n Please select from the given options \n";
		DoctorTask();//Calling back the function to display the Doctor tasks
	}
}



// Implementation of the function to sign up the Patients //


void PatientSignUp(){
	string p_name,p_email, p_id,p_pwd;
	system("cls");

	cout << "\n ----------  Sign Up Patients  ---------- \n" << endl;

	cin.ignore();		//Ignoring ENTER key as a string

	//getting user inputs
	cout << " Enter The Name : ";
	getline(cin, p_name);

	cout << " Enter The Email : ";
	cin >>p_email;

	cout << " Enter The Username : ";
	cin >> p_id;

	cout << " Enter The Password : ";
	cin >>p_pwd;

	fstream PatientSignUpFile;						//create an object to class fstream and name it ‘PatientSignUpFile’

	PatientSignUpFile.open("PatientDetails.dat",ios::app);		//open the file "PatientDetails.dat" to write the Patient details. (mode append)

	PatientSignUpFile << p_id << "   " <<p_pwd << "   " << p_name << "   " <<p_email << endl;			//Writing the Patient details to the file

	PatientSignUpFile.close();					// close the file

	fstream PatientLoginFile;						//create an object to class fstream and name it ‘PatientLoginFile’

	PatientLoginFile.open("PatientUserPwd.dat",ios::app);		//open the file "PatientUserPwd.dat" to write the Patient username and password. (mode append)

	PatientLoginFile << p_id << "|" <<p_pwd << endl;			//Writing the userId & Password to the file

	PatientLoginFile.close();					// close the file

	cout << "\n Patient Sign Up Is Successful";
	PatientLoginMenu();
}


// Implementation of the function to View Shedulds //
void ViewSheduld(){

	char appointmentSearchingOpt;

	fstream AppointmentFile("Appointment.txt", ios::in);

	cout << "\n\n\t ----- Appointment Search Menu ----- \n" << endl;
	cout << "\t   1. Display all" << endl;
	cout << "\t   2. Search" << endl;
	cout << "\t   3. Update" << endl;
	cout << "\t --------------------------------" << endl;
	cout << " Enter the option number : ";
	cin >> appointmentSearchingOpt;

	switch (appointmentSearchingOpt){
			//Display all option
		case '1':{
			char dLine[500];		//Variable declaration to store the data on the lines of the file Appointment.txt

			if (AppointmentFile.getline(dLine, 500)){	//Checks if the first line of the file "Appointment.txt" can be successfully read.
				AppointmentFile.seekg(0, ios::beg);	//This moves the file pointer back to the beginning of the file to read the file from the beginning.

				cout << "\n\n=======================================================================================================================\n" << endl;
				cout << "\n ID" << "\t|\t" << "Patient Name" << "\t|\t" << "Blood Group" << "\t|\t" << "CONTACT NUMBER" << "\t|\t" << "DATE OF APPOINMENT"<<"" <<"|"<<"Appointment Status";

				while (AppointmentFile.getline(dLine, 500)){		//This loop continues until there are lines left to read from the file.
					cout << "\n\n " << dLine;				//Display the data on the lines of the file Appointment.txt
				ViewSheduld();
				}

				cout << "\n\n=======================================================================================================================\n\n";
			}
			else{
				cout << "\n No Appointment found.";
				DoctorExit();
			}

			break;
		}
		//Search option
		case '2':{
			char sLine[500]; 		//Variable declaration to read the lines on the file Appointment.txt
			char AppDetail[50];	//Variable declaration to get a detail of the appoinment using user input

			cout << "\n Enter the appointment name or ID to find the appointment : ";
			cin.ignore();						//Ignoring the ENTER key as a string
			cin.getline(AppDetail, 50);	//Reads a line of input from the user and stores it in the AppDetail array. The function getline is used to capture the user's input.

			if (AppointmentFile.getline(sLine, 500)){	//Checks if the first line of the file "Appointment.txt" can be successfully read.
				AppointmentFile.seekg(0, ios::beg);	//This moves the file pointer back to the beginning of the file to read the file from the beginning.
				int found = 1;	//Initializes a flag variable found with the value 1. This flag will be used to indicate whether a appoinmentr matching the input detail was found or not.

				cout << "\n\n=======================================================================================================================";
				while (AppointmentFile.getline(sLine, 500)) {		//This loop continues until there are lines left to read from the file.
					if (strstr(sLine, AppDetail) != NULL ) {  //This line checks if the user's input detail (AppDetail) is found within the line read from the file (sLine)
																	//using the strstr function, which searches for a substring within a string.

						cout << " ID" << "\t|\t" << "NAME" << "\t\t\t|\t" << "EMAIL" << "\t\t|\t" << "CONTACT NUMBER" << "\t|\t" << "JOINED DATE" << "\n\n";
						cout << "\n\n " << sLine;	//Line from the file is displayed (appointment details)
						found = 0;	//the flag found is set to 0 to indicate that a match was found.
					}
				}
				if (found == 1){	//After searching through the entire file, the code checks the value of the flag found.
					cout << "\n\t Appointer not found";	//If 'found' is still 1, it means no matching appoinmentrs were found, and a "appoinmentr not found" message is displayed.
				}
				cout << "\n\n=======================================================================================================================\n\n";
			}
			else{	//If the initial attempt to read the first line of the file fails, the program directly displays a "appoinmentr not found" message.
				cout << "\n\t Appointer not found";
			}
			break;
		}
		case '3':{
		AppointmentUpdating();
		}

		default:{
			system("cls");
			cout << "\n Please select from the given options \n";
			AppointmentSearching();
			break;
		}
		ViewSheduld();
	}

	AppointmentFile.close();
}



void AppointmentUpdating(){
    system("cls");
    string PID;	//declaring a variable to get the user inputs

    fstream AppointmentFile;			//object for input file
    fstream TempAppointmentFile;		//object for temp file

    bool found = false;		//to track whether the appointment details to be updated was found

    cout << "\n ----------  Updating Appointment Status  ----------" << endl;
    cin.ignore();
   	cout << "\n Enter Appointment ID to change the A details : ";
    getline(cin,PID);

    AppointmentFile.open("Appointment.txt", ios::in);				//opens the file "Appointment.txt" for reading (to check the availability of the appointment details).
    TempAppointmentFile.open("tempUpdateAppointment.txt", ios::out);	//opens the file "tempUpdateAppointment.txt" for writing in out mode. This file will be used to store the updated content.

    string uLine;	//To store the record of the file "Appointment.txt" line by line

    if (!AppointmentFile || !TempAppointmentFile){
        cout << " File cannot be opened." << endl;
    }
    else {
        while (getline(AppointmentFile, uLine)) {				//reads a line from the input file into the uLine

            //declaration
            string Pname, pId,Blood_g;
            string Status = "New Appointment";
            int PatientContact, A_day,A_month, Doc_ID,A_year;

            stringstream ss(uLine);
            ss >> pId >> Pname >> Doc_ID >> PatientContact >> A_day >>A_month >> A_year>>Status;	//Parses the line using stringstream to extract individual attributes of the appointment

            if (PID == pId) {	  //Compares the appointment ID from the line with the user-provided pId to see if it's the appointment to be updated
                found = true;			//record found

				// Display the appointment details that we want to update
				cout << "\n\n===============================================================================================================================================================" << endl;
				cout << " ID" << "\t|\t" << "Patient Name" << "\t\t\t|" << "Blood Group" << "\t\t|\t" << "CONTACT NUMBER" << "\t|\t" << "DATE OF APPOINMENT"<<"|"<<"Appointment Status";
				cout << "\n" << uLine << endl;
				cout << "\n=================================================================================================================================================================" << endl;

                // Update the appointment details
                cout << " Enter the patient Name : ";
                getline(cin,Pname);

                cout << "\n Enter your ID (Enter Same ID before You entered) : ";
                cin >> pId;

                cout << "\n Enter the contact number : ";
                cin >> PatientContact;

                cout << "\n Enter Your Blood Group : ";
                cin >> Blood_g;

                cout << "\n Enter Docter Id Number : ";
                cin >>Doc_ID;

                cout << "\n Enter Appointment Status : ";
                cin >>Status;


                do {
			        cout << "\n Enter the appointment day : ";
			        cin >> A_day;
			        cout << "\n Enter the new appointment month : ";
			        cin >>A_month;
			        cout << "\n Enter the new appointment year : ";
			        cin >> A_year;

			        if(DateValidation(A_day,A_month, A_year) == false){
			        	cout << "\n Invalid Date. Please re-enter the date." << endl;
					}

			    } while (DateValidation(A_day,A_month, A_year) == false);

				//Writes the updated details to the temporary file.
                TempAppointmentFile << pId << "\t|\t" << Pname << "\t\t\t|\t" << Blood_g << "\t\t|\t"<< PatientContact << "\t|\t" << A_day << "/" <<A_month << "/" << A_year << "\t|\t"<<Doc_ID<<"\t|\t"<<Status<< endl;
            }
            else {
                TempAppointmentFile << uLine << endl;		//If the appointment Id doesn't match the provided ID, writes the original line from the input file to the temporary file.
            }
        }
    }

    // Close both files
    AppointmentFile.close();
    TempAppointmentFile.close();

    // If record found
    if (found == true) {
        char upOption;
        cout << "\n Are You Sure You Want To Update The Appointment Status Details (y/n)? ";
        cin >> upOption;

        if (upOption == 'Y' || upOption == 'y') {
            remove("Appointment.txt");								// delete the original file
            rename("tempUpdateAppointment.txt", "Appointment.txt");	//rename the temp file into original file name
            cout << "\n The Appointment status Details Have Been Successfully Updated";
            DoctorExit();	//calling the doc exit function
        }
        else {
            system("cls");
            DoctorTask();	//calling the doc menu function
        }
    }
	//if record not found
	else{
		cout << "\n The Appointment Not Found\n" << endl;
		cout << "\n Do You Want To Retry (y/n)? ";
		char retryOption;
        cin >> retryOption;

        if (retryOption == 'y' || retryOption == 'Y') {
            AppointmentUpdating(); 	// Retry the delete operation
        }
		else {
        	remove("tempUpdateAppointment.txt");		//delete the temp file
        	system("cls");
            DoctorTask();		//Function calling to display the doc task menu
        }
	}
}


void availabilityStat(){

    string DOC_ID;//declaring a variable to get the user inputs

    fstream DoctorFile;		//object for input file
    fstream TempDutyFile;	//object for temp file

    bool found = false;		//to track whether the doctor to be updated was found
     cout << "\n ==================================================================\n" << endl;
    cout << "\n ----------  On Duty/Off Duty  ----------" << endl;
    cin.ignore();
    cout << "\n Enter Docter ID : ";
    getline(cin, DOC_ID);

   DoctorFile.open("doctor.txt", ios::in);					//opens the file "doctor.txt" for reading (to check the availability of the Doctor).
    TempDutyFile.open("tempDuty.txt", ios::out);	//opens the file "tempDuty.txt" for writing in out mode. This file will be used to store the updated content.

    string uLine;	//To store the record of the file "doctor.txt" line by line

    if (!DoctorFile || !TempDutyFile){
        cout << " File cannot be opened." << endl;}

    else if(DoctorFile&&TempDutyFile){
            while (getline(DoctorFile, uLine)) {				//reads a line from the input file into the uLine

            int Duty;
            string Doc_ID,DocSpeciality, Doc_name,A_date,A_time;
            string doc_status ;
            string Doc_number = Doc_number;


            stringstream ss(uLine);
           ss >> Doc_ID >> DocSpeciality >> Doc_name >> Doc_number >> A_date >> A_time >> doc_status;
	//Parses the line using stringstream to extract individual attributes of the doc

            if (Doc_ID == DOC_ID) {	  //Compares the DOCTOR ID from the line with the user-provided DOCTOR ID to see if it's the STATUS to be updated
                found = true;			//record found

				// Display the DOCTOR details of the DOCTOR that we want to update
				cout << "\n\n==========================================================================================================================" << endl;
                cout << " Doctor ID" << "\t" << "Speciality" << "\tName" << "\tMobile Number" << "\tAvailable Days" << "\tAvailable Time"<<"\tStatus" << "\n";
				cout << "\n" << uLine << endl;
				cout << "\n============================================================================================================================" << endl;

                // Update the DOCTOR STATUS
                cout << "\n Enter your option (1.On/2.Off) : ";
                cin>>Duty;

                   if(Duty==1){
                        DoctorFile >> Doc_ID >> DocSpeciality >> Doc_name >> Doc_number >> A_date >> A_time >> doc_status;
                        doc_status = "On Duty";

                   }
                    else if(Duty==2){
                           DoctorFile >> Doc_ID >> DocSpeciality >> Doc_name >> Doc_number >> A_date >> A_time >> doc_status;
                       doc_status = "off duty";

                    }

                     else{


                            cout<<"\nInvalid option enter '1' for on duty , enter '2'for off duty, Enter Correct Input Again.\n "<<endl;
                            system("pause");
                            availabilityStat();

            }



                    }

                   TempDutyFile << Doc_ID << " " << DocSpeciality << " " << Doc_name << " " << Doc_number << " " << A_date << " " << A_time << " " << doc_status << endl;
    }


}            else {
                TempDutyFile << uLine << endl;		//If the doc doesn't match the provided ID, writes the original line from the input file to the temporary file.
            }




    // Close both files
    DoctorFile.close();
    TempDutyFile.close();

    // If record found
    if (found == true) {
        char upOption;
        cout << "\n Are You Sure You Want To Update The Duty Status (y/n)? ";
        cin >> upOption;

        if (upOption == 'Y' || upOption == 'y') {
            remove("doctor.txt");								// delete the original file
            rename("tempDuty.txt", "doctor.txt");	//rename the temp file into original file name
            cout << "\n The Duty Has Been Successfully Updated";

            DoctorExit();	//calling the Doc exit function
        }
        else {
            system("cls");
            DoctorTask();	//Function calling to display the Doc task menu
        }
    }
	//if record not found
	else{
		cout << "\n The Doctor Not Found\n" << endl;
		cout << "\n Do You Want To Retry (y/n)? ";
		char retryOption;
        cin >> retryOption;

        if (retryOption == 'y' || retryOption == 'Y') {
            availabilityStat(); 	// Retry the delete operation
        }
		else {
        	remove("tempDuty.txt");		//delete the temp file
        	system("cls");
            DoctorTask();		//Function calling to display the doctor task menu
        }
	}



}


void medical_rec_menu (){

    string med_menu;

    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<< "\n\t1.Add Medical Record"<<endl;
	cout<< "\n\t2.Update Medical Records"<<endl;
	cout<<"\n\t3.Go Back to Doctor Menu"<<endl;

	cout<< "\nEnter Your Option \t: ";
	cin>>med_menu;

	if(med_menu == "1"){
            system("cls");
		MedicalRecord();			//calling the function to enter the medical details about patient
	}
		else if(med_menu == "2"){
        updateMedical();			//function calling to update medical records
	}
	else if(med_menu == "3"){
		system("cls");		// Clear screen
		DoctorTask();				//function calling to display Doctor exit menu
	}
	else{
		system("cls");
		cout << "\n Please select from the given options \n";
		medical_rec_menu();			//calling back the medical record Menu function
	}

}


void MedicalRecord(){// Implementation of the function to add Medical Records //

	system("cls");


	string PId;
	char PatientName[50], diagnosis[50], medications[90], Recomendation[150];
//	string recordAvailability;
	int i;

	cout << "\n ----------  Adding Medical Record  ----------" << endl;

	cin.ignore();
	cout << "\n Enter Patient ID : ";
	cin >> PId;

	cin.ignore();
	cout << "\n Enter patient Name : ";
	cin.getline(PatientName, 50);

	cout << "\n Enter Diagnosis : ";
	cin.getline(diagnosis, 50);

	cout << "\n Enter Medications  : ";
	cin.getline(medications, 90);

	cout << "\n Enter Recomendations : ";
	cin.getline(Recomendation, 150);

	fstream MedicalFile;		//create an object to class fstream and name it ‘MedicalFile’

	MedicalFile.open("MedicalDetails.txt",ios::app);		//open the file to write, file name – MedicalDetails , mode append

	//Writing the medical report details to medical detail.txt
	MedicalFile << PId << "\t" << PatientName << "\t" <<diagnosis << "\t" << medications << " \t" << Recomendation << endl;

	MedicalFile.close();					// close the file

	cout << "\n Medical Record Have Been Successfully Added";
	medical_rec_menu();
}

void AccessMedicalRec(){
system("cls");
	char RecSearchingOption;

	fstream RecordFile("MedicalDetails.txt", ios::in);

	cout << "\n\n\t Medical Record \n" << endl;
	cout << "\t   1. Search Your Records by patient id." << endl;
	cout << "\t   2. back to patient task menu." << endl;
	cout << "\t ----------------------------------------" << endl;
	cout << " Enter the option number : ";
	cin >> RecSearchingOption;

	switch (RecSearchingOption){

		case '1':{
			char sLine[500]; 		//Variable declaration to read the lines on the file MedicalDetails.txt
			char RecDetail[50];	//Variable declaration to get a detail of the record using user input

			//getting user inputs
			cout << "\n Enter a patient id to find records : ";
			cin.ignore();						//Ignoring the ENTER key as a string
			cin.getline(RecDetail, 50);	//Reads a line of input from the user and stores it in the RecDetail array. The function getline is used to capture the user's input.

			if (RecordFile.getline(sLine, 500)){	//Checks if the first line of the file "MedicalDetails.txt" can be successfully read.
				RecordFile.seekg(0, ios::beg);	//This moves the file pointer back to the beginning of the file to read the file from the beginning.
				int found = 1;	//Initializes a flag variable found with the value 1. This flag will be used to indicate whether a record matching the input detail was found or not.

				cout << "\n\n=======================================================================================================================\n";
				while (RecordFile.getline(sLine, 500)) {		//This loop continues until there are lines left to read from the file.
					if (strstr(sLine, RecDetail) != NULL ) {  //This line checks if the user's input detail (RecDetail) is found within the line read from the file (sLine) using the strstr function,
															   //which searches for a substring within a string.

                    cout << " Patient ID" << "\t" << "Patient Name" << "\tDiagnosis" << "\tMedication" << "\tRecomendation" << "\n";
						cout << "\n\n " << sLine;	//Line from the file is displayed (record details)
						found = 0;	//the flag found is set to 0 to indicate that a match was found.

					}
				}
				if (found == 1){	//After searching through the entire file, the code checks the value of the flag found.
					cout << "\n\t Record Not Found";	//If found is still 1, it means no matching records were found, and a "record not found" message is displayed.
				}
				cout << "\n\n=======================================================================================================================\n\n";
                PatientExit();
                }
			else{	//If the initial attempt to read the first line of the file fails, the program directly displays a "record not found" message.
				cout << "\n\t record Not Found";
			}
			break;
		}
            case '2':{
                PatientTask();
            }

		default:{
			system("cls");
			cout << "\n Please select from the given options \n";
			AccessMedicalRec();
			break;
		}
	}

	RecordFile.close();


}

void updateMedical(){


    string pat_ID;	//declaring a variable to get the user inputs

    fstream MedicalFile;		//object for input file
    fstream TempMedicalFile;	//object for temp file

    bool found = false;		//to track whether the report to be updated was found

    cout << "\n ----------  Updating Medical report Details  ----------" << endl;
    cin.ignore();
    cout << "\n Enter Patient ID to find the report : ";
    getline(cin,pat_ID);

    MedicalFile.open("MedicalDetails.txt", ios::in);					//opens the file "MedicalDetails.txt" for reading (to check the availability of the Medical Detail).
    TempMedicalFile.open("tempUpdateMedicalDetails.txt", ios::out);	//opens the file "tempUpdateMedicalDetails.txt" for writing in out mode. This file will be used to store the updated content.

    string uLine;	//To store the record of the file "MedicalDetails.txt" line by line

    if (!MedicalFile || !TempMedicalFile){
        cout << " File cannot be opened." << endl;
    }
    else {
        while (getline(MedicalFile, uLine)) {				//reads a line from the input file into the uLine



            string PId,PatientName, diagnosis, medications, Recomendation;

            stringstream ss(uLine);
            ss >> PId >>  PatientName >> diagnosis >> medications >> Recomendation ;
            if (PId==pat_ID){	  //Compares the Medical Detail ID from the line with the user-provided PID to see if it's the Medical Detail to be updated
                found = true;			//record found

				// Display the Medical Detail details of the Medical Detail that we want to update
				cout << "\n\n=======================================================================================================================" << endl;
				cout << " ID" << "\t\t" << "Patient Name" << "\t" << "Diagnosis" << "\t" << "Medications" << "\t" << "Recomendation" << "\n\n";
				cout << "\n" << uLine << endl;
				cout << "\n=======================================================================================================================" << endl;

                // Update the Medical Detail details
                cout << "\n Enter the new Patient Name : ";
                getline(cin, PatientName);

                cout << "\n Enter the Diagnosis : ";
                getline(cin, diagnosis);

                cout << "\n Enter the Medication : ";
                getline(cin, medications);

                cout << "\n Enter the Recomendation : ";
                getline(cin, Recomendation);

                TempMedicalFile << " " << PId << "\t" << PatientName << "\t" <<diagnosis << "\t" << medications << " \t" << Recomendation << endl;	//Writes the updated details to the temporary file.
            }
            else {
                TempMedicalFile << uLine << endl;		//If the Medical Detail doesn't match the provided ID, writes the original line from the input file to the temporary file.
            }
        }
    }

    // Close both files
    MedicalFile.close();
    TempMedicalFile.close();

    // If record found
    if (found == true) {
        char upOption;
        cout << "\n Are You Sure You Want To Update The MEDICAL Details (y/n)? ";
        cin >> upOption;

        if (upOption == 'Y' || upOption == 'y') {
            remove("MedicalDetails.txt");								// delete the original file
            rename("tempUpdateMedicalDetails.txt", "MedicalDetails.txt");	//rename the temp file into original file name
            cout << "\n The Report Has Been Successfully Updated";

            medical_rec_menu();	//calling the medical record menu function
        }
        else {
            system("cls");
            DoctorTask();	//Function calling to display the Doctor task menu
        }
    }
	//if record not found
	else{
		cout << "\n The RECORD Not Found\n" << endl;
		cout << "\n Do You Want To Retry (y/n)? ";
		char retryOption;
        cin >> retryOption;

        if (retryOption == 'y' || retryOption == 'Y') {
            updateMedical(); 	// retry operation
        }
		else {
        	remove("tempUpdateMedicalDetails");		//delete the temp file
        	system("cls");
            DoctorExit();		//Function calling to display the doc task menu
        }
	}
}



// Implementation of the function to display the Doctor exit menu //
void DoctorExit(){


	string DoctorExitOption;

	cout << "\n\n -------  1. Go Back To Doctor Task Menu  -------" << endl;
	cout << " -------  2. Go Back To Main Menu  \t -------" << endl;
	cout << " Enter the option number : ";
	cin >> DoctorExitOption;

	if(DoctorExitOption == "1"){
		system("cls");			//clear screen
		DoctorTask();			//function calling to display the Doctor task menu
	}
	else if(DoctorExitOption == "2"){
		system("cls");
		main();						//function calling to display the main menu
	}
	else{
		system("cls");
		cout << "\n Please select from the given options \n";
		DoctorExit();
	}
}



// Implementation of the function to display the Patient login menu //
void PatientLoginMenu(){
	string PatientOption;
    system("color 1F");

	cout << "\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "\t                \t\t\t  Patient  \n                               " << endl;
	cout << "\t           			   1. Login                                             	" << endl;
	cout << "\t           			   2. Register as a patient                                      	" << endl;
	cout << "\t           			   3. Go back to main menu                                        	" << endl;
	cout << "\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "\t Enter the option number : ";
	cin >> PatientOption;

	if(PatientOption == "1"){
		PatientLogin();			//calling the function to get the login details of the Patient
	}
	else if(PatientOption == "2"){
		system("cls");
		PatientSignUp();						//function calling to register patient
	}
	else if(PatientOption == "3"){
		system("cls");
		main();
	}
	else{
		system("cls");
		cout << "\n Please select from the given options \n";
		PatientLoginMenu();

}








}


// Implementation of the function to get and check the username & password of Patient //
void PatientLogin(){
	char ch = ' ';	// char variable used to store each user input character for the password
	string PatientId, PatientPassword, p_id,p_pwd;
	system("cls");

	//Getting userId & Password
	cout << "\n\t\t Patient \n\n";

	cout << " Enter The Username To Log In : ";
	cin >> PatientId;

	cout << " Enter The Password To Log In : ";
	ch = getch(); 		// allow us to press any button without displaying it on the console window

	while(ch != 13){	// Loop to get the password until we press ENTER key  (13 is the ASCII number for ENTER)

		if (ch == 8) {  // Check for BACKSPACE key (8 is the ASCII number for BACKSPACE)

			//The program checks if the PatientPassword string is not empty. If it's not empty, the program moves the cursor back, writes a space to erase
			//the last asterisk, and then moves the cursor back again. This simulates the effect of deleting a character on the console.
            if (!PatientPassword.empty()) {
                cout << "\b \b"; // Move cursor back, write space, move cursor back again (This is regarding the display)
                PatientPassword.erase(PatientPassword.size() - 1);	// Remove the last character (This is the one which useful to delete the character we pressed)
            }
        }
		else{ 		// If the button we press is not the BACKSPACE  key
			PatientPassword += ch;		// Append the characters we pressed to the ptient password
			cout << "*";				//Buttons we press will display as *
		}
		ch = getch();  // Get the next character
	}

	bool found = false;
	string lLine;

	fstream PatientLoginFile;

	PatientLoginFile.open("PatientUserPwd.dat",ios::in);		//open the file "PatientUserPwd.dat" to read the username and password saved in the file.

	while(getline(PatientLoginFile, lLine)){		//read the file "PatientUserPwd.dat" from beginning to the end
		istringstream iss(lLine);
        getline(iss, p_id, '|');					//This loop reads the file line by line, splitting each line
        getline(iss,p_pwd, '|');			    //into p_id (Patient username) andp_pwd (Patient password) using a delimiter (|).

		if(p_id==PatientId &&p_pwd==PatientPassword){		//checking the username and password entered by the user with the ones saved in the file
			found = true;
		}
	}

	PatientLoginFile.close();

	if(found == true){
		cout << "\n\n Your LOGIN is successful \n";
		PatientTask();								//calling the function to display Patient task menu
	}
	else{system("color 04");
		cout << "\n\n LOGIN ERROR \n  Please check your Username and Password \n\n";
		system("PAUSE");
		PatientLoginMenu();
	}
}


// Implementation of the function to display the Patient task menu //
void PatientTask(){
	string PatientTaskOption;
	system ("color 71");		// Change the color of the text to red and background color to white

	cout << "\n\n\t-------------------- Patient TASKS --------------------\n" << endl;
	cout << "\t\t\t 1.  Add Appointment" << endl;
	cout << "\t\t\t 2.  Search Appointment" << endl;
	cout << "\t\t\t 3.  Delete Appointment Details" << endl;
	cout << "\t\t\t 4.  Check available doctors" << endl;
	cout << "\t\t\t 5.  Medical Records" <<endl;
	cout << "\t\t\t 6.  Go Back To Main Menu" << endl;
	cout << "\t---------------------------------------------------------\n" << endl;
	cout << "\t Enter the option number : ";
	cin >> PatientTaskOption;

	if(PatientTaskOption == "1"){
		AddAppointment();	 //Function calling to add Appointment
		PatientExit();	 //calling the Patient exit function//calling the Patient exit function
	}
	else if(PatientTaskOption == "2"){
		AppointmentSearching();	//Function calling to search Appointment
		PatientExit();		//calling the Patient exit function
	}
	else if(PatientTaskOption == "3"){
		AppointmentDeleting();	 //Function calling to delete appointment details
	}
	else if(PatientTaskOption == "4"){
		doc_availability();	//Function calling to cheack docter availability
	}
	else if(PatientTaskOption == "5"){
		AccessMedicalRec();	//Function calling to cheack docter availability
	}

	else if(PatientTaskOption == "6"){
		system("cls");
		main();
	}
	else{
		system("cls");
		cout << "\n Please select from the given options \n";
		PatientTask();		//Calling back the function to display the Patient tasks
	}
}






// Implementation of the function to add appoinment //
void AddAppointment(){
	string Pname, pId,Blood_g;
	string Status = "New Appointment";
	string menuopt;
	int PatientContact, A_day,A_month, Doc_ID,A_year;
	system("cls");

	cout << "\n ----------  Adding An Appointment  ---------- \n" << endl;

	cout<<"1.Press 1 to see doctor list"<<endl;
	cout<<"2.Press 2 to Continue"<<endl;
	cout<<"3.Press 3 to patient menu"<<endl;
	cout<<"\nenter your option : "<<endl;
	cin>>menuopt;
	 if(menuopt=="1"){
            doc_availability();
        	 }
	else if(menuopt=="2"){
	cin.ignore();
	cout << " Enter the patient full Name : ";
	getline(cin,Pname);

	cout << "\n Enter your ID : ";
	cin >> pId;

	cout << "\n Enter the contact number : ";
	cin >> PatientContact;

    cout << "\n Enter Your Blood Group : ";
	cin >> Blood_g;

	cout << "\n Enter Docter Id Number : ";
	cin >>Doc_ID;

	do {
        cout << "\n Enter the appointment day : ";
        cin >> A_day;
        cout << "\n Enter the appointment month : ";
        cin >>A_month;
        cout << "\n Enter the appoinment year : ";
        cin >> A_year;

        if(DateValidation(A_day,A_month,A_year) == false){
        	cout << "\n Invalid Date. Please re-enter the date." << endl;
		}
    } while (DateValidation(A_day,A_month,A_year) == false);



	fstream AppointmentFile;		//create an object to class fstream and name it ‘AppointmentFile’

	AppointmentFile.open("Appointment.txt",ios::app);		//open the "appointment.txt" file to write

	//Writing appointment details to the file
	AppointmentFile << pId << "\t|\t" << Pname << "\t\t\t|\t" << Blood_g << "\t\t|\t"<< PatientContact << "\t|\t" << A_day << "/" <<A_month << "/" << A_year << "\t|\t"<<Doc_ID<<Status<<"\n\n"<< endl;

	AppointmentFile.close();			// close the file

	cout << "\n Appointment Have Been Successfully Added";
	}
	else{
        cerr<<"\t\t_________Option Invalid please retry________";
    PatientTask();
	}
}




// Implementation of the function to display Appointment //
void AppointmentSearching(){
	system("cls");
	char appointmentSearchingOpt;

	fstream AppointmentFile("Appointment.txt", ios::in);

	cout << "\n\n\t ----- Appointment Search Menu ----- \n" << endl;
	cout << "\t   1. Display all appointments" << endl;
	cout << "\t   2. Search" << endl;
	cout << "\t --------------------------------" << endl;
	cout << " Enter the option number : ";
	cin >> appointmentSearchingOpt;

	switch (appointmentSearchingOpt){
			//Display all option
		case '1':{
			char dLine[500];		//Variable declaration to store the data on the lines of the file Appointment.txt

			if (AppointmentFile.getline(dLine, 500)){	//Checks if the first line of the file "Appointment.txt" can be successfully read.
				AppointmentFile.seekg(0, ios::beg);	//This moves the file pointer back to the beginning of the file to read the file from the beginning.

				cout << "\n\n=======================================================================================================================" << endl;
				cout << " ID" << "\t|\t" << "Patient Name" << "\t\t\t|\t" << "Blood Group" << "\t\t|\t" << "CONTACT NUMBER" << "\t|\t" << "DATE OF APPOINMENT"<<"" <<"|"<<"Appointment Status";

				while (AppointmentFile.getline(dLine, 500)){		//This loop continues until there are lines left to read from the file.
					cout << "\n\n " << dLine;				//Display the data on the lines of the file Appointment.txt
				}

				cout << "\n\n=======================================================================================================================\n\n";
			}
			else{
				cout << "\n No Appointment found.";
			}

			break;
		}
		//Search option
		case '2':{
			char sLine[500]; 		//Variable declaration to read the lines on the file Appointment.txt
			char AppDetail[50];	//Variable declaration to get a detail of the appointment using user input

			cout << "\n Enter the Patient name or ID to find the appointment : ";
			cin.ignore();						//Ignoring the ENTER key as a string
			cin.getline(AppDetail, 50);	//Reads a line of input from the user and stores it in the AppDetail array. The function getline is used to capture the user's input.

			if (AppointmentFile.getline(sLine, 500)){	//Checks if the first line of the file "Appointment.txt" can be successfully read.
				AppointmentFile.seekg(0, ios::beg);	//This moves the file pointer back to the beginning of the file to read the file from the beginning.
				int found = 1;	//Initializes a flag variable found with the value 1. This flag will be used to indicate whether a appointment matching the input detail was found or not.

				cout << "\n\n=======================================================================================================================";
				while (AppointmentFile.getline(sLine, 500)) {		//This loop continues until there are lines left to read from the file.
					if (strstr(sLine, AppDetail) != NULL ) {  //This line checks if the user's input detail (AppDetail) is found within the line read from the file (sLine)
																	//using the strstr function, which searches for a substring within a string.

                        cout << " ID" << "\t|\t" << "Patient Name" << "\t\t\t|\t" << "Blood Group" << "\t\t|\t" << "CONTACT NUMBER" << "\t|\t" << "DATE OF APPOINMENT"<<"" <<"|"<<"Appointment Status";
						cout << "\n\n " << sLine;	//Line from the file is displayed (appointsment details)
						found = 0;	//the flag found is set to 0 to indicate that a match was found.
						PatientExit();
					}
				}
				if (found == 1){	//After searching through the entire file, the code checks the value of the flag found.
					cout << "\n\t Appointer not found";	//If 'found' is still 1, it means no matching appointment were found, and a "aappointment not found" message is displayed.
				}
				cout << "\n\n=======================================================================================================================\n\n";
			}
			else{	//If the initial attempt to read the first line of the file fails, the program directly displays a "appointer not found" message.
				cout << "\n\t Appointer not found";
			}
			break;
		}

		default:{
			system("cls");
			cout << "\n Please select from the given options \n";
			AppointmentSearching();
			break;
		}
	}

	AppointmentFile.close();
}




// Implementation of the function to delete appointment details //
void AppointmentDeleting(){
	system("cls");
	fstream AppointmentFile;	//object for input file
	fstream TempAppointmentFile;	//object for temp file

	bool found = false;
	char Appointmentearch[500];	//Declaring char array to store the user's input for the appointment name.

	cin.ignore();
	cout << "\n ----------  Delete appointment Details  ----------" << endl;
	cout << "\n Enter the appointment name or ID to delete the appointment details : ";
	cin.getline(Appointmentearch, 500);

	AppointmentFile.open("Appointment.txt", ios::in);	//opens a input file "Appointment.txt" for reading.
	TempAppointmentFile.open("tempAppointmentDetail.dat", ios::out); //opens a temporary file "tempAppointmentDetail.dat" for writing.
																 //This file will be used to store the updated content after deletion.

	char bLine[500]; //To store the record of the file "Appointment.txt" line by line

	//if one of the files open has failed
	if(!AppointmentFile || !TempAppointmentFile){
		cout << " File cannot be opened." << endl;
	}
	else{
		while(AppointmentFile.getline(bLine, 500)){	//read the original file from the begining to the end

			if (strstr(bLine, Appointmentearch) == NULL){	//If the line read does not contain the appointment name that the user wants to delete, it is written to the temporary file "tempApointmentDetail.dat".
				TempAppointmentFile << bLine << endl;
			}
			else{
				found = true;	//record found
			}
		}
	}

	//close both files
	AppointmentFile.close();
	TempAppointmentFile.close();

	//if record found
	if(found == true){
		char deleteOption;
		cout << "\n Are You Sure You Want To Delete The Appointment Details (y/n)? ";
		cin >> deleteOption;

		if(deleteOption == 'Y' | deleteOption == 'y'){
			remove("Appointment.txt");	// delete the original file
			rename("tempAppointmentDetail.dat","Appointment.txt");	 //rename temp file into original file name
			cout << "\n The Appointment Details Have Been Successfully Deleted";

			PatientExit();	//calling the Patient exit function
		}
		else{
			system("cls");
			PatientTask();		//Function calling to display the Patient task menu
		}
	}
	//if record not found
	else{
		cout << "\n The Appointment Not Found" << endl;
		cout << "\n Do You Want To Retry (y/n)? ";
		char retryOption;
        cin >> retryOption;

        if (retryOption == 'y' || retryOption == 'Y') {
            AppointmentDeleting(); 	// Retry the delete operation
        } else {
        	remove("tempAppointmentDetail.dat");		//delete the temp file
        	system("cls");
            PatientTask();		//Function calling to display the Patient task menu
        }
	}
}






// Function implementation - Patient Task Exit Menu //
void PatientExit(){
	char PatientExitOption;

	cout << "\n\n -------  1. Go Back To Patient Task Menu  -------" << endl;
	cout << " -------  2. Go Back To Main Menu            -------" << endl;
	cout << " Enter the option number : ";
	cin >> PatientExitOption;

	if(PatientExitOption == '1'){
		system("cls");
		PatientTask();
	}
	else if(PatientExitOption == '2'){
		system("cls");
		main();
	}
	else{
		system("cls");
		cout << "\n Please select from the given options \n";
		PatientExit();
	}
}





// Implementation of the function to check whether the date
bool DateValidation(int day, int month, int year){
	int daysInMonth = 0; 	// Declaration of variable to store the number of days in a particular month

    if (year >= 1950 && year <= 2150 && month >= 1 && month <= 12) {

        if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        }
		else if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {	// Leap year
                daysInMonth = 29;
            }
			else {
                daysInMonth = 28;
            }
        }
        else {
        	daysInMonth = 31;
		}
        //day value is both greater than or equal to 1 and less than or equal to the maximum number of days in the month
        return day >= 1 && day <= daysInMonth;
    }

    return false;
}


