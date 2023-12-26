#ifndef MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP
#define MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP

#include <Eigen/Core>

namespace mpc {
namespace system {

class ContinuousSystem {
   public:
    virtual int GetNumState() const = 0;
    virtual int GetNumControl() const = 0;
    virtual void Dynamics(const Eigen::VectorXd &state,
                          const Eigen::VectorXd &control, const double &time,
                          Eigen::VectorXd &result) const = 0;
};

}  // namespace system
}  // namespace mpc

#endif  // MPC_SYSTEM_CONTINUOUS_SYSTEM_HPP
