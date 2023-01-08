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

int main(){
    //key for encrypt
    int key = getTime();
    // define text
    string inputText;
    cout<< "Please Enter Your String: ";
    cin>> inputText;
    // call function for encrypt string
    cout<<endl<< "output: "<< encript(inputText,key)<<endl;
    return 0;
}