//
//  main.cpp
//  Class 7
//
//  Created by Sir Rigel on 3/11/13.
//  Copyright (c) 2013 Sir Rigel. All rights reserved.
//

#include <iostream>
#include "Hash.h"
using namespace std;
int factorial(int n);
int recFunc(int n);
int hashFunction(string key);
int daveHashFunction(string key);
int main(int argc, const char * argv[]){
    cout<<"5 Factorial is: "<<factorial(5)<<"\n";
    cout<<"RecFunc of 84 is: "<<recFunc(84)<<"\n";
    sirRigel::hash<string, string> myHash(10, daveHashFunction);
    myHash.insert("Bob",  "(555) 525-0010");
    myHash.insert("Joe",  "(331) 465-9956");
    myHash.insert("Mary", "(116) 255-3904");
    myHash.insert("Death", "42-42-564");      //Collides with Joe
    cout<<"Getting Bob's Phone Number: "<<myHash.get("Bob")<<"\n";
    cout<<"Getting Joe's Phone Number: "<<myHash.get("Joe")<<"\n";
    cout<<"Getting Mary's Phone Number: "<<myHash.get("Mary")<<"\n";
    cout<<"Getting Death's Phone Number: "<<myHash.get("Death")<<"\n";
    
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int recFunc(int n){
    if (n<=0)
        return 0;
    else
        return recFunc(n/10)+1;
}
int hashFunction(string key){
    int returner = 0;
    for (int i=0; i<key.size(); i++) {
        returner+=key[i];
    }
    return returner%10;
}
int daveHashFunction(string key){
    //… because … Homestuck …
    int returner=0;
    for (int i=0; i<key.length(); i++) {
        if (toupper(key[i])=='A'||toupper(key[i])=='E'||toupper(key[i])=='I'||toupper(key[i])=='O'||toupper(key[i])=='U')
            returner+=1;//Cool, the Letter is a Vowel, let's add one.
        else
            returner+=2;//Drat, the Letter is a const. let's add two. damnit.
    }
    return returner;
}

