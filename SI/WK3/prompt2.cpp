#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
class ATT {
     private:
        int blaster;
        int speed;
        int stromTrooper;
        string weapon;
        int price;
        int rebelsKilled;
    public:
        void setWeaponryData();
        void ATTdata ();
        void troops ();
        void print ();
        ATT();
};

int main(){
    srand (time(0));
    ATT Walker1;
    Walker1.setWeaponryData();
    Walker1.ATTdata();
    Walker1.troops();
   Walker1.print ();
    return 0;
}

ATT::ATT(){
    rebelsKilled =1000;
}


void ATT::setWeaponryData(){
    cout << "Enter the damage"<<endl;
    cin >> blaster;
    cout << "Weapon name" <<endl;
    cin >> weapon;
}

void ATT::ATTdata(){
    cout << "Enter the price" << endl;
    cin >> price;
    cout << "Enter the speed" << endl;
    cin >> speed;
}

void ATT::troops(){
    cout << "Enter troop in bot" <<endl;
    cin >> stromTrooper;
}

void ATT::print(){
    cout << "This ATT cost " << price <<endl;
    cout << "It is equipped with " << weapon << " that deals " << blaster <<" damage." << endl;
    cout << "It will carry " << stromTrooper << " stormTroopers that will hunt down those rebels" << endl;
    cout << "rebel toyota spotted , destroying target with " << weapon << endl;
    cout << "Now this ATT has killed " << rebelsKilled << " rebels." << endl;
}

