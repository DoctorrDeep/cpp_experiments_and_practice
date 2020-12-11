#include "car.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main(){
    vector<Sedan*> sed_vect;
    Sedan* sed = nullptr;

    vector<string> colors = {"mahogany", "velvet pink", "royal blue", "jet black"};
    vector<int> door_count = {2,4,5};

    for(int i{40}; i <= 60; i++){
        sed = new Sedan(colors[i%4], i, i*7, door_count[i%3]);
        sed_vect.push_back(sed);
    }

    for(Sedan* a_sedan_pt : sed_vect){
        a_sedan_pt->IncrementDistance();
        a_sedan_pt->IncrementDistance();
        a_sedan_pt->IncrementDistance();

        a_sedan_pt->PrintCarData();
        a_sedan_pt->PrintDoorData();
    }


}
