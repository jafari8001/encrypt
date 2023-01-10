#include <iostream>
#include <ctime>
using namespace std;

//function for get time
int getTime(){
    int key;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    key = local_time->tm_hour;
    return key;
}

// encrypt function
string encript(string inputText, int key){
    //define output text 
    string outputText = "";
    for(int i=0; i<inputText.length(); i++){ // if char be upper
        if(inputText[i]>='A' && inputText[i]<='Z'){
            outputText += char(int(inputText[i] + key - 65) % 26 + 65);
        }else{// if char be lower
            outputText += char(int(inputText[i] + key - 97) % 26 + 97);
        }
    };
    // return result
    return outputText;
};
// function to display hex
void displayHex(string output){
    int len = output.length();
    for (int i = 0; i < len; i++){
        cout<< hex<< int(output[i]);
    }   
};

int main(){
    //key for encrypt
    int key = getTime();
    // define text
    string inputText;
    cout<< "Please Enter Your String: ";
    getline(cin, inputText);
    // get output text
    string outputText = encript(inputText, key);
    // call function for display hex
    displayHex(outputText);
    cout<< endl;
    return 0;
}