#include <iostream>
#include <ctime>
#include <string.h>
#include <cmath>
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

//function for convert hex to dec
int convertHexToDec(string hex){
    int p = 1;
    int result = 0;
    for (int i = 0; i < 2; i++){
        char ch = hex[i];
        if (ch >= '0' && ch <='9'){
            result += (ch-48) * (pow(16, p));
        }else if(ch >= 'A' && ch <= 'F'){
            result += (ch-55) * (pow(16, p));
        }
        p--;
    }
    cout<< result;
    return result;
};

//function for decode
string decode(string inputTexe, int key){
    string hex= "";
    string outPut = ""; 
    for (int i = 0; i < inputTexe.length(); i+=2){
        hex = "";
        hex += inputTexe[i];
        hex += inputTexe[i+1];
        outPut += convertHexToDec(hex);
    }
    return outPut;
};

int main(){
    int key;
    int method;
    cout<< "1: Encription"<< endl;
    cout<< "2: Decoding"<< endl;
    cout<< "please choose method: ";
    cin>> method;
    // conditiion for choose method
    if (method == 1){ // for encript
        //key for encrypt
        key = getTime();
        // define text
        string inputText;
        cout<< "Please Enter Your String: ";
        cin>> inputText;
        // get output text
        string outputText = encript(inputText, key);
        // call function for display hex
        displayHex(outputText);
        cout<< endl;
    } else if(method == 2){ // for decode
        // get key and text
        string str;
        cout<< "please enter key:";
        cin>> key;
        cout<< "please enter text to decoding: ";
        cin>> str;
        // call function for decoding 
        cout<< decode(str, key);
    } else{
        cout<< "Not Define";
    }
    return 0;
}