#ifndef MPC_INTEGRATION_EULER_STEPPER_HPP
#define MPC_INTEGRATION_EULER_STEPPER_HPP

#include "mpc/integration/stepper/stepper.hpp"

namespace mpc {
namespace integration {
namespace stepper {

template <class SYSTEM>
class EulerStepper : public Stepper<SYSTEM> {
   public:
    using Base = Stepper<SYSTEM>;
    using typename Base::System;
    using typename Base::State;
    using typename Base::Control;
    using typename Base::Time;

    void Step(const System &system, const State &state, const Control &control,
              const Time &time, const Time &delta_time,
              State &result) const override {
        system.Dynamics(state, control, time, result);
        result = state + result * delta_time;
    }
};

}  // namespace stepper
}  // namespace integration
}  // namespace mpc

#endif  // MPC_INTEGRATION_EULER_STEPPER_HPP