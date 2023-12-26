#include <gtest/gtest.h>

#include "mpc/system/continuous_system.hpp"

using namespace mpc::system;

class OneDimCart : public ContinuousSystem {
   public:
    int GetNumState() const { return 2; }
    int GetNumControl() const { return 1; }
    void Dynamics(const Eigen::VectorXd &state, const Eigen::VectorXd &control,
                  const double &time, Eigen::VectorXd &result) const override {
        const auto &pos = state(0);
        const auto &vel = state(1);
        const auto &acc = control(0);
        result(0) = vel;
        result(1) = acc;
    }
};

TEST(System, ContinuousSystemInit) {
    OneDimCart system;
    Eigen::VectorXd state;
    Eigen::VectorXd control;
    double time;

    state.resize(2);
    control.resize(1);
    state << 0.0, 0.0;
    control << 1.0;
    time = 0.0;

    Eigen::VectorXd result, expected;
    system.Dynamics(state, control, time, result);
    expected << state(1), control(0);

    ASSERT_EQ(2, system.GetNumState());
    ASSERT_EQ(1, system.GetNumControl());
    ASSERT_EQ(result, expected);
}