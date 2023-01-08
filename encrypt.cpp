#include <iostream>
using namespace std;

// encrypt function
string encript(string inputText, int key){
    //define output text 
    string outputText = "";
    for(int i=0; i<inputText.length(); i++){
        outputText += char(int(inputText[i] + key - 97) % 26 + 97);
    };
    return outputText;
};

int main(){
    // define text
    string inputText;
    cout<< "Please Enter Your String: ";
    cin>> inputText;
    cout<<endl<< "output: "<< encript(inputText, 5)<<endl;
    return 0;
}