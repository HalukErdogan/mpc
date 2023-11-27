#ifndef MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP
#define MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP

#include <Eigen/Core>

namespace mpc {
namespace system {

template <size_t NumState, size_t NumControl, typename Scalar = double>
class ContinuousSystem {
   public:
    using State = Eigen::Matrix<Scalar, NumState, 1>;
    using Control = Eigen::Matrix<Scalar, NumControl, 1>;
    using Time = Scalar;

    const size_t n_state = NumState;
    const size_t n_control = NumControl;

    virtual State dynamics(const State &state, const Control &control,
                           const Time &time) const = 0;
};

}  // namespace system
}  // namespace mpc

#endif  // MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP
