#ifndef MPC_INTEGRATION_ITERATOR_ITERATOR_HPP
#define MPC_INTEGRATION_ITERATOR_ITERATOR_HPP

namespace mpc {
namespace integration {
namespace iterator {

template <class SYSTEM, class STEPPER>
class ConstantIterator : public Iterator<SYSTEM, STEPPER> {
   public:
    using Base = Iterator<SYSTEM, STEPPER>;
    using typename Base::Control;
    using typename Base::State;
    using typename Base::Stepper;
    using typename Base::System;
    using typename Base::Time;

    void Next(const System &system, const Stepper &stepper, const State &state, const Control &control,
              const Time &time, const Time &delta_time,
              State &result) const override {
        stepper.Step(system, state, control, time, delta_time, result);
    }
};

}  // namespace iterator
}  // namespace integration
}  // namespace mpc

#endif  // MPC_INTEGRATION_ITERATOR_ITERATOR_HPP