#include<iostream>
#include <stdlib.h> // for system("CLS") & exit
#include <fstream> //FOR FILE HANDLING
#include <limits>//for cin.numericlimits
#include <iomanip> // for setw
#include <cstdio> //for rename and remove
//#include <bits/stdc++.h>
//#include<string>
#include<sstream>// for int to string
using namespace std ;

//*******************************
//          DECLARATION         *
//*******************************

int disp_fp () ;
int disp_sp () ;
int menu ();


//****************************
//            SUPER CLASS      *
//****************************
class account
{
    string name,password, password_1, user_id;
    float deposit ;

    public :
        void create_account () ;
        void modify_account ()  ;
        void pay_transfer () ;
        void view_account() ;
        void delete_account () ;
};
//***********************************
//          CREATE ACCOUNT          *
//***********************************
void account :: create_account ()
{
    char choice ;

    do
    {
        system ("cls");
        cout << "\nENTER USER ID: ";
        cin >> user_id;
        cout << "\nENTER THE NAME OF THE ACCOUNT HOLDER (NAME WITHOUT SPACING): " ;
        cin.ignore() ;
        getline( cin, name ) ;
        cout << "\nENTER AMOUNT FOR DEPOSIT : RM " ;
        cin >> deposit ;
        while(deposit<1 )
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "\nENTER NUMBERIC ONLY !" ;
            cout << "\nENTER AMOUNT FOR DEPOSIT : RM " ;
            cin >> deposit ;
        }
        cout << "\nENTER PASSWORD: ";
        cin >> password;
        cout << "\nRECONFIRMED PASSWORD: ";
        cin >> password_1;
        if(password_1 == password)
        {
            cout << "\nPASSWORD CORRECT" << endl;
            cout << "\nACCOUNT CREATED" << endl;
        }
        else
        {
            while(password_1 != password)
            {
                cout << "\nINCORRECT PASSWORD" << endl;
                cout << "\nENTER PASSWORD: ";
                cin >> password;
                cout << "\nRECONFIRMED PASSWORD:  ";
                cin >> password_1;
            }
            cout << "\nPASSWORD CORRECT" << endl;
            cout << "\nACCOUNT CREATED" << endl;
        }

// ALL THE DATA THAT ENTER BY USER ARE SAVE TO FILE "ACCOUNTS.TXT"
        ofstream outfile ("accounts.txt", ios::app) ;
        outfile  << setw(10) << user_id << setw(15) << name << setw(13) << deposit << setw(15) << password << endl ;
        outfile.close() ;
        cout << endl << endl ;
        cout << "ACCOUNT SUCCESSFULLY CREATED !" << endl << endl ;
        system ("pause") ;
    do
        {
           cout << "\nDO YOU WANT TO CREATE ANOTHER ACCOUNT ? "<< endl ;
           cout << "\nENTER YOUR CHOICE ( Y OR N ): " ;
           cin >> choice ;
        }while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N' );
    }while (choice == 'y' || choice == 'Y');
}
//***************************
//      MODIFY ACCOUNT      *
//***************************
void account :: modify_account ()
{
    cout << "\t\t\t\t\t***************************" << endl;
    cout << "\t\t\t\t\t       MODIFY ACCOUNT      "      << endl;
    cout << "\t\t\t\t\t***************************" << endl << endl;
    cout << "\t\t\t\t\t ENTER USER ID : ";
    cin >> user_id;
    ifstream infile ;
    infile.open("accounts.txt") ;
    ofstream outfile ;
    outfile.open ("new.txt");

    string x , y , z , w;
    infile >> x >> y >> z >> w;

    while (!infile.eof())
    {
        if (x != user_id )
        {
           // cout << "UPDATE FAILED ! " <<endl;
            outfile <<setw(10)<< x <<setw(15)<< y <<setw(13)<< z<<setw (15) << w << endl;

        }
        else
        {
            cout << endl << endl ;
            cout << "\t\t\t       NEW ACCOUNT HOLDER NAME : " ;
            cin.ignore();
            getline( cin, name ) ;
            cout << "\n\t\t\t\t    NEW BALANCE AMOUNT : RM " ;
            cin >> deposit ;
            while(deposit<1 )
            {
                cin.clear();
                cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                cout << "\nENTER NUMBERIC ONLY !" ;
                cout << "\nENTER AMOUNT FOR DEPOSIT : RM " ;
                cin >> deposit ;
            }
            cout << "\n\t\t\t\t          NEW PASSWORD : ";
            cin >> password ;
            outfile  << setw(10) << x << setw(15) << name << setw(13) << deposit << setw(15) << password << endl ;
            cout << "\n\t\t\t\t       ACCOUNT HAS BEEN UPDATED ! " << endl ;
        }
        infile >> x >> y >> z >> w;

    }
    outfile.close();
    infile.close();

    remove ("accounts.txt");
    rename("new.txt","accounts.txt");


	system("pause");
}

//***************************
//      PAY&TRANSFER        *
//***************************
void account :: pay_transfer ()
{
    cout << "\t\t\t\t\t***************************" << endl;
    cout << "\t\t\t\t\t        PAY & TRANSFER      "      << endl;
    cout << "\t\t\t\t\t***************************" << endl << endl;
    cout << "ENTER USER ID: ";
    cin >> user_id;
    ifstream infile ;
    infile.open("accounts.txt") ;
    ofstream outfile ;
    outfile.open ("new.txt");

    string x , y , z , w  ;
    infile >> x >> y >> z >> w ;

    while (!infile.eof())
    {
        if (x != user_id )
        {
            outfile <<setw(10)<< x <<setw(15)<< y <<setw(13)<< z << setw(15) << w << endl;
        }
        else
        {
                    string pay ;
                    float amount ;
                    int choice ;
                    while(choice < 1 || choice > 2 )
                    {
                        cin.clear();
                        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                        cout << endl << endl ;
                        cout << "1. TRANSFER MONEY " << endl << endl;
                        cout << "2. PAY BILLS " << endl << endl ;
                        cout << "ENTER YOUR CHOICE ( 1 OR 2  ) : " ;
                        cin >> choice ;
                    }
                    if ( choice == 1)
                         {
                            cout << "\nTO (ACCOUNT NUMBER) : " ;
                            cin >> pay;
                            cout << "\nENTER AMOUNT : RM " ;
                            cin >> amount ;
                            while(amount<1 )
                            {
                                cin.clear();
                                cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                                cout << "\nENTER NUMBERIC ONLY !" ;
                                cout << "\nENTER AMOUNT : RM " ;
                                cin >> amount ;
                            }
                            stringstream zz ;
                            zz << z ;
                            float deposit ;
                            zz >> deposit ;
                            if (amount > deposit )
                            {
                                cout <<"INSUFFICIENT BALANCE !" << endl << endl;
                                outfile  << setw(10) << x << setw(15) << y << setw(13) << z << setw(15) << w << endl ;
                            }
                            else
                            {
                                cout << "\nTHANK YOU ! YOUR ACCOUNT HAS TRANSFERED TO : " << pay << endl << endl;
                                cout << "\nYOUR ACCOUNT HAS BEEN DEDUCTED RM " << amount << " ! "<< endl << endl ;
                                deposit -= amount ;
                                outfile  << setw(10) << x << setw(15) << y << setw(13) << deposit<< setw(15) << w << endl ;
                                cout << "\nACCOUNT HAS BEEN UPDATED ! " << endl << endl ;
                            }

                        }
                        else if (choice == 2)
                        {
                            cout << "\nENTER YOUR BILL NUMBER : " ;
                            cin >> pay;
                            cout << "\nENTER AMOUNT : RM " ;
                            cin >> amount ;
                            while(amount<1 )
                            {
                                cin.clear();
                                cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                                cout << "\nENTER NUMBERIC ONLY !" ;
                                cout << "\nENTER AMOUNT : RM " ;
                                cin >> amount ;
                            }
                            stringstream zz ;
                            zz << z ;
                            float deposit ;
                            zz >> deposit ;
                            if (amount > deposit )
                            {
                                cout <<"INSUFFICIENT BALANCE !" << endl << endl;
                                outfile  << setw(10) << x << setw(15) << y << setw(13) << z << setw(15) << w << endl ;
                            }
                            else
                            {
                                cout << "\nTHANK YOU ! YOUR BILL WITH NUMBER " << pay << " HAS BEEN PAID ! " << endl << endl ;
                                cout << "\nYOUR ACCOUNT HAS BEEN DEDUCTED RM "<< amount << " ! "<< endl << endl ;
                                deposit -= amount  ;
                                outfile  << setw(10) << x << setw(15) << y << setw(13) << deposit<< setw(15) << w << endl ;
                                cout << "\nACCOUNT HAS BEEN UPDATED ! " << endl << endl;
                            }

                        }
        }
        infile >> x >> y >> z >> w ;
    }
    outfile.close();
    infile.close();

    remove ("accounts.txt");
    rename("new.txt","accounts.txt");


	system("pause");

}

//*******************************
//          VIEW ACCOUNT        *
//*******************************
void account :: view_account ()
{
    cout << "\t\t\t\t\t***************************" << endl;
    cout << "\t\t\t\t\t        VIEW ACCOUNT      "      << endl;
    cout << "\t\t\t\t\t***************************" << endl;
    string user_id1;

    int offset ;
    string line ;
    ifstream infile ;
    infile.open("accounts.txt");


       cout << endl << endl ;
       cout << "\nENTER YOUR USER ID: " ;
       cin >> user_id1 ;

        if (infile.is_open())
        {
            while(!infile.eof()) // FIND DATA IN NOTEPAD
            {
                getline (infile,line);// IF THE ACC_NO = ACC_HOLDER_NAME THN LOGIN SUCCESFULLY , OTHERWISE LOGIN FAIL
                if ( (offset = line.find(user_id1,0)) != string::npos )
                {
                    cout << "\nVIEW SUCCESSFULLY !" << endl << endl  ;
                    cout <<"\t\t\t***********************************************************"<<endl;
                    cout << "\t\t\t     USER ID          NAME      DEPOSIT       PASSWORD  " << endl ;
                    cout <<"\t\t\t***********************************************************"<<endl;
                    cout << "\t\t\t " << line << endl << endl ;
                    system("pause");
                }
            }
            infile.close() ;
        }
        else
        {
            cout << "" ;// PUT TIS BCS THE PROGRAM WILL SKIP TIS LINE(I ALSO DK WHY :p)
            system("cls") ;
            cout << endl << "VIEW FAILED !" << endl ;
            infile.close() ;
            system("pause");
        }
}

//***************************
//      DELETE ACCOUNT      *
//***************************
void account :: delete_account ()
{

    int offset;
    string line;
    string deleteline;
    string user_id;
    ifstream outfile;
    outfile.open("accounts.txt");
    ofstream temp;
    temp.open("temp.txt");

    cout << "ENTER USER ID: ";
    cin >> user_id;
   if (outfile.is_open())
        {
            while(!outfile.eof()) // FIND DATA IN NOTEPAD
            {
                getline(outfile,line);

               if ( (offset = line.find(user_id,0)) == string::npos )
                {
                    //cout << deleteline <<"," <<line<<"," << offset; //for our reference
                    deleteline = line;
                    temp << line << endl;
                }
            }
        }
    cout << "The record with the User ID " << user_id << " has been deleted!";
    outfile.close();
    temp.close();
    remove("accounts.txt");
    rename("temp.txt","accounts.txt");

    system("pause");
}

//***************************
//        SUB CLASS         *
//***************************
struct users : public account
{
    string userid ;
    string name ;
    float deposit ;
};

int login()
{
   cin.sync_with_stdio(0);


    string userid[20];
    string name[20];
    string password_1[20];
    float deposit [20] ;

    users obj[20];

    ifstream in ("accounts.txt");

    for (int i=0; i<20 ; i++)
    {
        in >> userid[i] >> name [i] >> deposit[i] >> password_1[i];
    }
    back:
        string user_id ;
        string password;
        cout <<"\nENTER USER ID : "  ;
        cin >> user_id;
        //cout << "ENTER ACCOUNT HOLDER NAME : " << endl ;
        //getline(cin, name1);
        cout << "\nENTER PASSWORD: ";
        cin >> password ;
        cout <<endl;

        bool islogin = false;
        for (int i=0; i<20 ; i++)
        {
            if(user_id == userid[i] && password == password_1[i]) //name1 == name[i] &&
            {
                cout << "LOGIN SUCCESSFULLY" << endl ;
                islogin = true ;
                cout << endl;
                system ("pause") ;
                in.close();
                return islogin;
            }
            else
            {
                islogin = false ;
                in.close();
            }
        }
        if (!islogin)
        {
            int option;
            do
            {
                cin.clear();
                cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                cout << "\nSORRY! YOU HAVE ENTERED INVALID USER ID OR ACCOUNT HOLDER NAME !" << endl
                     << "\nPLEASE LOG-IN AGAIN !" << endl
                     << "\n1. YES" << endl
                     << "\n2. NO" << endl
                     << "\nENTER YOUR CHOICE: ";
                cin >> option ;
            if (option == 1)
            {
                system("cls");
                in.close();
                fflush(stdin);
                cin.ignore( );
                goto back ;
            }
            else if (option == 2)
            {
                cout << "THANKS FOR USING OUR SYSTEM !" << endl;
                in.close();
                exit(2);
            }
            }while ( option != 1 || option != 2) ;
        }
}

//***************************
//      Welcome Page    *
//***************************
void welcome()
{
    system("color 06");
    cout << endl << endl << endl << endl ;
    cout << "\t\t\t ============================================================================="  << endl ;
    cout << "\t\t\t|.        ||                                                     ||          .|"  << endl;
    cout << "\t\t\t|.      ||||||                                                 ||||||        .|"  << endl;
    cout << "\t\t\t|.     || ||  ||                                              || ||  ||      .|"  << endl;
    cout << "\t\t\t|.     || ||                                                  || ||          .|"  << endl ;
    cout << "\t\t\t|.      |||||                                                  ||||||        .|"  << endl;
    cout << "\t\t\t|.        || ||           JAXX Bank Management System            || ||       .|"  << endl;
    cout << "\t\t\t|.        ||  ||                                                 ||  ||      .|"  << endl;
    cout << "\t\t\t|.    ||  ||  ||                                             ||  ||  ||      .|"  << endl;
    cout << "\t\t\t|.      ||||||                                                 ||||||        .|"  << endl;
    cout << "\t\t\t|.        ||                                                     ||          .|"  << endl;
    cout << "\t\t\t|.                                                                           .|"  << endl;
    cout << "\t\t\t ============================================================================="  << endl << endl ;
    cout << "\t\t\t                 Welcome to JAXX Bank Management System.\n\n";
    cout << "\t\t\t                    ...Press ENTER key to proceed...";
    cin.ignore(256,'\n');
    system("cls");
}

//***************************
//      Welcome Page         *
//***************************
int menu_1()
{
    int choice;
    cout << endl << endl << endl;
    cout << "\n\n\t\t\t\t\t+--------------------------+" << endl;
    cout << "\t\t\t\t\t|    :: MAIN MENU ::       |" << endl;
    cout << "\t\t\t\t\t|                          |" << endl;
    cout << "\t\t\t\t\t|    [1] Sign Up           |" << endl;
    cout << "\t\t\t\t\t|    [2] Log In            |" << endl;
    cout << "\t\t\t\t\t|    [3] Exit              |" << endl;
    cout << "\t\t\t\t\t+--------------------------+" << endl;
    cout << "\t\t\t\t\tPlease select your choice: ";
    cin >> choice;
    return choice;
}


//*******************************
//          MAIN  FUNCTION      *
//*******************************
main ()
    {
        welcome();
        int choice ;
        bool islogin = false ;
        account s1;

        choice =  menu_1() ;

        while (choice < 1 || choice >3 )
          {
                cin.clear();
                cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                cout << "\t\t\t\t\tINVALID CHOICE !" << endl;
                cout << "\t\t\t\t\tPLEASE RE-ENTER YOUR CHOICE: ";//ERROR
                cin >> choice;
                cout << endl ;
          }
            if (choice == 1 )
            {
                    s1.create_account () ;
                    system ("cls") ;
                    choice = disp_sp ();

                    if (choice == 1)
                    {
                      islogin =  login();

                    }else if ( choice == 2)
                    {
                        cout << "\n\t\t\t\tTHANK YOU FOR USING JAXX Bank Management System !" ;
                        exit (2);
                    }
            }
            else if(choice == 2)
            {
                system("cls");
                islogin =  login();
            }
            else if (choice == 3)
            {
                cout << "\n\t\t\t\tTHANK YOU FOR USING JAXX Bank Management System !\n " ;
                exit (3) ;
            }

    if (islogin = true )
    {
        float deposit ;
            do
            {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            system("cls") ;
            int choice ;
            main :
            cout << endl << "1. MODIFY ACCOUNT "
                 << endl << "2. PAY & TRANSFER "
                 << endl << "3. VIEW ACCOUNT "
                 << endl << "4. REMOVE ACCOUNT "
                 << endl << "5. EXIT "
                 << endl << "ENTER YOUR CHOICE ( 1 , 2 , 3 , 4 OR 5 ) : " ;
            cin  >>  choice ;
            switch (choice)
            {
                case 1 :
                    system("cls") ;
                    s1.modify_account () ;
                    break ;
                case 2 :
                    system("cls") ;
                    s1.pay_transfer () ;
                    break ;
                case 3 :
                    system("cls") ;
                    s1.view_account () ;
                    break ;
                case 4 :
                    system("cls") ;
                    s1.delete_account() ;
                    exit (4);
                    break;
                case 5 :
                    system("cls") ;
                    cout << "\n\nYOUR ACCOUNT IS LOGGED OUT !\n\n" ;
                    exit (5);
                    break ;
            }
            }while (choice != 5 );
    }
}

//***********************************
//         DISPLAY SECOND PAGE      *
//***********************************
int disp_sp ()
{
        int choice ;
        cout << endl << "PLEASE LOGIN YOUR ACCOUNT TO CONTINUE ."
             << endl << "1. LOGIN "
             << endl << "2. EXIT "
             << endl << "ENTER YOUR CHOICE : " ;
        cin >> choice ;
        while (choice < 1 || choice > 2 )
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << endl << "ERROR ! PLEASE INSERT A VALID CHOICE ( 1 OR 2  ) : ";
            cin >> choice ;
        }
        return choice ;
}



