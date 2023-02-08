#include <iostream>
#include <string>

using namespace std;
  int main(){
    const char k_cAuthenticatorCodeCharacter1 = 'E';
    const char k_cAuthenticatorCodeCharacter2 = 'C';
    const char k_cAuthenticatorCodeCharacter3 = 'A';
    char Characterno1;
    char Characterno2;
    char Characterno3;

      std::cout<< "Enter the first character of the message code:"<< std::endl;
      std::cin>> Characterno1;
      std::cout<< "Enter the second character of the message code:"<< std::endl;
      std::cin>> Characterno2;
      std::cout<< "Enter the third character of the message code:"<< std::endl;
      std::cin >> Characterno3;
      std::string Authenticator;
      Authenticator = Characterno1 + Characterno2 + Characterno3;
    if ((k_cAuthenticatorCodeCharacter1 == Characterno1) && (k_cAuthenticatorCodeCharacter2 == Characterno2) && (k_cAuthenticatorCodeCharacter3 == Characterno3)){
        std::cout<<"This message is authentic."<< std::endl;

    }
    else{
      std::cout<<"This message is inauthetic. "<< std::endl;
    }

    int sumcheck = (int(Characterno1) + int(Characterno2) + int(Characterno3)) % 7;
    int FixedSum = 5;
    if (sumcheck == FixedSum){
      std::cout<<"Message code checksum is valid: "<<sumcheck<<endl;
    }
    else{
      std::cout<<"Message code checksum is invalid: "<<sumcheck<<"; expected: "<<FixedSum<<endl;
    }
    std::cout<<"ASCII integer values of the message code characters:"<<int(k_cAuthenticatorCodeCharacter1)<<", "<<int(k_cAuthenticatorCodeCharacter2)<<", "<<int(k_cAuthenticatorCodeCharacter3)<<std::endl;
    std::cout<<"ASCII integer values of the chosen characters:"<<int(Characterno1)<<", "<<int(Characterno2)<<", "<<int(Characterno3)<<std::endl;
    std::cout<<"ASCII sum of the message code characters:"<<int(k_cAuthenticatorCodeCharacter1)+int(k_cAuthenticatorCodeCharacter2)+int(k_cAuthenticatorCodeCharacter3)<<std::endl;
    std::cout<<"ASCII sum of the chosen characters: "<<(int(Characterno1) + int(Characterno2) + int(Characterno3))<<std::endl;

    int my_message = (int(Characterno1) + int(Characterno2) + int(Characterno3));

    if (k_cAuthenticatorCodeCharacter1 != Characterno1){
      std::cout<<"First character does not match"<<"; Message: "<<Characterno1<<"; Authenticator: "<<k_cAuthenticatorCodeCharacter1<<endl;
    }
    if (k_cAuthenticatorCodeCharacter2 != Characterno2){
      std::cout<<"Second character does not match"<<"; Message: "<<Characterno2<<"; Authenticator: "<<k_cAuthenticatorCodeCharacter2 << endl;
    }
    if (k_cAuthenticatorCodeCharacter3 != Characterno3){
      std::cout<<"Third character does not match"<<"; Message: "<<Characterno3<<"; Authenticator: "<<k_cAuthenticatorCodeCharacter3<<endl;
    }
    if (my_message > 201){
      std::cout<<"The message code " << Characterno1 <<Characterno2 <<Characterno3 <<" is lexicographically more than the Authenticator code "<<k_cAuthenticatorCodeCharacter1<<k_cAuthenticatorCodeCharacter2<<k_cAuthenticatorCodeCharacter3<<std::endl;
    }
    if (my_message < 201){
      std::cout<<"The message code " << Characterno1 <<Characterno2<<Characterno3 <<" is lexicographically less than the Authenticator code "<<k_cAuthenticatorCodeCharacter1<<k_cAuthenticatorCodeCharacter2<<k_cAuthenticatorCodeCharacter3<<std::endl;
    }
}
