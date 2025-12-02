1class ParkingSystem {
2public:
3    int b, m, s;
4    ParkingSystem(int big, int medium, int small) {
5        b = big;
6        m = medium;
7        s = small;
8    }
9    
10    bool addCar(int carType) {
11        if(carType == 1 && b > 0){
12            b -= 1;
13            return true;
14        }
15        if(carType == 2 && m > 0){
16            m -= 1;
17            return true;
18        }
19        if(carType == 3 && s > 0){
20            s -= 1;
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