#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

   
    static int totalVehicles;

public:

    Vehicle() : vehicleID(0), manufacturer("Unknown"), model("Unknown"), year(0) {
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int yr)
        : vehicleID(id), manufacturer(manu), model(mod), year(yr) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    void setVehicleID(int id) { vehicleID = id; }
    int getVehicleID() const { return vehicleID; }

    void setManufacturer(string manu) { manufacturer = manu; }
    string getManufacturer() const { return manufacturer; }

    void setModel(string mod) { model = mod; }
    string getModel() const { return model; }

    void setYear(int yr) { year = yr; }
    int getYear() const { return year; }

    static int getTotalVehicles() { return totalVehicles; }

   
    virtual void display() const {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};


int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car() : Vehicle(), fuelType("Unknown") {}

    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    void setFuelType(string fuel) { fuelType = fuel; }
    string getFuelType() const { return fuelType; }

    void display() const override {
        cout << "\n--- Car ---" << endl;
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity; 

public:
    ElectricCar() : Car(), batteryCapacity(0) {}

    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void setBatteryCapacity(int cap) { batteryCapacity = cap; }
    int getBatteryCapacity() const { return batteryCapacity; }

    void display() const override {
        cout << "\n--- Electric Car ---" << endl;
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};


class Sedan : public Car {
public:
    Sedan(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}

    void display() const override {
        cout << "\n--- Sedan ---" << endl;
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class SUV : public Car {
public:
    SUV(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}

    void display() const override {
        cout << "\n--- SUV ---" << endl;
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Aircraft {
protected:
    int flightRange; // in km

public:
    Aircraft(int range = 0) : flightRange(range) {}

    void setFlightRange(int range) { flightRange = range; }
    int getFlightRange() const { return flightRange; }

    void displayAircraft() const {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string manu, string mod, int yr, string fuel, int range)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void display() const {
        cout << "\n--- Flying Car ---" << endl;
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
        displayAircraft();
    }
};

class SportsCar : public ElectricCar {
private:
    int topSpeed;

public:
    SportsCar(int id, string manu, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    void setTopSpeed(int speed) { topSpeed = speed; }
    int getTopSpeed() const { return topSpeed; }

    void display() const override {
        cout << "\n--- Sports Car ---" << endl;
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class VehicleRegistry {
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() : count(0) {}

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++)
            delete vehicles[i];
    }

    void addVehicle(Vehicle* v) {
        if (count < 100)
            vehicles[count++] = v;
        else
            cout << "Registry is full!" << endl;
    }

    void displayAll() const {
        if (count == 0) {
            cout << "No vehicles registered yet!" << endl;
            return;
        }

        cout << "\n===== Vehicle List =====" << endl;
        for (int i = 0; i < count; i++)
            vehicles[i]->display();
        cout << "\nTotal Vehicles: " << Vehicle::getTotalVehicles() << endl;
    }

    void searchByID(int id) const {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                vehicles[i]->display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Vehicle not found!" << endl;
    }
};
int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n===== Vehicle Registry Menu =====" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. Display All Vehicles" << endl;
        cout << "3. Search Vehicle by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nChoose Vehicle Type:" << endl;
            cout << "1. Car\n2. Electric Car\n3. Sedan\n4. SUV\n5. Flying Car\n6. Sports Car" << endl;
            int type;
            cin >> type;

            int id, year, battery, speed, range;
            string manu, model, fuel;

            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;

            cout << "Enter Fuel Type: ";
            cin >> fuel;

            switch (type) {
                case 1:
                    registry.addVehicle(new Car(id, manu, model, year, fuel));
                    break;
                case 2:
                    cout << "Enter Battery Capacity (kWh): ";
                    cin >> battery;
                    registry.addVehicle(new ElectricCar(id, manu, model, year, fuel, battery));
                    break;
                case 3:
                    registry.addVehicle(new Sedan(id, manu, model, year, fuel));
                    break;
                case 4:
                    registry.addVehicle(new SUV(id, manu, model, year, fuel));
                    break;
                case 5:
                    cout << "Enter Flight Range (km): ";
                    cin >> range;
                    registry.addVehicle(new FlyingCar(id, manu, model, year, fuel, range));
                    break;
                case 6:
                    cout << "Enter Battery Capacity (kWh): ";
                    cin >> battery;
                    cout << "Enter Top Speed (km/h): ";
                    cin >> speed;
                    registry.addVehicle(new SportsCar(id, manu, model, year, fuel, battery, speed));
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        } else if (choice == 2) {
            registry.displayAll();
        } else if (choice == 3) {
            int id;
            cout << "Enter Vehicle ID to search: ";
            cin >> id;
            registry.searchByID(id);
        } else if (choice == 4) {
            cout << "Exiting Vehicle Registry..." << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
