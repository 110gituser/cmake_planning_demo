#include <iostream>
#include "pnc_map.h"  // 确保路径正确
using std::cout,std::endl;

void mapTest(){
    PNC_Map my_map;
    my_map.map_info();
    cout<<"hello world\n";
}

int main(){
    mapTest();
    return 0;
}
