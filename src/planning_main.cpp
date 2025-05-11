#include<iostream>
#include"process.h"
#include"show_result.h"
using std::cout,std::endl;

int main(){
    cout<<"planning start\n";
    Process pro;
    pro.planProcess();
    cout<<"planning end\n";

    cout<<"show result :\n";
    ShowResult show;
    show.drawResult();
    return 0;
}