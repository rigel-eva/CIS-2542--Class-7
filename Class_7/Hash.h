//
//  Hash.h
//  Class 7
//
//  Created by Sir Rigel on 3/11/13.
//  Copyright (c) 2013 Sir Rigel. All rights reserved.
//

#ifndef __Class_7__Hash__
#define __Class_7__Hash__

#include <iostream>
namespace sirRigel{
    template<class data, class keyType>
    class hash{
    private:
        data *myData;
        int(*KeyGen)(data);                             //So we can remember to Call this function back, Mutlipule times.
    public:
        hash(int mySize, int(*Key_Generation)(data));
        ~hash();
        void insert(keyType key, data Data);
        data get(keyType key);
    };
}
template<class data, class keyType>
sirRigel::hash<data, keyType>::hash(int mySize, int(*keyGeneration)(data)){
    myData=new data[mySize];//Sets the array of data to the proper size
    KeyGen=keyGeneration;   //and let's try to remember the function that we need to go back to.
}
template<class data, class keyType>
sirRigel::hash<data, keyType>::~hash(){
    delete[] myData;        //Well, that was fun, but I guess we are done.
}
template<class data, class keyType>
void sirRigel::hash<data, keyType>::insert(keyType Key, data Data){
    myData[KeyGen(Key)]=Data;   //Let's go ahead and insert that data at the KeyGen Point.
}
template <class data, class keyType>
data sirRigel::hash<data, keyType>::get(keyType key){
    return myData[KeyGen(key)];
}
#endif /* defined(__Class_7__Hash__) */
