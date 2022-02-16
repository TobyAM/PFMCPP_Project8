#include "Highway.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */

    if( Car* car = dynamic_cast<Car*>(v))
    {
        car->closeWindows();
    }
    else if(Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(v))
    {
        motorcycle->lanesplitAndRace();
    }
    else if(SemiTruck* semi = dynamic_cast<SemiTruck*>(v))
    {
        semi->closeWindows();
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */

    if( Car* car = dynamic_cast<Car*>(v))
    {
        car->tryToEvade();
    }
    else if(Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(v))
    {
        motorcycle->tryToEvade();
    }
    else if(SemiTruck* semi = dynamic_cast<SemiTruck*>(v))
    {
        semi->pullOver();
    }
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
