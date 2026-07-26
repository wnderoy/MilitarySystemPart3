#ifndef BASE_FACILITY_H
#define BASE_FACILITY_H

#include <vector>

class Vehicle;
class Warehouse;

class BaseFacility {
private:
    std::vector<Vehicle*> vehicles;
    std::vector<Warehouse*> warehouses;

public:
    BaseFacility();
    ~BaseFacility();

    BaseFacility(const BaseFacility& other) = delete;
    BaseFacility& operator=(const BaseFacility& other) = delete;

    int              getVehicleCount() const;
    const Vehicle*   getVehicle(int index) const;

    int              getWarehouseCount() const;
    const Warehouse* getWarehouse(int index) const;

    bool addVehicle(Vehicle* vehicle);
    bool addWarehouse(Warehouse* warehouse);

    bool addJeep(const std::string& vehicleNumber, int maxPassengers);
    bool addTruck(const std::string& vehicleNumber, double maxWeightKG);
    bool addArmoredTransport(const std::string& vehicleNumber,
                             int maxPassengers,
                             double maxWeightKG);

    const Vehicle*   findVehicle(const std::string& vehicleNumber) const;
    const Warehouse* findWarehouse(const std::string& name) const;

    void printVehicles() const;
    void printWarehouses() const;
    void print() const;
};

#endif // BASE_FACILITY_H
