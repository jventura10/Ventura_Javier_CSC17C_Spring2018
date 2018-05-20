/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Hash Function with Chaining
 * Created on May 20, 2018, 12:00 PM
 */

#include <iostream>
#include "Hash.h"
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    //int a[]={15,11,27,8,16,24,7,12,13,55,67,68,90,134,38,28};
    int SIZE=20;
    string a[SIZE];
    int n=sizeof(a)/sizeof(a[0]);
    
    //Set some random strings 20 Char lengths
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
    
    //Insert 7 possible chains or columns
    Hash h(7);
    
    for(int i=0;i<n;i++){
        h.insert(a[i]);
    }
    
    h.dsply();
    
    return 0;
}

