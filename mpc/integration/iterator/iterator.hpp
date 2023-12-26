#ifndef MPC_INTEGRATION_ITERATOR_ITERATOR_HPP
#define MPC_INTEGRATION_ITERATOR_ITERATOR_HPP

namespace mpc {
namespace integration {
namespace iterator {

template <class SYSTEM, class STEPPER>
class Iterator {
   public:
    using Stepper = STEPPER<SYSTEM>;
    using System = typename SYSTEM::System;
    using State = typename SYSTEM::State;
    using Control = typename SYSTEM::Control;
    using Time = typename SYSTEM::Time;

    virtual void Next(const System &system, const Stepper &stepper,
                      const State &state, const Control &control,
                      const Time &time, const Time &delta_time,
                      State &result) const = 0;
};

}  // namespace iterator
}  // namespace integration
}  // namespace mpc

#endif  // MPC_INTEGRATION_ITERATOR_ITERATOR_HPP