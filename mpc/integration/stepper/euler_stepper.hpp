#ifndef MPC_INTEGRATION_EULER_STEPPER_HPP
#define MPC_INTEGRATION_EULER_STEPPER_HPP

#include "mpc/integration/stepper/stepper.hpp"

namespace mpc {
namespace integration {
namespace stepper {

class EulerStepper : public Stepper {
   public:
    void Step(const ContinuousSystem &system, const Eigen::VectorXd &state,
              const Eigen::VectorXd &control, const double &time,
              const double &delta_time,
              Eigen::VectorXd &result) const override {
        system.Dynamics(state, control, time, result);
        result = state + result * delta_time;
    }
};

}  // namespace stepper
}  // namespace integration
}  // namespace mpc

#endif  // MPC_INTEGRATION_EULER_STEPPER_HPP