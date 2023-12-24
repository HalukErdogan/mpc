#ifndef MPC_INTEGRATION_STEPPER_HPP
#define MPC_INTEGRATION_STEPPER_HPP

namespace mpc {
namespace integration {
namespace stepper {

template <class SYSTEM>
class Stepper {
   public:
    using System = SYSTEM;
    using State = typename SYSTEM::State;
    using Control = typename SYSTEM::Control;
    using Time = typename SYSTEM::Time;

    virtual void Step(const System &system, const State &state,
                      const Control &control, const Time &time,
                      const Time &delta_time, State &result) const = 0;
};

}  // namespace stepper
}  // namespace integration
}  // namespace mpc

#endif  // MPC_INTEGRATION_STEPPER_HPP