/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Linear Search
 * Created on May 19, 2018, 11:10 PM
 */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int SIZE=20;
    string a[SIZE];
   
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
        for(int i=0;i<SIZE;i++){
            if(a[i]=="tlkqpwoeirutiouryuih"){
                cout<<"Found"<<endl;
            }
        }
    }
    
    
    return 0;
}

