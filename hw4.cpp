box.h

#ifndef BOX_H
#define BOX_H

#include <string>

using namespace std;

class box{
    private:
        double length,width,height,weight;
        string address,city,state;
        int zip;
    public:
        box();
        box(double len,double wid,double hei,string add,string cit, string st,int z);
        double calcShippingPrice();
        void print();
        void setLength(double len);
        double getLength();
        void setWidth(double);
        double getWidth();
        void setHeight(double);
        double getHeight();
        void setWeight(double);
        double getWeight();
        void setAddress(string);
        string getAddress();
        void setCity(string);
        string getCity();
        void setState(string);
        string getState();
        void setZip(int);
        int getZip();
};

#endif

box.cpp

#include "box.h"

#include<iostream>

using namespace std;

box::box(){
    length = width = height = 0;
    address = "";
    city = "";
    state = "XX";
    zip = 0;
}

box::box(double len,double wid,double hei,string add,string cit, string st,int z){
    setLength(len);
    setWidth(wid);
    setHeight(hei);
    address = add;
    city = cit;
    setState(st);
    zip = z;
}

void box::setLength(double len){
    length = len;
    if(length<0){
        length = 0;
    }
}

double box::getLength(){
    return length;
}

void box::setWidth(double wid){
    width = wid;
    if(width<0){
        width = 0;
    }
}

double box::getWidth(){
    return width;
}

void box::setHeight(double hei){
    height = hei;
    if(height<0){
        height = 0;
    }
}

double box::getHeight(){
    return height;
}

string box::getAddress(){
    return address;
}

void box::setAddress(string add){
    address = add;
}

void box::setCity(string cit){
    city = cit;
}

string box::getCity(){
    return city;
}

void box::setState(string st){

    state = st;
    if(state.length()!=2){
        state = "XX";
    }
}
string box::getState(){
    return state;
}

void box::setZip(int z){
    zip = z;
    if(zip<0){
        zip = 0;
    }
}

int box::getZip(){
    return zip;
}

double box::calcShippingPrice(){
    return ((length+width*height)*0.50 + weight);
}

void box::print(){
    cout<<"Length : "<<length<<endl;
    cout<<"Width   : "<<width<<endl;
    cout<<"Height : "<<height<<endl;
    cout<<"Address : "<<address<<endl;
    cout<<"City    : "<<city<<endl;
    cout<<"State   : "<<state<<endl;
    cout<<"Zip     : "<<zip<<endl;
}

test.cpp

#include "box.cpp"

#include<iostream>

int main(){
    box boxes[3];

    double l,w,h;
    string add,cit,st;
    int zip;
    int i;
    for(i=0;i<3;i++){
        cout<<"Enter the details for box "<<(i+1)<<endl;
        cout<<"Enter the length"<<endl;
        cin>>l;
        cout<<"Enter the Width"<<endl;
        cin>>w;
        cout<<"Enter the height"<<endl;
        cin>>h;
        cout<<"Enter the address"<<endl;
        cin.ignore();
        getline(cin,add);
        cout<<"Enter the city"<<endl;
        cin>>cit;
        cout<<"Enter the state"<<endl;
        cin>>st;
        cout<<"Enter the zip code"<<endl;
        cin>>zip;
        boxes[i] = box(l,w,h,add,cit,st,zip);
    }

    double price = 0;
    for(int i=0;i<3;i++){
        cout<<"For box "<<(i+1)<<endl;
        price = price + boxes[i].calcShippingPrice();
        boxes[i].print();
    }
    cout<<"Total price of all the boxes is "<<price<<endl;
    return 0;
}
