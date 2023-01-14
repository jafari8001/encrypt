#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
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
        char ch = inputText[i];
        if( int(ch) == 32 ){
            outputText += ch;
        }else if(isupper(inputText[i])){
            for (int j = 0; j < key; j++){
                ch = char(int(ch %26) + 65);
            }
            outputText += ch;

        }else{// if char be lower
            for (int j = 0; j < key; j++){
                ch = char(int(ch %26) + 97);
            }
            outputText += ch;
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
    return result;
};

//function for decode
void decode(string inputTexe, int key){
    string hex= "";
    int len = inputTexe.length()/2;
    // array for decimal number
    int decArray[len]; 
    int j = 0;
    for (int i = 0; i < inputTexe.length(); i+=2){
        hex = "";
        hex += toupper(inputTexe[i]);
        hex += toupper(inputTexe[i+1]);
        decArray[j] = convertHexToDec(hex);
        j++;
    }

    for (int i = 0; i < len ; i++){
        int cipher = decArray[i];
            if( decArray[i] == 32 ){
                cout<< " ";
            }
        // cout<< "cipher: "<< cipher<< endl;
        for (int s = 97; s < 123; s++){
            // int number = 97;
            // cout<< "number: "<< number<< endl;
            int guess = s;
            for (int k = 0; k < key; k++){
               guess = guess %26 +97;
            }
            // cout<< "guess: "<< guess<< endl;
            if(guess == cipher){
                cout<< char(s);
                break;
            }
            // number += 1;
        }   
    }
    
};

//function for get info to encription
void forEncription(){
    int key;
    //key for encrypt
    key = getTime();
    // define text
    cout<< "Please Enter Your String: ";
    string inputText;
    getline(cin, inputText);
    // get output text
    string outputText = encript(inputText, key);
    // call function for display hex
    displayHex(outputText);
    cout<< endl;
};

// function for get info to decoding
void forDecoding(){
    int key;
    // get key and text
    string str;
    cout<< "please enter key:";
    cin>> key;
    cout<< "please enter text to decoding: ";
    cin>> str;
    // call function for decoding 
    decode(str, key);
    cout<< endl;
}

int main(){
    string method;
    cout<< "1: Encription"<< endl;
    cout<< "2: Decoding"<< endl;
    cout<< "please choose method: ";
    getline(cin, method);
    // conditiion for choose method
    if (method == "1"){ // for encript
        forEncription();
    } else if(method == "2"){ // for decode
        forDecoding();
    } else{
        cout<< "Not Define";
    }
    return 0;
}