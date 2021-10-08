#include <iostream>
#include "logs.h"

using namespace std;


void loginfo( std::string text) {
    cout << "\33[34m LogInfo " << text << "\33[0m" << endl ;
}
void loginfo( std::string text, std::string object) {

    cout << "\33[34m LogInfo " << text << " " << object << "\33[0m"  << endl ;
}
// log ausgabe für Images -> Grün
void logimage( std::string text) {
    cout << "\33[32m LogImage " << text << "\33[0m" << endl;
}
void logimage( std::string text, std::string object) {
    cout << "\33[32m LogImage " << text << " " << object << "\33[0m" << endl;
}
// -------------------------------------------------
// LogWarn ings für text und objects
// -------------------------------------------------
void logwarn( std::string text){
    cout << "\33[35m LogWarn : " << text << "\33[0m" << endl;
}
void logwarn( std::string text, std::string object) {
    cout << "\33[35m LogWarn : " <<  text  << " " <<  object << "\33[0m" << endl;
}

void logEmptyLine(int count) {
    for (int i = 0; i < count; i++)
        cout << "\n"  << endl;

}
