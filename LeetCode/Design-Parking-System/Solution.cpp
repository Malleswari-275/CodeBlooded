1class ParkingSystem {
2public:
3    int big, medium, small;
4    ParkingSystem(int big, int medium, int small) {
5        this->big = big;
6        this->medium = medium;
7        this->small = small;
8    }
9    
10    bool addCar(int carType) {
11        if(carType == 1 && this->big > 0){
12            this->big -= 1;
13            return true;
14        }
15        if(carType == 2 && this->medium > 0){
16            this->medium -= 1;
17            return true;
18        }
19        if(carType == 3 && this->small > 0){
20            this->small -= 1;
21            return true;
22        }
23        return false;
24    }
25};
26
27/**
28 * Your ParkingSystem object will be instantiated and called as such:
29 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
30 * bool param_1 = obj->addCar(carType);
31 */