#ifndef MPC_INTEGRATION_STEPPER_HPP
#define MPC_INTEGRATION_STEPPER_HPP

#include "mpc/system/continuous_system.hpp"

namespace mpc {
namespace integration {
namespace stepper {

using namespace mpc::system;

class Stepper {
   public:
    virtual void Step(const ContinuousSystem &system,
                      const Eigen::VectorXd &state,
                      const Eigen::VectorXd &control, const double &time,
                      const double &delta_time,
                      Eigen::VectorXd &result) const = 0;
};

}  // namespace stepper
}  // namespace integration
}  // namespace mpc

#endif  // MPC_INTEGRATION_STEPPER_HPP