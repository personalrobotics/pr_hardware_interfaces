#include <pr_hardware_interfaces/CartesianVelocityInterface.h>

using hardware_interface::HardwareInterfaceException;

using namespace pr_hardware_interfaces;

CartesianVelocityHandle::CartesianVelocityHandle()
  : velocity_command_(NULL)
{}

CartesianVelocityHandle::CartesianVelocityHandle(const std::string& name,
                                             std::vector<double> *velocity_command)
  : name_(name)
  , velocity_command_(velocity_command)
{
  if (!velocity_command_) {
    throw HardwareInterfaceException("Cannot create handle '" + name +
                                                         "'. Position command pointer is null.");
  }
}

std::string CartesianVelocityHandle::getName() const {return name_;}

bool CartesianVelocityHandle::setCommand(const std::vector<double> &commanded_velocity)
{
  if (commanded_velocity.size() != velocity_command_->size()) {
    // Commanded cartesian velocity is not in SE(3)
    return false;
  }

  for (size_t i=0; i < commanded_velocity.size(); ++i) {
    (*velocity_command_)[i] = commanded_velocity[i];
  }

  return true;
}
