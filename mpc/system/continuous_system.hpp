#ifndef MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP
#define MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP

#include <Eigen/Core>

namespace mpc {
namespace system {

template <size_t NUM_STATE, size_t NUM_CONTROL, typename SCALAR = double>
class ContinuousSystem {
   public:
    using State = Eigen::Matrix<SCALAR, NUM_STATE, 1>;
    using Control = Eigen::Matrix<SCALAR, NUM_CONTROL, 1>;
    using Time = SCALAR;

    constexpr size_t GetNumState() const { return NUM_STATE; }

    constexpr size_t GetNumControl() const { return NUM_CONTROL; }

    virtual void Dynamics(const State &state, const Control &control,
                          const Time &time, State &result) const = 0;
};

}  // namespace system
}  // namespace mpc

#endif  // MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP
