#include <iostream>
#include <boost/di.hpp>

namespace di = boost::di;
class Engine {
public:
    Engine(StartupMotorInterface* startupmotor, FuelPumpInterface* fuelpump)
        : startupmotor(startupmotor), fuelpump(fuelpump) {}

private:
    StartupMotorInterface* startupmotor;
    FuelPumpInterface* fuelpump;
};

class Transmission {};

class StartupMotor {};

class FuelPump {};

class Car {
public:
    Car(EngineInterface* engine, TransmissionInterface* transmission)
        : engine(engine), transmission(transmission) {}

private:
    EngineInterface* engine;
    TransmissionInterface* transmission;
};

class EngineInterface : public Engine {};

class TransmissionInterface : public Transmission {};

class StartupMotorInterface : public StartupMotor {};

class FuelPumpInterface : public FuelPump {};

int main() {
    auto injector = di::make_injector(
        di::bind<EngineInterface>().to<Engine>(),
        di::bind<TransmissionInterface>().to<Transmission>(),
        di::bind<StartupMotorInterface>().to<StartupMotor>(),
        di::bind<FuelPumpInterface>().to<FuelPump>()
    );

    auto car = injector.create<Car>();
    // injected car object
    return 0;
}
