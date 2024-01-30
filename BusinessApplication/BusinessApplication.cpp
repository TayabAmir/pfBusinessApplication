#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;

void printHeader();
void loginPage();
void csph();
void gotoxy(int x, int y);
string upperLetters(string word);
void loadDevicedata(string company[], double companyPrices[], int &count, string fileName);
void addDeviceData(string addMobileModel, double addMobilePrices, string company[], double companyPrices[], int &count, string fileName);
void UpdateDeviceData(string company[], double companyPrices[], int &count, string fileName);
bool isInputEmpty(string input);
void changeTheme(int value);
bool checkOptionValidation(string input);
bool checkMobileCompany(string company);
bool checkLaptopCompany(string company);
bool checkSWCompany(string company);
bool checkEarbudCompany(string company);
void storeFeedback(string feedbacks[], int feedbackCount);
void loadFeedback(string feedbacks[], int &feedbackCount);
bool checkModel(string models[], string modelName, int count);
string parseData(string record, int field);
string parseDataforLogin(string record, int field);
bool existedUsername(string newName[], int newCount);
bool checkUserName(string word, string newName[], int newCount);
bool checkAccount(string aNo, string accountNo[], int accountCount);
void displaySHDevices(string shDevices[], double shDevicesPrices[], int shCount);
bool deleteModel(string models[], double prices[], int &count, string &modelName);
double getDevicePrice(string buyModel, string models[], double prices[], int count);
string signIn(string Name, string Password, string newName[], string newPassword[], string role[]);
bool editModelPrice(string models[], double prices[], int count, string modelName, double newPrice);
int accountcount(string Name, string Password, string newName[], string newPassword[], string role[]);
double getshDevicePrice(string buySHDevice, string shDevices[], double shDevicesPrices[], int shCount);
string deleteSHDevice(string deleteshDevice, string shDevices[], double shDevicesPrices[], int &shCount);
void storeUserInfo(string newName[], string newPassword[], string role[], string accountNo[], int newCount);
void readUserInfo(string newName[], string newPassword[], string role[], string accountNo[], int &newCount);
void printMobiles(string mobileCompanies[], string SamsungM[], double SamsungMPrices[], string OppoM[], double oppoMPrices[], string InfinixM[], double infinixMPrices[], string miXiaomiM[], double miXiaomiMPrices[], string TecnoM[], double TecnoMPrices[], int mobileCount, int mobileSCount, int mobileOCount, int mobileICount, int mobileMCount, int mobileTCount);
void printLaptops(string LaptopCompanies[], string InfinixL[], double InfinixLPrices[], string Dell[], double dellPrices[], string HP[], double HPPrices[], string iphoneL[], double iphoneLPrices[], int laptopCount, int laptopICount, int laptopDCount, int laptopHCount, int laptopIpCount);
void printSmartWatches(string swCompanies[], string mibro[], double mibroPrices[], string kieslect[], double kieslectPrices[], string ZERO[], double zeroPrices[], string Assortedsw[], double AssortedswPrices[], int swCount, int swMCount, int swKCount, int swZCount, int swACount);
void printEarbuds(string EarbudsCompanies[], string XiaomiE[], double XiaomiEPrices[], string Audionic[], double AudionicPrices[], string AssortedE[], double AssortedEPrices[], int earbudCount, int earbudXCount, int earbudACount, int earbudAsCount);
void printMobileswithinbudget(double budget, string mobileCompanies[], string SamsungM[], double SamsungMPrices[], string OppoM[], double oppoMPrices[], string InfinixM[], double infinixMPrices[], string miXiaomiM[], double miXiaomiMPrices[], string TecnoM[], double TecnoMPrices[], int mobileCount, int mobileSCount, int mobileOCount, int mobileICount, int mobileMCount, int mobileTCount);
void printLaptopswithinbudget(double budget, string LaptopCompanies[], string InfinixL[], double InfinixLPrices[], string Dell[], double dellPrices[], string HP[], double HPPrices[], string iphoneL[], double iphoneLPrices[], int laptopCount, int laptopICount, int laptopDCount, int laptopHCount, int laptopIpCount);
void printSmartWatcheswithinbudget(double budget, string swCompanies[], string mibro[], double mibroPrices[], string kieslect[], double kieslectPrices[], string ZERO[], double zeroPrices[], string Assortedsw[], double AssortedswPrices[], int swCount, int swMCount, int swKCount, int swZCount, int swACount);
void printEarbudswithinbudget(double budget, string EarbudsCompanies[], string XiaomiE[], double XiaomiEPrices[], string Audionic[], double AudionicPrices[], string AssortedE[], double AssortedEPrices[], int earbudCount, int earbudXCount, int earbudACount, int earbudAsCount);
string editSHDevicePrice(string editshDevice, double editshDevicePrice, string shDevices[], double shDevicesPrices[], int &shCount);
void adminMenu(string newName[], string role[], int newCount, string mobileCompanies[], string SamsungM[], double SamsungMPrices[], string OppoM[], double oppoMPrices[], string InfinixM[], double infinixMPrices[], string miXiaomiM[], double miXiaomiMPrices[], string TecnoM[], double TecnoMPrices[], int &mobileCount, string LaptopCompanies[], string InfinixL[], double InfinixLPrices[], string Dell[], double dellPrices[], string HP[], double HPPrices[], string iphoneL[], double iphoneLPrices[], int laptopCount, string swCompanies[], string mibro[], double mibroPrices[], string kieslect[], double kieslectPrices[], string ZERO[], double zeroPrices[], string Assortedsw[], double AssortedswPrices[], int swCount, string EarbudsCompanies[], string XiaomiE[], double XiaomiEPrices[], string Audionic[], double AudionicPrices[], string AssortedE[], double AssortedEPrices[], int earbudCount, int &mobileSCount, int &mobileOCount, int &mobileICount, int &mobileMCount, int &mobileTCount, int &laptopICount, int &laptopDCount, int &laptopHCount, int &laptopIpCount, int &swMCount, int &swKCount, int &swZCount, int &swACount, int &earbudXCount, int &earbudACount, int &earbudAsCount, string shDevices[], double shDevicesPrices[], int &shCount, double &budget, double &tempBudget, string feedbacks[], int &feedbackCount);
bool modelExisted(string buyDevice, string buyModel, string SamsungM[], string OppoM[], string InfinixM[], string miXiaomiM[], string TecnoM[], string InfinixL[], string Dell[], string HP[], string iphoneL[], string mibro[], string kieslect[], string ZERO[], string Assortedsw[], string XiaomiE[], string Audionic[], string AssortedE[]);
void customerMenu(string mobileCompanies[], string SamsungM[], double SamsungMPrices[], string OppoM[], double oppoMPrices[], string InfinixM[], double infinixMPrices[], string miXiaomiM[], double miXiaomiMPrices[], string TecnoM[], double TecnoMPrices[], int &mobileCount, string LaptopCompanies[], string InfinixL[], double InfinixLPrices[], string Dell[], double dellPrices[], string HP[], double HPPrices[], string iphoneL[], double iphoneLPrices[], int laptopCount, string swCompanies[], string mibro[], double mibroPrices[], string kieslect[], double kieslectPrices[], string ZERO[], double zeroPrices[], string Assortedsw[], double AssortedswPrices[], int swCount, string EarbudsCompanies[], string XiaomiE[], double XiaomiEPrices[], string Audionic[], double AudionicPrices[], string AssortedE[], double AssortedEPrices[], int earbudCount, int &mobileSCount, int &mobileOCount, int &mobileICount, int &mobileMCount, int &mobileTCount, int &laptopICount, int &laptopDCount, int &laptopHCount, int &laptopIpCount, int &swMCount, int &swKCount, int &swZCount, int &swACount, int &earbudXCount, int &earbudACount, int &earbudAsCount, string shDevices[], double shDevicesPrices[], int shCount, double &budget, double &tempBudget, string accountNo[], int accountCount, string feedbacks[], int &feedbackCount);

int main()
{
    int newCount = 0, mobileCount = 0, laptopCount = 0, swCount = 0, earbudCount = 0;
    int mobileSCount = 0, mobileOCount = 0, mobileICount = 0, mobileMCount = 0, mobileTCount = 0,
        laptopICount = 0, laptopDCount = 0, laptopHCount = 0, laptopIpCount = 0,
        swMCount = 0, swKCount = 0, swZCount = 0, swACount = 0,
        earbudXCount = 0, earbudACount = 0, earbudAsCount = 0, shCount = 0, feedbackCount = 0;

    string SamsungM[100] = {}, OppoM[100] = {}, InfinixM[100] = {}, miXiaomiM[100] = {}, TecnoM[100] = {},
           InfinixL[100] = {}, Dell[100] = {}, HP[100] = {}, iphoneL[100] = {}, mibro[100] = {},
           kieslect[100] = {}, ZERO[100] = {}, Assortedsw[100] = {}, XiaomiE[100] = {}, Audionic[100] = {},
           AssortedE[100] = {}, shDevices[100] = {}, feedbacks[100] = {};

    double SamsungMPrices[100] = {}, oppoMPrices[100] = {}, infinixMPrices[100] = {}, miXiaomiMPrices[100] = {}, TecnoMPrices[100] = {}, InfinixLPrices[100] = {}, dellPrices[100] = {}, HPPrices[100] = {}, iphoneLPrices[100] = {}, mibroPrices[100] = {}, kieslectPrices[100] = {}, zeroPrices[100] = {}, AssortedswPrices[100] = {}, XiaomiEPrices[100] = {}, AudionicPrices[100] = {},
           AssortedEPrices[100] = {}, shDevicesPrices[100] = {};

    string mobileCompanies[5] = {"SAMSUNG", "OPPO", "INFINIX", "MI XIAOMI", "TECNO"};
    string LaptopCompanies[4] = {"INFINIX", "DELL", "HP", "IPHONE"};
    string swCompanies[4] = {"MIBRO", "KIESLECT", "ZERO", "ASSORTED"};
    string EarbudsCompanies[3] = {"MI XIAOMI", "AUDIONIC", "ASSORTED"};

    string newName[100], newPassword[100], role[100], accountNo[100];
    double budget = 0, tempBudget = budget;

    loadDevicedata(SamsungM, SamsungMPrices, mobileSCount, "Samsung.txt");
    loadDevicedata(OppoM, oppoMPrices, mobileOCount, "Oppo.txt");
    loadDevicedata(InfinixM, infinixMPrices, mobileICount, "InfinixM.txt");
    loadDevicedata(miXiaomiM, miXiaomiMPrices, mobileMCount, "MiM.txt");
    loadDevicedata(TecnoM, TecnoMPrices, mobileTCount, "Tecno.txt");
    loadDevicedata(InfinixL, InfinixLPrices, laptopICount, "InfinixL.txt");
    loadDevicedata(Dell, dellPrices, laptopDCount, "Dell.txt");
    loadDevicedata(HP, HPPrices, laptopHCount, "Hp.txt");
    loadDevicedata(iphoneL, iphoneLPrices, laptopIpCount, "Iphone.txt");
    loadDevicedata(mibro, mibroPrices, swMCount, "Mibro.txt");
    loadDevicedata(kieslect, kieslectPrices, swKCount, "Kieslect.txt");
    loadDevicedata(ZERO, zeroPrices, swZCount, "Zero.txt");
    loadDevicedata(Assortedsw, AssortedswPrices, swACount, "AssortedS.txt");
    loadDevicedata(XiaomiE, XiaomiEPrices, earbudXCount, "MiE.txt");
    loadDevicedata(Audionic, AudionicPrices, earbudACount, "Audionic.txt");
    loadDevicedata(AssortedE, AssortedEPrices, earbudAsCount, "AssortedE.txt");
    loadDevicedata(shDevices, shDevicesPrices, shCount, "Shdevices.txt");
    loadFeedback(feedbacks, feedbackCount);

    readUserInfo(newName, newPassword, role, accountNo, newCount);
    system("cls");
    while (true)
    {
        printHeader();
        cout << endl
             << endl
             << endl;
        int opt;
        string input;
        loginPage();
        cout << "Enter the option...";
        cin >> input;
        if (checkOptionValidation(input))
        {
            opt = stoi(input);
            if (opt == 1)
            {
                bool correct = false;
                system("cls");
                printHeader();
                cout << endl
                     << endl
                     << endl
                     << "\t \t \t \t \t \t SIGN IN PAGE " << endl
                     << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------" << endl
                     << endl;
                string Name, Password;
                cin.ignore();
                while (true)
                {
                    while (true)
                    {
                        cout << "Enter Username: ";
                        getline(cin, Name);
                        if (isInputEmpty(Name))
                        {
                            cout << "UserName cannot be empty." << endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter Password: ";
                        getline(cin, Password);
                        if (isInputEmpty(Password))
                        {
                            cout << "Password cannot be empty." << endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    string userRole = signIn(Name, Password, newName, newPassword, role);
                    int accountCount = accountcount(Name, Password, newName, newPassword, role);
                    string upperUserRole = upperLetters(userRole);
                    if (upperUserRole == "ADMIN")
                    {
                        printHeader();
                        cout << "Signing in as an ADMIN.";
                        Sleep(1500);
                        adminMenu(newName, role, newCount, mobileCompanies, SamsungM, SamsungMPrices, OppoM, oppoMPrices, InfinixM, infinixMPrices, miXiaomiM, miXiaomiMPrices, TecnoM, TecnoMPrices, mobileCount, LaptopCompanies, InfinixL, InfinixLPrices, Dell, dellPrices, HP, HPPrices, iphoneL, iphoneLPrices, laptopCount, swCompanies, mibro, mibroPrices, kieslect, kieslectPrices, ZERO, zeroPrices, Assortedsw, AssortedswPrices, swCount, EarbudsCompanies, XiaomiE, XiaomiEPrices, Audionic, AudionicPrices, AssortedE, AssortedEPrices, earbudCount, mobileSCount, mobileOCount, mobileICount, mobileMCount, mobileTCount, laptopICount, laptopDCount, laptopHCount, laptopIpCount, swMCount, swKCount, swZCount, swACount, earbudXCount, earbudACount, earbudAsCount, shDevices, shDevicesPrices, shCount, budget, tempBudget, feedbacks, feedbackCount);
                        break;
                    }
                    else if (upperUserRole == "CUSTOMER")
                    {
                        printHeader();
                        cout << "Signing in as a Customer.";
                        Sleep(1500);
                        customerMenu(mobileCompanies, SamsungM, SamsungMPrices, OppoM, oppoMPrices, InfinixM, infinixMPrices, miXiaomiM, miXiaomiMPrices, TecnoM, TecnoMPrices, mobileCount, LaptopCompanies, InfinixL, InfinixLPrices, Dell, dellPrices, HP, HPPrices, iphoneL, iphoneLPrices, laptopCount, swCompanies, mibro, mibroPrices, kieslect, kieslectPrices, ZERO, zeroPrices, Assortedsw, AssortedswPrices, swCount, EarbudsCompanies, XiaomiE, XiaomiEPrices, Audionic, AudionicPrices, AssortedE, AssortedEPrices, earbudCount, mobileSCount, mobileOCount, mobileICount, mobileMCount, mobileTCount, laptopICount, laptopDCount, laptopHCount, laptopIpCount, swMCount, swKCount, swZCount, swACount, earbudXCount, earbudACount, earbudAsCount, shDevices, shDevicesPrices, shCount, budget, tempBudget, accountNo, accountCount, feedbacks, feedbackCount);
                        break;
                    }
                    else
                    {
                        cout << endl
                             << userRole << endl;
                    }
                }
            }
            else if (opt == 2)
            {
                bool correct = false;
                system("cls");
                printHeader();
                cout << endl
                     << endl
                     << endl
                     << "\t \t \t \t \t \t SIGN UP PAGE" << endl
                     << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------" << endl
                     << endl;
                cout << "Instructions for Sign Up => \n Username must be at least 6 characters long and must not contain any special character and contain at least 3 letters \n Password must be at least 8 characters long" << endl
                     << endl;
                cin.ignore();
                while (true)
                {
                    cout << "Enter Username: ";
                    getline(cin, newName[newCount]);
                    if (checkUserName(newName[newCount], newName, newCount))
                    {
                        break;
                    }
                }
                while (true)
                {
                    cout << "Enter Password: ";
                    getline(cin, newPassword[newCount]);
                    if (newPassword[newCount].length() < 8)
                    {
                        cout << "Invalid input. Password does not contain 8 characters." << endl;
                        continue;
                    }
                    break;
                }
                string upperRole;
                while (true)
                {
                    cout << "Enter your role (Admin/Customer): ";
                    cin >> role[newCount];
                    upperRole = upperLetters(role[newCount]);
                    if (upperRole != "ADMIN" && upperRole != "CUSTOMER")
                    {
                        cout << endl
                             << "Invalide Role. Please select valid role." << endl;
                        continue;
                    }
                    break;
                }
                if (upperRole == "CUSTOMER")
                {
                    while (true)
                    {
                        cout << "Enter your Account Number ( Must be 13 digits ): ";
                        cin >> accountNo[newCount];
                        if (accountNo[newCount].length() == 13 && checkOptionValidation(accountNo[newCount]))
                        {
                            storeUserInfo(newName, newPassword, role, accountNo, newCount);
                            cout << endl;
                            newCount++;
                            cout << "You have successfully registered your credentials.";
                            break;
                        }
                        else
                        {
                            cout << endl
                                 << "Invalid Account Number / Account Number must be 13 digits." << endl;
                        }
                    }
                }
                else if (upperRole == "ADMIN")
                {
                    storeUserInfo(newName, newPassword, role, accountNo, newCount);
                    cout << endl;
                    newCount++;
                    cout << "You have successfully registered your credentials.";
                }
            }
            else if (opt == 3)
            {
                system("cls");
                printHeader();

                cout << "Thanks for coming here.";
                break;
            }
            else
            {
                cout << "Invalid Option Selection.";
                Sleep(750);
                system("cls");
                continue;
            }
            cout << endl
                 << endl
                 << endl
                 << "Press any Key to go to Login Page...";
            getch();
            system("cls");
        }
        else
        {
            cout << "Invalid input. Please write valid input.";
            Sleep(750);
            system("cls");
        }
    }
    return 0;
}
void loadFeedback(string feedbacks[], int &feedbackCount)
{
    fstream file;
    file.open("Feedback.txt", ios::in);
    while (getline(file, feedbacks[feedbackCount]))
    {
        feedbackCount++;
    }
}
void loadDevicedata(string company[], double companyPrices[], int &count, string fileName)
{
    string record;
    fstream file;
    file.open(fileName, ios::in);
    while (getline(file, record))
    {
        company[count] = parseData(record, 1);
        companyPrices[count] = stod(parseData(record, 2));
        count++;
    }
    file.close();
}
void UpdateDeviceData(string company[], double companyPrices[], int &count, string fileName)
{
    fstream file;
    file.open(fileName, ios::out);
    for (int i = 0; i < count; i++)
    {
        file << company[i] << "," << companyPrices[i];
        if (i < count - 1)
        {
            file << endl;
        }
    }
    file.close();
}
string parseData(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
string parseDataforLogin(string record, int field)
{
    char c = 138;
    int cCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == c)
        {
            cCount = cCount + 1;
        }
        else if (cCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
void readUserInfo(string newName[], string newPassword[], string role[], string accountNo[], int &newCount)
{
    string record;
    fstream file;
    file.open("Users.txt", ios::in);
    while (getline(file, record))
    {
        newName[newCount] = parseDataforLogin(record, 1);
        newPassword[newCount] = parseDataforLogin(record, 2);
        role[newCount] = parseDataforLogin(record, 3);
        accountNo[newCount] = parseDataforLogin(record, 4);
        newCount++;
    }
    file.close();
}
void storeUserInfo(string newName[], string newPassword[], string role[], string accountNo[], int newCount)
{
    char c = 138;
    fstream file;
    file.open("Users.txt", ios::app);
    file << newName[newCount] << c << newPassword[newCount] << c << role[newCount] << c << accountNo[newCount] << endl;
    file.close();
}

string upperLetters(string word)
{
    string letter;
    for (int i = 0; i < word.length(); i++)
    {
        letter += toupper(word[i]);
    }
    return letter;
}
bool checkUserName(string word, string newName[], int newCount)
{
    if (existedUsername(newName, newCount))
    {
        cout << "Username already taken.Please choose another." << endl;
        return false;
    }
    if (word.length() > 5)
    {
        int letterCount = 0;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            {
                letterCount++;
            }
            else if (!(c >= '0' && c <= '9'))
            {
                cout << "Invalid character in username. Use only letters and numbers." << endl;
                return false;
            }
        }
        if (letterCount >= 3)
        {
            return true;
        }
        else
        {
            cout << "Invalid username. Username must contain at least 3 letters." << endl;
            return false;
        }
    }
    else
    {
        cout << "Invalid username. Username must be at least 6 characters long." << endl;
        return false;
    }
}
bool checkOptionValidation(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        if (ch < '0' || ch > '9')
        {
            return false;
        }
    }
    return true;
}

void printHeader()
{
    cout << "___________________________________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                                         |" << endl;
    cout << "|                                                                                                                         |" << endl;
    cout << "|                              ____  _   _ _____ ___ _  ___   _   _____ _____ ____ _   _                                  |" << endl;
    cout << "|                             | ___|| | | | ____|_ _| |/ | | | | |_   _| ____| ___| | | |                                 |" << endl;
    cout << "|                             |___ || |_| |  _|  | || ' /| |_| |   | | |  _| | |  | |_| |                                 |" << endl;
    cout << "|                              ___)||  _  | |___ | || . \\|  _  |   | | | |__ | |__|  _  |                                 |" << endl;
    cout << "|                             |____||_| |_|_____|___|_|\\_|_| |_|   |_| |_____|____|_| |_|                                 |" << endl;
    cout << "|                                                                                                                         |" << endl;
    cout << "|                                                                                                                         |" << endl;
    cout << "|                                                                                                                         |" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
}

void loginPage()
{
    cout << "\t \t \t \t \t \tLOGIN PAGE " << endl
         << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl
         << endl;
    cout << " 1. Sign In with your credentials." << endl;
    cout << " 2. Sign Up your credentials" << endl;
    cout << " 3. Exit" << endl
         << endl;
}

string signIn(string Name, string Password, string newName[], string newPassword[], string role[])
{
    for (int j = 0; j < 100; j++)
    {
        if (Name == newName[j] && Password != newPassword[j])
        {
            return "You have entered Wrong Password.";
        }
    }
    for (int j = 0; j < 100; j++)
    {
        if (Name != newName[j] && Password == newPassword[j])
        {
            return "You have entered Wrong Username.";
        }
    }
    for (int j = 0; j < 100; j++)
    {
        if (Name == newName[j] && Password == newPassword[j])
        {
            system("cls");
            return role[j];
        }
    }
    return "You are not registered yet.";
}
int accountcount(string Name, string Password, string newName[], string newPassword[], string role[])
{
    for (int j = 0; j < 100; j++)
    {
        if (Name == newName[j] && Password == newPassword[j])
        {
            system("cls");
            return j;
        }
    }
    return -1;
}

bool existedUsername(string newName[], int newCount)
{
    for (int i = newCount - 1; i >= 0; i--)
    {
        if (newName[newCount] == newName[i])
        {
            return true;
        }
    }
    return false;
}
bool checkMobileCompany(string company)
{
    if (company == "SAMSUNG" || company == "OPPO" || company == "INFINIX" || company == "MI XIAOMI" || company == "TECNO")
    {
        return true;
    }
    return false;
}
bool checkLaptopCompany(string company)
{
    if (company == "INFINIX" || company == "DELL" || company == "HP" || company == "IPHONE")
    {
        return true;
    }
    return false;
}
bool checkSWCompany(string company)
{
    if (company == "MIBRO" || company == "KIESLECT" || company == "ZERO" || company == "ASSORTED")
    {
        return true;
    }
    return false;
}
bool checkEarbudCompany(string company)
{
    if (company == "MI XIAOMI" || company == "AUDIONIC" || company == "ASSORTED")
    {
        return true;
    }
    return false;
}
bool checkModel(string models[], string modelName, int count)
{
    for (int j = 0; j < count; j++)
    {
        if (models[j] == modelName)
        {
            return true;
        }
    }
    return false;
}
void printMobiles(string mobileCompanies[], string SamsungM[], double SamsungMPrices[], string OppoM[], double oppoMPrices[], string InfinixM[], double infinixMPrices[], string miXiaomiM[], double miXiaomiMPrices[], string TecnoM[], double TecnoMPrices[], int mobileCount, int mobileSCount, int mobileOCount, int mobileICount, int mobileMCount, int mobileTCount)
{
    int mX = 81, mY = 19;
    cout << "\t \t \t \t \t \t \t \t Samsung" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < mobileSCount; i++)
    {
        cout << "\t \t \t \t" << SamsungM[i];
        gotoxy(mX, mY);
        cout << SamsungMPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t Oppo" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < mobileOCount; i++)
    {
        cout << "\t \t \t \t" << OppoM[i];
        gotoxy(mX, mY + 7);
        cout << oppoMPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Infinix" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < mobileICount; i++)
    {
        cout << "\t \t \t \t" << InfinixM[i];
        gotoxy(mX, mY + 14);
        cout << infinixMPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t MI Xiaomi" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < mobileMCount; i++)
    {
        cout << "\t \t \t \t" << miXiaomiM[i];
        gotoxy(mX, mY + 21);
        cout << miXiaomiMPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t Tecno" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < mobileTCount; i++)
    {
        cout << "\t \t \t \t" << TecnoM[i];
        gotoxy(mX, mY + 28);
        cout << TecnoMPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
}
void printLaptops(string LaptopCompanies[], string InfinixL[], double InfinixLPrices[], string Dell[], double dellPrices[], string HP[], double HPPrices[], string iphoneL[], double iphoneLPrices[], int laptopCount, int laptopICount, int laptopDCount, int laptopHCount, int laptopIpCount)
{
    int mX = 90, mY = 19;
    cout << "\t \t \t \t \t \t \t \t Infinix" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < laptopICount; i++)
    {
        cout << "\t \t \t \t" << InfinixL[i];
        gotoxy(mX, mY);
        cout << InfinixLPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t  Dell" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < laptopDCount; i++)
    {
        cout << "\t \t \t \t" << Dell[i];
        gotoxy(mX, mY + 7);
        cout << dellPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t HP" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < laptopHCount; i++)
    {
        cout << "\t \t \t \t" << HP[i];
        gotoxy(mX + 5, mY + 14);
        cout << HPPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t iPhone" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < laptopIpCount; i++)
    {
        cout << "\t \t \t \t" << iphoneL[i];
        gotoxy(mX, mY + 21);
        cout << iphoneLPrices[i] << endl;
        mY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
}
void printSmartWatches(string swCompanies[], string mibro[], double mibroPrices[], string kieslect[], double kieslectPrices[], string ZERO[], double zeroPrices[], string Assortedsw[], double AssortedswPrices[], int swCount, int swMCount, int swKCount, int swZCount, int swACount)
{
    int lX = 90, lY = 19;
    cout << "\t \t \t \t \t \t \t \t Mibro" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < swMCount; i++)
    {
        cout << "\t \t \t \t" << mibro[i];
        gotoxy(lX, lY);
        cout << mibroPrices[i] << endl;
        lY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t Kieslect" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < swKCount; i++)
    {
        cout << "\t \t \t \t" << kieslect[i];
        gotoxy(lX + 8, lY + 7);
        cout << kieslectPrices[i] << endl;
        lY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t Zero" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < swZCount; i++)
    {
        cout << "\t \t \t \t" << ZERO[i];
        gotoxy(lX, lY + 14);
        cout << zeroPrices[i] << endl;
        lY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t Assorted" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < swACount; i++)
    {
        cout << "\t \t \t \t" << Assortedsw[i];
        gotoxy(lX, lY + 21);
        cout << AssortedswPrices[i] << endl;
        lY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
}
void printEarbuds(string EarbudsCompanies[], string XiaomiE[], double XiaomiEPrices[], string Audionic[], double AudionicPrices[], string AssortedE[], double AssortedEPrices[], int earbudCount, int earbudXCount, int earbudACount, int earbudAsCount)
{
    int lX = 82, lY = 19;
    cout << "\t \t \t \t \t \t \t \t Xiaomi" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < earbudXCount; i++)
    {
        cout << "\t \t \t \t" << XiaomiE[i];
        gotoxy(lX, lY);
        cout << XiaomiEPrices[i] << endl;
        lY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t Audionic" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < earbudACount; i++)
    {
        cout << "\t \t \t \t" << Audionic[i];
        gotoxy(lX, lY + 7);
        cout << AudionicPrices[i] << endl;
        lY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    cout << "\t \t \t \t \t \t \t \t Assorted" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < earbudAsCount; i++)
    {
        cout << "\t \t \t \t" << AssortedE[i];
        gotoxy(lX, lY + 14);
        cout << AssortedEPrices[i] << endl;
        lY++;
    }
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
}
bool editModelPrice(string models[], double prices[], int count, string modelName, double newPrice)
{
    for (int j = 0; j < count; j++)
    {
        if (models[j] == modelName)
        {
            prices[j] = newPrice;
            return true;
        }
    }
    return false;
}
bool deleteModel(string models[], double prices[], int &count, string &modelName)
{
    for (int j = 0; j < count; j++)
    {
        if (models[j] == modelName)
        {
            for (int k = j; k < count - 1; k++)
            {
                models[k] = models[k + 1];
                prices[k] = prices[k + 1];
            }
            count--;
            return true;
        }
    }
    return false;
}
string editSHDevicePrice(string editshDevice, double editshDevicePrice, string shDevices[], double shDevicesPrices[], int &shCount)
{
    for (int i = 0; i < shCount; i++)
    {
        if (editshDevice == shDevices[i])
        {
            shDevicesPrices[i] = editshDevicePrice;
            UpdateDeviceData(shDevices, shDevicesPrices, shCount, "Shdevices.txt");

            return "Device Price Update successfully.";
        }
    }
}
string deleteSHDevice(string deleteshDevice, string shDevices[], double shDevicesPrices[], int &shCount)
{
    for (int i = 0; i < shCount; i++)
    {
        if (deleteshDevice == shDevices[i])
        {
            for (int j = i; j < shCount - 1; j++)
            {
                shDevices[j] = shDevices[j + 1];
                shDevicesPrices[j] = shDevicesPrices[j + 1];
            }
            shCount--;
            UpdateDeviceData(shDevices, shDevicesPrices, shCount, "Shdevices.txt");

            return deleteshDevice + " deleted successfully";
        }
    }
    return "Wrong Device Name";
}
void addDeviceData(string addModel, double addModelPrice, string company[], double companyPrices[], int &count, string fileName)
{
    company[count] = addModel;
    companyPrices[count] = addModelPrice;
    fstream file;
    file.open(fileName, ios::app);
    file << endl
         << company[count] << "," << companyPrices[count];
    count++;
}
void csph()
{
    system("cls");
    printHeader();
}
void adminMenu(string newName[], string role[], int newCount, string mobileCompanies[], string SamsungM[], double SamsungMPrices[], string OppoM[], double oppoMPrices[], string InfinixM[], double infinixMPrices[], string miXiaomiM[], double miXiaomiMPrices[], string TecnoM[], double TecnoMPrices[], int &mobileCount, string LaptopCompanies[], string InfinixL[], double InfinixLPrices[], string Dell[], double dellPrices[], string HP[], double HPPrices[], string iphoneL[], double iphoneLPrices[], int laptopCount, string swCompanies[], string mibro[], double mibroPrices[], string kieslect[], double kieslectPrices[], string ZERO[], double zeroPrices[], string Assortedsw[], double AssortedswPrices[], int swCount, string EarbudsCompanies[], string XiaomiE[], double XiaomiEPrices[], string Audionic[], double AudionicPrices[], string AssortedE[], double AssortedEPrices[], int earbudCount, int &mobileSCount, int &mobileOCount, int &mobileICount, int &mobileMCount, int &mobileTCount, int &laptopICount, int &laptopDCount, int &laptopHCount, int &laptopIpCount, int &swMCount, int &swKCount, int &swZCount, int &swACount, int &earbudXCount, int &earbudACount, int &earbudAsCount, string shDevices[], double shDevicesPrices[], int &shCount, double &budget, double &tempBudget, string feedbacks[], int &feedbackCount)
{
    int choice = 1;
    while (choice != 0)
    {
        int selectOption, option, x = 35, y = 18;
        string addMobile, addLaptop, addSW, addEarbud, addMobileModel, addLaptopModel, addSWModel, addEarbudModel, deleteMobile, deleteMobileModel, deleteLaptop, deleteLaptopModel, deleteSw, deleteSwModel, deleteEarbud, deleteEarbudModel, editshDevice, deleteshDevice;
        double addMobilePrices, addLaptopPrice, addSWPrice, addEarbudPrice, editshDevicePrice;
        bool foundMobile = false, foundLaptop = false, foundSW = false, foundEarbud = false, correct = false;

        csph();
        cout << "\t \t \t \t \t \t ADMIN MENU " << endl
             << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------" << endl
             << endl;
        cout << endl
             << endl
             << endl;
        cout << "Enter 1 to check registered users and admins." << endl;
        cout << "Enter 2 to watch devices." << endl;
        cout << "Enter 3 to add Device Model." << endl;
        cout << "Enter 4 to edit Device Price." << endl;
        cout << "Enter 5 to delete Device." << endl;
        cout << "Enter 6 to handle second hand devices." << endl;
        cout << "Enter 7 to view your sales" << endl;
        cout << "Enter 8 to see Feedbacks" << endl;
        cout << "Enter 9 to change Theme " << endl;
        cout << "Enter 0 to escape the matrix" << endl
             << endl;

        cout << "Enter your choice... ";
        string input;
        cin >> input;

        if (checkOptionValidation(input))
        {
            choice = stoi(input);
        }
        else
        {
            cout << "Invalid input. Please enter a valid integer." << endl;
            Sleep(750);
            continue;
        }

        csph();
        switch (choice)
        {
        case 1:
            cout << "\t Registered Admins and Customers are: " << endl
                 << endl;
            cout << "\t Username \t \t Status " << endl
                 << endl;
            cout << "--------------------------------------------------------------" << endl
                 << endl;
            for (int i = 0; i < newCount; i++)
            {
                cout << "\t " << newName[i];
                gotoxy(x, y);
                cout << role[i] << endl;
                y++;
            }
            cout << endl
                 << "Press any key to go back to Menu.... ";
            getch();
            break;
        case 2:
            do
            {
                csph();
                cout << "Enter 1 to watch Mobiles List" << endl;
                cout << "Enter 2 to watch Laptops List" << endl;
                cout << "Enter 3 to watch Smart Watches List" << endl;
                cout << "Enter 4 to watch Wireless Earbuds List" << endl;
                cout << "Enter 0 to go back to admin menu" << endl
                     << endl;
                cout << "Enter your choice... ";
                cin >> input;

                if (checkOptionValidation(input))
                {
                    selectOption = stoi(input);
                }
                else
                {
                    cout << "Invalid input. Please enter a valid integer." << endl;
                    Sleep(800);
                    csph();
                    continue;
                }

                if (selectOption == 1)
                {
                    csph();
                    cout << "Following is the list of Mobiles with their prices." << endl
                         << endl;
                    printMobiles(mobileCompanies, SamsungM, SamsungMPrices, OppoM, oppoMPrices, InfinixM, infinixMPrices, miXiaomiM, miXiaomiMPrices, TecnoM, TecnoMPrices, mobileCount, mobileSCount, mobileOCount, mobileICount, mobileMCount, mobileTCount);
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 2)
                {
                    csph();
                    cout << "Following is the list of Laptops with their prices." << endl
                         << endl;
                    printLaptops(LaptopCompanies, InfinixL, InfinixLPrices, Dell, dellPrices, HP, HPPrices, iphoneL, iphoneLPrices, laptopCount, laptopICount, laptopDCount, laptopHCount, laptopIpCount);
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 3)
                {
                    csph();
                    cout << "Following is the list of Smart Watches with their prices." << endl
                         << endl;
                    printSmartWatches(swCompanies, mibro, mibroPrices, kieslect, kieslectPrices, ZERO, zeroPrices, Assortedsw, AssortedswPrices, swCount, swMCount, swKCount, swZCount, swACount);
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 4)
                {
                    csph();
                    cout << "Following is the list of Earbuds with their prices." << endl
                         << endl;
                    printEarbuds(EarbudsCompanies, XiaomiE, XiaomiEPrices, Audionic, AudionicPrices, AssortedE, AssortedEPrices, earbudCount, earbudXCount, earbudACount, earbudAsCount);
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption > 4)
                {
                    Sleep(800);
                    csph();
                    cout << endl
                         << " /!\\ Write valid option please." << endl
                         << endl
                         << endl;
                }
            } while (selectOption != 0);
            break;
        case 3:
            do
            {
                csph();
                cout << endl
                     << endl
                     << "Enter 1 to add new Mobile Model" << endl;
                cout << "Enter 2 to add new Laptops Model" << endl;
                cout << "Enter 3 to add new Smart Watches Model" << endl;
                cout << "Enter 4 to add new Wireless Earbuds Model" << endl;
                cout << "Enter 0 to go back to admin menu" << endl
                     << endl;
                cout << "Enter your choice... ";
                cin >> input;

                if (checkOptionValidation(input))
                {
                    selectOption = stoi(input);
                }
                else
                {
                    cout << "Invalid input. Please enter a valid integer." << endl;
                    Sleep(800);
                    csph();
                    continue;
                }
                if (selectOption == 1)
                {
                    csph();
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the name of company in which you want to add model...";
                        getline(cin, addMobile);
                        addMobile = upperLetters(addMobile);
                        if (checkMobileCompany(addMobile))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    cout << "Enter the name of model you wand to add...";
                    getline(cin, addMobileModel);
                    addMobileModel = upperLetters(addMobileModel);
                    while (true)
                    {
                        cout << "Enter the price for this model...";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            addMobilePrices = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }
                    if (addMobile == "SAMSUNG")
                    {
                        addDeviceData(addMobileModel, addMobilePrices, SamsungM, SamsungMPrices, mobileSCount, "Samsung.txt");
                        cout << "Mobile model added successfully to Samsung." << endl;
                    }
                    else if (addMobile == "OPPO")
                    {
                        addDeviceData(addMobileModel, addMobilePrices, OppoM, oppoMPrices, mobileOCount, "Oppo.txt");
                        cout << "Mobile model added successfully to Oppo." << endl;
                    }
                    else if (addMobile == "INFINIX")
                    {
                        addDeviceData(addMobileModel, addMobilePrices, InfinixM, infinixMPrices, mobileICount, "InfinixM.txt");
                        cout << "Mobile model added successfully to Infinix." << endl;
                    }
                    else if (addMobile == "MI XIAOMI")
                    {
                        addDeviceData(addMobileModel, addMobilePrices, miXiaomiM, miXiaomiMPrices, mobileMCount, "MiM.txt");
                        cout << "Mobile model added successfully to MI Xiaomi." << endl;
                    }
                    else if (addMobile == "TECNO")
                    {
                        addDeviceData(addMobileModel, addMobilePrices, TecnoM, TecnoMPrices, mobileTCount, "Tecno.txt");
                        cout << "Mobile model added successfully to Tecno." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 2)
                {
                    csph();
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the name of company in which you want to add model...";
                        getline(cin, addLaptop);
                        addLaptop = upperLetters(addLaptop);
                        if (checkLaptopCompany(addLaptop))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    cout << "Enter the name of model you want to add...";
                    getline(cin, addLaptopModel);
                    addLaptopModel = upperLetters(addLaptopModel);

                    while (true)
                    {
                        cout << "Enter the price for this model...";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            addLaptopPrice = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }

                    if (addLaptop == "INFINIX")
                    {
                        addDeviceData(addLaptopModel, addLaptopPrice, InfinixL, InfinixLPrices, laptopICount, "InfinixL.txt");
                        cout << "Laptop model added successfully to Infinix." << endl;
                    }
                    else if (addLaptop == "DELL")
                    {
                        addDeviceData(addLaptopModel, addLaptopPrice, Dell, dellPrices, laptopDCount, "Dell.txt");
                        cout << "Laptop model added successfully to Dell." << endl;
                    }
                    else if (addLaptop == "HP")
                    {
                        addDeviceData(addLaptopModel, addLaptopPrice, HP, HPPrices, laptopHCount, "Hp.txt");
                        cout << "Laptop model added successfully to HP." << endl;
                    }
                    else if (addLaptop == "IPHONE")
                    {
                        addDeviceData(addLaptopModel, addLaptopPrice, iphoneL, iphoneLPrices, laptopIpCount, "Iphone.txt");
                        cout << "Laptop model added successfully to iPhone." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 3)
                {
                    csph();
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the name of company in which you want to add model...";
                        getline(cin, addSW);
                        addSW = upperLetters(addSW);
                        if (checkSWCompany(addSW))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    cout << "Enter the name of model you want to add...";
                    getline(cin, addSWModel);
                    addSWModel = upperLetters(addSWModel);
                    while (true)
                    {
                        cout << "Enter the price for this model...";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            addSWPrice = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }

                    if (addSW == "MIBRO")
                    {
                        addDeviceData(addSWModel, addSWPrice, mibro, mibroPrices, swMCount, "Mibro.txt");
                        cout << "Smart Watch model added successfully to Mibro." << endl;
                    }
                    else if (addSW == "KIESLECT")
                    {
                        addDeviceData(addSWModel, addSWPrice, kieslect, kieslectPrices, swKCount, "Kieslect.txt");
                        cout << "Smart Watch model added successfully to Kieslect." << endl;
                    }
                    else if (addSW == "ZERO")
                    {
                        addDeviceData(addSWModel, addSWPrice, ZERO, zeroPrices, swZCount, "Zero.txt");
                        cout << "Smart Watch model added successfully to ZERO." << endl;
                    }
                    else if (addSW == "ASSORTED")
                    {
                        addDeviceData(addSWModel, addSWPrice, Assortedsw, AssortedswPrices, swACount, "AssortedS.txt");
                        cout << "Smart Watch model added successfully to Assorted." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 4)
                {
                    csph();
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the name of company in which you want to add model...";
                        getline(cin, addEarbud);
                        addEarbud = upperLetters(addEarbud);
                        if (checkEarbudCompany(addEarbud))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    cout << "Enter the name of model you want to add...";
                    getline(cin, addEarbudModel);
                    addEarbudModel = upperLetters(addEarbudModel);
                    while (true)
                    {
                        cout << "Enter the price for this model...";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            addEarbudPrice = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }

                    if (addEarbud == "XIAOMI")
                    {
                        addDeviceData(addEarbudModel, addEarbudPrice, XiaomiE, XiaomiEPrices, earbudXCount, "MiE.txt");
                        cout << "Earbud model added successfully to Xiaomi." << endl;
                    }
                    else if (addEarbud == "AUDIONIC")
                    {
                        addDeviceData(addEarbudModel, addEarbudPrice, Audionic, AudionicPrices, earbudACount, "Audionic.txt");
                        cout << "Earbud model added successfully to Audionic." << endl;
                    }
                    else if (addEarbud == "ASSORTED")
                    {
                        addDeviceData(addEarbudModel, addEarbudPrice, AssortedE, AssortedEPrices, earbudAsCount, "AssortedE.txt");
                        cout << "Earbud model added successfully to Assorted." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption > 4)
                {
                    cout << "Write valid option.";
                }
            } while (selectOption != 0);
            break;
        case 4:
            do
            {
                csph();
                cout << "Enter 1 to edit Mobile Price" << endl;
                cout << "Enter 2 to edit Laptop Price" << endl;
                cout << "Enter 3 to edit Smart Watch Price" << endl;
                cout << "Enter 4 to edit Earbuds Price" << endl;
                cout << "Enter 0 to return to Admin Menu" << endl;
                cout << "Choose the option: ";
                cin >> input;
                if (checkOptionValidation(input))
                {
                    selectOption = stoi(input);
                }
                else
                {
                    cout << "Invalid input. Please enter a valid integer." << endl;
                    Sleep(750);
                    continue;
                }
                if (selectOption == 1)
                {
                    csph();
                    printMobiles(mobileCompanies, SamsungM, SamsungMPrices, OppoM, oppoMPrices, InfinixM, infinixMPrices, miXiaomiM, miXiaomiMPrices, TecnoM, TecnoMPrices, mobileCount, mobileSCount, mobileOCount, mobileICount, mobileMCount, mobileTCount);
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the company name for which you want to edit the mobile price: ";
                        getline(cin, addMobile);
                        addMobile = upperLetters(addMobile);
                        if (checkMobileCompany(addMobile))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the model name for which you want to edit the price: ";
                        getline(cin, addMobileModel);
                        addMobileModel = upperLetters(addMobileModel);
                        if (addMobile == "SAMSUNG" && checkModel(SamsungM, addMobileModel, mobileSCount))
                        {
                            break;
                        }
                        else if (addMobile == "OPPO" && checkModel(OppoM, addMobileModel, mobileOCount))
                        {
                            break;
                        }
                        else if (addMobile == "INFINIX" && checkModel(InfinixM, addMobileModel, mobileICount))
                        {
                            break;
                        }
                        else if (addMobile == "MI XIAOMI" && checkModel(miXiaomiM, addMobileModel, mobileMCount))
                        {
                            break;
                        }
                        else if (addMobile == "TECNO" && checkModel(TecnoM, addMobileModel, mobileTCount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the new price: ";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            addMobilePrices = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }
                    if (addMobile == "SAMSUNG")
                    {
                        foundMobile = editModelPrice(SamsungM, SamsungMPrices, mobileSCount, addMobileModel, addMobilePrices);
                        UpdateDeviceData(SamsungM, SamsungMPrices, mobileSCount, "Samsung.txt");
                    }
                    else if (addMobile == "OPPO")
                    {
                        foundMobile = editModelPrice(OppoM, oppoMPrices, mobileOCount, addMobileModel, addMobilePrices);
                        UpdateDeviceData(OppoM, oppoMPrices, mobileOCount, "Oppo.txt");
                    }
                    else if (addMobile == "INFINIX")
                    {
                        foundMobile = editModelPrice(InfinixM, infinixMPrices, mobileICount, addMobileModel, addMobilePrices);
                        UpdateDeviceData(InfinixM, infinixMPrices, mobileICount, "InfinixM.txt");
                    }
                    else if (addMobile == "MI XIAOMI")
                    {
                        foundMobile = editModelPrice(miXiaomiM, miXiaomiMPrices, mobileMCount, addMobileModel, addMobilePrices);
                        UpdateDeviceData(miXiaomiM, miXiaomiMPrices, mobileMCount, "MiM.txt");
                    }
                    else if (addMobile == "TECNO")
                    {
                        foundMobile = editModelPrice(TecnoM, TecnoMPrices, mobileTCount, addMobileModel, addMobilePrices);
                        UpdateDeviceData(TecnoM, TecnoMPrices, mobileTCount, "Tecno.txt");
                    }

                    if (foundMobile)
                    {
                        cout << "Mobile price updated successfully." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 2)
                {
                    csph();
                    cin.ignore();
                    printLaptops(LaptopCompanies, InfinixL, InfinixLPrices, Dell, dellPrices, HP, HPPrices, iphoneL, iphoneLPrices, laptopCount, laptopICount, laptopDCount, laptopHCount, laptopIpCount);

                    while (true)
                    {
                        cout << "Enter the company name for which you want to edit the Laptop price: ";
                        getline(cin, addLaptop);
                        addLaptop = upperLetters(addLaptop);
                        if (checkLaptopCompany(addLaptop))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the model name for which you want to edit the price: ";
                        getline(cin, addLaptopModel);
                        addLaptopModel = upperLetters(addLaptopModel);
                        if (addLaptop == "INFINIX" && checkModel(InfinixL, addLaptopModel, laptopICount))
                        {
                            break;
                        }
                        else if (addLaptop == "DELL" && checkModel(Dell, addLaptopModel, laptopDCount))
                        {
                            break;
                        }
                        else if (addLaptop == "HP" && checkModel(HP, addLaptopModel, laptopHCount))
                        {
                            break;
                        }
                        else if (addLaptop == "IPHONE" && checkModel(iphoneL, addLaptopModel, laptopIpCount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the new price: ";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            addLaptopPrice = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }
                    if (addLaptop == "INFINIX")
                    {
                        foundLaptop = editModelPrice(InfinixL, InfinixLPrices, laptopICount, addLaptopModel, addLaptopPrice);
                        UpdateDeviceData(InfinixL, InfinixLPrices, laptopICount, "InfinixL.txt");
                    }
                    else if (addLaptop == "DELL")
                    {
                        foundLaptop = editModelPrice(Dell, dellPrices, laptopDCount, addLaptopModel, addLaptopPrice);
                        UpdateDeviceData(Dell, dellPrices, laptopDCount, "Dell.txt");
                    }
                    else if (addLaptop == "HP")
                    {
                        foundLaptop = editModelPrice(HP, HPPrices, laptopHCount, addLaptopModel, addLaptopPrice);
                        UpdateDeviceData(HP, HPPrices, laptopHCount, "Hp.txt");
                    }
                    else if (addLaptop == "IPHONE")
                    {
                        foundLaptop = editModelPrice(iphoneL, iphoneLPrices, laptopICount, addLaptopModel, addLaptopPrice);
                        UpdateDeviceData(iphoneL, iphoneLPrices, laptopIpCount, "Iphone.txt");
                    }

                    if (foundLaptop)
                    {
                        cout << "Laptop price updated successfully." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 3)
                {
                    csph();
                    printSmartWatches(swCompanies, mibro, mibroPrices, kieslect, kieslectPrices, ZERO, zeroPrices, Assortedsw, AssortedswPrices, swCount, swMCount, swKCount, swZCount, swACount);
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the company name for which you want to edit the smart watch price: ";
                        getline(cin, addSW);
                        addSW = upperLetters(addSW);
                        if (checkSWCompany(addSW))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the model name for which you want to edit the price: ";
                        getline(cin, addSWModel);
                        addSWModel = upperLetters(addSWModel);
                        if (addSW == "MIBRO" && checkModel(mibro, addSWModel, swMCount))
                        {
                            break;
                        }
                        else if (addSW == "KIESLECT" && checkModel(kieslect, addSWModel, swKCount))
                        {
                            break;
                        }
                        else if (addSW == "ZERO" && checkModel(ZERO, addSWModel, swZCount))
                        {
                            break;
                        }
                        else if (addSW == "ASSORTED" && checkModel(Assortedsw, addSWModel, swACount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }

                    while (true)
                    {
                        cout << "Enter the new price: ";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            addSWPrice = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }
                    if (addSW == "MIBRO")
                    {
                        foundSW = editModelPrice(mibro, mibroPrices, swMCount, addSWModel, addSWPrice);
                        UpdateDeviceData(mibro, mibroPrices, swMCount, "Mibro.txt");
                    }
                    else if (addSW == "KIESLECT")
                    {
                        foundSW = editModelPrice(kieslect, kieslectPrices, swKCount, addSWModel, addSWPrice);
                        UpdateDeviceData(kieslect, kieslectPrices, swKCount, "Kieslect.txt");
                    }
                    else if (addSW == "ZERO")
                    {
                        foundSW = editModelPrice(ZERO, zeroPrices, swZCount, addSWModel, addSWPrice);
                        UpdateDeviceData(ZERO, zeroPrices, swZCount, "Zero.txt");
                    }
                    else if (addSW == "ASSORTED")
                    {
                        foundSW = editModelPrice(Assortedsw, AssortedswPrices, swACount, addSWModel, addSWPrice);
                        UpdateDeviceData(Assortedsw, AssortedswPrices, swACount, "AssortedS.txt");
                    }

                    if (foundSW)
                    {
                        cout << "Smartwatch price updated successfully." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 4)
                {
                    csph();
                    cin.ignore();
                    printEarbuds(EarbudsCompanies, XiaomiE, XiaomiEPrices, Audionic, AudionicPrices, AssortedE, AssortedEPrices, earbudCount, earbudXCount, earbudACount, earbudAsCount);

                    while (true)
                    {
                        cout << "Enter the company name for which you want to edit the Earbud price: ";
                        getline(cin, addEarbud);
                        addEarbud = upperLetters(addEarbud);
                        if (checkEarbudCompany(addEarbud))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the model name for which you want to edit the price: ";
                        getline(cin, addEarbudModel);
                        addEarbudModel = upperLetters(addEarbudModel);
                        if (addEarbud == "MI XIAOMI" && checkModel(XiaomiE, addEarbudModel, earbudXCount))
                        {
                            break;
                        }
                        else if (addEarbud == "AUDIONIC" && checkModel(Audionic, addEarbudModel, earbudACount))
                        {
                            break;
                        }
                        else if (addEarbud == "ASSORTED" && checkModel(AssortedE, addEarbudModel, earbudAsCount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the new price: ";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            addEarbudPrice = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }
                    if (addEarbud == "XIAOMI")
                    {
                        foundEarbud = editModelPrice(XiaomiE, XiaomiEPrices, earbudXCount, addEarbudModel, addEarbudPrice);
                        UpdateDeviceData(XiaomiE, XiaomiEPrices, earbudXCount, "MiE.txt");
                    }
                    else if (addEarbud == "AUDIONIC")
                    {
                        foundEarbud = editModelPrice(Audionic, AudionicPrices, earbudACount, addEarbudModel, addEarbudPrice);
                        UpdateDeviceData(Audionic, AudionicPrices, earbudACount, "Audionic.txt");
                    }
                    else if (addEarbud == "ASSORTED")
                    {
                        foundEarbud = editModelPrice(AssortedE, AssortedEPrices, earbudAsCount, addEarbudModel, addEarbudPrice);
                        UpdateDeviceData(AssortedE, AssortedEPrices, earbudAsCount, "AssortedE.txt");
                    }
                    if (foundEarbud)
                    {
                        cout << "Earbuds price updated successfully." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption > 4)
                {
                    cout << "Invalid Option";
                }
            } while (selectOption != 0);
            break;
        case 5:
            do
            {
                csph();
                cout << "Enter 1 to Delete Mobile " << endl;
                cout << "Enter 2 to Delete Laptops " << endl;
                cout << "Enter 3 to Delete Smart Watches " << endl;
                cout << "Enter 4 to Delete Wireless Earbuds " << endl;
                cout << "Enter 0 to return to Admin Menu" << endl;
                cout << "Enter your choice... ";
                cin >> input;

                if (checkOptionValidation(input))
                {
                    selectOption = stoi(input);
                }
                else
                {
                    cout << "Invalid input. Please enter a valid integer." << endl;
                    Sleep(750);
                    continue;
                }
                if (selectOption == 1)
                {
                    csph();
                    printMobiles(mobileCompanies, SamsungM, SamsungMPrices, OppoM, oppoMPrices, InfinixM, infinixMPrices, miXiaomiM, miXiaomiMPrices, TecnoM, TecnoMPrices, mobileCount, mobileSCount, mobileOCount, mobileICount, mobileMCount, mobileTCount);
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the company name for which you want to delete a Mobile model: ";
                        getline(cin, deleteMobile);
                        deleteMobile = upperLetters(deleteMobile);
                        if (checkMobileCompany(deleteMobile))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the model name which you want to delete: ";
                        getline(cin, deleteMobileModel);
                        deleteMobileModel = upperLetters(deleteMobileModel);
                        if (deleteMobile == "SAMSUNG" && checkModel(SamsungM, deleteMobileModel, mobileSCount))
                        {
                            break;
                        }
                        else if (deleteMobile == "OPPO" && checkModel(OppoM, deleteMobileModel, mobileOCount))
                        {
                            break;
                        }
                        else if (deleteMobile == "INFINIX" && checkModel(InfinixM, deleteMobileModel, mobileICount))
                        {
                            break;
                        }
                        else if (deleteMobile == "MI XIAOMI" && checkModel(miXiaomiM, deleteMobileModel, mobileMCount))
                        {
                            break;
                        }
                        else if (deleteMobile == "TECNO" && checkModel(TecnoM, deleteMobileModel, mobileTCount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }

                    if (deleteMobile == "SAMSUNG")
                    {
                        foundMobile = deleteModel(SamsungM, SamsungMPrices, mobileSCount, deleteMobileModel);
                        UpdateDeviceData(SamsungM, SamsungMPrices, mobileSCount, "Samsung.txt");
                    }
                    else if (deleteMobile == "OPPO")
                    {
                        foundMobile = deleteModel(OppoM, oppoMPrices, mobileOCount, deleteMobileModel);
                        UpdateDeviceData(OppoM, oppoMPrices, mobileOCount, "Oppo.txt");
                    }
                    else if (deleteMobile == "INFINIX")
                    {
                        foundMobile = deleteModel(InfinixM, infinixMPrices, mobileICount, deleteMobileModel);

                        UpdateDeviceData(InfinixM, infinixMPrices, mobileICount, "InfinixM.txt");
                    }
                    else if (deleteMobile == "MI XIAOMI")
                    {
                        foundMobile = deleteModel(miXiaomiM, miXiaomiMPrices, mobileMCount, deleteMobileModel);
                        UpdateDeviceData(miXiaomiM, miXiaomiMPrices, mobileMCount, "MiM.txt");
                    }
                    else if (deleteMobile == "TECNO")
                    {
                        foundMobile = deleteModel(TecnoM, TecnoMPrices, mobileTCount, deleteMobileModel);
                        UpdateDeviceData(TecnoM, TecnoMPrices, mobileTCount, "Tecno.txt");
                    }

                    if (foundMobile)
                    {
                        cout << "Mobile model deleted successfully." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 2)
                {
                    csph();
                    cin.ignore();
                    printLaptops(LaptopCompanies, InfinixL, InfinixLPrices, Dell, dellPrices, HP, HPPrices, iphoneL, iphoneLPrices, laptopCount, laptopICount, laptopDCount, laptopHCount, laptopIpCount);
                    while (true)
                    {
                        cout << "Enter the company name for which you want to delete a Laptop model: ";
                        getline(cin, deleteLaptop);
                        deleteLaptop = upperLetters(deleteLaptop);
                        if (checkLaptopCompany(deleteLaptop))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the model name you want to delete: ";
                        getline(cin, deleteLaptopModel);
                        deleteLaptopModel = upperLetters(deleteLaptopModel);
                        if (deleteLaptop == "INFINIX" && checkModel(InfinixL, deleteLaptopModel, laptopICount))
                        {
                            break;
                        }
                        else if (deleteLaptop == "DELL" && checkModel(Dell, deleteLaptopModel, laptopDCount))
                        {
                            break;
                        }
                        else if (deleteLaptop == "HP" && checkModel(HP, deleteLaptopModel, laptopHCount))
                        {
                            break;
                        }
                        else if (deleteLaptop == "IPHONE" && checkModel(iphoneL, deleteLaptopModel, laptopIpCount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }

                    if (deleteLaptop == "INFINIX")
                    {
                        foundLaptop = deleteModel(InfinixL, InfinixLPrices, laptopICount, deleteLaptopModel);
                        UpdateDeviceData(InfinixL, InfinixLPrices, laptopICount, "InfinixL.txt");
                    }
                    else if (deleteLaptop == "DELL")
                    {
                        foundLaptop = deleteModel(Dell, dellPrices, laptopDCount, deleteLaptopModel);
                        UpdateDeviceData(Dell, dellPrices, laptopDCount, "Dell.txt");
                    }
                    else if (deleteLaptop == "HP")
                    {
                        foundLaptop = deleteModel(HP, HPPrices, laptopHCount, deleteLaptopModel);
                        UpdateDeviceData(HP, HPPrices, laptopHCount, "Hp.txt");
                    }
                    else if (deleteLaptop == "IPHONE")
                    {
                        foundLaptop = deleteModel(iphoneL, iphoneLPrices, laptopICount, deleteLaptopModel);
                        UpdateDeviceData(iphoneL, iphoneLPrices, laptopIpCount, "Iphone.txt");
                    }

                    if (foundLaptop)
                    {
                        cout << "Laptop model deleted successfully." << endl;
                    }

                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 3)
                {
                    csph();
                    cin.ignore();
                    printSmartWatches(swCompanies, mibro, mibroPrices, kieslect, kieslectPrices, ZERO, zeroPrices, Assortedsw, AssortedswPrices, swCount, swMCount, swKCount, swZCount, swACount);

                    while (true)
                    {
                        cout << "Enter the company name for which you want to delete a Smart Watch model: ";
                        getline(cin, deleteSw);
                        deleteSw = upperLetters(deleteSw);
                        if (checkSWCompany(deleteSw))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the model name you want to delete: ";
                        getline(cin, deleteSwModel);
                        deleteSwModel = upperLetters(deleteSwModel);
                        if (deleteSw == "MIBRO" && checkModel(mibro, deleteSwModel, swMCount))
                        {
                            break;
                        }
                        else if (deleteSw == "KIESLECT" && checkModel(kieslect, deleteSwModel, swKCount))
                        {
                            break;
                        }
                        else if (deleteSw == "ZERO" && checkModel(ZERO, deleteSwModel, swZCount))
                        {
                            break;
                        }
                        else if (deleteSw == "ASSORTED" && checkModel(Assortedsw, deleteSwModel, swACount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }

                    if (deleteSw == "MIBRO")
                    {
                        foundSW = deleteModel(mibro, mibroPrices, swMCount, deleteSwModel);
                        UpdateDeviceData(mibro, mibroPrices, swMCount, "Mibro.txt");
                    }
                    else if (deleteSw == "KIESLECT")
                    {
                        foundSW = deleteModel(kieslect, kieslectPrices, swKCount, deleteSwModel);
                        UpdateDeviceData(kieslect, kieslectPrices, swKCount, "Kieslect.txt");
                    }
                    else if (deleteSw == "ZERO")
                    {
                        foundSW = deleteModel(ZERO, zeroPrices, swZCount, deleteSwModel);
                        UpdateDeviceData(ZERO, zeroPrices, swZCount, "Zero.txt");
                    }
                    else if (deleteSw == "ASSORTED")
                    {
                        foundSW = deleteModel(Assortedsw, AssortedswPrices, swACount, deleteSwModel);
                        UpdateDeviceData(Assortedsw, AssortedswPrices, swACount, "AssortedS.txt");
                    }
                    if (foundSW)
                    {
                        cout << "Smart Watch deleted successfully." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 4)
                {
                    csph();
                    cin.ignore();
                    printEarbuds(EarbudsCompanies, XiaomiE, XiaomiEPrices, Audionic, AudionicPrices, AssortedE, AssortedEPrices, earbudCount, earbudXCount, earbudACount, earbudAsCount);

                    while (true)
                    {
                        cout << "Enter the company name for which you want to delete a Earbud model: ";
                        getline(cin, deleteEarbud);
                        deleteEarbud = upperLetters(deleteEarbud);
                        if (checkEarbudCompany(deleteEarbud))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid company name" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the model name for which you want to edit the price: ";
                        getline(cin, deleteEarbudModel);
                        deleteEarbudModel = upperLetters(deleteEarbudModel);
                        if (deleteEarbud == "MI XIAOMI" && checkModel(XiaomiE, deleteEarbudModel, earbudXCount))
                        {
                            break;
                        }
                        else if (deleteEarbud == "AUDIONIC" && checkModel(Audionic, deleteEarbudModel, earbudACount))
                        {
                            break;
                        }
                        else if (deleteEarbud == "ASSORTED" && checkModel(AssortedE, deleteEarbudModel, earbudAsCount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }

                    if (deleteEarbud == "Xiaomi")
                    {
                        foundEarbud = deleteModel(XiaomiE, XiaomiEPrices, earbudXCount, deleteEarbudModel);
                        UpdateDeviceData(XiaomiE, XiaomiEPrices, earbudXCount, "MiE.txt");
                    }
                    else if (deleteEarbud == "Audionic")
                    {
                        foundEarbud = deleteModel(Audionic, AudionicPrices, earbudACount, deleteEarbudModel);
                        UpdateDeviceData(Audionic, AudionicPrices, earbudACount, "Audionic.txt");
                    }
                    else if (deleteEarbud == "Assorted")
                    {
                        foundEarbud = deleteModel(AssortedE, AssortedEPrices, earbudAsCount, deleteEarbudModel);
                        UpdateDeviceData(AssortedE, AssortedEPrices, earbudAsCount, "AssortedE.txt");
                    }
                    if (foundEarbud)
                    {
                        cout << "Earbuds deleted successfully." << endl;
                    }
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption > 4)
                {
                    cout << "Invalid Option";
                }
            } while (selectOption != 0);
            break;
        case 6:
            do
            {
                csph();
                cout << "Enter 1 to watch Second Hand Devices " << endl;
                cout << "Enter 2 to add Second Hand Devices " << endl;
                cout << "Enter 3 to edit Second Hand Device Price" << endl;
                cout << "Enter 4 to delete Second Hand Device" << endl;
                cout << "Enter 0 to return to Admin Menu" << endl;
                cout << "Choose an option...";
                cin >> input;
                if (checkOptionValidation(input))
                {
                    selectOption = stoi(input);
                }
                else
                {
                    cout << "Write valid Input";
                    Sleep(750);
                    continue;
                }

                if (selectOption == 1)
                {
                    csph();
                    displaySHDevices(shDevices, shDevicesPrices, shCount);
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 2)
                {
                    csph();
                    cout << "Enter the name of device (with model and company) to add: ";
                    cin.ignore();
                    getline(cin, shDevices[shCount]);
                    shDevices[shCount] = upperLetters(shDevices[shCount]);
                    while (true)
                    {
                        cout << "Enter the price for this device: ";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            shDevicesPrices[shCount] = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }
                    cout << endl
                         << shDevices[shCount] << " of price " << shDevicesPrices[shCount] << " has been added.";
                    shCount++;
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 3)
                {
                    csph();
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the name of device (with model and company) of which you want to change price: ";
                        getline(cin, editshDevice);
                        editshDevice = upperLetters(editshDevice);
                        if (checkModel(shDevices, editshDevice, shCount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter the new price for " << editshDevice << ": ";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            editshDevicePrice = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }
                    cout << endl
                         << editSHDevicePrice(editshDevice, editshDevicePrice, shDevices, shDevicesPrices, shCount);
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption == 4)
                {
                    csph();
                    cin.ignore();
                    while (true)
                    {
                        cout << "Enter the name of device (with model and company) to delete: ";
                        getline(cin, deleteshDevice);
                        deleteshDevice = upperLetters(deleteshDevice);
                        if (checkModel(shDevices, deleteshDevice, shCount))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Model not found." << endl;
                        }
                    }
                    cout << deleteSHDevice(deleteshDevice, shDevices, shDevicesPrices, shCount);
                    cout << endl
                         << "Press any key to go back...";
                    getch();
                }
                else if (selectOption > 4)
                {
                    cout << "Enter valid option.";
                }
            } while (selectOption != 0);

            break;
        case 7:
            cout << "Your Sales: $" << tempBudget;
            cout << endl
                 << "Press any key to go back to Menu.... ";
            getch();
            break;
        case 8:
            if (feedbackCount == 0)
            {
                gotoxy(35, 12);
                cout << "No Feedbacks Till Now.";
            }
            else
            {
                cout << "                                       FEEDBACKS              " << endl;
                cout << "=======================================================================================================" << endl
                     << endl;

                for (int i = 0; i < feedbackCount; i++)
                {
                    cout << feedbacks[i] << endl;
                }
            }
            cout << endl
                 << "Press any key to go back to Menu.... ";
            getch();
            break;
        case 9:
            cout << "Enter 1 for black theme." << endl;
            cout << "Enter 2 for white theme." << endl
                 << endl;
            while (true)
            {
                cout << "Choose the option: ";
                cin >> input;
                if (checkOptionValidation(input))
                {
                    option = stoi(input);
                    break;
                }
                else
                {
                    cout << "Write valid input" << endl;
                }
            }
            if (option == 1)
            {
                changeTheme(1);
            }
            else if (option == 2)
            {
                changeTheme(2);
            }
            break;
        case 0:

            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            Sleep(800);
            break;
        }
    }
}

void changeTheme(int val)
{
    if (val == 1)
    {
        system("Color 07");
    }
    else if (val == 2)
    {
        system("Color 70");
    }
}

void printMobileswithinbudget(double budget, string mobileCompanies[], string SamsungM[], double SamsungMPrices[], string OppoM[], double oppoMPrices[], string InfinixM[], double infinixMPrices[], string miXiaomiM[], double miXiaomiMPrices[], string TecnoM[], double TecnoMPrices[], int mobileCount, int mobileSCount, int mobileOCount, int mobileICount, int mobileMCount, int mobileTCount)
{
    int mX = 81, mY = 19;

    cout << "\t \t \t \t \t \t \t \t Samsung" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < mobileSCount; i++)
    {
        if (SamsungMPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << SamsungM[i];
            gotoxy(mX, mY);
            cout << SamsungMPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Oppo" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < mobileOCount; i++)
    {
        if (oppoMPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << OppoM[i];
            gotoxy(mX, mY + 7);
            cout << oppoMPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Infinix" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < mobileICount; i++)
    {
        if (infinixMPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << InfinixM[i];
            gotoxy(mX, mY + 14);
            cout << infinixMPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t MI Xiaomi" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < mobileMCount; i++)
    {
        if (miXiaomiMPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << miXiaomiM[i];
            gotoxy(mX, mY + 21);
            cout << miXiaomiMPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Tecno" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < mobileTCount; i++)
    {
        if (TecnoMPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << TecnoM[i];
            gotoxy(mX, mY + 28);
            cout << TecnoMPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
}
void printLaptopswithinbudget(double budget, string LaptopCompanies[], string InfinixL[], double InfinixLPrices[], string Dell[], double dellPrices[], string HP[], double HPPrices[], string iphoneL[], double iphoneLPrices[], int laptopCount, int laptopICount, int laptopDCount, int laptopHCount, int laptopIpCount)
{
    int mX = 90, mY = 19;

    cout << "\t \t \t \t \t \t \t \t Infinix" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < laptopICount; i++)
    {
        if (InfinixLPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << InfinixL[i];
            gotoxy(mX, mY);
            cout << InfinixLPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t  Dell" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < laptopDCount; i++)
    {
        if (dellPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << Dell[i];
            gotoxy(mX, mY + 7);
            cout << dellPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t HP" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < laptopHCount; i++)
    {
        if (HPPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << HP[i];
            gotoxy(mX + 5, mY + 14);
            cout << HPPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t iPhone" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < laptopIpCount; i++)
    {
        if (iphoneLPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << iphoneL[i];
            gotoxy(mX, mY + 21);
            cout << iphoneLPrices[i] << endl;
            mY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
}
void printSmartWatcheswithinbudget(double budget, string swCompanies[], string mibro[], double mibroPrices[], string kieslect[], double kieslectPrices[], string ZERO[], double zeroPrices[], string Assortedsw[], double AssortedswPrices[], int swCount, int swMCount, int swKCount, int swZCount, int swACount)
{
    int lX = 90, lY = 19;

    cout << "\t \t \t \t \t \t \t \t Mibro" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < swMCount; i++)
    {
        if (mibroPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << mibro[i];
            gotoxy(lX, lY);
            cout << mibroPrices[i] << endl;
            lY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Kieslect" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < swKCount; i++)
    {
        if (kieslectPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << kieslect[i];
            gotoxy(lX + 8, lY + 7);
            cout << kieslectPrices[i] << endl;
            lY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Zero" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < swZCount; i++)
    {
        if (zeroPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << ZERO[i];
            gotoxy(lX, lY + 14);
            cout << zeroPrices[i] << endl;
            lY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Assorted" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < swACount; i++)
    {
        if (AssortedswPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << Assortedsw[i];
            gotoxy(lX, lY + 21);
            cout << AssortedswPrices[i] << endl;
            lY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
}
void printEarbudswithinbudget(double budget, string EarbudsCompanies[], string XiaomiE[], double XiaomiEPrices[], string Audionic[], double AudionicPrices[], string AssortedE[], double AssortedEPrices[], int earbudCount, int earbudXCount, int earbudACount, int earbudAsCount)
{
    int lX = 82, lY = 19;

    cout << "\t \t \t \t \t \t \t \t Xiaomi" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < earbudXCount; i++)
    {
        if (XiaomiEPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << XiaomiE[i];
            gotoxy(lX, lY);
            cout << XiaomiEPrices[i] << endl;
            lY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Audionic" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < earbudACount; i++)
    {
        if (AudionicPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << Audionic[i];
            gotoxy(lX, lY + 7);
            cout << AudionicPrices[i] << endl;
            lY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    cout << "\t \t \t \t \t \t \t \t Assorted" << endl
         << endl;
    cout << "\t \t \t \t \t Model" << setw(28) << "\t \t Prices" << endl;
    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;

    for (int i = 0; i < earbudAsCount; i++)
    {
        if (AssortedEPrices[i] <= budget)
        {
            cout << "\t \t \t \t" << AssortedE[i];
            gotoxy(lX, lY + 14);
            cout << AssortedEPrices[i] << endl;
            lY++;
        }
    }

    cout << "                              ---------------------------------------------------------------------------" << endl
         << endl;
}
void displaySHDevices(string shDevices[], double shDevicesPrices[], int shCount)
{
    int x = 56, y = 15;
    cout << "\t \t \t SECOND HAND DEVICES " << endl
         << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < shCount; i++)
    {
        cout << shDevices[i];
        gotoxy(x, y);
        cout << shDevicesPrices[i] << endl;
        y++;
    }
}

bool modelExisted(string buyDevice, string buyModel, string SamsungM[], string OppoM[], string InfinixM[], string miXiaomiM[], string TecnoM[], string InfinixL[], string Dell[], string HP[], string iphoneL[], string mibro[], string kieslect[], string ZERO[], string Assortedsw[], string XiaomiE[], string Audionic[], string AssortedE[])
{
    if (buyDevice == "MOBILE")
    {
        for (int i = 0; i < 10; i++)
        {
            if (buyModel == SamsungM[i] || buyModel == OppoM[i] || buyModel == InfinixM[i] || buyModel == miXiaomiM[i] || buyModel == TecnoM[i])
            {
                return true;
            }
        }
    }
    else if (buyDevice == "LAPTOP")
    {
        for (int i = 0; i < 10; i++)
        {
            if (buyModel == InfinixL[i] || buyModel == Dell[i] || buyModel == HP[i] || buyModel == iphoneL[i])
            {
                return true;
            }
        }
    }
    else if (buyDevice == "SMART WATCH")
    {
        for (int i = 0; i < 10; i++)
        {
            if (buyModel == mibro[i] || buyModel == kieslect[i] || buyModel == ZERO[i] || buyModel == Assortedsw[i])
            {
                return true;
            }
        }
    }
    else if (buyDevice == "EARBUDS")
    {
        for (int i = 0; i < 10; i++)
        {
            if (buyModel == XiaomiE[i] || buyModel == Audionic[i] || buyModel == AssortedE[i])
            {
                return true;
            }
        }
    }
    return false;
}

double getDevicePrice(string buymodel, string models[], double prices[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (models[i] == buymodel)
        {
            return prices[i];
        }
    }
    return 0.0;
}
double getshDevicePrice(string buySHDevice, string shDevices[], double shDevicesPrices[], int shCount)
{
    for (int i = 0; i < shCount; i++)
    {
        if (buySHDevice == shDevices[i])
        {
            return shDevicesPrices[i];
        }
    }
    return 0;
}
bool checkAccount(string aNo, string accountNo[], int accountCount)
{
    for (int i = 0; i < aNo.length(); i++)
    {
        if (aNo[i] != accountNo[accountCount][i])
        {
            return false;
        }
    }
    return true;
}

void customerMenu(string mobileCompanies[], string SamsungM[], double SamsungMPrices[], string OppoM[], double oppoMPrices[], string InfinixM[], double infinixMPrices[], string miXiaomiM[], double miXiaomiMPrices[], string TecnoM[], double TecnoMPrices[], int &mobileCount, string LaptopCompanies[], string InfinixL[], double InfinixLPrices[], string Dell[], double dellPrices[], string HP[], double HPPrices[], string iphoneL[], double iphoneLPrices[], int laptopCount, string swCompanies[], string mibro[], double mibroPrices[], string kieslect[], double kieslectPrices[], string ZERO[], double zeroPrices[], string Assortedsw[], double AssortedswPrices[], int swCount, string EarbudsCompanies[], string XiaomiE[], double XiaomiEPrices[], string Audionic[], double AudionicPrices[], string AssortedE[], double AssortedEPrices[], int earbudCount, int &mobileSCount, int &mobileOCount, int &mobileICount, int &mobileMCount, int &mobileTCount, int &laptopICount, int &laptopDCount, int &laptopHCount, int &laptopIpCount, int &swMCount, int &swKCount, int &swZCount, int &swACount, int &earbudXCount, int &earbudACount, int &earbudAsCount, string shDevices[], double shDevicesPrices[], int shCount, double &budget, double &tempBudget, string accountNo[], int accountCount, string feedbacks[], int &feedbackCount)
{
    int choice = 1;
    string buyDevice, showDevice, company, buyModel, feedback, buySHDevice, aNo;
    double shPrice;
    while (choice != 0)
    {
        system("cls");
        printHeader();
        cout << "\t \t \t \t \t \t CUSTOMER MENU " << endl
             << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------" << endl
             << endl;
        cout << endl
             << endl
             << endl;
        cout << "Enter 1 to Watch the Device you want (Mobile / Laptop / Smart Watch/ Earbuds)" << endl;
        cout << "Enter 2 to Add money in your account" << endl;
        cout << "Enter 3 to Watch the Device (Mobile / Laptop / Smart Watch/ Earbuds) within your budget" << endl;
        cout << "Enter 4 to Watch Second Hand Devices" << endl;
        cout << "Enter 5 to Select the Device you Wanna Buy " << endl;
        cout << "Enter 6 to Select the Second Hand Device you Want to Buy " << endl;
        cout << "Enter 7 to see your bill and remaining amount." << endl;
        cout << "Enter 8 to give your feedback" << endl;
        cout << "Enter 0 to escape the matrix" << endl
             << endl;

        cout << "Enter your choice... ";
        string input;
        cin >> input;

        if (checkOptionValidation(input))
        {
            choice = stoi(input);
        }
        else
        {
            cout << "Invalid input. Please enter a valid integer." << endl;
            Sleep(750);
            continue;
        }
        system("cls");
        printHeader();
        switch (choice)
        {
        case 1:
            cin.ignore();
            while (true)
            {
                cout << "Enter the name of device (Mobile / Laptop / Smart Watch/ Earbuds) you want to view: ";
                getline(cin, showDevice);
                showDevice = upperLetters(showDevice);
                if (showDevice == "MOBILE")
                {
                    printMobiles(mobileCompanies, SamsungM, SamsungMPrices, OppoM, oppoMPrices, InfinixM, infinixMPrices, miXiaomiM, miXiaomiMPrices, TecnoM, TecnoMPrices, mobileCount, mobileSCount, mobileOCount, mobileICount, mobileMCount, mobileTCount);
                    break;
                }
                else if (showDevice == "LAPTOP")
                {
                    printLaptops(LaptopCompanies, InfinixL, InfinixLPrices, Dell, dellPrices, HP, HPPrices, iphoneL, iphoneLPrices, laptopCount, laptopICount, laptopDCount, laptopHCount, laptopIpCount);
                    break;
                }
                else if (showDevice == "SMART WATCH")
                {
                    printSmartWatches(swCompanies, mibro, mibroPrices, kieslect, kieslectPrices, ZERO, zeroPrices, Assortedsw, AssortedswPrices, swCount, swMCount, swKCount, swZCount, swACount);
                    break;
                }
                else if (showDevice == "EARBUDS")
                {
                    printEarbuds(EarbudsCompanies, XiaomiE, XiaomiEPrices, Audionic, AudionicPrices, AssortedE, AssortedEPrices, earbudCount, earbudXCount, earbudACount, earbudAsCount);
                    break;
                }
                else
                {
                    cout << "Invalid Device Name. " << endl;
                }
            }
            break;
        case 2:

            while (true)
            {
                cout << "Enter your Account Number: ";
                cin >> aNo;
                if ((checkAccount(aNo, accountNo, accountCount)) && aNo.length() == 13)
                {
                    while (true)
                    {
                        cout << "Enter the amount of money you want to add: ";
                        cin >> input;
                        if (checkOptionValidation(input))
                        {
                            budget = stoi(input);
                            break;
                        }
                        else
                        {
                            cout << "Write valid input" << endl
                                 << endl;
                        }
                    }
                    tempBudget = budget;
                    cout << endl
                         << endl
                         << "Your amount of " << budget << " has been updated.";
                    break;
                }
                else
                {
                    cout << "Wrong Account Number." << endl;
                }
            }
            break;
        case 3:
            if (budget == 0)
            {
                cout << "Please first Enter the Amount by going to Option 2." << endl;
            }
            else
            {
                cin.ignore();
                while (true)
                {
                    cout << "Enter the name of device (Mobile / Laptop / Smart Watch / Earbuds) you want to see under " << budget << ": ";
                    getline(cin, buyDevice);
                    buyDevice = upperLetters(buyDevice);
                    if (buyDevice == "MOBILE")
                    {
                        cout << endl;

                        printMobileswithinbudget(budget, mobileCompanies, SamsungM, SamsungMPrices, OppoM, oppoMPrices, InfinixM, infinixMPrices, miXiaomiM, miXiaomiMPrices, TecnoM, TecnoMPrices, mobileCount, mobileSCount, mobileOCount, mobileICount, mobileMCount, mobileTCount);
                        break;
                    }
                    else if (buyDevice == "LAPTOP")
                    {
                        cout << endl;

                        printLaptopswithinbudget(budget, LaptopCompanies, InfinixL, InfinixLPrices, Dell, dellPrices, HP, HPPrices, iphoneL, iphoneLPrices, laptopCount, laptopICount, laptopDCount, laptopHCount, laptopIpCount);
                        break;
                    }
                    else if (buyDevice == "SMART WATCH")
                    {
                        cout << endl;

                        printSmartWatcheswithinbudget(budget, swCompanies, mibro, mibroPrices, kieslect, kieslectPrices, ZERO, zeroPrices, Assortedsw, AssortedswPrices, swCount, swMCount, swKCount, swZCount, swACount);
                        break;
                    }
                    else if (buyDevice == "EARBUDS")
                    {
                        cout << endl;
                        printEarbudswithinbudget(budget, EarbudsCompanies, XiaomiE, XiaomiEPrices, Audionic, AudionicPrices, AssortedE, AssortedEPrices, earbudCount, earbudXCount, earbudACount,
                                                 earbudAsCount);
                        break;
                    }
                    else
                    {
                        cout << "Wrong device Name." << endl;
                    }
                }
            }
            break;
        case 4:
            displaySHDevices(shDevices, shDevicesPrices, shCount);
            break;
        case 5:

            if (budget == 0)
            {
                cout << "Please first Enter the Amount by going to Option 2." << endl;
            }
            else
            {
                cin.ignore();
                while (true)
                {
                    cout << "Enter the name of device (Mobile / Laptop / Smart Watch/ Earbuds) you want to buy: ";
                    getline(cin, buyDevice);
                    buyDevice = upperLetters(buyDevice);
                    if (buyDevice == "MOBILE" || buyDevice == "MOBILES")
                    {
                        printMobileswithinbudget(budget, mobileCompanies, SamsungM, SamsungMPrices, OppoM, oppoMPrices, InfinixM, infinixMPrices, miXiaomiM, miXiaomiMPrices, TecnoM, TecnoMPrices, mobileCount, mobileSCount, mobileOCount, mobileICount, mobileMCount, mobileTCount);
                        break;
                    }
                    else if (buyDevice == "LAPTOP" || buyDevice == "LAPTOPS")
                    {
                        printLaptopswithinbudget(budget, LaptopCompanies, InfinixL, InfinixLPrices, Dell, dellPrices, HP, HPPrices, iphoneL, iphoneLPrices, laptopCount, laptopICount, laptopDCount, laptopHCount, laptopIpCount);
                        break;
                    }
                    else if (buyDevice == "SMART WATCH" || buyDevice == "SMARTWATCH")
                    {
                        printSmartWatcheswithinbudget(budget, swCompanies, mibro, mibroPrices, kieslect, kieslectPrices, ZERO, zeroPrices, Assortedsw, AssortedswPrices, swCount, swMCount, swKCount, swZCount, swACount);
                        break;
                    }
                    else if (buyDevice == "EARBUDS" || buyDevice == "EARBUD")
                    {
                        printEarbudswithinbudget(budget, EarbudsCompanies, XiaomiE, XiaomiEPrices, Audionic, AudionicPrices, AssortedE, AssortedEPrices, earbudCount, earbudXCount, earbudACount, earbudAsCount);
                        break;
                    }
                    else
                    {
                        cout << "This device ain't available." << endl;
                    }
                }
                cout << endl
                     << endl;
                cout << "If no device available Enter 'Return' to go back." << endl;

                while (true)
                {
                    cout << "Enter the name of model: ";
                    getline(cin, buyModel);
                    buyModel = upperLetters(buyModel);

                    if (modelExisted(buyDevice, buyModel, SamsungM, OppoM, InfinixM, miXiaomiM, TecnoM, InfinixL, Dell, HP, iphoneL, mibro, kieslect, ZERO, Assortedsw, XiaomiE, Audionic, AssortedE))
                    {
                        double devicePrice = 0.0;
                        if (buyDevice == "MOBILE")
                        {
                            devicePrice = getDevicePrice(buyModel, SamsungM, SamsungMPrices, mobileSCount) +
                                          getDevicePrice(buyModel, OppoM, oppoMPrices, mobileOCount) +
                                          getDevicePrice(buyModel, InfinixM, infinixMPrices, mobileICount) +
                                          getDevicePrice(buyModel, miXiaomiM, miXiaomiMPrices, mobileMCount) +
                                          getDevicePrice(buyModel, TecnoM, TecnoMPrices, mobileTCount);
                        }
                        else if (buyDevice == "LAPTOP")
                        {
                            devicePrice = getDevicePrice(buyModel, InfinixL, InfinixLPrices, laptopICount) +
                                          getDevicePrice(buyModel, Dell, dellPrices, laptopDCount) +
                                          getDevicePrice(buyModel, HP, HPPrices, laptopHCount) +
                                          getDevicePrice(buyModel, iphoneL, iphoneLPrices, laptopIpCount);
                        }
                        else if (buyDevice == "SMART WATCH")
                        {
                            devicePrice = getDevicePrice(buyModel, mibro, mibroPrices, swMCount) +
                                          getDevicePrice(buyModel, kieslect, kieslectPrices, swKCount) +
                                          getDevicePrice(buyModel, ZERO, zeroPrices, swZCount) +
                                          getDevicePrice(buyModel, Assortedsw, AssortedswPrices, swACount);
                        }
                        else if (buyDevice == "EARBUDS")
                        {
                            devicePrice = getDevicePrice(buyModel, XiaomiE, XiaomiEPrices, earbudXCount) +
                                          getDevicePrice(buyModel, Audionic, AudionicPrices, earbudACount) +
                                          getDevicePrice(buyModel, AssortedE, AssortedEPrices, earbudAsCount);
                        }
                        if (devicePrice > 0 && devicePrice <= budget)
                        {
                            cout << "The selected device " << buyDevice << " (" << buyModel << ") is within your budget and is bought successfully." << endl;
                            cout << "Price: " << devicePrice << endl;
                            budget -= devicePrice;
                            break;
                        }
                        else if (devicePrice > budget)
                        {
                            cout << "The selected device " << buyDevice << " (" << buyModel << ")  is out of your budget." << endl;
                            break;
                        }
                    }
                    else if (buyModel == "RETURN")
                    {
                        break;
                    }
                    else
                    {
                        cout << "Wrong Model Name" << endl;
                    }
                }
            }
            break;
        case 6:
            if (budget == 0)
            {
                cout << "Please first Enter the Amount by going to Option 2." << endl;
            }
            else
            {
                displaySHDevices(shDevices, shDevicesPrices, shCount);
                cout << endl
                     << endl;
                cin.ignore();
                while (true)
                {
                    cout << "Enter the name of device you want to buy: ";
                    getline(cin, buySHDevice);
                    buySHDevice = upperLetters(buySHDevice);
                    shPrice = getshDevicePrice(buySHDevice, shDevices, shDevicesPrices, shCount);
                    if (shPrice > 0 && shPrice <= budget)
                    {
                        cout << "The selected device " << buySHDevice << " is within your budget and is bought successfully." << endl;
                        cout << "Price: " << shPrice << endl;
                        budget -= shPrice;
                        break;
                    }
                    else if (shPrice > budget)
                    {
                        cout << "The selected device " << buySHDevice << " is out of your budget." << endl;
                        break;
                    }
                    else if (shPrice == 0)
                    {
                        cout << "Invalid selection. Please check your input." << endl;
                    }
                }
            }
            break;
        case 7:
            cout << " \t \t \t BILL" << endl;
            cout << "-------------------------------------------------------------------------" << endl
                 << endl;
            cout << "Your Initial Amount: $" << tempBudget << endl;
            if (true)
            {
                tempBudget = tempBudget - budget;
            }
            cout << "Your Paid Amount: $" << tempBudget << endl;
            cout << "Your Remaining Amount: $" << budget << endl;
            break;
        case 8:
            cin.ignore();
            while (true)
            {
                cout << "Enter your feedback: ";
                getline(cin, feedbacks[feedbackCount]);
                if (isInputEmpty(feedbacks[feedbackCount]))
                {
                    cout << "Feedback cannot be empty. Please Enter correct feedback." << endl;
                }
                else
                {
                    cout << "Thanks for your Feedback.";
                    break;
                }
            }
            storeFeedback(feedbacks, feedbackCount);
            feedbackCount++;
            break;
        case 0:
            cout << " ";
            budget = 0, tempBudget = budget;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
        if (choice != 0)
        {
            cout << endl
                 << endl
                 << "Press any key to go back to Menu.... ";
            getch();
        }
    }
}
bool isInputEmpty(string input)
{
    return input.empty();
}
void storeFeedback(string feedbacks[], int feedbackCount)
{
    fstream file;
    file.open("Feedback.txt", ios::app);
    file << feedbacks[feedbackCount] << endl;
    file.close();
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
