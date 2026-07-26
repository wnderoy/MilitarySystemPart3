#include "ArmoredTransport.h"
using namespace std;

ArmoredTransport::ArmoredTransport(const string& vehicleNumber, int maxPassengers, double maxWeightKG)
    : Vehicle(vehicleNumber), Jeep(vehicleNumber, maxPassengers), Truck(vehicleNumber, maxWeightKG) {};

std::ostream &operator<<(std::ostream &os, const ArmoredTransport &transport)
{
    os << "Armored Transport Vehicle Number: " << transport.getVehicleNumber()
       << ", Max Passengers: " << transport.getMaxPassengers()
       << ", Max Weight (KG): " << transport.getMaxWeightKG();
    return os;
};
