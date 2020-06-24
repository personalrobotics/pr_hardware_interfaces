#ifndef PR_HARDWARE_INTERFACES_CARTESIAN_VELOCITY_INTERFACE_H_
#define PR_HARDWARE_INTERFACES_CARTESIAN_VELOCITY_INTERFACE_H_

#include <hardware_interface/hardware_interface.h>
#include <hardware_interface/internal/hardware_resource_manager.h>
#include <pr_hardware_interfaces/MoveState.h>

namespace pr_hardware_interfaces {

class CartesianVelocityHandle
{
public:
  CartesianVelocityHandle();
  CartesianVelocityHandle(const std::string& name,
                        std::vector<double> *velocity_command);

  std::string getName() const;
  bool setCommand(const std::vector<double> &commanded_velocity);

private:
  std::string name_;
  std::vector<double> *velocity_command_;
};

class CartesianVelocityInterface :
    public hardware_interface::HardwareResourceManager<CartesianVelocityHandle, hardware_interface::ClaimResources>{};

} // namespace

#endif
