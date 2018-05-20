/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Binary Search
 * Created on May 20, 2018, 11:36 AM
 */

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char** argv) {
    //Declare Variables
    int SIZE=20;
    string a[SIZE];
    bool found=false;
    int min=0;
    int max=SIZE;
   
    a[0]="abcdefghijklmnopqrst";
    a[1]="bbcdefghijklmnopqrsu";
    a[2]="cbcdeefghijklmnopqrv";
    a[3]="dsdbfkjdbsfjkbjksdfj";
    a[4]="enfkjnsgjnfjgndfjdgn";
    a[5]="forrkgoirejgiongikrm";
    a[6]="gernewjknjkewnjkfklk";
    a[7]="hlksmklnfksdlnglknkl";
    a[8]="ifmfnmfklfngfkdlgnkg";
    a[9]="jgkrmgklerkngntrkntj";
    a[10]="kjsnfjknsjnfjsnjdfjf";
    a[11]="lkjdsnfjkdsnfsddjnff";
    a[12]="mknjkoeopwqpkmcnzxcn";
    a[13]="ndsfknsdlkngjntieitu";
    a[14]="oitueiowoxmnvbmmdmke";
    a[15]="prtncnxmxlxalldsklje";
    a[16]="qxmcxnzcbmbskjhehreu";
    a[17]="rfpwoqoriiruthurhgjn";
    a[18]="spqwoeoetirutihuhjnz";
    a[19]="tlkqpwoeirutiouryuih";
    
    for(int i=0;i<50000;i++){
        do{
            int mid=(min+max)/2;

            if(a[mid]=="tlkqpwoeirutiouryuih"){
                cout<<"Found"<<endl;
                found=true;
            }
            else if(a[mid]>"tlkqpwoeirutiouryuih"){
                max=mid;
            }
            else if(a[mid]<"tlkqpwoeirutiouryuih"){
                min=mid;
            }
        }while(found==false);
    }
    
    return 0;
}

